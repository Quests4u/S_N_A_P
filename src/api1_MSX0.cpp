/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api1_MSX0.h>




/* Statische Definitions */

/* Dynamische Definitions */




/* Routine Definitions */




#if  defined(ADC_AV) & defined(ADC_ANT_ISR_AV)


bool  API1_MSX_ANT_Isr( int8_t _ix){
  //
  bool _f=false;
  ANT_set_t* _an=ANTptr( _ix);
  if (_an!=NULL){
    //
    bool _sw=_an->SW;
    //
    if (_sw){
      //
      Serial.println( "<- Ux got switched!");
      _f=true;
    }
    //
  }//has
  return _f;
}


#endif






/*!
 *
 */
class API_msx0:  public ApiBase{

 private:
 

 bool       _hasML
           ,_hasUx
           ,_hasUref
           ,_hasUshow
        ;

 int16_t     _visStyle
            ,_visLine

        ;


public:



   API_msx0():
      ApiBase(){
      //
   }
   
   
   API_msx0( const char* _Title):
      ApiBase( _Title){
      //
   }




/*!
 *  one per reset
 */
virtual bool  Setup( int8_t _ix){
  //
  bool _f=false;
  
  
#if defined( ADC_AV)
  //
  _hasUshow=true;
  //
  _hasUx=_ADC_Ux->has;
  _hasUref=_ADC_Uref->has;
  _ADC_Uref->V=ADC_UREF_V;//2.00;//
  
#if defined( ADC_ANT_AV)
  //
  _ANT_c->has=true;
  _ANT_c->Polarity=false;
    _ANT_c->HX=-0.3;

    #if defined( ADC_ANT_ISR_AV)
      _ANT_c->Action=&API1_MSX_ANT_Isr;
    #endif
  ANTbegin( 0);
  
  //
  _f=true;
#endif

#else
  _hasUref=false;
  _hasUshow=false;
#endif

   return _f;
}


/*!
 *  one per all loops
 */
virtual bool  Prepare( int8_t _ix){
   bool _f=true;
   //
#if defined( VIS_AV)
   _hasML    =_VIS0_D.hasML;
   _visStyle =_VIS0_F.style;
#else
   _hasML    =false;
   _visStyle = 0;
#endif
   _visLine  =1;


  // ADC:
#if defined( ADC_AV)
    ADChandler( _ADC_Uref, true, true);
    ADChandler( _ADC_Ux, true, true);
#endif
    //

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
      _MSX0_Values=false;
    }
    //
   //
#ifdef PWM_AV
    //_PWM_setDAC( _T0, _P0, _F0);
    _PWM_setDAC( _MSX_sn0.T, _MSX_sn0.P, _MSX_sn0.H);
    
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
  #ifdef PIN_AV
   _PwmValue=_PWM_setTestDAC( _Pwm);
  #ifdef PWM_AD_AV
    //
    _T0 = _Pwm/100.0*(pwm_t_M-pwm_t_0)+pwm_t_0;
    _P0 = _Pwm/100.0*(pwm_p_M-pwm_p_0)+pwm_p_0;
    _H0 = _Pwm/100.0*(pwm_h_M-pwm_h_0)+pwm_h_0;
    //
    pwm_t_value=_PwmValue;
    pwm_p_value=_PwmValue;
    pwm_h_value=_PwmValue;
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
  #endif
    //
  }//[no]/value


  //
#ifdef VAL_ALYS
  // relativ werte abnahme
  dTx+=Tx-_T0;
  dPx+=Px-_P0;
  dFx+=Fx-_F0;
#endif  


   return _f;
}



/*!
 *  one per all loops 
 */
virtual bool  Task( int8_t _ix){
   bool _f=true;

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
          Serial.print( (char*)_MSX_0.head);
          if (_MSX0_Has){
            Serial.print( _tx_on);
            Serial.println( _MSX0_i2c, HEX);
          }
          else{               
            Serial.println( _tx_off);
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
        OS_str_clr( SO_line);
        //
      #ifdef SIO_SESTU_AV
        if (SeStu0.v){
          //
          OS_str_BaddC( SO_line, -1, SeStu0.B, SO_LINE_MAX);  
          OS_str_BaddC( SO_line, -1, _tx_logo, SO_LINE_MAX);
          OS_str_BaddC( SO_line, -1, SeStu0.H, SO_LINE_MAX);
        }
      #if defined( MSX_AV)
        else{
          //
          OS_str_BaddC( SO_line, -1, _tx_msx_head, SO_LINE_MAX);
        }
      #endif
      #endif 

      #if defined( MSX_AV)
        if (_MSX0_Has){
          // T
            OS_str_BaddR( SO_line, -1, _MSX_sn0.T, 2, SO_LINE_MAX);
               OS_str_BaddV( SO_line, -1, SO_csv, SO_LINE_MAX);
          // P
            OS_str_BaddR( SO_line, -1, _MSX_sn0.P, 2, SO_LINE_MAX);
               OS_str_BaddV( SO_line, -1, SO_csv, SO_LINE_MAX);
          // F
            OS_str_BaddR( SO_line, -1, _MSX_sn0.H, 2, SO_LINE_MAX);
        }
        else
      #endif
        {
           OS_str_BaddC( SO_line, -1, "-1;-1;-1", SO_LINE_MAX);
        }
        
        
    #if defined( ADC_AV)
         
          OS_str_BaddV( SO_line, -1, SO_csv, SO_LINE_MAX);
          //
          if (_hasUref){
            OS_str_BaddR( SO_line, -1, _ADC_Uref->V, 2, SO_LINE_MAX);
               OS_str_BaddV( SO_line, -1, SO_csv, SO_LINE_MAX);   
          }
          else{
            OS_str_BaddC( SO_line, -1, "-1;", SO_LINE_MAX);
          } 
          //
          if (_hasUx){
            OS_str_BaddR( SO_line, -1, _ADC_Ux->V, 2, SO_LINE_MAX);
          }
          else{
            OS_str_BaddC( SO_line, -1, "-1", SO_LINE_MAX);
          }
         
    #endif
        
        
        //
      #ifdef SIO_AV
      #ifdef SIO_SESTU_AV
        if (SeStu0.v){
          //
          OS_str_BaddC( SO_line, -1, SeStu0.E, SO_LINE_MAX);
        }
      #endif
      #endif
        
      #ifdef SIO_AV
        // put serial
        //
         SIO_println();        
      #endif
      //
    }//SIO: msx
#endif

   return _f;
}


/*!
 *  visual/mesure/check refresh
 */
virtual bool  Refresh( int8_t _ix){
   bool _f=true;
   
   //
  #ifdef VIS_AV
     OS_loop_tdown=_vis_msx_rotate_M+1;
  #else
     OS_loop_tdown=2;
  #endif

   return _f;
}



/*!
 *  each delay
 */
virtual bool  Loop( int8_t _ix){
   bool _f=true;
   //
  #if defined( VIS_AV)
  int _style=_visStyle&VIS_ACT_CLR;
          _style|=VIS_ACT_NEW;

  bool _hasANT=false;
  #if defined(ADC_AV)
    #if defined( MSX_AV)
  if (_MSX0_Had==_MSX0_Has)
    #endif
      {
      //
      if ((_hasUx)|
          (_hasUref)
          ){
          OS_str_clr( vis_line);
          //
  #if defined( ADC_ANT_HX_SHOW_AV)
         //vis_line="U ";
         OS_str_BaddC( vis_line, -1, "U ", VIS_LINE_MAX);
         if (_hasUx){
            //
            OS_str_BaddR( vis_line, -1, _ADC_Ux->V, 2, VIS_LINE_MAX);
            OS_str_BaddV( vis_line, -1, '/', VIS_LINE_MAX);
            OS_str_BaddR( vis_line, -1, _ADC_Ux->dV, 2, VIS_LINE_MAX);
  #else
         //vis_line="Ux ";
         OS_str_BaddC( vis_line, -1, "Ux ", VIS_LINE_MAX);
         if (_hasUx){
            //
            OS_str_BaddR( vis_line, -1, _ADC_Ux->V, 3, VIS_LINE_MAX);
  #endif
            //
            OS_str_BaddV( vis_line, -1, 'V', VIS_LINE_MAX);
         }
         else{
            //
            OS_str_BaddV( vis_line, -1, '_', VIS_LINE_MAX);
         }//x
         //
         OS_str_BaddC( vis_line, -1, " < ", VIS_LINE_MAX);
         if (_hasUref){
            //
            OS_str_BaddR( vis_line, -1, _ADC_Uref->V, 3, VIS_LINE_MAX);
            OS_str_BaddV( vis_line, -1, 'V', VIS_LINE_MAX);
         }//ref
         else{
            //
            OS_str_BaddV( vis_line, -1, '_', VIS_LINE_MAX);
         }
         // WOT
         OS_str_BaddC( vis_line, -1, "     ", VIS_LINE_MAX);

          bool _clr=OS_param0.put;
          _VIS_print( 0, _clr, 0, _style, -1);
          _hasANT=_clr;
      }//[ref]x
    }//msx0
  #endif

  #endif      
  
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
      //vis_line="";      
      OS_str_clr( vis_line);
      OS_str_BaddC( vis_line, -1, _MSX_0.head, VIS_LINE_MAX); 
      if (_MSX0_Has){
        //
         OS_str_BaddC( vis_line, -1, _tx_on, VIS_LINE_MAX);
         OS_str_BaddN( vis_line, -1, _MSX_0.i2c, HEX, VIS_LINE_MAX);
      }
      else{
        //
         OS_str_BaddC( vis_line, -1, _tx_off, VIS_LINE_MAX);
      }
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
         &(!_hasANT)
         ){
        _VIS_cls( 0, 0, _visStyle, -1);
      }
      //

    }

    // rotate/single
    //
    bool _huge=false;
    if (_vis_msx_setup!=VIS_MS_AUTO){
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
      _visLine=_vis_msx_rotate;
    }

    

    // fetch vis_line
    //vis_line="";      
    OS_str_clr( vis_line);
    //
    if ((OS_param0.vis)
       &(OS_param0.sensor)
        ){
        //
  #if defined( MSX_AV)
        if (_MSX0_Has){  
            // select value to put
            if        (_vis_msx_rotate==1){
               // T
               #if defined(TFT_AV)
                  if (!_huge){              
                     //
                     OS_str_BaddC( vis_line, -1, "T ", VIS_LINE_MAX);
                  }
                  else{
                     //
                     OS_str_BaddC( vis_line, -1, "Temp.:\n", VIS_LINE_MAX);
                  }
               #else
                  //
                  OS_str_BaddC( vis_line, -1, "T ", VIS_LINE_MAX);
               #endif
                  OS_str_BaddR( vis_line, -1, _MSX_sn0.T, 2, VIS_LINE_MAX); 
                  OS_str_BaddV( vis_line, -1, 'C', VIS_LINE_MAX);
               //
            }
            else if (_vis_msx_rotate==2){
                //
              #if defined(TFT_AV)
                  if (!_huge){              
                     //
                     OS_str_BaddC( vis_line, -1, "P ", VIS_LINE_MAX);
                  }
                  else{
                     //
                     OS_str_BaddC( vis_line, -1, "Pressur:\n", VIS_LINE_MAX);
                  }
              #else
                  //
                  OS_str_BaddC( vis_line, -1, "P ", VIS_LINE_MAX);
              #endif 
                  OS_str_BaddR( vis_line, -1, _MSX_sn0.P, 2, VIS_LINE_MAX);
                  OS_str_BaddC( vis_line, -1, "mB", VIS_LINE_MAX);
            }
            else if (_vis_msx_rotate==3){
                //
              
              #if defined(TFT_AV)
                  if (!_huge){              
                     //
                     OS_str_BaddC( vis_line, -1, "H ", VIS_LINE_MAX);
                  }
                  else{
                     OS_str_BaddC( vis_line, -1, "Humi.:\n", VIS_LINE_MAX);
                  }
              #else
                  //
                  OS_str_BaddC( vis_line, -1, "H ", VIS_LINE_MAX);
            #endif
                  OS_str_BaddR( vis_line, -1, _MSX_sn0.H, 2, VIS_LINE_MAX);
                  OS_str_BaddV( vis_line, -1, '%', VIS_LINE_MAX);          
            }
            else{
               //
               OS_str_BaddC( vis_line, -1, "X ", VIS_LINE_MAX);
               OS_str_BaddC( vis_line, -1, _tx_novalue, VIS_LINE_MAX);
            }
        }
        // no SN[values]
        else{
            // -:-
            //
            OS_str_BaddC( vis_line, -1, _tx_msx, VIS_LINE_MAX);
            #if defined(TFT_AV)
               if (_huge){
                  //
                  OS_str_BaddC( vis_line, -1, ": ..\n^-", VIS_LINE_MAX);
               }
            #endif
            //
            OS_str_BaddC( vis_line, -1, "~off_?", VIS_LINE_MAX);
        }//
      //
    #else 
         
        
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


   return _f;
}




};//msx0


// -- installation
#if   defined( API0_MSX0_AV)
   ApiBase*  Api0=new API_msx0("MSX0_#0");
#elif defined( API1_MSX0_AV)
   ApiBase*  Api1=new API_msx0("MSX0_#1");
#elif defined( API2_MSX0_AV)
   ApiBase*  Api2=new API_msx0("MSX0_#2");
#elif defined( API3_MSX0_AV)
   ApiBase*  Api3=new API_msx0("MSX0_#3");
#endif




//@