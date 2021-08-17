#include "SWserial.h"

SWserial::SWserial(uint8_t rx, uint8_t tx, SerialMode mode = _readwrite){
    this->tx = tx;
    this->rx = rx;
    this->mode = mode;
}

void SWserial::setMode(SerialMode mode){
    this->mode = mode;
}

void SWserial::begin(int baud){
    this->baud = baud;
    this->delay_us = 1000000 / baud;
}

void SWserial::setBaud(int baud = 9600){
    this->baud = baud;
    this->delay_us = 1000000 / baud;
    start_rx_thread();
}

SWserial::~SWserial(){}

void SWserial::reading_serial()
{
    if (uBit.pins.digitalReadPin(DigitalPin.P0) == 0) {
        isreading = true;
        sleep_us(delay_us);
        recvData = 0;
        for (int i = 0; i < 8;i++){
            if(uBit.pins.digitalReadPin(DigitalPin.P0) == 1){
                recvData |= (1 << i);
            }else{
                recvData &= ~(1 << i);
            }
        }
        recvBuf = recvData;
        isreading = false;
    }
}

void SWserial::writing_serial(unsigned char Data)
{
	u8 i = 0;
	uBit.pins.digitalWritePin((DigitalPin)tx, 1);  
	sleep_us(delay_us);
	for(i = 0; i < 8; i++)
	{
		if(Data&0x01)
			uBit.pins.digitalWritePin((DigitalPin)tx, 1);  
		else
			uBit.pins.digitalWritePin((DigitalPin)tx, 0); 
		
		sleep_us(delay_us);
		Data = Data>>1;
	}
	uBit.pins.digitalWritePin((DigitalPin)tx, 1);  
	sleep_us(delay_us);
}

void SWserial::write(char *dates)
{
	while(*dates != 0)
	{
		writing_serial((unsigned char)(*dates));
        dates++;
    }
}

char SWserial::read()
{
    char ret = 0;
    if(isreading){
        while(isreading);
        ret = (char)recvBuf;
        recvBuf = 0;
    }else{
       ret = (char)recvBuf;
       recvBuf = 0;
    }
    return ret;
}

void SWserial::start_rx_thread()
{
    if(mode | _readonly != 0){
        uBit.control.in_background(reading_serial)
    }
}



