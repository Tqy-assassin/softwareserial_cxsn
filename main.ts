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
    _readonly = 1 << 0,
    //% block="writeonly"
    _writeonly = 1 << 1,
    //% block="readwrite"
    _readwrite = _readonly | _writeonly
}

//% color="#ff6600" weight=103 icon="\uf085"
namespace serial{
    let Pins = [ 
        [EventBusSource.MICROBIT_ID_IO_P0, EventBusSource.MICROBIT_ID_IO_P3, EventBusSource.MICROBIT_ID_IO_P4],
        [EventBusSource.MICROBIT_ID_IO_P1, EventBusSource.MICROBIT_ID_IO_P5, EventBusSource.MICROBIT_ID_IO_P6],
        [EventBusSource.MICROBIT_ID_IO_P2, EventBusSource.MICROBIT_ID_IO_P7, EventBusSource.MICROBIT_ID_IO_P8],
        [EventBusSource.MICROBIT_ID_IO_P9, EventBusSource.MICROBIT_ID_IO_P10, EventBusSource.MICROBIT_ID_IO_P11],
        [EventBusSource.MICROBIT_ID_IO_P13, EventBusSource.MICROBIT_ID_IO_P14, EventBusSource.MICROBIT_ID_IO_P15],
        [EventBusSource.MICROBIT_ID_IO_P16, EventBusSource.MICROBIT_ID_IO_P19, EventBusSource.MICROBIT_ID_IO_P20]];
    let baud = 9600;

    //% block="set serial %port with %mode"
    export function pin_set(port: SerialPortNo, mode: SerialMode): void{
        
    }

    //% block="start %port as serial with baudrate %baud"
    export function begin(port: SerialPortNo, baud: Number): void{
        
        control.onEvent(Pins[port][0], EventBusValue.MICROBIT_PIN_EVT_RISE, function () {

        })
    }
    //% block="serial %port write %values"
    export function write(port: SerialPortNo, values: number[]): void{

    }
}