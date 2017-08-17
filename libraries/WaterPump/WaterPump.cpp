#include "WaterPump.h"


WaterPump::WaterPump(char pinNum, int _interval) {
    interval = _interval;
    pinNumber = pinNum;
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinState = false;
    stopTime = 0;
}

void WaterPump::on() {
    digitalWrite(pinNumber, HIGH);
    pinState = true;
}

void WaterPump::off() {
    digitalWrite(pinNumber, LOW);
    pinState = false;
}

void WaterPump::changeInterval(int newInterval) {
    interval = newInterval;
}

void WaterPump::strobe() {
    if (stopTime <= millis()) {
        if(pinState) this->off();
        else this->on();
        stopTime = millis() + interval;
    }
}
