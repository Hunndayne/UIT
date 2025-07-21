
#include <Timer.h>
#include "BlinkToRadio.h"

configuration LightTempStationAppC
{
}
implementation
{
  components MainC;
  components LightTempStationC as App;
  // components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components new AMReceiverC(AM_BLINKTORADIO);
  components SerialPrintfC;
  components SerialStartC; 

  App.Boot->MainC;
  // App.Timer0 -> Timer0;
  // App.Packet -> AMSenderC;
  App.AMControl->ActiveMessageC;
  App.Receive->AMReceiverC;
}
