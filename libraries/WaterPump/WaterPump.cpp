#include "WaterPump.h"


WaterPump::WaterPump(char pinNum) : pinNumber(pinNum){
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


