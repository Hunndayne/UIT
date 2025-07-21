configuration LightSensorAppC{

{
}
implementation
{
    components LightSensor as App;
    components MainC, LedsC;
    components new TimerMillic();

    App.Boot->MainC;
    App.Leds->LedsC;
    App.Timer->TimerMilliC;

    components SerialPrintfC;

    components new HamamatsuS10871TsrC() as LightSensor;
    App.LightRead->LightSensor;
}