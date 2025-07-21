
#include <Timer.h>
#include "BlinkToRadio.h"

configuration TempNodeAppC {
}
implementation {
  components MainC;

  components TempNodeC as App;
  components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components new AMSenderC(AM_BLINKTORADIO);
  components new SensirionSht11C() as TempSensor;

  App.Boot -> MainC;
  App.Timer0 -> Timer0;
  App.Packet -> AMSenderC;
  App.AMPacket -> AMSenderC;
  App.AMControl -> ActiveMessageC;
  App.AMSend -> AMSenderC;
  App.TempRead->TempSensor.Temperature;
}
