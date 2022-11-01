/*!
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       twi.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * two wire components
 * [i2c]
 * 
 * 
 * @defgroup twi i2c
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/sys/_config.h>



#ifndef TWI_H_
#define TWI_H_ 1


/* Header includes */
//#include <Arduino.h>
#include <Wire.h>

#include <Q/sys/_def.h>


// TEST
#define nTWI_AV 1
  #define nTWI_SCAN_AV 1



/* Statische Definitions */

//#ifdef TWI_SCAN_AV

  #define TWI_SCAN_B0  0x01
  #define TWI_SCAN_E0  0xF0

//#endif



/* Statische Definitions */

#define             TX_TWI_DEV     "device = "
#define             TX_TWI_MAX     "[!]"

#define  TWI_MAX  10


/* Dynamische Definitions */

//#ifdef TWI_SCAN_AV

extern byte                 _TWI[TWI_MAX];
extern byte                 _TWI_cou;                          
extern byte                 _TWI_max;

//#endif

extern const char*         _tx_twi_dev;//    = "device = ";
extern const char*         _tx_twi_max;//    = "[!]";






/* Routine Definitions */



//#ifdef TWI_SCAN_AV

/*!
 * tests TWI port
 * @param _i2c .. TWI[i2c] port
 */
extern  bool TWI_port( byte _i2c);


/*!
 * scannes all defined twi ports
 * and put into _TWI[..]
 * @param _show .. put log to SO
 */
extern void  TWI_scanner( bool _show);




#endif
//@
