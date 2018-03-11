#ifndef TempHumidityControl_h
#define TempHumidityControl_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#include <HumidThermoSensor.h>
#include <Fan.h>

class TempHumidityControl {
    
    static double desiredTemp;
    static double desiredHumidity;
    static double measuredTempAverage;
    static double measuredHumidityAverage;
    static long pollingTime;
    static HumidThermoSensor** sensorList;
    static Fan** fanList;
    static char numOfSensors;
    static char numOfFans;

public:
    TempHumidityControl();
    static void addSensor(HumidThermoSensor& sensor);
    static void addFan(Fan& fan);
    static void updateSensorValues(); //gets updated values from the temp/humidity sensors (do not poll more than once every two seconds)
    static void setDesiredTemp(double temp);
    static void setDesiredHumidity(double humidity);
    static double getTempAverage();
    static double getHumidityAverage();
    static void regulate();

    
};

#endif
