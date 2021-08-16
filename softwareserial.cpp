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

enum SerialMode{
    //% block="unused"
    _unused = 0,
    //% block="readonly"
    _readonly = 1,
    //% block="writeonly"
    _writeonly = 2,
    //% block="readwrite"
    _readwrite = 3
}


int Pins_id = {
    [uBit.EventBusSource.MICROBIT_ID_IO_P0, uBit.EventBusSource.MICROBIT_ID_IO_P3, uBit.EventBusSource.MICROBIT_ID_IO_P4],
    [uBit.EventBusSource.MICROBIT_ID_IO_P1, uBit.EventBusSource.MICROBIT_ID_IO_P5, uBit.EventBusSource.MICROBIT_ID_IO_P6],
    [uBit.EventBusSource.MICROBIT_ID_IO_P2, uBit.EventBusSource.MICROBIT_ID_IO_P7, uBit.EventBusSource.MICROBIT_ID_IO_P8],
    [uBit.EventBusSource.MICROBIT_ID_IO_P9, uBit.EventBusSource.MICROBIT_ID_IO_P10, uBit.EventBusSource.MICROBIT_ID_IO_P11],
    [uBit.EventBusSource.MICROBIT_ID_IO_P13, uBit.EventBusSource.MICROBIT_ID_IO_P14, uBit.EventBusSource.MICROBIT_ID_IO_P15],
    [uBit.EventBusSource.MICROBIT_ID_IO_P16, uBit.EventBusSource.MICROBIT_ID_IO_P19, uBit.EventBusSource.MICROBIT_ID_IO_P20]};

//% color="#ff6600" weight=50 icon="\uf085"
namespace softwareserial{
    //% block="set serial %port with %mode"
    void pin_set(SerialPortNo port, SerialMode mode){
        
    }

    //% block="start %port as serial with baudrate %baud"
    void begin(SerialPortNo port, int baud){
        uBit.control.onEvent(Pins_id[port][0], EventBusValue.MICROBIT_PIN_EVT_RISE, function () {

        })
    }
    //% block="serial %port write %values"
    void write(SerialPortNo port, char* values){

    }


}

