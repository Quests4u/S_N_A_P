/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       sio.h
* @brief      muster drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/io/sio.h>

#include <Arduino.h>


#if defined(SIO_AV)

/* Statische Definitions */



/* Dynamische Definitions */


uint8_t              SO_line_b[SO_LINE_MAX+2]={ '@', 0};

uint8_t*             SO_line=&SO_line_b[0];                              
                              
bool                 SO_para     = true; // -> put parameter regular on SO_line


/*!
 * [bool]   v       .. valid
 * [int]    baud    .. [-1]/ value (9600)
 *
 */
SIO_set_t        SIO0       ={
        true
        //
        ,SIO_Baud

};//


#ifdef SIO_SESTU_AV


SeStu_set_t  SeStu0    ={
    //
    false,
    //
    TX_SESTU_B,
    TX_SESTU_HEAD,
    TX_SESTU_E
    //
};


#endif



/* Routine Definitions */

/*!
 *
 */
bool SIO_setup(){
    //
    bool _f=true;
    
    //Serial1.setPollingMode( false);
    if (SIO0.Baud<9600){
        //
        SIO0.Baud=9600;
    }
    //
    Serial.begin( SIO0.Baud);
    OS_delay(250);
    //
    //OS_str_clr( SO_line);
    //
    return _f;
}





/*!
 *
 */
bool SIO_print( bool _clr){
   //
   Serial.print( (char*)SO_line);
   if (_clr){
      SO_line[0]=0;
   }
   //
   return true;
}

/*!
 *
 */
bool SIO_println(){
   //
   Serial.println( (char*)SO_line);
   //
   SO_line[0]=0;
   //
   return true;
}




#endif
//@