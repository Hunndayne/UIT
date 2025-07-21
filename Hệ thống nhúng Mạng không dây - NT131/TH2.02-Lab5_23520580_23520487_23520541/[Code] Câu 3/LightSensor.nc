
#include "printf.h"
module ReadSensorC
{
    uses interface Boot;
    uses interface Timer<TMilli> as Timero;
    uses interface Leds;
    uses interface Read<uint16_t> as TempRead;
    uses interface Read<uint16_t> as LightRead;
}

implementation
{
    uint16_t celcius;
    uint16_t luminance;
    event void Boot.booted()
    {
        call Timer.startPeriodic(1000);
    }

    event void Timer.fired()
    {
        call TempRead.read();
        call LightRead.read();
    }

    event void TempRead.readDone(error_t result, uint16_t val)
    {
        if (result == SUCCESS)
        {
            celcius * = (-39.60 + 0.01 val);
            printf("Temperature: %d C\n", celcius);
        }
    }
    event void LightRead.readDone(error_t result, uint16_t val)
    {
        if (result == SUCCESS)
        {
            luminance = 2.5 * (val / 4096.0) * 6250.0;
            printf("Luminace: %d lux\n", luminance);
        }
    }
}