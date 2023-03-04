<pre>
[Synaptic Neuronal Association Processor]
<b><big>
LANG   :   C
IDE    :   VS Studio Code 
Modul  :   PlattformIO
Devices:   <a target=dev href='https://store.arduino.cc/products/arduino-nano'>Arduino [Nano]</a>
           Mini D1 [ESP8266]
           RASP [PI2] Piko [WOT: possible, just  with <a target=dev href='https://github.com/earlephilhower/arduino-pico'>earlephilhower (@github)</a> image!!]
AVRs   :   <a target=avr href='https://www.microchip.com/en-us/product/ATmega328P'>ATmega328P</a>
           ESP8266
           §[UC]ESP32
           RP2040
Name   :   SNAP[_AT/_E82/_RB]
</b></big>

Arduino sorta BIOS to handle Sensor-data (here BMP280 / BME 280[180] )
                   to handle visual-out  (TFT/OLED/LCD44)
                   to handle serial-i/o  
                                    o    (see "Serial  Studio")/usb formated out sensordata
                                    i    commands and settings
                   to handle storage-i/o
                                    EProm[intern] EEProm[extern twi/i2c]
                   to handle PWM/PINS/Analoge 
                   to handle small APIs[0,1,2,3] with a set of methodes
                        [within "setup"]
                            .setup(ix)                 (on each chip reset, after std. setup)
                        [within "loop"]
                            .prepare(ix)               (prepare[set]/per loop)
                            .refresh(ix)               (refresh hardware if needed)
                            .task(ix)                  (one per 1sek; for regular data output) 
                            .loop(ix)                  (each "delay" [<<60mS])



1. Sensor  
  a.)  PWM(parallel)      [put] constant analog sensor-stream -> through external 3xConverter  for SPS-conform 0-10V(2-10V) signals
  b.)  ADC(Analog)        Analog/Digital + (Hard/Soft) Trigger[+-Hysterese+Timing]

2. Connex
  a.)  USB(serial)        [put] regular measured and csv formatted data
  b.)   -"-               [get],[parse] command to configure inner parameter  ("debug=[on,off]; Tpwm=[min,max]; OSsave;.. aso")
  c.)  SPI                primary used with TFT screen(§[US]touch-handles); (hotplugable built)
  d.)  I2C[TWI]           primary used with all sensoric mesurments; (hotplugable built and adress finder)
  e.)  §LoRa              [§UC] ->over RxTx far remotable/dataxchange able
  f.)  §WLan              [§UC] ->[Rasp W/ESP32/ESP8266] 

3. Settings
  a.)  USB-commands       soft settable 
  b.)  Jumper             onboard hard(overrule) setupable

4. Memory(Flash/E[EE]prom
  a.)  OS                 OSsave,OSload,[OSstd]  on initialisation/via USB-commands  

</pre>  

