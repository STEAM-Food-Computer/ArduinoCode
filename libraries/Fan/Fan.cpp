#include <Fan.h>

Fan::Fan(char pinNum, int _interval) {
    interval = _interval;
    pinNumber = pinNum;
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
    pinState = false;
    stopTime = 0;
}

void Fan::on() {
    digitalWrite(pinNumber, HIGH);
    pinState = true;
}

void Fan::off() {
    digitalWrite(pinNumber, LOW);
    pinState = false;
}

void Fan::changeInterval(int newInterval) {
    interval = newInterval;
}

void Fan::strobe() {
    if (stopTime <= millis()) {
        if(pinState) this->off();
        else this->on();
        stopTime = millis() + interval;
    }
}
