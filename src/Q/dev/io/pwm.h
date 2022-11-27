/*!
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       pwm.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * puls wide modulation components
 * 
 * @defgroup PWM
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/_config.h>



#ifndef PWM_H_
#define PWM_H_ 1


#if defined(PWM_AV)


/* Header includes */

// TEST
#define nPWM_AV 1
    #define nPWM_328_AV    1
        #define nPWM_ADA_AV    1



/* Statische Definitions */

#define  PWM_DAC_HIGH             100
#define  PWM_DAC_LOW              0
#define  PWM_DAC_NONENULL         20


#ifdef PWM_328_AV

#ifdef PWM_AD_AV

#define  PIN_AN0_VCOM         6          // D6(o)    = PD6/AN0 (ACOMP-)


//
#define  PWM_PIN_DAC_T            10             // D10(o)   = PB2/PCM(T)
#define  PWM_PIN_DAC_P            11             // D11(o)   = PB3/PCM(P)   
#define  PWM_PIN_DAC_F            9              // D9(o)    = PB1/PCM(F)


#define  PWM_T0_0             -20.0     //  -> -20C   = 0%    (0)   0[+2]V
#define  PWM_T0_M             +80.0     //  -> +80C   = 100%  (255) 9.99V

#define  PWM_P0_0             +950.0    //  -> 950    = 0%    (0)   
#define  PWM_P0_M            +1030.0    //  -> 1030   = 100%  (255)

#define  PWM_F0_0             0.0       //  -> 0%     = 0%    (0)
#define  PWM_F0_M             100.0     //  -> 100%   = 100%  (255)

#endif




#endif



/* Dynampisch Definitions */

#ifdef PWM_328_AV



extern int               _PWM_DAC_null;//     = PWM_DAC_LOW;         


#ifdef PWM_AD_AV

extern int               pwm_t_value;//     = -1;
extern int               pwm_p_value;//     = -1;
extern int               pwm_f_value;//     = -1;

extern double            pwm_t_0;//         = PWM_T0_0;
extern double            pwm_t_M;//         = PWM_T0_M;
//
extern double            pwm_p_0;//         = PWM_P0_0;
extern double            pwm_p_M;//         = PWM_P0_M;
//
extern double            pwm_f_0;//         = PWM_F0_0;
extern double            pwm_f_M;//         = PWM_F0_M;


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
extern int _PWM_getLevel( 
            double _pwm,
            int _none_null
          );



/*!
 * set test value to all valid DACs
 * @param  _v     ..  [test]value
 * @return _pwm
 */
extern int _PWM_setTestDAC( 
            double _v
          );




/*!
 * set DA[C] within Min-Max BoxParameters
 * @see pcm_X_0/d
 */
extern bool _PWM_setDAC( 
            double _T,
            double _P,
            double _F
          );



#endif



#endif
#endif 
//@
