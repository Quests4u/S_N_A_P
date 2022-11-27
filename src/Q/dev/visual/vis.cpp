/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       Q/vis.h
* @brief      visual drivers
* @date       2022-07-01
* @version    v1.00
*
*/
#include <Q/dev/visual/vis.h>



#if defined( VIS_AV)

/* Statische Definitions */

/* Dynamische Definitions */

// TFT
#if defined(TFT_AV)

// TFT: GFX ST7735 (ADAFruit)
#ifdef TFT_GFX_AV



#ifdef AVR_AV


// data IF
Arduino_DataBus *bus = create_default_Arduino_DataBus();
// driver
Arduino_GFX *gfx = new Arduino_ST7735(
          bus 
          ,DF_GFX_RST 
          ,1 //1 Quer/0 Hoch
          ,false 
);


#elif ESP8266_AV //WEMOS D1 LITE!


// GFX  standard
#if defined(TFT_RAW_AV)

#if defined(TFT_ST7735_AV)
Adafruit_ST7735 tft = Adafruit_ST7735(
          SPI_pin0.CS//TFT_CS
        , SPI_pin0.DC//TFT_DC
         // , SPI_pin0.MOSI
         // , SPI_pin0.SCK
        , SPI_pin0.RST//TFT_RST
);
#endif


#else

//Arduino_DataBus *bus = new Arduino_ESP8266SPI(DF_GFX_DC, DF_GFX_CS);// data IF
Arduino_DataBus *bus = new Arduino_ESP8266SPI( 
//Arduino_DataBus *bus = new Arduino_HWSPI( 
        SPI_pin0.DC//DF_GFX_DC
       ,SPI_pin0.CS//DF_GFX_CS
);// data IF
// driver
Arduino_GFX *gfx = new Arduino_ST7735(
          bus 
          ,SPI_pin0.RST//DF_GFX_RST, 
          ,1 //1 Quer/0 Hoch
          ,false 
);

#endif


#elif RASP_AV //piko!


// GFX  standard
#if defined(TFT_RAW_AV)

#if defined(TFT_ST7735_AV)
Adafruit_ST7735 tft = Adafruit_ST7735(
          SPI_pin0.CS//TFT_CS
        , SPI_pin0.DC//TFT_DC
         // , SPI_pin0.MOSI
         // , SPI_pin0.SCK
        , SPI_pin0.RST//TFT_RST
);
#endif


#else

Arduino_DataBus *bus = new Arduino_RPiPicoSPI( 
        SPI_pin0.DC//DF_GFX_DC
       ,SPI_pin0.CS//DF_GFX_CS
);// data IF
// driver
Arduino_GFX *gfx = new Arduino_ST7735(
          bus 
          ,SPI_pin0.RST//DF_GFX_RST, 
          ,1 //1 Quer/0 Hoch
          ,false 
);

#endif


#endif




#endif

#endif


// OLED: 
#ifdef OLED_AV

#ifdef  OLED_ASCII_AV 
  //
  SSD1306AsciiAvrI2c oled0;
#endif 

#ifdef  OLED_SSD1306_AV 
  //
  Adafruit_SSD1306 oled0(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#endif

#endif



//  LCD 
#ifdef LCD_AV

//  LCD (HD 44780 comp.)
#ifdef LCD_HD44780_AV
LiquidCrystal  LCD( 
      PIN_LCD_RS,
      PIN_LCD_E,
      PIN_LCD_D4,
      PIN_LCD_D5,
      PIN_LCD_D6,
      PIN_LCD_D7
);
#endif

#endif


String        vis_line          = String("012345678901234567");
                                //^- 18By Puffer


int           _vis_ms_setup     = 0;     
                                //^- rotate  VSI_MS_T;// --> rotate T->P->F

//byte          _vis_ms_i         = 0;
                                //^- act 
byte          _vis_ms_rotate    = 0;
                                //^- start ix
byte          _vis_ms_rotate_M  = 3;
                                //^- rotate   T->P->F
                                //            ^-----'



const char*         _tx_vis_off        = TX_VIS_OFF;
//const char*         _tx_vis_on         = TX_VIS_ON;


// needs to go indexed!!
//
//
String              _VIS0_head         = String("012345678901234567");//(12by)
int                 _VIS0_type         = 0;  
bool                _VIS0_has          = false;
bool                _VIS0_had          = false;

bool                _VIS0_Refresh         = false;    // WOT:  refresh busted LCD each 3rd delay loop(5)
bool                _VIS0_Refreshed       = false;         
bool                _VIS0_RefreshForced   = false;//WOT: with LCD needed!!


bool                _VIS0_Center          = true;     //obsolete!! center view
_VIS_size_t         _VIS0_D            = {  
                                          8 
                                          ,2 
                                          //
                                          ,-1     //LCD_TYPE
                                          //
                                          ,VIS_QUER  //Portrait/wide
                                          ,false  //center
                                          ,false  //Multiline
                                          //
                                          ,16
                                          ,1
                                        };   
_VIS_font_t         _VIS0_F           ={
                                          VIS_FNT_STD
                                          |VIS_ACT_STD
                                          ,1
                                          ,1 
                                        };


bool                _VIS0_has_TWI      = false;
bool                _VIS0_had_TWI      = false;
bool                _VIS0_chk_TWI      = false;
byte                _VIS0_i2c          = 0;

bool                _VIS0_has_SPI      = false;
bool                _VIS0_had_SPI       = false;


bool                _VIS0_has_Emu       = false; // emulation 8x2 -> 16x1
bool                _VIS0_has_PP        = false;





#ifdef LCD_AV
#ifdef LCD_HD44780_AV
// obsolete! use  font_t
_VIS_size_t               _lcdBox       = { 16, 1, -1, false, 8, 2};     // vir. dimension
#endif
#endif





int                 _vis_wot_i    = 0;
int                 _vis_wot_m    = 3;






/* Routine Definitions */


/*!
 *  detect  'Lines' (used by \n).
 *  (without its 1)
 */
uint8_t  _VIS_detectLines(
            uint8_t  _ix
            ){
    uint8_t _LNs=0,
            _m=vis_line.length();
    if (_m>0){
      _LNs=1;
      for( int _i=0; _i<_m; _i++){
        //
        if (vis_line[_i]=='\n'){
          //
          _LNs++;
        }
      }//loop
      //
    }//has
  //
  return _LNs;
}



/*!
 * setup vis[ix] 
 *
 *  _lcdEMU .. (Needs to be fitted spezial to each LCD!)
 *
 *@Param  _ix  .. indexed vis
 */
bool  _VIS_setup( 
            uint8_t _ix
                ){
  // 
  bool _f=false;
  // - tft
#ifdef TFT_AV  
#ifdef TFT_GFX_AV
    //
    if (_VIS0_has!=_VIS0_had){
      _VIS0_type=TFT_TYPE_GFX;
      OS_loop_refresh    =true;
    }
    //
#if defined(TFT_RAW_AV)
  #if defined(TFT_ST7735_AV)
    tft.initR( INITR_BLACKTAB);
  #endif
#else
    gfx->begin();
#endif
    //
    // WOT: needs to get connection status!!!
    //
    _VIS0_has_SPI =true;// gfx->availableForWrite();
    //
    _VIS0_F.w     =6;
    _VIS0_F.h     =8;
    _VIS0_F.style =VIS_FNT_STD|VIS_ACT_STD;
    //
#if defined(TFT_RAW_AV)
    _VIS0_D.h     =tft.height();
    _VIS0_D.w     =tft.width();
#else
    _VIS0_D.h     =gfx->height();
    _VIS0_D.w     =gfx->width();
#endif
    _VIS0_D.cols  =round( (float)_VIS0_D.h/_VIS0_F.w);
    _VIS0_D.rows  =round( (float)_VIS0_D.w/_VIS0_F.h);
    _VIS0_D.hasML =true;
    //  check set!
      //gfx->setRotation(1)
#if defined(TFT_RAW_AV)
      tft.fillScreen(BLACK);
#else
      gfx->fillScreen(BLACK);
#endif

    #ifdef TFT_PIN_BL
      #ifdef TFT_GFX_BL
        SPI_pin0.BL=TFT_GFX_BL;
      #endif
        if (SPI_pin0.BL>0){
          pinMode( SPI_pin0.BL, OUTPUT);
          digitalWrite( SPI_pin0.BL, HIGH);
        }
    #endif

      //
    #if defined( TFT_GFX_F12_AV)
        gfx->setFont(&FreeSerifBoldItalic12pt7b);
    #endif
      
    #if defined( TFT_RAW_AV)
      tft.setTextWrap( false);
      tft.setRotation( _VIS0_D.VH);
    #else
      gfx->setTextWrap( false);

    #endif
    
  _f=_VIS0_has_SPI;
#endif

#endif



  // - OLED
#ifdef OLED_AV

#ifdef OLED_ASCII_AV
  //
  if (_VIS0_has!=_VIS0_had){
      _VIS0_type=OLED_TYPE_ASCII;
      OS_loop_refresh    =true;
  }
  //
  _VIS0_i2c=I2C_SCREEN0;
  _VIS0_has_TWI=TWI_port( _VIS0_i2c);
  //
  if (_VIS0_has_TWI){
    //
    oled0.begin( &Adafruit128x32, _VIS0_i2c);
    //
    _VIS0_F.w     = oled0.charWidth('_');
    _VIS0_F.h     = 8;
    _VIS0_F.style =VIS_FNT_STD|VIS_ACT_STD;
    //
    _VIS0_D.h     =SCREEN_HEIGHT;
    _VIS0_D.w     =SCREEN_WIDTH;
    //
    _VIS0_D.cols  = round( (float)SCREEN_WIDTH/_VIS0_F.w);
    _VIS0_D.rows  = oled0.displayRows();
    _VIS0_D.hasML =true;
    //
    oled0.setFont(System5x7);
    oled0.set1X();
    //
  }
  _VIS0_chk_TWI=true;
  _f=_VIS0_has_TWI;
#endif

#ifdef OLED_SSD1306_AV
  //
  if (_VIS0_has!=_VIS0_had){
    _VIS0_type=OLED_TYPE_SSD1306;
    OS_loop_refresh    =true;
  }
  //
  _VIS0_i2c=I2C_SCREEN0;
    _VIS0_has_TWI=TWI_port( _VIS0_i2c);
    //
    if (_VIS0_has_TWI) {
      //
      oled0.begin(
            SSD1306_SWITCHCAPVCC
            ,_VIS0_i2c 
      );
      //
      _VIS0_F.w     =6;//oled0.charWidth('_');
      _VIS0_F.h     =8;
      _VIS0_F.style =VIS_FNT_STD|VIS_ACT_STD;
      //
      _VIS0_D.w     =SCREEN_WIDTH;
      _VIS0_D.h     =SCREEN_HEIGHT;
      _VIS0_D.cols  = round( (float)SCREEN_WIDTH/_VIS0_F.w);
      _VIS0_D.rows  = 4;//oled0.displayRows();
      _VIS0_D.hasML =true;
      //
      oled0.display();
      
      //delay(633); // Pause for 2 seconds
      OS_delay( 633);

      // Clear the buffer
      oled0.clearDisplay();
      oled0.cp437(true);         // Use full 256 char 'Code Page 437' font
      oled0.setTextSize( 1);
      oled0.setTextWrap( false);
      oled0.display();
      //break;
    }
  //}//loop
  //
  _VIS0_chk_TWI=true;
  _f=_VIS0_has_TWI;
#endif

#endif



// LCD
#ifdef LCD_AV

#ifdef LCD_HD44780_AV
  //
  if (_VIS0_Has!=_VIS0_had){
    _VIS0_type=LCD_TYPE_HD44780;
    OS_loop_refresh=true;
  }
  //
  bool _emu=_VIS0_hasEmu;
    if (_emu){
      _VIS0_D.w=8;
      _VIS0_D.h=2;
      //
      _VIS0_D.cols=16;
      _VIS0_D.rows=1;
      //
    }
    else{
      _VIS0_D.w=16;
      _VIS0_D.h=1;
      //
      _VIS0_D.cols=16;
      _VIS0_D.rows=1;
      //
    }

    // modus                  
    LCD.begin( 
          _VIS0_D.w, 
          _VIS0_D.h,
          _VIS0_D.typ
          );
    //
    LCD.noBlink();
    //
    LCD.noCursor();
    //
      _VIS0_has_PP=true;
      _visRefreshForced=true;
    _f=true;
#endif

#endif


  
  // common
    if (_VIS0_has!=_VIS0_had){
      _VIS0_has=_f;
      _VIS0_had=_f;
      //
      _visSetHeader( 0, _f);
    #ifdef SIO_AV
      Serial.println( _VIS0_head);
    #endif
    }
  return _f;
}




    /*!
     * prepare _VIS0_head
     *@param  _ix  .. vis[ix]
     *@param  _on  .. on/offline
     */
    void  _visSetHeader(
                  uint8_t _ix
                  //
                  ,bool _on
                ){
      //
      _VIS0_head="";
      if (_on){
        _VIS0_head.concat(TX_VIS);
        switch( _VIS0_type){
   #ifdef TFT_TYPE_GFX
   case TFT_TYPE_GFX: _VIS0_head.concat( TFT_TYPE_GFX_N); 
   #endif
   #ifdef OLED_TYPE_ASCII
   case OLED_TYPE_ASCII: _VIS0_head.concat( OLED_TYPE_ASCII_N); 
   #endif
   #ifdef OLED_TYPE_SSD1306
   case OLED_TYPE_SSD1306: _VIS0_head.concat( OLED_TYPE_SSD1306_N); 
   #endif
   #ifdef LCD_TYPE_HD44780
   case LCD_TYPE_HD44780: _VIS0_head.concat( LCD_TYPE_HD44780_N); 
   #endif

        }
        //
   #ifdef VIS_HEAD_EXT_AV
        //
        _VIS0_head.concat( '*');
        _VIS0_head.concat( _VIS0_D.cols);
        _VIS0_head.concat( 'x');
        _VIS0_head.concat( _VIS0_D.rows);
        //
        if (_VIS0_i2c>0){
          _VIS0_head.concat( " >@");
          _VIS0_head.concat( _VIS0_i2c);
        }
    #endif
      }
      else{
        _VIS0_head.concat( _tx_vis_off);
      }
      
    }






/*!
 * clear whole vis[ix]
 *
 * @param  _ix     .. vis[ix] -- NC!
 *
 * @param  _delay  .. added delay after print
 */
 bool  _VIS_cls( 
                int   _ix
                //
                ,int _delay
                ){
    return _VIS_handle( _ix, true, false, -1, -1, _delay);
  }

/*!
 * clear  vis[ix]  row[_line]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _line   .. [Text]line 0,1,2,3..
 * @param  _style  .. -1/font size etc.
 * @param  _delay  .. -1/added delay after print
 */
 bool  _VIS_cls( 
                int   _ix
                //
                ,int _line
                //
                ,int _style
                ,int _delay
                ){
    return _VIS_handle( _ix, true, false, _line, _style, _delay);
  }





/*!
 * print on vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 */
 bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                ){
    return _VIS_handle( _ix, _clr, true, -1, -1, -1);
  }





/*!
 * print on vis[ix]
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 * 
 * @param  _line   .. [Text]line 0,1,2,3..
 * 
 * @param  _delay  .. added delay after print
 */
 bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                ,int   _line
                ,int   _delay
                ){
    return _VIS_handle( _ix, _clr, true, _line, -1, _delay);
  }


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
 bool  _VIS_print(
                int    _ix
                ,bool   _clr
                // 
                ,int   _line
                ,int   _style
                //
                ,int   _delay
                ){
    return _VIS_handle( _ix, _clr, true, _line, _style, _delay);
  }




/*!
 * @param  _ix     .. vis[ix] -- NC!
 * @param  _clr    .. cls befor print
 * 
 * @param  _put    .. put on screen
 * @param  _line   .. [Text]line 0,1,2,3..
 * @param  _style  .. 0x00x0
 *                    ^-- [Highlight/new/std]
 *                    0x000x
 *                    ^-- [sml/std/big]
 * 
 * @param  _delay  .. added delay after print
 */
bool  _VIS_handle(
                 int    _ix
                ,bool   _clr
                // 
                ,bool   _put
                ,int    _line
                //
                ,int    _style
                //
                ,int    _delay
                ){
  //
  bool _f=false;
  //
  // TFT
#if defined(TFT_AV) & defined(TFT_GFX_AV)
  int _act,
      _fnt;
#ifdef TFT_PIN_BL
    bool _hasClr=false;
#endif


  if (_VIS0_has_SPI){
    //
    int _u=1;//STD
        if (_style<0){
          _style=_VIS0_F.style;
        }
        _fnt=_style&VIS_FNT_MSK;
        _act=_style&VIS_ACT_MSK;
        //
        switch(_fnt){
        case VIS_FNT_BIG: _u=2;
          break;
        case VIS_FNT_HGE: _u=3;
          break;
        }
        //
    bool _hasL=_line>=0;
    int _y=0;
    if (_hasL){
      _y=_line*_VIS0_F.h*_u;
    }
    //


  // ADA ST7735
#if defined(TFT_RAW_AV)

    if (_clr){
      //
      if (_hasL){
        //
        _u=_VIS_detectLines( 0)*_u;
        //
        tft.fillRect( 0,_y,_VIS0_D.w,_VIS0_F.h*_u,VIS_BLACK);
        tft.setCursor( 0, _y);
        //
      }
      else{
    #ifdef TFT_PIN_BL
        digitalWrite( TFT_spi_pin0.BL, LOW);
        _hasClr=true;
    #endif
        //
        tft.fillScreen(BLACK);
        tft.setCursor(0, 0);
      }
    }
    //

    if (_put){
      //
      //
        switch( _fnt){
        case VIS_FNT_HGE:  
                  tft.setTextSize( 3);
          break;
        case VIS_FNT_BIG: 
                  tft.setTextSize( 2);
          break;
        default:          
                  tft.setTextSize( 1); 
          break;
        }
        switch( _act){
        case VIS_ACT_HL:
                  tft.setTextColor(VIS_YELLOW);
          break;
        case VIS_ACT_NEW:
                  tft.setTextColor(VIS_CYAN);
          break;
        case VIS_ACT_ERR:
                  tft.setTextColor(VIS_RED);
          break;
        default:
                  tft.setTextColor(VIS_WHITE);
          break;
        }
      //
      //gfx->flush();
      tft.println( vis_line);
      //


#else
  // GFX: standard

    if (_clr){
      //
      if (_hasL){
        //
        _u=_VIS_detectLines( 0)*_u;
        //
        gfx->fillRect( 0,_y,_VIS0_D.w,_VIS0_F.h*_u,VIS_BLACK);
        gfx->setCursor( 0, _y);
        //
      }
      else{
    #ifdef TFT_PIN_BL
        digitalWrite( SPI_pin0.BL, LOW);
        _hasClr=true;
    #endif
        //
        gfx->fillScreen(BLACK);
        gfx->setCursor(0, 0);
      }
    }
    //

    if (_put){
      //
        switch( _fnt){
        case VIS_FNT_HGE:  
                  gfx->setTextSize( 3);
          break;
        case VIS_FNT_BIG: 
                  gfx->setTextSize( 2);
          break;
        default:          
                  gfx->setTextSize( 1); 
          break;
        }
        switch( _act){
        case VIS_ACT_HL:
                  gfx->setTextColor(VIS_YELLOW);
          break;
        case VIS_ACT_NEW:
                  gfx->setTextColor(VIS_CYAN);
          break;
        case VIS_ACT_ERR:
                  gfx->setTextColor(VIS_RED);
          break;
        default:
                  gfx->setTextColor(VIS_WHITE);
          break;
        }
      //
      gfx->println( vis_line);
      //
#endif



    #ifdef TFT_PIN_BL
      if (_hasClr){
        digitalWrite( SPI_pin0.BL, HIGH);
      }
    #endif
    }//put    
    //
  }


#endif


  // OLED
#ifdef OLED_AV

  // AcsII (ADA derivat)
#ifdef OLED_ASCII_AV
  //
  int _fnt;  
  if (_VIS0_has_TWI){
    //
    bool _hasL=_line>=0;
    if (_clr){
      //
      if (_hasL){
        //
        uint8_t _u=_VIS_detectLines( 0);
        //
        for( ;_u>0; _u--){
          oled0.setCursor( 0, _line+(_u-1));
          oled0.clearToEOL();
        }
      }
      else{
        //
        oled0.clear();
      }
    }
    else{
      //
      if (_hasL){
        oled0.setCursor( 0, _line);
      }
    }
    //
    if (_put){
      //
        if (_style<0){
          _style=_VIS0_F.style;
        }
        _fnt=_style&VIS_FNT_MSK;
        //_act=_style&VIS_ACT_MSK;
        //
        switch( _fnt){
        case VIS_FNT_HGE:  
        case VIS_FNT_BIG: 
                  oled0.set2X();
          break;
        default:          
                  oled0.set1X(); 
          break;
        }
      //
      oled0.println(vis_line);
    }
    //
    oled0.flush();
    //
  }
#endif

  // ADA SSD1306
#ifdef OLED_SSD1306_AV
  //
  if (_VIS0_has_TWI){
    //
    int _fnt,
        _act,
        _u=1;
        //
        if (_style<0){
          _style=_VIS0_F.style;
        }
        _fnt=_style&VIS_FNT_MSK;
        _act=_style&VIS_ACT_MSK;
        //
        switch(_fnt){
        case VIS_FNT_BIG:
        case VIS_FNT_HGE: 
                _u=2;
          break;
        }
        //
    bool _hasL=_line>=0;
    int _y=0;
    if (_hasL){
      _y=_line*_VIS0_F.h;//*_u;
    }
    //
    //
    if (_clr){ 
      //
      if (_hasL){
        //
        _u=_VIS_detectLines( 0)*_u;
        //
        oled0.fillRect( 0,_y,_VIS0_D.w,_VIS0_F.h*_u, VIS_BLACK);
        oled0.setCursor( 0, _y);
        oled0.display();
      }
      else{
        //
        oled0.clearDisplay();
        oled0.setCursor( 0, 0);
        oled0.display();
      }
    }
  
  
    //
    if (_put){
      //
        if (_style<0){
          _style=_VIS0_F.style;
        }
        _fnt=_style&VIS_FNT_MSK;
        _act=_style&VIS_ACT_MSK;
        //
        switch( _fnt){
        case VIS_FNT_HGE:  
        case VIS_FNT_BIG: 
                  oled0.setTextSize(2);
          break;
        default:          
                  oled0.setTextSize(1); 
          break;
        }
        //
        switch( _act){
          //
        case VIS_ACT_ERR:
                  oled0.setTextColor(VIS_INVERSE);
          break;
        case VIS_ACT_NEW:
        case VIS_ACT_HL:
        default:
                  oled0.setTextColor(VIS_WHITE);
          break;
        }
      //
      oled0.println(vis_line);
      oled0.display();
    }
    //
    
  }//has
#endif 

#endif


  // LCD
#ifdef LCD_AV
  //
  // LCD parallel
#ifdef LCD_HD44780_AV
  if (_VIS0_has_PP){
    //
    if (_clr){
      //
      LCD.clear();
    }
    //
    char    _c=' ';
    uint8_t _b=0;
    int   _i=0,
          _h=0,
          //
          _Lbox=_lcdBox.w,
          _L=vis_line.length(),
          _l=0, 
          _=0;
    //
    if      (_L<0){
      _L=0;
    }
    else if (_L>=_Lbox){
      _L=_Lbox;
    }
    //
    if (_visCenter){
      _=(_lcdBox.w-_L)>>1;// center gap
    }
    //
    if (_put){
      //
    while((!_f)
         &(_h<_VIS0_D.h)
         ){
      //
      _i=0;
      while((!_f)
           &(_i<_VIS0_D.w)
           ){
        //  
        _b=vis_line.charAt( _l);
        _c=(char)_b;
        //
        if ((_c>0)&
            (_l<_L)){
          if (_>0){
            //
            LCD.print( ' ');
            _--;
          }
          else{
            LCD.print( _c);
            _l++;
          }
          _i++;
          //delay( 1);
        }
        else{
          _f=true;
        }
      }
      // NextLine
      _h++;
      LCD.send( LCD_CDADR_LINE1, LOW);
      //delay( 1);
      //
    }//loop(f)
    }//put
  }//has
#endif
  //
#endif

    // common
    if (_delay>0){
      //
      OS_delay( _delay);
    }
  //
  return _f;
}



#endif
//--

