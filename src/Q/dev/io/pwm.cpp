/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       pwm.h
* @brief       drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/io/pwm.h>


#if defined( PWM_AV)

/* Dynamische Definitions */


#ifdef PWM_328_AV

int16_t               _PWM_DAC_null     = PWM_DAC_LOW;         

int16_t              _PwmValue = -1;


#ifdef PWM_AD_AV


int16_t           pwm_t_value     = -1;
int16_t           pwm_p_value     = -1;
int16_t           pwm_h_value     = -1;

double            pwm_t_0         = PWM_T0_0;
double            pwm_t_M         = PWM_T0_M;
//
double            pwm_p_0         = PWM_P0_0;
double            pwm_p_M         = PWM_P0_M;
//
double            pwm_h_0         = PWM_H0_0;
double            pwm_h_M         = PWM_H0_M;


// Analyses:: Parameter
#ifdef VAL_ALYS

int8_t               xCount          =0,               
                  MCount          =30;


float             Tx              =0.0,
                  dTx           =0.0,
                  dTdif         =0.0,
                  Px              =0.0,
                  dPx           =0.0,
                  dPdif         =0.0,
                  Hx              =0.0,
                  dHx           =0.0,
                  dHdif         =0.0,
                  xLimit        =0.0;

#endif

#endif

#endif



/* Routine Definitions */


#ifdef PWM_AV



/*!
 * 
 * @param  _pwm         .. 0.00-100.00%
 * @param  _none_null   .. nonull offset
 * @return level(0-256)
 */
int16_t   _PWM_getLevel( 
            double _pwm,
            int16_t _none_null
          ){
    //
    double _v=0.0;
    if (_pwm>0){
      _v=100.0;
      if (_pwm<_v){
        _v=_pwm;
      } 
    }
    int16_t _=round( (_v*(255.0-_none_null))/100.0)+_none_null;
    return _;
}
  



/*!
 * set test value to all valid DACs
 * @param  _v     ..  [test]value
 * @return _pwm
 */
int16_t _PWM_setTestDAC( 
            double _v
          ){
    //
    int16_t _v_=0;
  #ifdef PWM_AD_AV
    _v_=_PWM_getLevel( _v, _PWM_DAC_null);
    
    //
    analogWrite( PWM_PIN_DAC_T, _v_);
    analogWrite( PWM_PIN_DAC_P, _v_);
    analogWrite( PWM_PIN_DAC_H, _v_);
  #elif PWM_328_AV
    _v_=_PWM_getLevel( _v, _PWM_DAC_null);
  #endif
    //
    return _v_;
}


/*!
 * set DA[C] within Min-Max BoxParameters
 * @see pcm_X_0/d
 */
bool _PWM_setDAC( 
            double _T,
            double _P,
            double _F
          ){
    //
    bool   _f=true;
#ifdef PWM_AD_AV
    int16_t     _i_=-1;
    double  _v=0,
            _pwm_t_d=pwm_t_M-pwm_t_0,
            _pwm_p_d=pwm_p_M-pwm_p_0,
            _pwm_f_d=pwm_h_M-pwm_h_0
            ;


    // T: 
      _v=(_T-pwm_t_0)*100.0/_pwm_t_d;
        _i_=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_t_value=_i_;
      analogWrite( PWM_PIN_DAC_T, _i_);
    // P:
    _v=(_P-pwm_p_0)*100.0/_pwm_p_d;
      _i_=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_p_value=_i_;
      analogWrite( PWM_PIN_DAC_P, _i_);

    // F: 
    _v=(_F-pwm_h_0)*100.0/_pwm_f_d;
      _i_=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_h_value=_i_;
      analogWrite( PWM_PIN_DAC_H, _i_);

#endif
    //
    return _f;
}




/*!
 *
 */
bool  PWM_setup(){
   //
   bool _f=false;
   
   #if defined(PWM_328_AV)

   #if defined( PWM_PIN_AV)
      // PWM: DAC->STD/+NULL
      pinMode( PIN_MS_DA_NUL, INPUT_PULLUP);
   #endif

   #if defined(PWM_AV) & defined(PWM_328_AV)
   #if defined(PWM_AD_AV)

      // VCOM[outclk]
      pinMode( PIN_AN0_VCOM, OUTPUT);     // --> AIN1 = (PWM out [~1kHz])
      analogWrite( PIN_AN0_VCOM, 100);
      //
      pinMode( PWM_PIN_DAC_T, OUTPUT);
      pinMode( PWM_PIN_DAC_P, OUTPUT);
      pinMode( PWM_PIN_DAC_H, OUTPUT);
      //
      _PWM_DAC_null=PWM_DAC_LOW;
      _PWM_setTestDAC( _PWM_DAC_null);
      //   
   #else
      _PWM_setTestDAC( 0.5);
   #endif

      _f=true;
   #endif
   #endif
   
   return _f;
}



#endif

#endif
//@