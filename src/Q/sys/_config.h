/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _config.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup SYSTEM
 * @brief <a href="https://">Product Overview</a>
 */


#ifndef CONFIG_H_
#define CONFIG_H_ 1


/* Header includes */


/* Statische Definitions */


//***  Arduino: base
#include <Arduino.h>
#include <math.h>



#define IO_AV       1

#define nISR_AV     1
#define nANALOG_AV  1  
#define nSLEEP_AV   1
#define nISR_ANX    1


#define WDT_AV      1//-->reset!
    #define WDT_COM_AV 1
#define nISR_WDT    1



//*** ATMEL 

#define  nAVR_AV 1
#ifdef AVR_AV

    #ifdef IO_AV
    #include <avr/io.h>
    #endif

    #ifdef WDT_AV
    #include <avr/wdt.h>
    #endif

    #ifdef ISR_AV
    #include <avr/interrupt.h>
    #endif

    #ifdef SLEEP_AV
    #include <avr/sleep.h>
    #endif


#endif
//

//*** ESP

#define  ESP8266_AV 1
#ifdef ESP8266_AV

    #include <ESP.h>

    #ifdef IO_AV
    #endif

    #ifdef WDT_AV
    //#include <esp32/aes.h>
    #endif

    #ifdef ISR_AV
    #include <avr/interrupt.h>
    #endif

    #ifdef SLEEP_AV
    #include <avr/sleep.h>
    #endif



#endif
//








//*** peripherie

#define TWI_AV 1
    #define TWI_SCAN_AV 1  //<-- at mom. std. added!



#define SPI_AV 1


//** io


#define SIO_AV 1
    #define SIO_COM_AV 1
    #define SIO_SESTU_AV 1//<-- SerialStudio format!
        #define SIO_COM_SESTU_AV 1


//#define PIN_AV
    //#define PIN_328_AV




//#define PWM_AV 1  
//#define PWM_COM_AV 1
    #define PWM_328_AV    1
        #define PWM_AD_AV    1




//*** visual

#define VIS_AV 1
#define VIS_COM_AV 1
#define VIS_HEAD_EXT_AV 1


    //#define TFT_AV 1
    #define TFT_PIN_BL 1//<-- has Backlight PIN std: (D6)
        
    
        #define TFT_GFX_AV 1
            //#define TFT_GFX_F12_AV 1   
        //^- Font 12x_ <--WOT: in case resource overflow!
        //#define TFT_GFX_BL 6
        //^- BackLight Pin <- if not def. D6


    #define OLED_AV  1
        #define OLED_SSD1306_AV  1
        //#define OLED_ASCII_AV 1
    

    //#define LCD_AV 1
        #define LCD_HD44780_AV 1
            //#define LCD_HD44780_PIN_AV 1
            #define LCD_HD44780_EMU_AV true



//*** sensoric



#define MSX_AV 1
#define MSX_COM_AV 1//<--  NC yet!
    //#define MSX_PIN_AV


    #define BMP_280_AV 1
        #define ADF_P280_AV 1


    //#define BME_280_AV 1
        #define JWA_E280_AV 1
        //#define ADF_E280_AV 1
    



//*** tools
#define COM_AV 1


#define LED_AV 1




//*** storages

#define EP_AV 1
    #define EP_COM_AV 1


// data bulk definition
struct EP_bulk_t{
  //
  bool  Valid; 
  //
  /**   define  storeable values (raw!!) ! ********/
  /*            (fill below)                      */
  // OS
  bool  dbgCom;
  bool  noBreak;
  int   OS_loops;
  //
  // vis
  int   vis_ms_setup;
  //
  // PWM
  #ifdef PWM_328_AV
  int   pwm_dac_nul;
  
  #ifdef PWM_AD_AV
  int   pwm_t_0;
  int   pwm_t_M;
  int   pwm_p_0;
  int   pwm_p_M;
  int   pwm_f_0;
  int   pwm_f_M;
  #endif
  #endif
//
  // Serial
  // 
  bool  SO_para;
  bool  SO_sestu;
  //
  /**    ^-- define above               *****/
  char  prem[6];
  //
};



//**** Applications


#define API0_AV 1



/* Dynamische Definitions */



// -- SNAP

#include <Q/sys/_def.h>


#ifdef SPI_AV
#include <Q/dev/peripherie/spi.h>
#endif

#ifdef TWI_AV
#include <Q/dev/peripherie/twi.h>
#endif


#ifdef PIN_AV
#include <Q/dev/io/pin.h>
#endif

#ifdef PWM_AV
#include <Q/dev/io/pwm.h>
#endif



#ifdef SIO_AV
#include <Q/dev/io/sio.h>
#endif



#ifdef VIS_AV
#include <Q/dev/visual/vis.h>
#endif


#ifdef MSX_AV
#include <Q/dev/sensor/msx.h>
#endif



#ifdef EP_AV
#include <Q/dev/storage/ep.h>
#endif


#ifdef EEP_AV
#include <Q/dev/storage/eep.h>
#endif


#ifdef COM_AV
#include <Q/sys/tools/cmd.h>
#endif


#ifdef LED_AV
#include <Q/sys/tools/led.h>
#endif


#ifdef API0_AV
#include <api0.h>
#endif





#endif 
//@
