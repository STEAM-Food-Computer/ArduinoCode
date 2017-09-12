#ifndef SerialPortParser_h
#define SerialPortParser_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

Class SerialPortParser {

const char serialIn;
const char serialOut;
const short start;
const short end;

public:
    SerialPortParser(char serial_in, char serial_out);
    void send(byte[] data);
    byte[] receive();


};
#endif