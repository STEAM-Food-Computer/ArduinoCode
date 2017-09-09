#ifndef WateringApparatus_h
#define WateringApparatus_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif
#include <WaterSensor.h>
#include <WaterPump.h>

class WateringApparatus {

static WaterSensor **sensorList;  //stores all the connected sensors
static WaterPump *waterPump; //reference to the water pump variable
static short allSensorAverage;
const static int pollingInterval = 60000; //how often to read data from the sensors, in future, make this modifiable
static bool isReading;
static bool *sensorValueReturn;
static short *sensorValues;
static char numOfSensors;
static float desiredMoisture;
static float currentMoisture;
static float error;

private:
    WateringApparatus();
    static bool checkIfSensorValuesReturned();  //checks to see if all sensors have returned
    static void pollSensors();  //gives sensor data when available to the sensorValue array
    static void readAllSensors();  //reads the values from the sensors at a regular interval
    static float controlModelOutput(short input);

public:
    static void addSensor(WaterSensor& wSensor);
    static void addWaterPump(WaterPump& wPump);
    static short getAllSensorAverage();
    static void pump();



};

#endif
