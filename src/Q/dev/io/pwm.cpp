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

int               _PWM_DAC_null     = PWM_DAC_LOW;         


#ifdef PWM_AD_AV


int               pwm_t_value     = -1;
int               pwm_p_value     = -1;
int               pwm_f_value     = -1;

double            pwm_t_0         = PWM_T0_0;
double            pwm_t_M         = PWM_T0_M;
//
double            pwm_p_0         = PWM_P0_0;
double            pwm_p_M         = PWM_P0_M;
//
double            pwm_f_0         = PWM_F0_0;
double            pwm_f_M         = PWM_F0_M;


// Analyses:: Parameter
#ifdef VAL_ALYS

int               xCount          =0,               
                  MCount          =30;


float             Tx              =0.0,
                  dTx           =0.0,
                  dTdif         =0.0,
                  Px              =0.0,
                  dPx           =0.0,
                  dPdif         =0.0,
                  Fx              =0.0,
                  dFx           =0.0,
                  dFdif         =0.0,
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
int _PWM_getLevel( 
            double _pwm,
            int _none_null
          ){
    //
    double _v=0.0;
    if (_pwm>0){
      _v=100.0;
      if (_pwm<_v){
        _v=_pwm;
      } 
    }
    int _=round( (_v*(255.0-_none_null))/100.0)+_none_null;
    return _;
}
  



/*!
 * set test value to all valid DACs
 * @param  _v     ..  [test]value
 * @return _pwm
 */
int _PWM_setTestDAC( 
            double _v
          ){
    //
    int _=0;
  #ifdef PWM_AD_AV
    _=_PWM_getLevel( _v, _PWM_DAC_null);
    
    //
    analogWrite( PWM_PIN_DAC_T, _);
    analogWrite( PWM_PIN_DAC_P, _);
    analogWrite( PWM_PIN_DAC_F, _);
  #elif PWM_328_AV
    _=_PWM_getLevel( _v, _PWM_DAC_null);
  #endif
    //
    return _;
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
    int     _=-1;
    double  _v=0,
            _pwm_t_d=pwm_t_M-pwm_t_0,
            _pwm_p_d=pwm_p_M-pwm_p_0,
            _pwm_f_d=pwm_f_M-pwm_f_0
            ;


    // T: 
      _v=(_T-pwm_t_0)*100.0/_pwm_t_d;
        _=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_t_value=_;
      analogWrite( PWM_PIN_DAC_T, _);
    // P:
    _v=(_P-pwm_p_0)*100.0/_pwm_p_d;
      _=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_p_value=_;
      analogWrite( PWM_PIN_DAC_P, _);

    // F: 
    _v=(_F-pwm_f_0)*100.0/_pwm_f_d;
      _=_PWM_getLevel( _v, _PWM_DAC_null);
    pwm_f_value=_;
      analogWrite( PWM_PIN_DAC_F, _);

#endif
    //
    return _f;
}




#endif

#endif
//@