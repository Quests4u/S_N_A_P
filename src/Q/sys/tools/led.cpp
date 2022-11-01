/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       led.h
* @brief      led drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/~/_muster.h>




/* Statische Definitions */


/* Dynamische Definitions */


/*
bool                _LedHas       = false;
bool                _LedState     = false;
//
bool                _LedAuto_SW   = true;
*/
LED_set_t           _LED0= 
                            {
                                    true
                                    ,0
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
  uint8_t _sw=_state ? HIGH:LOW;
  digitalWrite( LED_BUILTIN, _sw);
  //
}




//@