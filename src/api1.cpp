/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api1.h>




/* Statische Definitions */


/* Dynamische Definitions */

/*
API_set_t      API1{
                false
                ,false
                //
                ,50//%
                //
                ,true
};
*/


 bool       _hasML
        ;

 int        _visStyle
            ,_visLine
          
        ;

  

/* Routine Definitions */


/*!
 * ....
 */
void  API1_prepare(){

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
 * each wait stop 
 */
void  API1_task(){


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
        OS_param0.vis=false;
    }//has-had 
  #endif


    // SIO: parameter out
  #ifdef SIO_AV
    if ((OS_param0.vis)
       &(SO_para)
       ){
        // head:
//Serial.println( "S::Task");
        SO_line="";
        //
      #ifdef SIO_SESTU_AV
        if (SeStu0.v){
          SO_line.concat( SeStu0.B);
          SO_line.concat( _tx_logo);
          SO_line.concat( SeStu0.H);
        }
      #if defined( MSX_AV)
        else{
          SO_line.concat( _tx_msx_head);
        }
      #endif
      #endif 

      #if defined( MSX_AV)
        if (_MSX0_Has){
          // T
            SO_line.concat( _MSX_sn0.T);//_T0);
          SO_line.concat( SO_csv);
          
          // P
            SO_line.concat( _MSX_sn0.P);//_P0);
          SO_line.concat( SO_csv);
          
          // F
            SO_line.concat( _MSX_sn0.F);//_F0);
        }
        else
      #endif
        {
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
 *  visual/mesure/check refresh
 */
void  API1_refresh(){
   //
  #ifdef VIS_AV
     OS_loop_tdown=_vis_ms_rotate_M+1;
  #else
     OS_loop_tdown=2;
  #endif


}

/*!
 *  each delay
 */
void  API1_loop(){
   //
   
  // vis:[blink]put
  if ((OS_param0.vis)
     &(OS_param0.put)
      ){
    // msx
    OS_msx_state=false;// next update!
    // vis
  #if defined( VIS_AV)
    //

  #ifdef MSX_AV
    if  (_MSX0_Has!=_MSX0_Had){
      //
      vis_line="";      
      //
      if (_MSX0_Has){
        vis_line.concat(_MSX_0.head);
        vis_line.concat(_tx_msx_on);
        vis_line.concat(_MSX_0.i2c);
      }
      else{
        vis_line.concat(_tx_msx_off);
      }
      int _style=_visStyle&VIS_ACT_CLR;
          _style|=VIS_ACT_NEW;
      _VIS_print( 0, true, 0, _style, -1);
      //
      //
      OS_param0.vis=false;
    }//has-had
    else
  #endif
        {
      if ((OS_loop_tdown<=0)
  #ifdef MSX_AV
         &(_MSX0_Has)
  #endif
         ){
        _VIS_cls( 0, 0, _visStyle, -1);
      }
    }

    // rotate/single
    //
    bool _huge=false;
    if (_vis_ms_setup!=VIS_MS_AUTO){
      //
      _visLine=1;
      _visStyle&=VIS_FNT_CLR;
      _visStyle|=VIS_FNT_HGE;
      //
      _huge=true;
    }
    else{
      #if defined(TFT_AV)
        _visStyle&=VIS_FNT_CLR;
        _visStyle|=VIS_FNT_BIG;
      #endif
      //
      _visLine=_vis_ms_rotate;
    }

    

    // fetch vis_line
    vis_line="";      
    //
    if ((OS_param0.vis)
       &(OS_param0.sensor)
        ){
        //
  #if defined( MSX_AV)
        if (_MSX0_Has){  
            // select value to put
            if        (_vis_ms_rotate==1){
                // T
              #if defined(TFT_AV)
                if (!_huge){              
                  vis_line.concat( "T ");
                }
                else{
                  vis_line.concat( "Temp.:\n");
                }
              #else
                vis_line.concat( "T ");
              #endif
                vis_line.concat( _MSX_sn0.T);//_T0);
                vis_line.concat( 'C');
            }
            else if (_vis_ms_rotate==2){
                //
              #if defined(TFT_AV)
                if (!_huge){              
                  vis_line.concat( "P ");
                }
                else{
                  vis_line.concat( "Pressur:\n");
                }
              #else
                vis_line.concat( "P ");
              #endif 
                vis_line.concat( _MSX_sn0.P);//_P0);
                vis_line.concat( "mB");
            }
            else if (_vis_ms_rotate==3){
                //
              #if defined(TFT_AV)
                if (!_huge){              
                  vis_line.concat( "H ");
                }
                else{
                  vis_line.concat( "Humi.:\n");
                }
              #else
                vis_line.concat( "H "); 
            #endif
                vis_line.concat( _MSX_sn0.F);//_F0);
                vis_line.concat( '%');
          }
          else{
                //
                vis_line.concat( "X ");
                vis_line.concat( _tx_novalue);
          }
        }
        // no SN[values]
        else{
            // -:-
           vis_line.concat( "MSX");
            #if defined(TFT_AV)
                if (_huge){
                  vis_line.concat( ": ..\n^-");              
                }
            #endif
            vis_line.concat( " ~off_?");
        }//
      //
    #else 
           vis_line.concat( "MSX");
            if (_huge){
                  vis_line.concat( ": ..\n^-");              
            }
            vis_line.concat( " ~off_?");
    #endif
  
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