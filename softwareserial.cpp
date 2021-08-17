#include "pxt.h"
#include "core/SWserial.h"

//% color="#ff6600" weight=130 icon="\uf110"
namespace softwareserial{
    SWserial *serial[6] = {nullptr};

    const int Pins_id = {
        [uBit.EventBusSource.MICROBIT_ID_IO_P0, uBit.EventBusSource.MICROBIT_ID_IO_P3, uBit.EventBusSource.MICROBIT_ID_IO_P4],
        [uBit.EventBusSource.MICROBIT_ID_IO_P1, uBit.EventBusSource.MICROBIT_ID_IO_P5, uBit.EventBusSource.MICROBIT_ID_IO_P6],
        [uBit.EventBusSource.MICROBIT_ID_IO_P2, uBit.EventBusSource.MICROBIT_ID_IO_P7, uBit.EventBusSource.MICROBIT_ID_IO_P8],
        [uBit.EventBusSource.MICROBIT_ID_IO_P9, uBit.EventBusSource.MICROBIT_ID_IO_P10, uBit.EventBusSource.MICROBIT_ID_IO_P11],
        [uBit.EventBusSource.MICROBIT_ID_IO_P13, uBit.EventBusSource.MICROBIT_ID_IO_P14, uBit.EventBusSource.MICROBIT_ID_IO_P15],
        [uBit.EventBusSource.MICROBIT_ID_IO_P16, uBit.EventBusSource.MICROBIT_ID_IO_P19, uBit.EventBusSource.MICROBIT_ID_IO_P20]};

    /**
     * Initialize MU.
     */
    //% blockId=serial_set block="set serial %port| with %mode"
    //% group="Settings"
    void pin_set(SerialPortNo port, SerialMode mode){
        if(serial[port] == nullptr){
            serial[port] = new SWserial(Pins_id[port][0], Pins_id[port][2], mode);
        }else{
            serial[port].setMode(mode);
        }
    }

    /**
     * Start serial.
     */
    //% block="start %port as serial with baudrate %baud"
    //% group="Functions"
    void begin(SerialPortNo port, int baud){
        if(serial[port] == nullptr){
            serial[port].begin(baud);
        }
    }

    /**
     * Write message by serial.
     */
    //% block="serial %port write %values"
    //% group="Functions"
    void write(SerialPortNo port, uint8[] values){
        if(serial[port] == nullptr){
            serial[port].write(values);
        }
    }

    /**
     * Read message from serial.
     */
    //% block="serial %port read"
    //% group="Functions"
    uint8 read(SerialPortNo port){
        uint8_t ret = 0;
        if(serial[port] == nullptr){
            ret = serial[port].read();
        }
        return ret;
    }
}

