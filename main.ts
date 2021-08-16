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


namespace serial{
    //% block="set serial %pin, with %mode"
    export function pin_set(pin: SerialPortNo, mode: SerialMode): void{
        
    }
    //% block="start begin with baudrate %baud"
    export function begin(baud: Number): void{
        control.onEvent(EventBusSource.MICROBIT_ID_BUTTON_A, EventBusValue.MICROBIT_EVT_ANY, function on_microbit_id_button_a_evt() {
            
        })
    }

    export function write(values: number[]): void{

    }
}