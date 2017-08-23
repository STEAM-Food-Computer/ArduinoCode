#ifndef Fan_h
#define Fan_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif /* Fan_h */

class Fan {
    
    int interval;
    unsigned long stopTime; //millis() rolls over every 50 days watch out
    bool pinState;
    char pinNumber;
    
public:
    Fan(char pinNum, int _interval);
    void on();
    void off();
    void strobe();
    void changeInterval(int _interval);
    
};
#endif
