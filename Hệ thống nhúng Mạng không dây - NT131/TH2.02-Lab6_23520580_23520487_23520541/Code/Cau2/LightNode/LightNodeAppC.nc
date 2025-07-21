
#include <Timer.h>
#include "BlinkToRadio.h"

configuration LightNodeAppC {
}
implementation {
  components MainC;

  components LightNodeC as App;
  components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components new AMSenderC(AM_BLINKTORADIO);
  components new HamamatsuS10871TsrC() as LightSensor;

  App.Boot -> MainC;
  App.Timer0 -> Timer0;
  App.Packet -> AMSenderC;
  App.AMPacket -> AMSenderC;
  App.AMControl -> ActiveMessageC;
  App.AMSend -> AMSenderC;
  App.LightRead->LightSensor;
}
