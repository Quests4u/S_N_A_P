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


String            SO_line   = String( "01234567890123456789012345");//26By SerialOut Puffer

bool              SO_para     = true; // -> put parameter regular on SO_line


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
bool SIO_setup(){
    //
    SO_line="";
    //Serial1.setPollingMode( false);
    if (SIO0.Baud>0){
        Serial.begin( SIO0.Baud);
    }
    else{
        Serial.begin();
    }
    OS_delay(100);
    //
    return true;
}



#endif
//@