configuration ChaseLEDAppC{
{
}
implementation
{
    components MainC, ChaseLEDC as App;
    components new TimerMillic() as Timer0;
    components LedsC;
    components SerialPrintfc;

    App->MainC.Boot;
    App.Timer0->Timer0;
    App.Leds->LedsC;
}