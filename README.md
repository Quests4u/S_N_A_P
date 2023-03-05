<pre>
[Synaptic Neuronal Association Processor]
<b><big>
LANG   :   C
IDE    :   /scp [VS Studio Code]
Modul  :   PlattformIO
Devices:   <a target=dev href='https://store.arduino.cc/products/arduino-nano'>Arduino [Nano]</a> 
           <a target=dev href='https://www.az-delivery.de/en/products/d1-mini'>Mini D1 [ESP8266]
           <a target=dev href='https://www.raspberrypi.com/products/raspberry-pi-pico/'>RASP [PI2] Piko</a>
             WOT: possible, just with 
               a.) (<a target=dev href='https://github.com/earlephilhower/arduino-pico'>earlephilhower</a>) <a target=dev href='https://github.com/maxgerhardt/platform-raspberrypi.git'>maxgerhardt</a> (@github) images.
               b.) <a target=dev href='https://git-scm.com/download/'>git-scm </a> (git-package loader).
               c.) <a target=conn href='https://zadig.akeo.ie'>Zadig</a> (virtiual com driver) is also needed in Win7x.
AVRs   :   <u>Setup</u>
           - <a target=dev href='../../tree/AT328/'>Atmel328p</a>
           - <a target=dev href='../../tree/ESP8266/'>ESP8266</a>
           [UC]ESP32
           - <a target=dev href='../../tree/RaspPI/'>RP2040</a>
           
Name   :   SNAP[_AT/_E82/_RB]
</b></big>

Arduino sorta BIOS to handle Sensor-data (here BMP280 / BME 280[180] )
                   to handle visual-out  (TFT/OLED/LCD44)
                   to handle serial-i/o  
                                    o    (see "Serial  Studio")/usb formated out sensordata
                                    i    commands and settings
                                    i    §touchscreen in combine with TFT
                   to handle storage-i/o
                                    EProm[intern] EEProm[extern twi/i2c]
                   to handle PWM/PINS/Analoge 
                   to handle small APIs[0,1,2,3] with a set of methodes
                        [within "setup"]
                            .setup(ix)                 (anytime)             ..on each chip reset, after std. setup
                        [within "loop"]
                            .prepare(ix)               (per loop)            ..prepare[set]
                            .refresh(ix)               (per loop/task)       ..(auto)refresh hardware if needed
                            .task(ix)                  (per 6-more loops)    ..regular data output/slow ops
                            .loop(ix)                  (the loop)            ..each delay[<<60mS] or §SleepMode



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

