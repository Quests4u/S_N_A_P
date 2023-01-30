/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       sio.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Muster
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef SIO_H_
#define SIO_H_ 1


#if defined(SIO_AV)

/* Header includes */




// TEST
#define nSIO_AV 1
    #define nSIO_SESTU_AV 1



/* Statische Definitions */

#if defined(AVR_328_AV)
    #define  SO_LINE_MAX                60
#else
    #define  SO_LINE_MAX                90
#endif


// connex
#define SO_PARAM  1
#if defined( RASP_AV)
    #define  SIO_Baud              115200
#elif defined( ESP8266_AV)
    #define  SIO_Baud              9600
#else
    #define  SIO_Baud              9600
#endif




struct SIO_set_t{
    //
    bool            v;
    //
    uint32_t         Baud;   

};



#ifdef SIO_SESTU_AV

#define  TX_SESTU_B                  "/*"
#define  TX_SESTU_E                  "*/"

#define  TX_SESTU_HEAD               "~EdIO,"



struct SeStu_set_t{
    //
    bool      v;
    const char*     B;
    const char*     H;
    const char*     E;
    //
};


#endif

/* Dynamische Definitions */


extern uint8_t*         SO_line;

extern bool             SO_para;//     = true; // -> put parameter regular on SO_line



extern SIO_set_t            SIO0;//

#ifdef SIO_SESTU_AV


extern SeStu_set_t           SeStu0;//   




#endif




/* Routine Definitions */


/*!
 * ....
 */
extern bool SIO_setup();


/*!
 * ....
 */
extern bool SIO_print( bool _clr);

/*!
 * ....
 */
extern bool SIO_println();

/*!
 * ....
 */
//extern bool SIO_out( StringBuffer_t* _sio);







#endif 
#endif
//@
