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



/* Statische Definitions */



/* Dynamische Definitions */


String            SO_line   = String( "01234567890123456789012345");//26By SerialOut Puffer

bool              SO_para     = true; // -> put parameter regular on SO_line




#ifdef SIO_SESTU_AV

/*
bool              SO_sestu    = false;// -> Se[rial]Stu[dio] compatible serial data output            

const char*       SO_sestu_B     = "/__*";
const char*       SO_sestu_head  = "~EdIO,";
const char*       SO_sestu_E     = "*__/";
*/
SeStu_t  SeStu0    ={
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



//@