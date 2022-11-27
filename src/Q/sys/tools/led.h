/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       led.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup LED
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/_config.h>


#ifndef LED_H_
#define LED_H_ 1


#if defined( LED_AV)

/* Header includes */
//#include <Arduino.h>

//#include <Q/sys/_def.h>


/* Statische Definitions */

#define nLED_AV



struct LED_set_t{
    //
    bool  v;//
    int   pin;
    //
    int   count;
    //
    bool  has;//
    bool  state;//
    //
    bool  hasAuto;//


};



/* Dynamische Definitions */

/*
extern bool                _LedHas;//       = false;
extern bool                _LedState;//     = false;
//
extern bool                _LedAuto_SW;//   = true;
*/

extern LED_set_t           _LED0;   
                            /*             ={
                                            true
                                            //
                                            ,false
                                            ,false
                                            //
                                            ,true

                                            };
                            */

/* Routine Definitions */


/*!
 * switch led[ix]  with state
 *@param _state   true/false  on/off
 */
extern void _LED_sw( 
                int  _ix
                //
                ,bool _state
            );




#endif 
#endif
//@
