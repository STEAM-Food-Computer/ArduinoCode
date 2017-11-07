#ifndef HumidThermoSensor_h
#define HumidThermoSensor_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#include <dht.h>


class HumidThermoSensor {
    
    const char pinNumber;
    double temperature;
    double humidity;
    dht sensorModule;
    
public:
    HumidThermoSensor(char pinNum);
    void updateSensorValues(); //reads the sensor values from the device (can't run this faster than 0.5Hz)'
    double getTemperature();
    double getHumidity();
    
};

#endif
