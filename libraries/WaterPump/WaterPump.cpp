#include "WaterPump.h"


WaterPump::WaterPump(char pinNum, int _interval) : pinNumber(pinNum){
    interval = _interval;
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinState = false;
    stopTime = 0;
}

void WaterPump::on() {
    digitalWrite(pinNumber, HIGH);
    pinState = true;
    Serial.println("WaterPump turning on." );
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
