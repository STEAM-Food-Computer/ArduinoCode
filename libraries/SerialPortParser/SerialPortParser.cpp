#include <SerialPortParser.h>
short SerialPortParser::start = 0xffff;
short SerialPortParser::end = 0x0000;
SerialPortParser::SerialPortParser(char serial_in, char serial_out) : serialIn(serial_in), serialOut(serial_out) {
    Serial.begin();
    pinMode(serialIn, INPUT);
    pinMode(serialOut, OUTPUT);
}

void SerialPortParser::send(byte[] data) {
    byte *b = new byte[sizeof(data) + 7]; //going according to the google doc, need an extra 7 byte for other info
    byte[0] = (start & 0x00ff);
    byte[1] = (start & 0xff00) >> 8;

    for(int i = 0; i < size of data; i++) {
        b[i + 2] = data[i];
    }

    b[sizeof(b) - 3] = (end & 0x00ff);
    b[sizeof(b) - 2] = (end & 0xff00);

    for(int i = 0; i < sizeof(b); i++) {
        Serial.write(b[i]);
    }

    delete[] b;
    b = NULL;
}