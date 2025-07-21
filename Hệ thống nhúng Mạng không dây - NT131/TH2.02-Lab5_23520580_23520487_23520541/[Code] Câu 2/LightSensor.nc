#include <string.h>
#include <stdio.h>

module LightSensor
{
    uses
    {
        interface Boot;
        interface Timer<TMilli>;
        interface Leds;
        interface Read<uint16_t> as LightRead;
    }
}
implementation
{
    uint16_t luminance;
    event void Boot.booted()
    {
        call Timer.startPeriodic(1000);
    }
    event void Timer.fired()
    {
        call LightRead.read();
    }

    event void LightRead.readDone(error_t result, uint16_t val)
    {
        if (result == SUCCESS)
        {
            luminance = 2.5 * (val / 4096.0) * 6250.0;
            printf("Luminace: %d lux\n", luminance);
        }
        if (luminance > 1000.0)
        {
            call Leds.led1Off();
            call Leds.led2Off();
            call Leds.led0On();
        }
        if (luminance >= 100.0 && luminance <= 1000.0)
        {
            call Leds.led0Off();
            call Leds.led2Off();
            call Leds.led1On();
        }

        if (luminance < 100.0)
        {
            call Leds.led0Off();
            call Leds.led1Off();
            call Leds.led2On();
        }
    }
}