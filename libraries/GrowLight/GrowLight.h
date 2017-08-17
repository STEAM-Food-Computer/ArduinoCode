
#ifndef GrowLight_h
#define GrowLight_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

class GrowLight
{
    int interval;
    unsigned long stopTime; //millis() rolls over every 50 days watch out
    bool pinState;
    int pinNumber;
    
public:
    GrowLight(int pinNum, int _interval);
    void on();
    void off();
    void strobe();
    void changeInterval(int _interval);
    
};

#endif
