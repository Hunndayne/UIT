#include <stdio.h>
#include <string.h>
#include <printf.h>
module ChaseLEDC
{
    uses interface Boot;
    uses interface Timer<TMilli> as Timer0;
    uses interface Leds;
}

implementation
{
    uint8_t current = 0;

    event void Boot.booted()
    {
        call Timer0.startPeriodic(500); // chu kỳ là 500ms
    }
    event void Timer0.fired()
    {
        // Tât tất ca LED
        call Leds.set(0);

        // Bật LED tương Ứng
        if (current == 0)
        {
            printf("LED 0 ON\r\n");
            call Leds.ledoon();
        }
        else if (current == 1)
        {
            printf("LED 1 ON\r\n");
            call Leds.led10n();
        }
        else if (current == 2)
        {

            printf("LED 2 ON\r\n");
            call Leds.led20n();
        }
        current = (current + 1) % 3; // Lặp lại từ LED 0 đến 2
    }
}