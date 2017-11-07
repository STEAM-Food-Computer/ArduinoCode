#include <Fan.h>

Fan::Fan(char pinNum) {
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

