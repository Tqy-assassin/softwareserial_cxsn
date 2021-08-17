#ifndef __SWSERIAL_H__
#define __SWSERIAL_H__
#include "pxt.h"

enum SerialPortNo {
    //% block="port1"
    port1 = 0,
    //% block="port2"
    port2 = 1,
    //% block="port3"
    port3 = 2,
    //% block="port4"
    port4 = 3,
    //% block="port5"
    port5 = 4,
    //% block="port6"
    port6 = 5
}

enum SerialMode {
    //% block="unused"
    _unused = 0,
    //% block="readonly"
    _readonly = 1,
    //% block="writeonly"
    _writeonly = 2,
    //% block="readwrite"
    _readwrite = 3
}
class SWserial
{
public:
    SWserial(uint8_t rx, uint8_t tx, SerialMode mode);
    void setMode(SerialMode mode);
    void begin(int baud);
    void setBaud(int baud);
    ~SWserial();
    void write(char *dates);
    char read();

  private:
    void reading_serial();
    void writing_serial(unsigned char dt);
    void start_rx_thread();
    int tx;
    int rx;
    int baud = 9600;
    int delay_us = 100;
    unsigned char recvData;
    unsigned char recvBuf;

    bool avaiable = false;
    bool isreading = false;
    bool iswriting = false;
    int recvLen = 0;    
    SerialMode mode = _readwrite;
};



#endif