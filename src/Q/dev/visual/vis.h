/**
*
* @file       vis.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * Visuelle Componenten
 * TFT
 * OLED
 * LCD
 * @defgroup OLED TFT LCD
 * @brief <a href="https://">Product Overview</a>
 */

#include <Q/_config.h>


#ifndef VIS_H_
#define VIS_H_ 1


#if defined( VIS_AV)


/* Header includes */



//TEST
#define nVIS_AV 1
#define nVIS_HEAD_EXT_AV 1


#define nTFT_AV 1
#define nTFT_PIN_BL 1//<-- has PIN for BackLight / Vcc connected
  #define nTFT_GFX_AV 1
    #define nTFT_GFX_F12_AV 1   
    //^- Font 12x_ <--WOT: in case resource overflow!


#define nOLED_TW_AV  1
  #define nOLED_SSD1306_AV  1
  #define nOLED_ASCII_AV 1


#define nLCD_AV 1
  #define nLCD_HD44780_AV 1
    #define nLCD_HD44780_EMU_AV 1


/* Statische Definitions */


// Lcd/oled/vled 

#define    TX_VIS                 "VIS0:"
#define    TX_VIS_ON              TX_VIS TX_ONLINE
#define    TX_VIS_OFF             TX_VIS TX_OFFLINE


// auto rotation (std.Auto='0' <- First = '1')
#define  VIS_MS_AUTO          0x00
  #define  VIS_MS_SN            0x0F
#define  VIS_MS_ROTATE        0x10


#define  VIS_MS_T             0x01
#define  VIS_MS_P             0x02
#define  VIS_MS_F             0x03




#ifdef TFT_AV
 #define V_VIS "~tft"

#ifdef TFT_GFX_AV
  #define TFT_TYPE_GFX    0x4010 
  #define TFT_TYPE_GFX_N  "GXF(SPI)"
/* 
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
 * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
 * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
 * ESP32-S2 various dev board  : CS: 34, DC: 35, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
 * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
 * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
 * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
 * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
 * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
 * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
 * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
 * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
 * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
*/

//#define    SPI_DEFAULT_FREQ   1000000


#include <Arduino_GFX_Library.h>
#include <Q/dev/peripherie/spi.h>

#if defined(TFT_RAW_AV)
  #if defined(TFT_ST7735_AV)
    #include <Adafruit_ST7735.h>
  #endif
#endif

#if defined(TFT_GFX_F12_AV)
  #include <Q/dev/visual/FreeSerifBoldItalic12pt7b.h>
#endif

#if defined(TFT_RAW_AV)
  //
  #define   VIS_RED     RED
  #define   VIS_BLACK   BLACK
  #define   VIS_WHITE   WHITE
  #define   VIS_BLUE    BLUE
  #define   VIS_YELLOW  YELLOW
  #define   VIS_CYAN    CYAN
  //
#else 
  //
  #define   VIS_RED     BLUE
  #define   VIS_BLACK   BLACK
  #define   VIS_WHITE   WHITE
  #define   VIS_BLUE    RED 
  #define   VIS_YELLOW  CYAN
  #define   VIS_CYAN    YELLOW        
   //
#endif

#endif

#endif




// OLed:
#ifdef OLED_AV
  #define V_VIS "~oled"



#ifdef OLED_ASCII_AV
  #define OLED_TYPE_ASCII     0x2010
  #define OLED_TYPE_ASCII_N   "OLII"

#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

#include <Q/dev/peripherie/twi.h>

// 0X3C+SA0 - 0x3C or 0x3D
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define I2C_SCREEN0 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1


#endif


#ifdef OLED_SSD1306_AV
  #define OLED_TYPE_SSD1306     0x2020
  #define OLED_TYPE_SSD1306_N   "SSD1306"


  #define  I2C_SCREEN0   0x3C


  #define   VIS_BLACK   SSD1306_BLACK
  #define   VIS_WHITE   SSD1306_WHITE
  #define   VIS_INVERSE SSD1306_INVERSE


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };


#endif


#endif




#ifdef LCD_AV
  #define V_VIS  "~lcd"


#ifdef LCD_HD44780_AV
  #define LCD_TYPE_HD44780    0x1010  
  #define LCD_TYPE_HD44780_N  "HD44780(PP)" 
    #include <LCD.h>
    #include <LiquidCrystal.h>

    #include <Q/dev/io/pin.h>

#ifdef PIN_AV

#ifdef PIN_328_AV

// mode: select
#define  PIN_MS_LCD_8X2_EMU     7               // D7(i)    = PC7
#define nLCD_HD44780_SHARE_WR 1
//
#ifndef LCD_HD44780_SHARE_WR 
  #define  PIN_MS_DA_NUL        12            // D12(i) 
                                              // ^-- shared (incase) with PIN_LCD_WR (NU at mom.)
#else                                              
  #define  PIN_MS_DA_NUL        A0            // A0(i)    = PC0
#endif



// LCD: [HD44780 comp] -> MS_LCD_8X2 emu
#ifdef LCD_HD44780_SHARE_WR
  #define  PIN_LCD_WR         12             // D12(o)   = LCD 0_write/1_read
  //^-- const low for write (used otherwise)
#endif




#endif//328


#endif//pin



#define  PIN_LCD_RS           13             // D13(o)   = LCD set (1)
#define  PIN_LCD_E            8              // D8(o)    = LCD enable
//
#define  PIN_LCD_D4           5              // D5(o)    = LCD (hData) D4-7 
#define  PIN_LCD_D5           4              // D4(o)
#define  PIN_LCD_D6           3              // D3(o)
#define  PIN_LCD_D7           2              // D2(o)

#define  LCD_CDADR_LINE1      0x80 | 0x40       // SETDDRAM => LCD_SETDDRAMADDR = 0x80

#define  LCD_TYPE             0x00           // <--LCD_5x8DOTS



#endif//HD44


#endif//LCD


#define   VIS_HOCH      0x00
#define   VIS_QUER      0x01


#define   VIS_FNT_MSK   0x000F
#define   VIS_FNT_CLR   0xFFF0
//
#define   VIS_FNT_SML   0x0001
#define   VIS_FNT_STD   0x0002
#define   VIS_FNT_BIG   0x0004
#define   VIS_FNT_HGE   0x0008


#define   VIS_ACT_MSK 0x00F0
#define   VIS_ACT_CLR 0xFF0F
//
#define   VIS_ACT_STD 0x0010
#define   VIS_ACT_HL  0x0020
#define   VIS_ACT_NEW 0x0040
#define   VIS_ACT_ERR 0x0080





struct  _VIS_size_t{
  //
  int  w;
  int  h;
  //
  int  typ;
  //
  byte VH;// Hoch/Quer
  bool center;
  bool hasML;//<multiline
  //
  int  rows;
  int  cols;
  //
};


struct _VIS_font_t{
  //
  /**
   *  0x000x
   *       ^-- fnt[std/.../huge]
   *  0x00x0
   *      ^--- act[std/../new]
   */
  int  style;//

  int w;
  int h;
  //
  
};


/*!
 *   
 */
struct VIS_Set{
  //
  bool  v;
  //
  String head;
  int   type;
  bool  has;
  bool  had;
  //
  bool  refresh;
  bool  refreshed;
  bool  refreshForced;
  //
  _VIS_size_t D;
  _VIS_font_t F;
  //
  bool  hasTWI;
  bool  hadTWI;
  bool  chkTWI;
  byte  i2c;
  //
  bool  hasSPI;
  bool  hadSPI;
  //
  bool  hasEmu;
  bool  hasPP;

};






//#endif




/* Dynamische Definitions */

#ifdef  TFT_AV




#endif


// OLED:
#ifdef  OLED_AV 


#ifdef  OLED_ASCII_AV 
  //
  //SSD1306AsciiAvrI2c oled0;
#endif 


#ifdef  OLED_SSD1306_AV 
  //
  //Adafruit_SSD1306 oled0(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif

#endif


// LCD
#ifdef LCD_AV

//  LCD (HD 44780 comp.)
#ifdef LCD_HD44780_AV
  /*
  LiquidCrystal  LCD( 
      PIN_LCD_RS,
      PIN_LCD_E,
      PIN_LCD_D4,
      PIN_LCD_D5,
      PIN_LCD_D6,
      PIN_LCD_D7
    );
  */
#endif


#endif



// common


extern String        vis_line;//        = String("012345678901234567");//18By Puffer


extern int           _vis_ms_setup;//    = 0;      //<-rotate  VSI_MS_T;// --> rotate T->P->F
                                              //            ^------
//extern byte          _vis_ms_i;//  = 1,
extern byte          _vis_ms_rotate;//  = 0,
extern byte          _vis_ms_rotate_M;//= 3;





//<-- needs indexing[0]
extern String              _VIS0_head;//
extern int                 _VIS0_type;//          = 0;
extern bool                _VIS0_has;//          = false;
extern bool                _VIS0_had;//          = false;

extern bool                _VIS0_Refresh;//   = false;// WOT:  refresh busted LCD each 3rd delay loop(5)
extern bool                _VIS0_Refreshed;//   = false;
extern bool                _VIS0_RefreshForced;//   = false;//WOT: with LCD needed!!


extern _VIS_size_t               _VIS0_D;//      = {  16, 1, LCD_TYPE, 8,2};     // Real Config
extern _VIS_font_t               _VIS0_F;//      = {  1,1};  


extern bool                _VIS0_has_TWI;//      = false;
extern bool                _VIS0_had_TWI;//      = false;
extern bool                _VIS0_chk_TWI;//      = true;
extern byte                _VIS0_i2c;//          = 0;


extern bool                _VIS0_has_SPI;//      = false;
extern bool                _VSI0_had_SPI;//     = false;


extern bool                _VIS0_has_Emu;//          = false;
extern bool                _VIS0_has_PP;//       = false;












#ifdef LCD_AV
#ifdef LCD_HD44780_AV
extern _VIS_size_t               _lcdBox;//       = { 16, 1 };     // vir. dimension
#endif
#endif



extern int                 _vis_wot_i;//    = 0;
extern int                 _vis_wot_m;//    = 3;








/* Routine Definitions */


/*!
 * setup vis[ix] 
 *
 *  _VIS0_emu .. (Needs to be fitted spezial to each LCD!)
 *
 *@Param  _ix  .. indexed vis
 */
extern bool  _VIS_setup( 
            uint8_t _ix
                );



    /*!
     * prepare _VIS0_head
     *@param  _ix  .. vis[ix]
     *@param  _on  .. on/offline
     */
    extern void  _visSetHeader(
                  uint8_t _ix
                  //
                  ,bool _on
                );
    



                
/*!
 * clear  screen on vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _delay  .. added delay after print
 */
 extern bool  _VIS_cls( 
                int   _ix
                //
                ,int _delay
                );

/*!
 * clear  screen on vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _line   .. [Text]line 0,1,2,3..
 * @param  _style  .. -1/font size etc.
 * @param  _delay  .. -1/added delay after print
 */
 extern bool  _VIS_cls( 
                int   _ix
                //
                ,int  _line
                ,int  _style
                ,int  _delay
                );



/*!
 * print to screen vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 */
 extern bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                );

/*!
 *  print to screen vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 * 
 * @param  _line   .. [Text]line 0,1,2,3..
 * 
 * @param  _delay  .. added delay after print
 */
 extern bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                ,int    _line
                ,int   _delay
                );


/*!
 * print on vis[ix]
 *
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 * 
 * @param  _line   .. [Text]line 0,1,2,3..
 * @param  _style  .. -1/
 *                    0x00x0
 *                    ^-- [Highlight/new/std]
 *                    0x000x
 *                    ^-- [sml/std/big]
 * 
 * @param  _delay  .. -1/added delay after print
 */
 extern bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                ,int    _line
                ,int    _style
                //
                ,int   _delay
                );




/*!
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 * 
 * @param  _put    .. put to VIS[ix]
 * @param  _line   .. [Text]line 0,1,2,3..
 * @param  _fnt    .. [sml/std/big]
 * 
 * @param  _delay  .. added delay after print
 */
 extern bool  _VIS_handle(
                int    _ix
                ,bool   _clr
                // 
                ,bool   _put
                ,int    _line
                ,int    _fnt
                //
                ,int    _delay
                );




#endif 
#endif
//@
