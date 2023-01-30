/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       adc.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Analog
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef ADC_H_
#define ADC_H_ 1


#if defined( ADC_AV)

/* Header includes */


/* Statische Definitions */

#define nADC_AV 1
   #define nADC_ANT_AV 1



/* Statische Definitions */


#define  ADC_12    4096
#define  ADC_10    1024
#define  ADC_08    256


#if   defined(ESP8266_AV)

   #define   ADC_UX_HAS       true
   #define   ADC_UX           A0       // ADC_TOUT

   #define   ADC_UREF_HAS     true
   #define   ADC_UREF         -1       
   #define   ADC_UREF_V       2.00     

   #define   ADC_STEPS        ADC_10
   #define   ADC_FX           (3.2/ADC_STEPS)
   #define   ADC_KX           (3.3/3.3)


   #define   ANT_C_HAS        true
   #define   ANT_PORT_SIGN    D6   // D6 = MISO D3 = CS, D0 = Rst
   #define   ANT_REF_SOFT     true
   




#elif defined(RASP_AV)


   #define   ADC_UX_HAS       true
   #define   ADC_UX           A0 //GP26_A0

   #define   ADC_UREF_HAS     true
   #define   ADC_UREF         A1 //GP26_A1
   #define   ADC_UREF_V       1.75

   #define   ADC_STEPS        ADC_10
   #define   ADC_FX           (3.3/ADC_STEPS)
   #define   ADC_KX           (3.28/3.3)

   #define   ANT_C_HAS        true
   #define   ANT_PORT_SIGN    A2//D28  GP28  DI1 
   #if defined( ADC_ANT_ISR_AV)
      #define   ANT_REF_SOFT     true
   #else
      #define   ANT_REF_SOFT     true
   #endif





#else


      #define   ADC_UX_HAS       true
      #define   ADC_UX           A6


   #if defined( AVR_AV) & defined( PWM_AV)
      #define   ADC_UREF_HAS     true
      #define   ADC_UREF         -1
      #define   ADC_UREF_V       2.00
   
   #else
      #define   ADC_UREF_HAS     true
      #define   ADC_UREF         A7
      #define   ADC_UREF_V       1.75
      
   #endif

   #define   ADC_STEPS        ADC_10
   #define   ADC_FX           (5.0/ADC_STEPS)
   #define   ADC_KX           (4.75/5.0)

   #define   ANT_C_HAS        true
   #define   ANT_PORT_SIGN    A0 
   
   #if defined( ADC_ANT_ISR_AV) 
      #if defined( PWM_AV)
         #define   ANT_REF_SOFT     true
      #else
         #define   ANT_REF_SOFT     false
      #endif
   #else
      #define   ANT_REF_SOFT     true
   #endif

#endif







#if defined(AVR_AV)

   #if defined( ADC_AN_AV)
      //
      #if defined( ADC_AN_ISR_AV)
         //
         #if defined( AVR_AV)
            #include  <avr/interrupt.h>
         #endif
      #endif
   #endif


   #define ADC_MUX_AD   0
      #define ADC_MUX_A0  0
      #define ADC_MUX_A1  1
      #define ADC_MUX_A2  2
      #define ADC_MUX_A3  3
      #define ADC_MUX_A4  4
      #define ADC_MUX_A5  5
      #define ADC_MUX_A6  6
      #define ADC_MUX_A7  7
   //

   #define ADC_MUX_INNER  13
      #define ADC_MUX_1v1 14 // inner referenz 1.1V
      #define ADC_MUX_GND 15 // ??


#endif//AVR



/*

Program notes:

- The AIN0D bit in the DIDR1 register should be disabled in order to save power consumption for the default digital input buffer.
   DIDR1 |= (1<<AIN0D); 
- When any of the analog input is used for the negative input to the comparator(such as A1 here)

1) the ADC must be disabled by clearing the ADEN bit in the ADCSRA register. 
   ADCSRA &= ~(1<<ADEN);

2) the ACME bit in the ADCSRB register must be set to use analog input pins instead of AIN1 pin
   ADCSRB |= (1<<ACME);

3) the MUX2:0 bits in ADMUX register must be configured to select which of the analog pins A0 to A7 to use.
   ADMUX = 0x01;

- The ACSR register bits are configured according to the user application intention. 
1. The analog comparator must be enabled.
2. The user selects the input to the positive input of the comparator which can be either the external input via the AIN0 pin as used here or the bandgap reference voltage(1.1V). This is set using the ACBG bit.
3. Whether to use or not the output of the analog comparator. Here we don't need it so we turned it off.
4. We can clear the analog comparator interrupt flag.
5. We can disable the analog comparator interrupt.
6. We can use or not use the Analog Comparator Input Capture feature. Here we disabled it.
7. We can choose type of interrupt trigger mode. Here we set it to output toggle mode but this is not required since we did not use the interrupt feature.

 - In the main loop we can simply monitor the analog comparator output ACO bit in the ACSR register and turn on/off a LED.


   // setup
   DDRD |= (1<<PD4)           // Output
   
        DIDR1 |= (1<<AIN0D); // Disable Digital Inputs at AIN0 and AIN1
	ADCSRA &= ~(1<<ADEN);
        ADCSRB |= (1<<ACME);	//Set ACME bit in ADCSRB to use external analog input at AIN1 -ve input
	ADMUX = 0x01; //select A1 as input 
	ACSR = 
	(0 << ACD) |    // Analog Comparator: Enabled
	(0 << ACBG) |   // Clear ACBG to use external input to AIN0 +ve input
	(0 << ACO) |    // Analog Comparator Output: OFF
	(1 << ACI) |    // Analog Comparator Interrupt Flag: Clear Pending Interrupt by setting the bit
	(0 << ACIE) |   // Analog Comparator Interrupt: Disabled 
	(0 << ACIC) |   // Analog Comparator Input Capture: Disabled
	(0 << ACIS1) | (0 << ACIS0);   // Analog Comparator Interrupt Mode: Comparator Interrupt on Output Toggle

   // setup derivat
   ACSR =
    (0 << ACD) |    // Analog Comparator: Enabled
    (0 << ACBG) |   // Analog Comparator Bandgap Select: AIN0 is applied to the positive input
    (0 << ACO) |    // Analog Comparator Output: Off
    (1 << ACI) |    // Analog Comparator Interrupt Flag: Clear Pending Interrupt
    (1 << ACIE) |   // Analog Comparator Interrupt: Enabled
    (0 << ACIC) |   // Analog Comparator Input Capture: Disabled
    (1 << ACIS1) | (1 << ACIS0);   // Analog Comparator Interrupt Mode: Comparator Interrupt on Rising Output Edge

   pinMode(13, OUTPUT);  // toggles when ISR runs
   pinMode(9, OUTPUT);   // indicates status of comparator output
   
   
   // loop
   if (ACSR & (1<<ACO))
		PORTD |= (1<<PD4);
	else
		PORTD &= ~(1<<PD4);
   
   //loop derivat
   if(ACSR & (1 << ACO))         //  check status of comparator output flag
      digitalWrite(9, HIGH);    //   and mirror it to Pin 9
   else
      digitalWrite(9, LOW);
 
 
 
   //ISR
   
   
 
   //ISR derivate
   ISR(ANALOG_COMP_vect ) {
      digitalWrite(13, !digitalRead(13));   // toggle state of Pin 13
   }

*/


/*!
 *  [bool]  has
 *  [bool]  had
 * 
 *  [bool]  rw
 *  [int8_t]  Port
 * 
 *  [double]   dV
 *  [double]   V
 *  [int]      v
 * 
 *  [int]      Steps
 *  [double]   Fx
 *  [double]   Kx
 * 
 *  [int]   min
 *  [int]   max
 * 
 *  [int8_t]  ANix
 * 
 */
struct ADC_set_t {
    //
    bool       has;        // has port
    bool       had;        // had r/w

    //
    bool       rw;         // r=true w=false 
    int8_t     Port;       // GIO port for measurment
    //
    double     dV;         // act. dvalue (new-last)
    double     V;          // act. value
    int        v;          // act. steps    
    //
    int        Steps;      // 10b=1024, 8bit=256 usw
    double     Fx;         // U/step factor
    double     Kx;         // 1.0 korrectur  
    //
    int        min;        // NC: step min
    int        max;        // NC: step max  

    int8_t     ANTix;      // -1 no AN for this

};






/*!
 *
 */
struct ANT_set_t {
    //
    bool       has;        // has port
    bool       had;        // had r/w
    //
    bool       Polarity;   // true->[Out] / false->[!Out] 
    int8_t     Mux;        // 0-7[8] or inner referenz (multiplex with V or other ADCs)

    int8_t     SW;         // 0/1 LOW/HIGH false/true  -> NC: -1=Threestate      
    int8_t     Port;       // Output signalPort -1=none

    double     HX;         // Hysterese (0 = off.)
    double     V;          // Old Value

    int8_t     ANTix;       // this.Index
    ADC_set_t  *Adc;       // none -> connected ADC

    bool       refSoft;    //        
    ADC_set_t  *Ref;       // none -> with refSoft
    //
    bool       (*Action)(int8_t);
                           // bool Action(_ANix)
};



/* Dynamische Definitions */



extern ADC_set_t     ADCx[];
extern int8_t       ADCxcount; 

extern ANT_set_t      ANTx[];
extern int8_t       ANTxcount;

#if defined( ADC_ANT_ISR_AV)
//extern AN_set_t*     AN01_isr;
#endif


extern ADC_set_t*    _ADC_Ux;
extern ADC_set_t*    _ADC_Uref;

extern ANT_set_t*    _ANT_c;






/* Routine Definitions */

/*!
 * 
 */
extern bool       ADC_setup();



/*!
 * Refresh analog data 
 */
extern double     ADChandler( 
                        ADC_set_t*     _adc
                        ,bool          _hanVx
                        ,bool          _hanAN
                        );





#if defined( ADC_ANT_AV)


/*!
 *
 */
extern bool       ANTbegin(
                        int8_t _ix
                        );

/*!
 *
 */
extern ANT_set_t*  ANTptr(
                        int8_t _ix
                        );



#endif



#endif
#endif
//@
