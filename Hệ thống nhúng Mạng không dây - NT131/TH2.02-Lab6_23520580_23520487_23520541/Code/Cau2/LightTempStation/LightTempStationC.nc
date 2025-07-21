

#include <Timer.h>
#include "BlinkToRadio.h"
#include "stdio.h"
#include "string.h"
#include "printf.h"

module LightTempStationC
{
  uses interface Boot;
  // uses interface Timer<TMilli> as Timer0;
  uses interface Packet;
  uses interface AMPacket;
  uses interface Receive;
  uses interface SplitControl as AMControl;
}
implementation
{

  event void Boot.booted()
  {
    call AMControl.start();
  }

  event void AMControl.startDone(error_t err)
  {
    if (err == SUCCESS)
    {
      printf("Light Station ready to receive data...\r\n");
      printfflush();
    }
    else
    {
      call AMControl.start();
    }
  }

  event void AMControl.stopDone(error_t err)
  {
  }
  event message_t *Receive.receive(message_t * msg, void *payload, uint8_t len)
  {
    if (len == sizeof(SenseToRadioMsg))
    {
      SenseToRadioMsg *datapkt = (SenseToRadioMsg *)payload;
      if (datapkt->nodeid==2000)
      {
        printf("Luminace: %d lx from %d\r\n", datapkt->value, datapkt->nodeid);
        printfflush();
      } else if(datapkt->nodeid==3000){
        printf("Temperature: %d C from %d\r\n", datapkt->value, datapkt->nodeid);
        printfflush();
      }
    }
    return msg;
  }
}
