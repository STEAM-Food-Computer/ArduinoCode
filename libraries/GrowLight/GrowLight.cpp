#include "GrowLight.h"


GrowLight::GrowLight( int pinNum, int _interval) {
    interval = _interval;
    pinNumber = pinNum;
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinState = false;
    stopTime = 0;
}

void GrowLight::on() {
    digitalWrite(pinNumber, HIGH);
    pinState = true;
}

void GrowLight::off() {
    digitalWrite(pinNumber, LOW);
    pinState = false;
}

void GrowLight::changeInterval(int newInterval) {
    interval = newInterval;
}

void GrowLight::strobe() {
    if (stopTime <= millis()) {
        if(pinState) this->off();
        else this->on();
        stopTime = millis() + interval;
    }
}
