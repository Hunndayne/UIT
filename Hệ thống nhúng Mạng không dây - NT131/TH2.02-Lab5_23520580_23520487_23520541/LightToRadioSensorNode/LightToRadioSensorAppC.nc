#include <Timer.h>
#include "BlinkToRadio.h"

configuration LightToRadioSensorAppC {
}
implementation {
  components MainC;
  components LedsC;
  components LightToRadioSensorC as App;
  components new TimerMilliC() as Timer0;
  components ActiveMessageC;
  components new AMSenderC(AM_BLINKTORADIO);
  components new HamamatsuS10871TsrC() as LightSensor; 
  components new SerialPrintfC;
  
  App.Boot -> MainC;
  App.Leds -> LedsC;
  App.Timer0 -> Timer0;
  App.Packet -> AMSenderC;
  App.AMPacket -> AMSenderC;
  App.AMControl -> ActiveMessageC;
  App.AMSend -> AMSenderC;
  App.Receive -> AMReceiverC;
  App.LightRead -> LightSensor;
}
