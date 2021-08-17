// Auto-generated. Do not edit.



    //% color="#ff6600" weight=130 icon="\uf110"
declare namespace softwareserial {

    /**
     * Initialize MU.
     */
    //% blockId=serial_set block="set serial %port| with %mode"
    //% group="Settings" shim=softwareserial::pin_set
    function pin_set(port: SerialPortNo, mode: SerialMode): void;

    /**
     * Start serial.
     */
    //% block="start %port as serial with baudrate %baud"
    //% group="Functions" shim=softwareserial::begin
    function begin(port: SerialPortNo, baud: int32): void;

    /**
     * Write message by serial.
     */
    //% block="serial %port write %values"
    //% group="Functions" shim=softwareserial::write
    function write(port: SerialPortNo, values: uint8[]): void;

    /**
     * Read message from serial.
     */
    //% block="serial %port read"
    //% group="Functions" shim=softwareserial::read
    function read(port: SerialPortNo): uint8;
}

// Auto-generated. Do not edit. Really.
