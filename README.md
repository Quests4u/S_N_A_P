# S_N_A_P
<pre>
[Synaptic Neuronal Association Processor]
<b><big>
IDE    :   VS Studio Code 
Modul  :   PlattformIO
Devices:   <a target=dev href='https://store.arduino.cc/products/arduino-nano'>Arduino [Nano]</a>
           Mini D1 [ESP8266]
           *RESP Piko
AVRs   :   <a target=avr href='https://www.microchip.com/en-us/product/ATmega328P'>ATmega328P</a>
           ESP8266
           RESP
Name   :   SNAP[_AT/_ESP/_RB]
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
                            .prepared(ix)   (setup/per loop)
                            .refresh(ix)    (refresh hardware if needed)
                            .task(ix)       (one per 1sek; for regular data output) 
                            .loop(ix)       (each "delay" [<<60mS])
                            
                      
                                    
1. Sensor  
  a.)  PWM(parallel)      <put> constant analog sensor-stream -> through external 3xConverter  for SPS-conform 0-10V(2-10V) signals

2. Connex
  a.)  USB(serial)        [put] regular measured and csv formatted data
  b.)   -"-               [get],[parse] command to configure inner parameter  ("debug=[on,off]; Tpwm=[min,max]; EPsave;.. aso")

3. Settings
  a.)  USB-commands       soft settable 
  b.)  Jumper             onboard hard(overrule) setupable
 
4. Memory(Flash/E[EE]prom
  a.)  OS                 save,load,[std]  on initialisation/via USB-commands  
                        
</pre>  

