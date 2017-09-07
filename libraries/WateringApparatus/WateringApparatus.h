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
#include <WaterPump.h>
#endif

class WateringApparatus {

static std::list<WaterSensor*> sensorList;  //stores all the connected sensors
static WaterPump *waterPump; //reference to the water pump variable
static short allSensorAverage;
const static int pollingInterval = 60000; //how often to read data from the sensors, in future, make this modifiable
static bool isReading = false;
static bool *sensorValueReturn;
static short *sensorValues;

private:
    WateringApparatus();
    static bool checkIfSensorValuesReturned();  //checks to see if all sensors have returned
    static void pollSensors();  //gives sensor data when available to the sensorValue array
    static void readAllSensors();  //reads the values from the sensors at a regular interval

public:
    static void addSensor(WaterSensor& wSensor);
    static void addWaterPump(WaterPump& wPump);
    static short getAllSensorAverage();



};
