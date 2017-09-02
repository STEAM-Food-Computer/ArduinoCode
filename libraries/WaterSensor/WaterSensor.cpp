#include "WaterSensor.h"

WaterSensor::WaterSensor(char digPinNum, char anPinNum) {
    digitalPinNumber = digPinNum;
    analogPinNumber = anPinNum;
    pinState = false;
}

void WaterSensor::on() {
    digitalWrite(digitalPinNumber, HIGH);
    pinState = true;
}

void WaterSensor::off() {
    digitalWrite(digitalPinNumber, LOW);
    pinState = false;
}
short WaterSensor::poll() {

    if(!pinState) { //turn on the pin to start the reading process
        this->on();
        stopTime = millis() + stabilizingInterval;
        return -1; //if a negative is returned, then the sensor is not ready to be read from
    }

    else {
        if(millis() > stopTime) {   //if the minimum stabilizing time has passed, then do the reading
            lastRawReading = (short)analogRead(analogPinNumber);
            this->off();
            return readValue;
        }
        else return -1;
    }

}

short WaterSensor::getLastRawReading() {return lastRawReading;}