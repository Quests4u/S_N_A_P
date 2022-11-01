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
#include <Q/sys/_config.h>



#ifndef SPI_H_
#define SPI_H_ 1


/* Header includes */
//#include <Arduino.h>
#include <SPI.h>

#include <Q/sys/_def.h>


// TEST
#define nSPI_AV 1
  


/* Statische Definitions */


struct SPI_pin_t{

    uint8_t  BL;

    uint8_t  CS;
    uint8_t  RS;

    uint8_t  MOSI;
    uint8_t  MISO;

    uint8_t  CLK;


};



/* Dynamische Definitions */




/* Routine Definitions */





#endif 
//@
