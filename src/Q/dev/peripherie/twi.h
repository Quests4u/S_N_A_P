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
#include <_config.h>



#ifndef TWI_H_
#define TWI_H_ 1



#if defined( TWI_AV)


/* Header includes */
#include <Wire.h>


// TEST
#define nTWI_AV 1
  #define nTWI_SCAN_AV 1



/* Statische Definitions */

#define  TX_TW          "TW:"


#define  TWI_MAX        16
#define  TWI_TIMEOUT    300  // 0,3mS


/* Dynamische Definitions */

extern const char*            _tx_TW;

extern uint8_t                 _TWI[];
extern uint8_t                 _TWI_cou;                          


extern uint16_t                _TWI_timeout;







/* Routine Definitions */



//#ifdef TWI_SCAN_AV


/*!
 *  TWI setup
 */
extern  bool TWI_setup( int8_t _ix);



/*!
 * tests TWI port
 * @param _i2c .. TWI[i2c] port
 */
extern  bool TWI_port( byte _i2c);



#if defined( TWI_SCAN_AV)


/*!
 * scannes all defined twi ports
 * and put into _TWI[..]
 * @param _show .. put log to SO
 */
extern void  TWI_scanner( bool _show);

#endif





#endif
#endif
//@
