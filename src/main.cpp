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



// LOOP[ix]




// DATA_RING[ix]
#ifdef RP_AV

int                    RP_pos_adr;
int                    RP_data_adr;

int                    RP_data_delta;     // <-4


#endif






// Command:
#ifdef COM_AV

#endif




// AN[0]  
#ifdef ANX_AV 
int                 _AN0_count    = 0;
int                 _AN0_time     = 1000;
#endif




/*** COMMAND: needed implant form abstract definition ***/
#ifdef COM_AV



/*!
 *@param _  act. com[] set
 */
COM_set_t  _COM_execute( COM_set_t _){
  //
  switch( _.ix){

default:

    break;
  }
  //
  return _;
}




#endif





/*** [inner]EProm: needed implant form abstract definition ***/
//#ifdef EP_AV


  /** insert fillxxx  meth. with std/load/save values! ***/

          void _OS_fillStdValues(){ 
            //
            OS_debug                = false;
            OS_nobreak              = false;
            OS_loop_max             = OS_LOOPS;
            //
            _vis_ms_setup          = VIS_MS_AUTO;//(rotate)
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
            pwm_f_0               = PWM_F0_0;
            pwm_f_M               = PWM_F0_M;
        #endif
        #endif
        #endif
            //
            SO_para               = true;
            //SO_sestu              = false;
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
            OS_bulk.t.vis_ms_setup = _vis_ms_setup;
            //
        #ifdef PWM_AV
        #ifdef PWM_328_AV
            OS_bulk.t.pwm_dac_nul = _PWM_DAC_null;
        
        #ifdef PWM_AD_AV
            OS_bulk.t.pwm_t_0     = pwm_t_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_t_M     = pwm_t_M;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_p_0     = pwm_p_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_p_M     = pwm_p_M;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_f_0     = pwm_f_0;//*EP_DOUBLE_DIV;
            OS_bulk.t.pwm_f_M     = pwm_f_M;//*EP_DOUBLE_DIV;
        #endif
        #endif
        #endif
            //
            OS_bulk.t.SO_para     = SO_para;
        #ifdef SIO_SESTU_AV
            //EP_bulk.t.SO_sestu    = SO_sestu;
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
            _vis_ms_setup       = OS_bulk.t.vis_ms_setup;
            //
        #ifdef PWM_AV
        #ifdef PWM_328_AV
            _PWM_DAC_null       = OS_bulk.t.pwm_dac_nul;
            
        #ifdef PWM_AD_AV
            pwm_t_0             = OS_bulk.t.pwm_t_0;///EP_DOUBLE_DIV;
            pwm_t_M             = OS_bulk.t.pwm_t_M;///EP_DOUBLE_DIV;
            pwm_p_0             = OS_bulk.t.pwm_p_0;///EP_DOUBLE_DIV;
            pwm_p_M             = OS_bulk.t.pwm_p_M;///EP_DOUBLE_DIV;
            pwm_f_0             = OS_bulk.t.pwm_f_0;///EP_DOUBLE_DIV;
            pwm_f_M             = OS_bulk.t.pwm_f_M;///EP_DOUBLE_DIV;
        #endif
        #endif
        #endif
            //
            SO_para             = OS_bulk.t.SO_para;//
        #ifdef SIO_SESTU_AV
            SeStu0.v            = OS_bulk.t.SO_sestu;//
        #endif
          }



//#endif








/************************************ ROUTINES *************************************/




#ifdef  DATA_RING_AV





#endif







// ISR:   ************

#ifdef ISR_ANX

  /** AComp0
   */
  ISR( ANALOG_COMP_vect  ){
    //
    // system should restart.
    // loop should repeat.
    //
    if (_AN0_count<_AN0_time){
      //
      _AN0_count=0;
    }
    else{
      //
      _AN0_count++;
    }
  }

#endif

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


//  ANx:  ************

#ifdef ISR_ANALOG

/**
 *  AN0:
 */
void  _setAN(){
    //
    int _x=0;
    noInterrupts();
      // wrt
      _x = // _BV( ACD)
           //|_BV( ACBG)
           //|_BV( ACIC)
           //|_BV( ACIS0)
           _BV( ACIE)
          |_BV( ACIS1)
      ;
      ACSR = _x;      
      // 
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
#if defined(SIO_AV)

#if defined(SIO_IRQ_AV)

/*!
 * Serial: data in Evt
 * normally triggered with serial input[usbser]
 */
void serialEvent(){
  CheckSerial();
}

#endif


/*!
 *  check for Seril[0] content <- com channel!
 */
void CheckSerial(){
  //
  int   _m=Serial.available();
  if (_m>0){
    //
    char  _c=0;
    int   _i=0;
    //

#if defined( OS_DEBUG_SIO_AV)
    if (OS_debug){
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
      //
      COM_serialParser( _i, _c);
  #endif      
    }//loop
  }//has
}//checkSerial


#endif



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
  TWI_setup();
#endif

#ifdef SPI_AV
  SPI_setup();
#endif


  // LED: test
#if defined(LED_AV)
  //
  pinMode( _LED0.pin, OUTPUT);
  _LED_sw( 0, false);
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
#ifdef PWM_328_AV

#ifdef PWM_PIN_AV
  // PWM: DAC->STD/+NULL
   pinMode( PIN_MS_DA_NUL, INPUT_PULLUP);
#endif

#if defined(PWM_AV) & defined(PWM_328_AV)
#ifdef PWM_AD_AV

  // VCOM[outclk]
  pinMode( PIN_AN0_VCOM, OUTPUT);     // --> AIN1 = (PWM out [~1kHz])
  analogWrite( PIN_AN0_VCOM, 100);

  //
  pinMode( PWM_PIN_DAC_T, OUTPUT);
  pinMode( PWM_PIN_DAC_P, OUTPUT);
  pinMode( PWM_PIN_DAC_F, OUTPUT);
    //
    _PWM_DAC_null=0;
    _PWM_setTestDAC( _PWM_DAC_null);
#elif PWM_FORIGN_AV
#else
    _PWM_setTestDAC( 0.5);
#endif

#endif
#endif


  // PWM??
#ifdef ISR_ANX
  _setAN();
#endif
  


// com[mand]:
#ifdef COM_AV

  com_ai=0;

#endif



  // Serial
#ifdef SIO_AV
  if (SIO_setup()){
    //
    SO_line.concat( _tx_logo);
    SO_line.concat( _tx_vers);
      Serial.println( SO_line);
  }
  SO_line="";

#endif


  // OS Bulk
#if defined( OS_STORE_AV)
OS_bulk.t.Valid=true;// bulk -> valid(load/save)
    

  //Flash
#if defined(FLASH_AV)

  #if defined( FLASH_FS_AV)

  if (FS_setup()){
    //
#if defined( SIO_AV)
    SO_line.concat( FS_bulk_file);
#endif
    // !exists
    if (!FS_existsValues()){
      //
      if (FS_saveValues()){
        //
#if defined( SIO_AV)
        SO_line.concat( TX_SET);
#endif
      }
      else{
        //
#if defined( SIO_AV)
        SO_line.concat( TX_FAULT);
#endif
      }
      //
    }
    // has!
    else{
      if (FS_loadValues( true)){
        //
#if defined( SIO_AV)
        SO_line.concat( TX_INIT);
#endif        
      }
      else{
        //
#if defined( SIO_AV)
        SO_line.concat( _tx_novalue);
#endif        
      }
    }
  }//is
  else{
    //
#if defined( SIO_AV)
    SO_line.concat( _tx_notexists);
#endif    
  }
#if defined( SIO_AV)
    Serial.println( SO_line);
    SO_line="";  
#endif    

  #endif

#endif

  // Eprom
#if defined( EP_AV)

  if (EP_GET_ATSTART){
    //
    SO_line="";
    if (EP_loadValues( true)){
      //
#ifdef SIO_AV
      SO_line.concat( EP_GET_INIT);
#endif
    }
    else{
      //
#ifdef SIO_AV
      SO_line.concat( EP_PREM_N);
      SO_line.concat( _tx_novalue);
#endif
    }
  }
#endif

#elif
    //
#ifdef SIO_AV
    SO_line.concat( TX_STORE);
    SO_line.concat( _tx_notexists);
    Serial.println( SO_line);
    SO_line="";
#endif    
    //
#endif

  //EEP
  // [E]Eprom
#ifdef EEP_AV

#endif


#if defined( TWI_AV) & defined(TWI_SETUP_SCAN_AV)
   //
   TWI_scanner( true);
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

      _VIS0_has=true;
      _VIS_setup( 0);
      //
      OS_delay(100);

          vis_line="";
          vis_line.concat( _tx_logo);
          vis_line.concat( _tx_vers);
          _VIS_print( 0, true, 0, VIS_ACT_NEW, OS_init_delay);
          //


#endif


  // -- Sensoric
#ifdef MSX_AV
  //
  _MSX_init( 0);
  //
#endif



  // LCD/OLED/VLED
#ifdef VIS_AV
    vis_line="";
    vis_line.concat( SO_line);
    _VIS_print( 0, true, -1, com_lineDelay);

#endif
    //
    


}






/**
 * Loop::Task
 */
//
void loop() {

  // LOOP needed
  //
  
  OS_param0.vis     =true;
  OS_param0.sensor  =true;
  //
 
#ifdef PIN_AV

#ifdef MSX_PIN_AV
   int   _SN    =digitalRead( PIN_MS_SENSOR);
   int  _DBG    =digitalRead( PIN_MS_DEBUG);
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

  //  eachLoop setted!!

  //  visual: selcet
#ifdef LCD_AV
  #ifdef LCD_PIN_AV
    int _EMU  =(digitalRead( PIN_MS_LCD_8X2_EMU)==LOW);
  #else
    int _EMU  =LCD_HD44780_EMU_AV;//<-- static.
  #endif
#endif

  // peripherie: select
  //
  // Pin(hard) ~ select
#ifdef PWM_AV

  #ifdef PIN_AV
    int _Pwm=1;
    int _DA_NUL;
    int _DA_00;
    int _DA_99;

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





  // internal: loop counter
  bool _over=false;
  if (OS_nobreak){
    _over=(OS_loop_i++)>OS_loop_put;
  }
  else{
    _over=(OS_loop_i++)>OS_loop_max;
  }
  if (_over){
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

  

  // PWM: DAC(SPS) null level(0V) / plus level(20% = 2V / 4mA)
#ifdef PWM_AV
  if (_DA_NUL==LOW){
    //
#ifdef PWM_AD_AV
    _PWM_DAC_null=_PWM_getLevel( PWM_DAC_NONENULL, 0);
    OS_loop_delay=LED_TIME_FAST;
#endif
  }
  else{
    //
#ifdef PWM_AD_AV
    _PWM_DAC_null=0;
#endif
  }
#endif


#ifdef VIS_AV
  //   
  if (_VIS0_Refresh){
      //
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
    // check 
#if defined( MSX_AV)
    _MSX0_Values=false;
    if (_MSX0_Has){
      //
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
          _LED0.count=3;//_LedB=3;//x
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
    //          _  .. 99%/0% or NUL ->(0%/20%)
#ifdef PWM_AV
      if      (_DA_99==LOW){ 
        //
#ifdef PWM_AD_AV      
        OS_loop_delay=LED_TIME_FAST;
#endif
        _Pwm=PWM_DAC_HIGH;
#if defined( LED_AV) & defined( LED_MSX_AV)
        _LED0.count=5;//x
#endif
      }
#ifdef LCD_HD44780
#ifndef LCD_HD44780_SHARE_WR
      else if (_DA_00==LOW)
#endif
#else  
      else
#endif
      {
      //
#if defined(PWM_AD_AV)      
        OS_loop_delay=OS_DELAY_FAST;
#endif
        _Pwm=PWM_DAC_HIGH;
#if defined( LED_AV) & defined( LED_MSX_AV)
        _LED0.count=3;//x
#endif
      }
#else
      //
#if defined( LED_AV) & defined( LED_MSX_AV)
      _LED0.count=3;//
#endif
      //
      OS_loop_delay=OS_DELAY_FAST;
#endif
      //
      // MSX: check on iLoop==1 -> values also ..
      if (OS_loop_i==1){ 
        
  #if defined(TWI_AV) & defined( TWI_SCAN_AV)
        TWI_scanner( false);
  #endif
        //
        OS_msx_state=false;
        //
  #if defined( MSX_AV)
        _MSX0_Has=_MSX_setup( 0);//MSX->0
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
    API_prepare( 0);
  #endif
//APPLICATION_END: <- void prepare( _ix)





  // 1.) delayed visual with Loop==1(0-12 oe.)
  //
  if (OS_loop_i==0){
    //
    //
  #if defined( LED_AV) & defined( LED_MSX_AV)
    _LED0.has=true;
  #endif
    OS_loop_delay=OS_DELAY_SLOW;

    // rotate
    //
    int _rotate_sn=_vis_ms_setup & VIS_MS_SN;
    if (_rotate_sn==0){
      //
      _vis_ms_rotate++;
      if (_vis_ms_rotate>_vis_ms_rotate_M){
        //
        _vis_ms_rotate=++_rotate_sn;
      }
    }
    else{
      //
      _vis_ms_rotate=_vis_ms_setup;
    }
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
    API_refresh( 0);
  #endif
// APPLICATION_END: <- void refresh( _ix)

  }//




//APPLICATION_START: <- void loop( _ix)
  OS_param0.put=OS_loop_i<=OS_loop_put;
  #ifdef API_AV
    /*
    if (OS_loop_i<=OS_loop_put){
      //
    }//>0-tX loop
    */
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


#if defined(SIO_AV) & !defined(SIO_IRQ_AV)

  CheckSerial();

#endif
  //
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
