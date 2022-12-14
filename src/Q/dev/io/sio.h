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

// Serial
#define SO_PARAM  1
#define  SIO_Baud              9600
#define  SO_hex                 '#'
#define  SO_csv                 ','
#define  SO_col                 '/'


#ifdef SIO_SESTU_AV

#define  TX_SESTU_B                  "/*"
#define  TX_SESTU_E                  "*/"

#define  TX_SESTU_HEAD               "~EdIO,"



struct SIO_set_t{
    //
    bool            v;
    //
    int             Baud;   

};

struct SeStu_set_t{
    //
    bool            v;
    const char*     B;
    const char*     H;
    const char*     E;
    //
};


#endif

/* Dynamische Definitions */


extern String            SO_line;//   = String( "01234567890123456789012345");//26By SerialOut Puffer

extern bool              SO_para;//     = true; // -> put parameter regular on SO_line



extern SIO_set_t            SIO0;//

#ifdef SIO_SESTU_AV


extern SeStu_set_t           SeStu0;//   




#endif




/* Routine Definitions */


/*!
 * ....
 */
extern bool SIO_setup();









#endif 
#endif
//@
