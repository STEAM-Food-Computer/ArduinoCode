#ifndef WateringApparatus_h
#define WateringApparatus_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#include <iostream>
#include <list>
#include <WaterSensor.h>
#endif

class WateringApparatus {

std::list<WaterSensor*> SensorList;

private:
    WateringApparatus();

};
