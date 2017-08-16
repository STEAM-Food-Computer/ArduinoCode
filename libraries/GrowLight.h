
#ifndef GROWLIGHT_H
#define GROWLIGHT_H

#include "WConstants.h" //Core wiring API

class GrowLight
{
    int interval;
    unsigned long stopTime; //millis() rolls over every 50 days watch out
    bool pinState;
    const int pinNumber;
    
public:
    GrowLight(int pinNum, int _interval);
    void on();
    void off();
    void strobe();
    void changeInterval(int _interval);
    
};

#endif
