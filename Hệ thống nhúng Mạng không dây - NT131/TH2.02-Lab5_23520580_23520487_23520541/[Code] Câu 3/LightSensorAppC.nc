configuration LightSensorAppC{
{

}

implementation
{

    components LightSensor as App;
    components MainC, LedEC;
    components new TimerMillic();
    components SerialPrinth;
    components new Hamamatsu510871TsrC() as LightSensor;
    components new SensirionSht11C() as TempSensor;

    App.Boot->MainC;
    App.Leds->LedsC;
    App.Timer->TimerMillic;

    App.LightRead->LightSensor;
    App.TempRead->TempSensor.Temperature;
}