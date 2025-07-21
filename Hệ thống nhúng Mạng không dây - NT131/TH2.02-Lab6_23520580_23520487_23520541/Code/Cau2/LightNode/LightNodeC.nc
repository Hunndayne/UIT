
#include <Timer.h>
#include "BlinkToRadio.h"

module LightNodeC
{
  uses interface Boot;

  uses interface Timer<TMilli> as Timer0;
  uses interface Packet;
  uses interface AMPacket;
  uses interface AMSend;
  uses interface Read<uint16_t> as LightRead;
  uses interface SplitControl as AMControl;
}
implementation
{
  message_t pkt;
  bool busy = FALSE;
  uint16_t lux;
  
  event void Boot.booted()
  {
    call AMControl.start();
  }

  event void AMControl.startDone(error_t err)
  {
    if (err == SUCCESS)
    {
      call Timer0.startPeriodic(TIMER_PERIOD_MILLI);
    }
    else
    {
      call AMControl.start();
    }
  }

  event void AMControl.stopDone(error_t err)
  {
  }

  event void Timer0.fired()
  {
    if (!busy)
    {
      call LightRead.read();
    }
  }

  event void LightRead.readDone(error_t result, uint16_t val)
  {
    SenseToRadioMsg *btrpkt;
    if (result == SUCCESS && !busy)
    {
      lux = 2.5 * (val / 4096.0) * 6250.0;

      btrpkt =
          (SenseToRadioMsg *)(call Packet.getPayload(&pkt, sizeof(SenseToRadioMsg)));
      if (btrpkt != NULL)
      {
        btrpkt->nodeid = TOS_NODE_ID;
        btrpkt->value = lux;
        if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof(SenseToRadioMsg)) == SUCCESS)
        {
          busy = TRUE;
        }
      }
    }
  }

  event void AMSend.sendDone(message_t * msg, error_t err)
  {
    if (&pkt == msg)
    {
      busy = FALSE;
    }
  }
}
