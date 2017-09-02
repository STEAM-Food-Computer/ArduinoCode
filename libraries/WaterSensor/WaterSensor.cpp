#include "WaterSensor.h"

WaterSensor::WaterSensor(char digPinNum, char anPinNum) {
    digitalPinNumber = digPinNum;
    analogPinNumber = anPinNum;
}

void WaterSensor::on() {
    digitalWrite(digitalPinNumber, HIGH)
    pinState = true;
}

void WaterSensor::off() {
    digitalWrite(digitalPinNumber, LOW)
    pinState = false;
}
short WaterSensor::poll() {

    if(!pinState) {
        this->on();
        stopTime = millis() + stabilizingInterval;
        return -1; //if a negative is returned, then the sensor is not ready to be read from
    }

    else {
        if(millis() > stopTime) {
            short readValue = (short)analogRead(analogPinNumber);
            this->off();
            return readValue;
        }
        else return -1;
    }

}