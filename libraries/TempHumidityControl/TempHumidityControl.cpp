#include <TempHumidityControl.h>

static double TempHumidityControl::desiredTemp = 18;
static double TempHumidityControl::desiredHumidity = 50;
static double TempHumidityControl::measuredTempAverage = 0;
static double TempHumidityControl::measuredHumidityAverage = 0;
static long TempHumidityControl::pollingTime = millis() + 2000;
static HumidThermoSensor** TempHumidityControl::sensorList = NULL;
static Fan** TempHumidityControl::fanList = NULL;
static char TempHumidityControl::numOfSensors = 0;
static char TempHumidityControl::numOfFans = 0;


static void TempHumidityControl::addSensor(HumidThermoSensor& sensor) {
    HumidThermoSensor **temp = new HumidThermoSensor*[++numOfSensors];
    for (char i = 0; i < numOfSensors - 1; i++) {
        temp[i] = sensorList[i];
        }
    temp[numOfSensors-1] = &sensor;
    delete[] sensorList;
    sensorList = temp;
    Serial.println("Adding TempHumid sensor" );
}

static void TempHumidityControl::addFan(Fan& fan) {
    Fan **temp = new Fan*[++numOfFans];
    for (char i = 0; i < numOfFans - 1; i++) {
        temp[i] = fanList[i];
        }
    temp[numOfFans-1] = &fan;
    delete[] fanList;
    fanList = temp;
    Serial.println("Adding Fan" );
}


static void TempHumidityControl::updateSensorValues() {
    double temp = 0;
    double hum = 0;
    for(char i = 0; i < numOfSensors; i++) {
        sensorList[i]->updateSensorValues();
        temp += sensorList[i]->getTemperature();
        hum += sensorList[i]->getHumidity();
    }
    measuredTempAverage = temp/numOfSensors;
    measuredHumidityAverage = hum/numOfSensors;
}

static void TempHumidityControl::setDesiredTemp(double temp) {
    if(temp < 0 || temp > 50)
        ;
    else
        desiredTemp = temp;
}

static void TempHumidityControl::setDesiredHumidity(double humidity) {
    if(humidity < 20 || humidity > 90)
        ;
    else
        desiredHumidity = humidity;
}

static void TempHumidityControl::regulate() {
    if(pollingTime < millis()) {
        updateSensorValues();
        if(measuredTempAverage > desiredTemp) {
            for(char i = 0; i < numOfFans; i++)
                fanList[i]->on();
        }
        else {
            for(char i = 0; i < numOfFans; i++)
                fanList[i]->off();
        }
        pollingTime = millis() + 2000;
    }
}
