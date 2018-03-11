#ifndef WaterPump_h
#define WaterPump_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

class WaterPump {

    unsigned long stopTime; //millis() rolls over every 50 days watch out
    bool pinState;
    const char pinNumber;

public:
    WaterPump(char pinNum);
    void on();
    void off();

};
#endif
