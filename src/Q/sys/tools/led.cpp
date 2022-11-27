/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       led.h
* @brief      led drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/sys/tools/led.h>



#if defined( LED_AV)
/* Statische Definitions */


/* Dynamische Definitions */



LED_set_t           _LED0= 
                            {
                                    true
                                    ,0
                                    ,LED_BUILTIN
                                     //
                                    ,false
                                    ,false
                                    //
                                    ,true
                             };


/* Routine Definitions */


/*!
 * switch led[ix]  with state
 *@param _state   true/false  on/off
 */
void _LED_sw( 
                int  _ix
                //
                ,bool _state
            ){
  //
  uint8_t _sw=0;
  #ifdef ESP8266_AV
  _sw=_state ? LOW:HIGH;
  #elif AVR_AV
  _sw=_state ? HIGH:LOW;
  #endif
  digitalWrite( _LED0.pin, _sw);
  //
}



#endif
//@