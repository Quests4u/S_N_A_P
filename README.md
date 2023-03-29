<pre>
[Synaptic Neuronal Association Processor]
<b><big>
LANG   :   C
IDE    :   /scp [VS Studio Code]
Modul  :   PlattformIO
Devices:   <a target=dev href='https://www.raspberrypi.com/products/raspberry-pi-pico/'>RASP [PI2] Piko</a>
             WOT: possible, just with 
               a.) (<a target=dev href='https://github.com/earlephilhower/arduino-pico'>earlephilhower</a>) <a target=dev href='https://github.com/maxgerhardt/platform-raspberrypi.git'>maxgerhardt</a> (@github) images.
               b.) <a target=dev href='https://git-scm.com/download/'>git-scm </a> (git-package loader).
               c.) <a target=conn href='https://zadig.akeo.ie'>Zadig</a> (virtiual com driver) is also needed in Win7x.
AVRs   :   RP2040
Name   :   SNAP_RB
</b>
   <u>Prepare:</u>
        source               |   destination     |  unit         |   explaination
        ---------------------------------------------------------------------------------------------------------   
        _config-RaspPI.h     |  /src/config.h    |   [C]         |  xchange for   file with choosen device-setup
        platformio.ini       |  /platformio.ini  |   [VScode]    |  modul-ini for setup needed [arduino-libraries]
   
</big>
<p>
<h2><b><i>Special Setup needed to use RaspPI on Arduino [VS-Code]</i></b></h2>
Please follow those Instructions: <a target=info href='./rasp-platformIO-setup.lsp'>rasp-platformIO-setup.lsp</a>
</p>

<p>
#//json 'rasp-platformIO-setup.lsp'
{
   "dev" :  "Raspberry PI Pico [W]"
   "url" :  "https://arduino-pico.readthedocs.io/en/latest/platformio.html"
   "tools":[
      "needed[download]":[
         "git": {
            "url":  "https://git-scm.com/download/win",
            "info":[
               "needed inside platformIO to download packages",
               "must be installed",
               "",
               "@platformIO",
               "^- to deativate Git erase .git folder"
               "   (but u must be logged off from git.)
            ],
         },
         "zadig":{   
            "url":   "https://zadig.akeo.ie",
            "info":  "it is standalone, no install!"
         },    
      ],
      "platformIO":{
         "configuration":{
            "url": "https://github.com/maxgerhardt/platform-raspberrypi.git",
            "name":  "platformIO.ini",
            "raw":[
               "
[env:s_n_a_p]
platform = https://github.com/maxgerhardt/platform-raspberrypi.git
board = rpipico
framework = arduino
board_build.core = earlephilhower

lib_deps =
   ; .. optional libraries
	adafruit/Adafruit Unified Sensor @ ^1.1.6
	adafruit/Adafruit BMP280 Library@^2.6.6
	fmalpartida/LiquidCrystal @ ^1.5.0
	adafruit/Adafruit SSD1306@^2.5.7
	moononournation/GFX Library for Arduino@^1.2.9
	adafruit/Adafruit GFX Library @ ^1.11.3

   ;.. tc u just have 2M flash in summe
board_build.filesystem_size = 512k 
;board_build.filesystem_size = 1M   
 
   ;.. different core versions
;platform_packages =
;   framework-arduinopico@https://github.com/earlephilhower/arduino-pico.git#master           
               ",
            ],
         },
      },
      "serial":{
         "boot-mode":{
            "RP2 boot (interface0)":{
               "org" :  "USBSTOR (v10.0.19041.1949) oä",
               "info": [
                  "Visible Drive to manually load  [.pio\build\%projectname%\]`firmware`,uf2 ",
                  "  ^- drag those file into the drive `RPI-RP2` it will flash",
                  "     and restart the *.uf2 image",
                  "IMPORTANT",
                  "  ^- dont put any serial driver there!",
               ],
            },
            "RP2 boot (interface1)":{
               "org":   "WinUSB oä",
               "new":   "libusb0 (v1.2.6.0)",
               "info":  [
                  "with %zadig% do change  %org% -> %new%",
                  "^- may take a few min to complete",
                  "",
               ]
            },
            //
         },
         "work-mode":{
            "ArduinoPico":{
               "org":   "WinUSB oä",
               "new":   "WinUSB(CDC)",
               "info":[
                  "with %zadig% do change  %org% -> %new%",
                  "^- incase it has usbwin driver inside and interface appears",
                  "   no change driver action is needed",
               ],
            },
         },
      },
       "info": [
         "if all configs r done, normal compiler action plus uploads should be standard.",
         "",
         "",
       ]
   ],
  
 }
 #//eof
</p>	



</pre>
