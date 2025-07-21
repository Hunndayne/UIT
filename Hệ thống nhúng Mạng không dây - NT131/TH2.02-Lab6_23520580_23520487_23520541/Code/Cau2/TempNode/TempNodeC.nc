
#include <Timer.h>
#include "BlinkToRadio.h"

module TempNodeC
{
  uses interface Boot;

  uses interface Timer<TMilli> as Timer0;
  uses interface Packet;
  uses interface AMPacket;
  uses interface AMSend;
  uses interface Read<uint16_t> as TempRead;
  uses interface SplitControl as AMControl;
}
implementation
{
  message_t pkt;
  bool busy = FALSE;
  uint16_t temperature;
  
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
      call TempRead.read();
    }
  }

  event void TempRead.readDone(error_t result, uint16_t temp)
  {
    SenseToRadioMsg *btrpkt;
    if (result == SUCCESS && !busy)
    {
      temperature = (-39.60 + 0.01 * temp);

      btrpkt =
          (SenseToRadioMsg *)(call Packet.getPayload(&pkt, sizeof(SenseToRadioMsg)));
      if (btrpkt != NULL)
      {
        btrpkt->nodeid = TOS_NODE_ID;
        btrpkt->temp = temperature;
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
