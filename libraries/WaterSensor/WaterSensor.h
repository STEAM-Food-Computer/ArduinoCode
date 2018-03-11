#ifndef WaterSensor_h
#define WaterSensor_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

class WaterSensor {

    const char digitalPinNumber;  //keeps track of the Vcc pin connected to the particular sensor
    const char analogPinNumber;   //keeps track of the pin the sensor is read from
    short lastRawReading;
    const short stabilizingInterval = 20000;    //time it takes for sensor reading to stabilize
    bool pinState;  //keep track of if the pin is high or low
    long stopTime;

    public:
        WaterSensor(char digPinNum, char anPinNum);
        short poll();   //initiate the process of reading the sensor
        short getLastRawReading();
    private:
        void on();  //Vcc is on
        void off(); //Vcc is off

};
#endif
/*
    Turning on and off the Vcc to read the sensor reduces corrosion on the sensor
*/
