enum SerialPortNo {
    //% block="端口1"
    port1 = 0,
    //% block="端口2"
    port2 = 1,
    //% block="端口3"
    port3 = 2,
    //% block="端口4"
    port4 = 3,
    //% block="端口5"
    port5 = 4,
    //% block="端口6"
    port6 = 5
}

enum SerialMode{
    _unused = 0,

    _readonly = 1 << 0,

    _writeonly = 1 << 1,

    _readwrite = _readonly | _writeonly
}


namespace serial{

    export function pin_set(pin: SerialPortNo, mode: SerialMode) {

    }

    export function begin(baud: Number){

    }
}