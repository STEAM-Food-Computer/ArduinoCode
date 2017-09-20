#include<WateringApparatus.h>

static bool WateringApparatus::isReading = false;
static char WateringApparatus::numOfSensors = 0;
static short WateringApparatus::allSensorAverage = 0;
static float WateringApparatus::desiredMoisture = 7.5;
static float WateringApparatus::currentMoisture = 0;
static WaterSensor** WateringApparatus::sensorList = NULL;
static WaterPump* WateringApparatus::waterPump = NULL;
static bool* WateringApparatus::sensorValueReturn = NULL;
static short* WateringApparatus::sensorValues = NULL;



static void WateringApparatus::addWaterPump(WaterPump& wPump) {
    Serial.println("Adding water pump" );
    waterPump = &wPump;
}

static void WateringApparatus::addSensor(WaterSensor& wSensor) {
    WaterSensor **temp = new WaterSensor*[++numOfSensors];
    for (char i = 0; i < numOfSensors - 1; i++) {
        temp[i] = sensorList[i];
        }
    temp[numOfSensors-1] = &wSensor;
    delete[] sensorList;
    sensorList = temp;
    Serial.println("Adding sensor" );
    
}

static short WateringApparatus::getAllSensorAverage() {
    return allSensorAverage;
}

static bool WateringApparatus::checkIfSensorValuesReturned() {

    for (char i = 0; i < numOfSensors; i++) {
        if(sensorValueReturn[i]);
        else
            return false;
    }

    return true;

}

static void WateringApparatus::pollSensors() {

    for(char i = 0; i < numOfSensors; i++) {
    if(!sensorValueReturn[i]) {
        short temp = sensorList[i]->poll();
            if(temp > 0){
                sensorValues[i] = temp;
                sensorValueReturn[i] = true;
            }
            else
                sensorValueReturn[i] = false;  
        }
        }
    

}

static void WateringApparatus::readAllSensors() {

    if(!isReading) {
        isReading = true;
        sensorValueReturn = new bool[numOfSensors];
        for(char i = 0; i < numOfSensors; i++)
            sensorValueReturn[i] = false;
        sensorValues = new short[numOfSensors];
        pollSensors();
    }

    else {

        if(checkIfSensorValuesReturned()) {
            float temp = 0;
            for(char i = 0; i < numOfSensors; i++) {
                temp += (float)sensorValues[i];
            }

            Serial.print("Sensor 1: "); Serial.println(sensorValues[0]);
            Serial.print("Sensor 2: "); Serial.println(sensorValues[1]);
            temp /= numOfSensors;
            allSensorAverage = (short)temp;
            isReading = false;
            delete[] sensorValueReturn;
            delete[] sensorValues;
            sensorValueReturn = NULL;
            sensorValues = NULL;
        }

            else
                pollSensors();

    }

}

static float WateringApparatus::controlModelOutput(short input) {

    if (input > 523.1)
        return (-1)*(0.0000001194243)*input*input*input + 0.0002552256*input*input - 0.18673343*input + 52.05055;

    else
        return 0.0001083993*input*input - 0.1053092*input + 32.54123;
}

static void WateringApparatus::pump() {

static bool isInInterval = true;
static long timePassed = 9223372036854775807;
static long timeToTurnOffPump = 9223372036854775807;

    if(isInInterval) {
    readAllSensors();
    //Serial.println("reading the sensors");
    if(allSensorAverage != 0 && sensorValues == NULL) {
        Serial.print("first sensor value: "); Serial.println(allSensorAverage);
        currentMoisture = controlModelOutput(allSensorAverage);
        if(!(currentMoisture < desiredMoisture))
            waterPump->on();
        isInInterval = false;
        timePassed = millis() + pollingInterval - 20000;
        timeToTurnOffPump = millis() + 3000;
    }
    }

    if(timePassed < millis())
        isInInterval = true;
    if(timeToTurnOffPump < millis())
        waterPump->off();

}