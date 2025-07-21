#include <Timer.h>
#include "BlinkToRadio.h"

typedef nx_struct SenseToRadioMsg {
  nx_uint16_t nodeid;
  nx_float value;
} SenseToRadioMsg;

module LightToRadioSensorC {
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;
  uses interface Packet;
  uses interface AMPacket;
  uses interface AMSend;
  uses interface Receive;
  uses interface SplitControl as AMControl;
  uses interface Read<uint16_t> as LightRead;
}
implementation {
  uint16_t value;
  message_t pkt;
  bool busy = FALSE;
  float lux;
  void setLeds(uint16_t val) {
    if (val & 0x01)
      call Leds.led0On();
    else 
      call Leds.led0Off();
    if (val & 0x02)
      call Leds.led1On();
    else
      call Leds.led1Off();
    if (val & 0x04)
      call Leds.led2On();
    else
      call Leds.led2Off();
  }

  event void Boot.booted() {
    call AMControl.start();
  }

  event void AMControl.startDone(error_t err) {
    if (err == SUCCESS) {
      call Timer0.startPeriodic(TIMER_PERIOD_MILLI);
    }
    else {
      call AMControl.start();
    }
  }

  event void AMControl.stopDone(error_t err) {
  }

  event void LightRead.readDone(error_t result, uint16_t val) {
    if (result == SUCCESS) {
      lux = 2.5 * (val / 4096.0) * 6250.0;
    }
  }

  event void Timer0.fired() { 
    if (!busy) { 
      SenseToRadioMsg* datapkt = (SenseToRadioMsg*)(call Packet.getPayload(&pkt, sizeof(SenseToRadioMsg))); 
      if (datapkt == NULL) { 
        return; 
      } 
      datapkt->nodeid = TOS_NODE_ID; 
      datapkt->value = lux; 
      if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof(SenseToRadioMsg)) == SUCCESS) { 
        busy = TRUE; 
      } 
    } 
  } 

  event void AMSend.sendDone(message_t* msg, error_t err) {
    if (&pkt == msg) {
      busy = FALSE;
    }
  }

  event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
    if (len == sizeof(BlinkToRadioMsg)) {
      BlinkToRadioMsg* btrpkt = (BlinkToRadioMsg*)payload;
      setLeds(btrpkt->value);
    }
    return msg;
  }
}
