#include<WateringApparatus.h>

static void WateringApparatus::addWaterPump(&WaterPump wPump) {
    waterPump = &wPump;
}

static void WateringApparatus::addSensor(WaterSensor& wSensor) {
    sensorList.push_back(&wSensor);
}

static short WateringApparatus::getAllSensorAverate() {
    return allSensorAverage;
}

static bool WateringApparatus::checkIfSensorValuesReturned() {

    for (char i = 0; i < sensorValueReturn->size(); i++) {
        if(sensorValueReturn[i]);
        else
            return false;
    }

    return true;

}

static void WateringApparatus::pollSensors() {

    for(std::list<WaterSensor>::iterator it = sensorList.begin(), char i = 0; it != sensorList.end(); ++it, i++) {    //don't know if this is how you do a double initialzation in a for loop
        short temp = it->poll();
            if(temp > 0){
                sensorValues[i] = temp;
                sensorValueReturn[i] = true;
            }
            else
                sensorValueReturn[i] = false;  
        }
    

}

static void WateringApparatus::readAllSensors() {

    if(!isReading) {
        isReading = true;
        sensorValueReturn = new bool[sensorList.size()];
        sensorValues = new short[sensorList.size()];
        pollSensors();
    }

    else {

        if(checkIfSensorValuesReturned()) {
            float temp = 0;
            for(char i = 0; i < sensorValues.size(); i++) {
                temp += (float)sensorValues[i];
            }

            temp /= sensorValues.size();
            allSensorAverage = (short)temp;
            isReading = false;
            delete[] sensorValueReturn;
            delete[] sensorValues;
        }

            else
                pollSensors();

    }

}