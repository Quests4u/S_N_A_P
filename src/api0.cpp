/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api0.h>




/* Statische Definitions */


/* Dynamische Definitions */


API_set_t      API0{
                false
                ,false
                //
                //,0//0
                ,50//%
                //
                ,true
};

 bool       _hasML
        ;

 int        _visStyle
            ,_visLine
          
        ;

  /*
  float    _T0
          ,_P0
          ,_F0
        ;
  */

/* Routine Definitions */


/*!
 * ....
 */
void  API0_prepare( int _ix){

   _hasML    =_VIS0_D.hasML;
   _visStyle =_VIS0_F.style;
   _visLine  =1;

  //  DAC: (BME ON && VALUES)  PWM 0-2: Values -> T0,P0,F0
  //
#ifdef MSX_AV
  if (_MSX0_Values){
    //
     if (_MSX_read( 0)){
      //
    }
    else{
      //
      Serial.println( "..msx:false!");
      _MSX0_Values=false;
    }
   //
#ifdef PWM_AV
    _PWM_setDAC( _T0, _P0, _F0);
    
#endif
  }
  // no value/no MSX
  else
#endif
      {
    //
    //  PWM:  -> jumpe setup to PWM0-2
  #ifdef PWM_AV
  #ifdef PWM_328_AV
    _PwmValue=_PWM_setTestDAC( _Pwm);
  #ifdef PWM_AD_AV
    //
    _T0 = _Pwm/100.0*(pwm_t_M-pwm_t_0)+pwm_t_0;
    _P0 = _Pwm/100.0*(pwm_p_M-pwm_p_0)+pwm_p_0;
    _F0 = _Pwm/100.0*(pwm_f_M-pwm_f_0)+pwm_f_0;
    //
    pwm_t_value=_PwmValue;
    pwm_p_value=_PwmValue;
    pwm_f_value=_PwmValue;
    //
  #else
    _T0 = 25.0;
    _P0 = 1000.0;
    _F0 = 50.0;
    _LedB= 5;
  #endif
  #else
    _PwmValue=50;
  #endif
  #endif
    //
  }


  //
#ifdef VAL_ALYS
  // relativ werte abnahme
  dTx+=Tx-_T0;
  dPx+=Px-_P0;
  dFx+=Fx-_F0;
#endif  


}

/*!
 * ....
 */
void  API0_task( int _ix){

    // analysis parameter
  #ifdef VAL_ALYS
    xCount++;

    if (xCount==MCount){
        //
        xCount=0;
        //
        dTdif=dTx/xLimit;
        dPdif=dPx/xLimit;
        dFdif=dFx/xLimit;
        //
        dTx=0;
        dPx=0;
        dFx=0;
    }
  #endif

    
    // MSX Check
  #ifdef MSX_AV
    if (_MSX0_Has!=_MSX0_Had){ 
        // measure broke:
  #ifdef VIS_AV
        OS_loop_refresh=true;
  #endif
        // S0:
          if (_MSX0_Has){
            Serial.print( _MSX_0.head);
            Serial.print( _tx_msx_on);
            Serial.print( SO_hex);
            Serial.println( _MSX0_i2c, HEX);
          }
          else{               
            Serial.println( _tx_msx_off);
          }
        //
        _MSX0_Had=_MSX0_Has; //-> clear
        //
        API0.vis=false;
    }//has-had 
  #endif


    // SIO: parameter out
  #ifdef SIO_AV
    if ((API0.vis)
       &(SO_para)
       ){
        // head:
        SO_line="";
        //
      #ifdef SIO_SESTU_AV
        if (SeStu0.v){
          SO_line.concat( SeStu0.B);
          SO_line.concat( _tx_logo);
          SO_line.concat( SeStu0.H);
        }
        else{
      #ifdef MSX_AV
          SO_line.concat( _tx_msx_head);
      #endif
        }
      #endif 

        if (_MSX0_Has){
          // T
            SO_line.concat( _MSX_sn0.T);//_T0);
          SO_line.concat( SO_csv);
          
          // P
            SO_line.concat( _MSX_sn0.P);//_P0);
          SO_line.concat( SO_csv);
          
          // F
            SO_line.concat( _MSX_sn0.T);//_F0);
        }
        else{
           SO_line.concat( "-1;-1;-1"); 
        }
        //
      #ifdef SIO_AV
      #ifdef SIO_SESTU_AV
        if (SeStu0.v){
          SO_line.concat( SeStu0.E);
        }
      #endif
      #endif
        
      #ifdef SIO_AV
        // put serial
        Serial.println( SO_line);
      #endif
      //
    }//SIO: msx
#endif



}

/*!
 * ....
 */
void  API0_refresh( int _ix){
   //
  #ifdef VIS_AV
     OS_loop_tdown=_vis_ms_rotate_M+1;
  #else
     OS_loop_tdown=2;
  #endif


}

/*!
 * ....
 */
void  API0_loop( int _ix){
   //
   
  // vis:[blink]put
  if (API0.vis){
    // msx
    OS_msx_state=false;// next update!
    // vis
  #ifdef VIS_AV
    //
  #ifdef MSX_AV
    if  (_MSX0_Has!=_MSX0_Had){
      //
      vis_line="";      
      //
      if (_MSX0_Has){
        vis_line.concat(_MSX_0.head);
        vis_line.concat(_tx_msx_on);
        vis_line.concat(_MSX0_i2c);
      }
      else{
        vis_line.concat(_tx_msx_off);
      }
      int _style=_visStyle&VIS_ACT_CLR;
          _style|=VIS_ACT_NEW;
      _VIS_print( 0, true, 0, _style, -1);
      //
      //
      API0.vis=false;
    }//has-had
    else
  #endif
        {
      if ((OS_loop_tdown<=0)
  #ifdef MSX_AV
         &(_MSX0_Has)
  #endif
         ){
        _VIS_cls( 0, 0, -1);
      }
    }

    // rotate/single
    //
    if (_vis_ms_setup!=VSI_MS_AUTO){
      //
      _visLine=1;
      _visStyle&=VIS_FNT_CLR;
      _visStyle|=VIS_FNT_HGE;
    }
    else{
      _visLine=_vis_ms_rotate;
    }

    

    // fetch vis_line
    vis_line="";      
    //
    if ((API0.vis)
       &(API0.sensor)
        ){
        //
        if (_MSX0_Has){  
            // select value to put
            if        (_vis_ms_rotate==1){
                // T
                vis_line.concat( "T "); 
                vis_line.concat( _MSX_sn0.T);//_T0);
                vis_line.concat( 'C');
            }
            else if (_vis_ms_rotate==2){
                //
                vis_line.concat( "P "); 
                vis_line.concat( _MSX_sn0.P);//_P0);
                vis_line.concat( "mB");
            }
            else if (_vis_ms_rotate==3){
                //
                vis_line.concat( "F "); 
                vis_line.concat( _MSX_sn0.F);//_F0);
                vis_line.concat( '%');
            }
            else{
                //
                vis_line.concat( _tx_novalue  );
            }
        }
        // no SN[values]
        else{
            // -:-
            vis_line.concat( "-?-");
        }//
      //
    }//MSX out
    //

    // fetched line
    //
    if (_hasML){
       //
       if (OS_loop_i<OS_loop_put){
         _visStyle&=VIS_ACT_CLR;
         _visStyle|=VIS_ACT_HL;
       }
       _VIS_print( 0, true, _visLine, _visStyle, -1);
    }
    else{
      //
      _VIS_print( 0, true, 0, -1);
    }
    //
#endif
  }//[]put




}






//@