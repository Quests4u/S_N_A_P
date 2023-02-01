/*!
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       spi.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * spi components
 * 
 * 
 * @defgroup spi
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>



#ifndef SPI_H_
#define SPI_H_ 1


#if defined(SPI_AV)


/* Header includes */
//#include <Arduino.h>
#include <SPI.h>

//#include <Q/sys/_def.h>


// TEST
#define nSPI_AV 1
  


/* Statische Definitions */


struct SPI_pin_t{

    int8_t  BL;

    int8_t  RST;

    int8_t  DC;
    int8_t  CS;

    int8_t  MISO;
    int8_t  MOSI;

    int8_t  SCK;
    int8_t  SS;

};



/* Dynamische Definitions */
//#if defined(SPI_AV)

extern SPI_pin_t   SPI_pin0;





/* Routine Definitions */
/*!
 * SPI setup
 */
extern bool SPI_setup( int8_t _ix);




#endif 
#endif
//@
