#ifndef __SWSERIAL_H__
#define __SWSERIAL_H__
#include "pxt.h"

class SWserial
{
public:
    enum SerialPortNo {
        port1 = 0,
        port2 = 1,
        port3 = 2,
        port4 = 3,
        port5 = 4,
        port6 = 5
    }
    enum SerialMode {
        _unused = 0,
        _readonly = 1,
        _writeonly = 2,
        _readwrite = 3
    }
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