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
#include <Q/_config.h>


#ifndef SIO_H_
#define SIO_H_ 1


#if defined(SIO_AV)

/* Header includes */

//#include <Q/sys/_def.h>



// TEST
#define nSIO_AV 1
    #define nSIO_SESTU_AV 1



/* Statische Definitions */


#ifdef SIO_SESTU_AV

#define  TX_SESTU_B                  "/*"
#define  TX_SESTU_E                  "*/"

#define  TX_SESTU_HEAD               "~EdIO,"


struct SeStu_t{
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



#ifdef SIO_SESTU_AV

/*
extern bool              SO_sestu    = false;// -> Se[rial]Stu[dio] compatible serial data output            

extern 
extern const char*       SO_sestu_B     = "/__*";
extern const char*       SO_sestu_head  = "~EdIO,";
extern const char*       SO_sestu_E     = "*__/";
*/
extern SeStu_t           SeStu0;//   




#endif




/* Routine Definitions */


/*!
 * ....
 */
//uint8_t bme280_init(struct bme280_dev *dev);




#endif 
#endif
//@
