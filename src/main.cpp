/*!
* Copyrights by @Edtronix-LABs 1992-2022
* v2.xx
* @file  main.h
*/


// config (individual setup)
#include <_config.h>





// RING PUFFER
#define RP_AV 1
#ifdef RP_AV



#endif




// Analysis
//!! N
//#define  VAL_ALYS  1   //<--§§
#ifdef VAL_ALYS

#define  VAL_COUNT              30.0     //  -> count of integrater values

#endif





#ifdef ISR_ANX
// [NC yet] an0 -> timing isr
#define  PIN_AN0_REF          7              // D7(i)    = PD7/ANI (ACOMP+)
                                             // ^-- !! shared with MS_LCD_8X2_EMU
#endif









/*********************** STATIC / DYNAMIC  Data Collection - Transfer **********************/


#ifndef V_VIS
  #define V_VIS ""
#endif
#ifndef V_MSX0
  #define V_MSX0 ""
#endif
#ifndef V_MSX1
  #define V_MSX1 ""
#endif
#ifndef V_PWM
  #define V_PWM ""
#endif
#ifndef V_EP
  #define V_EP ""
#endif

#define  VERS                V_VERSION V_VIS V_MSX0 V_MSX1 V_PWM V_EP


#ifndef V_LOGO
  #define V_LOGO "@"
#endif
#ifndef V_DEV
  #define V_DEV "*"
#endif

#define  LOGO                V_LOGO V_DEV


//*** def(initions) [_def.h]

const char*         _tx_logo          = LOGO;
const char*         _tx_vers          = VERS;      





/** BEGIN: insert fillxxx  meth. with std/load/save values! ***/
#if defined( OS_STORE_AV)



          void _OS_fillStdValues(){ 
            //
            OS_debug                = false;
            OS_nobreak              = false;
            OS_loop_max             = OS_LOOPS;
            //
        #if defined(VIS_AV)
            _vis_msx_setup          = VIS_MS_AUTO;//(rotate)
        #endif
            //
        #ifdef PWM_AV
        #ifdef PWM_328_AV
            _PWM_DAC_null         =PWM_DAC_LOW;
            //
        #ifdef PWM_AD_AV
            pwm_t_0               = PWM_T0_0;
            pwm_t_M               = PWM_T0_M;
            pwm_p_0               = PWM_P0_0;
            pwm_p_M               = PWM_P0_M;
            pwm_h_0               = PWM_H0_0;
            pwm_h_M               = PWM_H0_M;
        #endif
        #endif
        #endif
            //
            SO_para               = true;
        #ifdef SIO_SESTU_AV
            SeStu0.v              =false;
        #endif
          }

      


          void _OS_fillValues2Bulk(){
            //
            OS_bulk.t.dbgCom      = OS_debug;
            OS_bulk.t.noBreak     = OS_nobreak;
            OS_bulk.t.OS_loops    = OS_loop_max;
            //
        #if defined(VIS_AV)
            OS_bulk.t.vis_ms_setup = _vis_msx_setup;
        #endif
            //
        #ifdef PWM_AV
        #ifdef PWM_328_AV
            OS_bulk.t.pwm_dac_nul = _PWM_DAC_null;
        
        #ifdef PWM_AD_AV
            OS_bulk.t.pwm_t_0     = pwm_t_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_t_M     = pwm_t_M;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_p_0     = pwm_p_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_p_M     = pwm_p_M;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_h_0     = pwm_h_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_h_M     = pwm_h_M;//*EP_DOUBLE_DIV;
        #endif
        #endif
        #endif
            //
            OS_bulk.t.SO_para     = SO_para;
        #ifdef SIO_SESTU_AV
            OS_bulk.t.SO_sestu    = SeStu0.v;
        #endif
            //
          }

          void _OS_fillBulk2Values(){
            // 
            OS_debug            = OS_bulk.t.dbgCom;
            OS_nobreak          = OS_bulk.t.noBreak;
            OS_loop_max         = OS_bulk.t.OS_loops;
            // 
        #if defined(VIS_AV)
            _vis_msx_setup       = OS_bulk.t.vis_ms_setup;
        #endif
            //
        #ifdef PWM_AV
        #ifdef PWM_328_AV
            _PWM_DAC_null       = OS_bulk.t.pwm_dac_nul;
            
        #ifdef PWM_AD_AV
            pwm_t_0             = OS_bulk.t.pwm_t_0;///EP_DOUBLE_DIV;
            pwm_t_M             = OS_bulk.t.pwm_t_M;///EP_DOUBLE_DIV;
            pwm_p_0             = OS_bulk.t.pwm_p_0;///EP_DOUBLE_DIV;
            pwm_p_M             = OS_bulk.t.pwm_p_M;///EP_DOUBLE_DIV;
            pwm_h_0             = OS_bulk.t.pwm_h_0;///EP_DOUBLE_DIV;
            pwm_h_M             = OS_bulk.t.pwm_h_M;///EP_DOUBLE_DIV;
        #endif
        #endif
        #endif
            //
            SO_para             = OS_bulk.t.SO_para;//
        #ifdef SIO_SESTU_AV
            SeStu0.v            = OS_bulk.t.SO_sestu;//
        #endif
          }

#endif
/** END: insert fillxxx  meth. with std/load/save values! ***/





/** BEGIN: insert fillxxx  meth. with std/load/save values! ***/
#if defined( API_AV)

      
   /*!
    *
    */
   bool  API_install_WOT(){
      //
      bool _f=true;
      //
   #if defined(API0_INSTALL_AV)
         APIxInstall( Api0);         
   #endif

   #if defined(API1_INSTALL_AV)
         APIxInstall( Api1);         
   #endif
   
   #if defined(API2_INSTALL_AV)
         APIxInstall( Api2);         
   #endif

   #if defined(API3_INSTALL_AV)
         APIxInstall( Api3);         
   #endif
   
      //
      return _f;
   }
   

#endif
/** END: insert fillxxx  meth. with std/load/save values! ***/












/************************************ ROUTINES *************************************/







// WDT:  *****************

#ifdef ISR_WDT

  /** WatchDog
   */
  ISR( WDT_vect){
    //
    // system should restart.
    // loop should repeat.
    //
  }



/**
 *  WDT:
 */
void _delaySetWD(
            int _pwm,
            int _time,
            bool _state
          ){
    noInterrupts();
      //
      __LED0.hasAuto=true;
      int _WD_time=LED_DELAY_WD_SLOW+LED_DELAY_WB_LS;  // <-- 0.5s
      //
      WDTCSR =   _BV(WDCE)      // do changes to WDTCSR
                |_BV(WDIF)      // clear WDIF sigflag
                |_BV(WDE)       // after IF set Reset (should never happen)
                |_BV( WDIE)     // set IF (WD_vect)
                //
                |_WD_time
      ;
      //
    interrupts();
}

#endif






// PWR/SLEEP:  **********

#ifdef SLEEP_AV

/**
 *  POWER/SLEEP: 
 */
void  _sleepMode(){
  //
  noInterrupts();//cli
  //
    set_sleep_mode( SLEEP_MODE_ADC);
    //
    sleep_enable();
    sleep_bod_disable();
      //
      interrupts();//sti ->  WDT_vect
      //
      sleep_cpu();
      sleep_disable();
  //
}

#endif











/* SERIAL:  *************/



/**
 * Serial: data in Evt
 */


void serialEvent(){
  //
  int   _m=Serial.available();
  char  _c=0;
  int   _i=0;
    //

#if defined( OS_DEBUG_SIO_AV)
  if (OS_param0.dbg){
    //
    Serial.print( "--got(");
    Serial.print( _m);
    Serial.println( ")by--");
  }
#endif

    //
    for ( ;_i<_m; _i++){
      //
      _c=(char)Serial.read();

      //
  #ifdef COM_AV

      COM_serialParser( _i, _c);

  #endif      
    }//loop



}//










/* MAIN: ***************/






/**
 *  INITIALISATION
 */
//
void setup() {
  //
  // OS
  //
  OS_loop0      =true;
  OS_loop_delay =1;
  //
  OS_loop_tdown =0;
  OS_loop_tasks =0;
  //
  OS_msx_state  =false;
  
  OS_param0.dbg     =OS_debug;
  //
  OS_param0.vis     =false;
  OS_param0.put     =false;
  //
  OS_param0.percent =50;
  OS_param0.sensor  =OS_msx_sensor;
  OS_param0.led     =false;
  
  
  /* WOT:!! ll cause system reboot!!
#ifdef  ISR_WDT  
  wdt_disable();
#endif
  */
  //
#ifdef TWI_AV
  //
  TWI_setup( 0);
  //
#endif

#ifdef SPI_AV
  //
  SPI_setup( 0);
  //
#endif



  // LED: test
#if defined(LED_AV)
  //
  pinMode( _LED0.pin, OUTPUT);
  _LED_sw( 0, false);
  //
#endif


  // LED: test
#if defined(ADC_AV)
  //
  ADC_setup();  
  //
#endif




  // Vis: modeselect
#ifdef PIN_AV

#ifdef LCD_HD44780_AV
#ifdef LCD_HD44780_PIN_AV
  pinMode( PIN_MS_LCD_8X2_EMU, INPUT_PULLUP);
#endif

//LCDPwm
#ifndef LCD_HD44780_SHARE_WR
    pinMode( PIN_MS_DA_00, INPUT_PULLUP);
    pinMode( PIN_MS_DA_99, INPUT_PULLUP);
#endif

#endif

#ifdef PIN_328_AV
#ifdef MSX_PIN_AV
  // Sensor
  pinMode( PIN_MS_SENSOR, INPUT_PULLUP);
  //
  pinMode( PIN_MS_DEBUG, INPUT_PULLUP);
#endif
#endif

#endif


  // PCM: [DAC]
#if defined(PWM_AV)

   PWM_setup();

#endif

  //Flash
#if defined(FLASH_AV)

  #if defined( FLASH_FS_AV)


  //LittleFS.begin();
  FS_setup();


#endif
#endif



 //EEP
  // [E]Eprom
#ifdef EEP_AV

#endif



// 
 

// com[mand]:
#ifdef COM_AV

  CMD_setup( 0);

#endif



  // Serial
#ifdef SIO_AV

  SIO_setup(); 
   OS_str_BaddC( SO_line, -1, _tx_logo, SO_LINE_MAX);
   OS_str_BaddC( SO_line, -1, _tx_vers, SO_LINE_MAX);
      SIO_println();
      
#endif







/// old Bulk!!




 

#if defined( TWI_AV)
//
#if defined( TWI_SCAN_AV)

   TWI_scanner( true);

#endif
#endif



  // -- LCD
#ifdef VIS_AV
  #ifdef LCD_HD44780_SHARE_WR
    pinMode( PIN_LCD_WR, OUTPUT);
    digitalWrite( PIN_LCD_WR, LOW);
  #endif

#ifdef LCD_HD44780_AV
#ifdef LCD_PIN_AV
      _VIS0_emu=(digitalRead( PIN_MS_LCD_8X2_EMU)==LOW);
      //
#endif
#endif

      OS_str_clr( vis_line);
      _VIS0_has=true;
      _VIS_cmd( 0);
      _VIS_setup( 0);
      //
      #if defined( SIO_AV)
         Serial.print(  _tx_vis_nul);
         Serial.println( (char*)_VIS0_head);      
      #endif
      
      
          OS_str_clr( vis_line);
          //
          OS_str_BaddC( vis_line, -1, _tx_logo, VIS_LINE_MAX);
          OS_str_BaddC( vis_line, -1, _tx_vers, VIS_LINE_MAX);
          //
          _VIS_print( 0, true, 0, VIS_ACT_NEW, OS_init_delay);
          //


#endif


  // -- Sensoric
#ifdef MSX_AV
  //
  _MSX_setup( 0);
  //
#endif







  // OS Bulk
OS_bulk.t.has=false;
#if defined( OS_STORE_AV)

  OS_str_BaddC( SO_line, -1, _tx_store, SO_LINE_MAX);
  bool _hasStore=false;
  //Flash
  #if defined(FLASH_AV)

    #if defined( FLASH_FS_AV)

  OS_str_BaddC( SO_line, -1, _tx_FS, SO_LINE_MAX);
  if (FS0.has){
    //
    OS_str_BaddC( SO_line, -1, FS_bulk_file, SO_LINE_MAX);
    _hasStore=FS_loadValues( true);
    if (!_hasStore){
      //
      _hasStore=FS_saveValues();
      //
    }//!exists
  }
  else{
    if (!FS0.hasFmt){
      OS_str_BaddC( SO_line, -1, _tx_notexists, SO_LINE_MAX);
    }
    OS_str_BaddC( SO_line, -1, _tx_novalue, SO_LINE_MAX);
  }


  #endif//FS


  // Eprom
  //
  #elif defined( EP_AV)

    //
    OS_str_BaddC( SO_line, -1, _tx_EP, SO_LINE_MAX);
    _hasStore=EP_loadValues( true);
    if (!_hasStore){
      //
      _hasStore=EP_saveValues();
    }

#else
      //

#endif

    //
#ifdef SIO_AV
    //
    if (_hasStore){
      OS_str_BaddC( SO_line, -1, _tx_ok, SO_LINE_MAX);
    }
    else{
      //
      OS_str_BaddC( SO_line, -1, _tx_err, SO_LINE_MAX);
    }
    SIO_println();
#endif
    //
#endif








    

//APPLICATION_START: <- void setup( _ix)
  #ifdef API_AV
/*D*/#if defined( OS_SIO_DEBUG_AV)
    Serial.println( ">api:setup");
#endif

    // WOT for installation of Apps
    //
    API_install_WOT();

    //
    //
    API_setup( 0);
  #endif
//APPLICATION_END: <- void setup( _ix)


}






/**
 * Loop::Task
 */
//
void loop() {

 
  OS_param0.vis     =true;
  OS_param0.sensor  =true;
  //
 

#ifdef PIN_AV

#if defined( MSX_PIN_AV)
   int8_t   _SN    =digitalRead( PIN_MS_SENSOR);
   int8_t  _DBG    =digitalRead( PIN_MS_DEBUG);
   // debug: select
  if (_DBG==LOW){
    //
    OS_parm0.dbg=true;
  }
  if (_SN==LOW){
    OS_parm0.sensor=true;
  }
#endif
    

#endif


 

  //  visual: selcet
#ifdef LCD_AV
  #ifdef LCD_PIN_AV
    int8_t _EMU  =(digitalRead( PIN_MS_LCD_8X2_EMU)==LOW);
  #else
    int8_t _EMU  =LCD_HD44780_EMU_AV;//<-- static.
  #endif
#endif

  // peripherie: select
  //
  // Pin(hard) ~ select
#ifdef PWM_AV

  #ifdef PIN_AV
    int8_t _Pwm=1;
    int8_t _DA_NUL;
    int8_t _DA_00;
    int8_t _DA_99;

  #ifdef LCD_PIN_AV
    #ifndef LCD_HD44780_SHARE_WR
    _DA_NUL   =digitalRead( PIN_MS_DA_NUL);
    _DA_00    =digitalRead( PIN_MS_DA_00);
    _DA_99    =digitalRead( PIN_MS_DA_99);
    _vis_ms_setup= ~(_DA_00 | _DA_99<<1) & 0x03;
    #endif
    _DA_NUL   =LOW;
    _DA_99    =LOW;
    _vis_ms_setup= ~(_DA_NUL | _DA_99<<1) & 0x03;
    #endif
#endif

#endif



  //
  // Parameter xchange
  // !!Needs to be solver/changed
  //


/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">setup");
#endif

  // internal: loop counter
  bool _task=false;
  if (OS_nobreak){
    _task=(OS_loop_i++)>OS_loop_put;
  }
  else{
    _task=(OS_loop_i++)>OS_loop_max;
  }
  if (_task){
    //
    OS_loop0=false;
    if (OS_loop_tdown>0){
      OS_loop_tdown--;
    }
    OS_loop_tasks++;
    //
    OS_loop_i=0;
    //
  }//<-- counter

  

  // !WOT ---> PWM: DAC(SPS) 
#ifdef PWM_AV
  #if defined( PIN_AV ) & defined(PWM_AD_AV)
  if (_DA_NUL==LOW){
      //
      _PWM_DAC_null=PWM_DAC_LOW;
   }
   else{
      //
      _PWM_DAC_null=PWM_DAC_NONENULL;
   }
   #endif
#endif



// Visual
#ifdef VIS_AV
  //   
  if (_VIS0_Refresh){
      //
/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">vis:refresh");
#endif

      _VIS_setup( 0);
      _VIS0_Refresh=false;
      _VIS0_Refreshed=true;
      //
  }
#endif

  // sensoric
  //
  if ( OS_param0.sensor){
    //
/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">msx?");
#endif

    // check 
#if defined( MSX_AV)
    _MSX0_Values=false;
    if (_MSX0_Has){
      //
/*D*/#if defined( OS_SIO_DEBUG_AV)
    Serial.println( ">msx:has");
#endif

#if defined( LED_AV) & defined( LED_MSX_AV)
      _LED0.has=false;
      _LED0.count=1;
#endif
      //
      // measure: update!
      if (!OS_msx_state){
        OS_msx_state=true;  
        //
#if defined(BMP_280_AV)
  #if defined( ADF_P280_AV)
        _MSX0_Values=BMP0_280.begin( _MSX0_i2c);
        //_MSX0_Values=BMP0_280.takeForcedMeasurement();//<-- WOT:  taskForcedRead
        //
  #endif
#endif

#ifdef BME_280_AV
#ifdef  JWA_E280_AV      
        _MSX0_Values=BME0_280.measure();
#endif
#ifdef  ADF_E280_AV
        _BME_Values=BME0_280.init();
#endif
#endif
        //
        if (!_MSX0_Values){
          //
#if defined(LED_AV) & defined(LED_MSX_AV)
          _LED0.has=true;
          _LED0.count=3;
#endif
          OS_loop_delay=OS_DELAY_FAST;
          //
          _MSX0_Has=false;
        }
        //
      }//measure:update
    }
    else
#endif
    {
    //
    // PWM: test select 
#ifdef PWM_AD_AV      
        OS_loop_delay=OS_DELAY_FAST;//LED_TIME_FAST;
#endif
      #ifdef PIN_AV
        _Pwm=PWM_DAC_HIGH;
      #endif
#if defined( LED_AV) & defined( LED_MSX_AV)
        _LED0.count=5;//x
#endif

    

      // TWI: scan
  #if defined(TWI_AV) & defined( TWI_SCAN_AV)

#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">twi:scan?");
#endif
      if (OS_loop_i==2){//<-- !WOT:: prevent to scan @ stasrt!
        //
        TWI_scanner( false);
        //
      }
  #endif

      //
      // MSX: check on iLoop==1 -> values also ..
      if (OS_loop_i==1){ 
        
        //
        OS_msx_state=false;
        //
  #if defined( MSX_AV)

/*D*/#if defined( OS_SIO_DEBUG_AV)
    Serial.println( ">msx:setup!");
#endif
        _MSX0_Has=_MSX_prepare( 0);//MSX->0
        if (!_MSX0_Has){
          //
  #if defined( LED_AV) & defined( LED_MSX_AV)
        _LED0.has=true;
          _LED0.count=2;
  #endif
          //
          OS_loop_delay=OS_DELAY_FAST;
          //
        }
        else
  #endif
            {
          //
  #if defined( LED_AV) & defined( LED_MSX_AV)
          _LED0.has=false;
          _LED0.count=1;
  #endif
        }
      }//loop==1

      //
    }//noMSX

  }//sensor
 


//APPLICATION_START: <- void prepare( _ix)
  #ifdef API_AV
/*D*/#if defined( OS_SIO_DEBUG_AV)
    Serial.println( ">api:prepare");
#endif
    API_prepare( 0);
  #endif
//APPLICATION_END: <- void prepare( _ix)





  // 1.) delayed visual with Loop==1(0-12 oe.)
  //
  if (OS_loop_i==0){
    //
/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">os:loop=0");
#endif
    //
  #if defined( LED_AV) & defined( LED_MSX_AV)
    _LED0.has=true;
  #endif
    OS_loop_delay=OS_DELAY_SLOW;

    // rotate
    //
  #if defined(VIS_AV)
    bool _msx_clr=false;
    int _rotate_sn=_vis_msx_setup & VIS_MS_SN;
    if (_rotate_sn==0){
      //
      _vis_msx_rotate++;
      if (_vis_msx_rotate>_vis_msx_rotate_M){
        //
        _vis_msx_rotate=++_rotate_sn;
        //
        _msx_clr=!_MSX0_Has;
      }
    }
    else{
      //
      _vis_msx_rotate=_vis_msx_setup;
      _msx_clr=!_MSX0_Has;
    }
    //
        if  (_msx_clr){
          //
          _VIS_cls( 0, 100);
        }//



  #endif
    //
    //
#ifdef VIS_AV
    //
    if ((_vis_wot_i++)>_vis_wot_m){
      //
      _vis_wot_i=0;
      if (_VIS0_RefreshForced){
        //
        _VIS0_Refresh=!_VIS0_Refreshed;
      }
      else{
        if (_VIS0_chk_TWI){
          //
  #if defined(TWI_AV)
          _VIS0_has=TWI_port( _VIS0_i2c);
          if (_VIS0_has!=_VIS0_had){
            //
            _VIS0_Refresh=true;
          }
  #endif
        }
      }
      //
    }
#endif




// APPLICATION_START:  <- void task( _ix)
#ifdef API_AV
/*D*/#if defined( OS_SIO_DEBUG_AV)
   Serial.println( ">api:task");
#endif
    API_task( 0);
#endif
//APPLICATION_END: <- task( _ix)




  }// iLoop==1



  // 2.) prompt visual each loop
  //

  // OS_loop: <- API[ix].refresh()
  //
  if (OS_loop_refresh){
    OS_loop_refresh=false;
     //
     //
     OS_loop_delay=1;


// APPLICATION_START: <- void refresh( _ix)
  #ifdef API_AV
/*D*/#if defined( OS_SIO_DEBUG_AV)
    Serial.println( ">api:refresh");
#endif
    API_refresh( 0);
  #endif
// APPLICATION_END: <- void refresh( _ix)

  }//




//APPLICATION_START: <- void loop( _ix)
  OS_param0.put=OS_loop_i<=OS_loop_put;
  #ifdef API_AV
/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">api:loop"); 
#endif
    API_loop( 0);
  #endif
//APPLICATION_END: <- void loop( _ix)
  

 
  // LED+ Delay:
#if defined( VIS_AV)
  if (OS_loop_tdown>0){
    //
    OS_loop_delay=5;
  }  
#endif

  //
#if defined( LED_AV) & defined( LED_MSX_AV)
  if (_LED0.has){
    //
    if (_LED0.hasAuto){
      if (OS_loop_i<_LED0.count){
        _LED_sw( 0, true);
      }
      else{
        _LED_sw( 0, false);
      }
    }
    else{
      _LED_sw( 0, true);
    }
  }
  else{
      _LED_sw( 0, false);
  }
#endif
  //
  //
/*D*/#if defined( OS_SIO_DEBUG_AV)
  Serial.println( ">os:loop>end");
#endif

  OS_delay( OS_loop_delay);

  //  ISR..   
    //
    //_delaySetWD( _PwmB, _time, _LED0.has);
    //_LedAT_SW=true;
    //wdt_reset();
    //wdt_enable( WDTO_500MS);
    
    //  _delay_us( 250);
    //  _sleepMode();
  //
  

}
