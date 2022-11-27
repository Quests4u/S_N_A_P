/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       eep.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup EEPROM
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/_config.h>


#ifndef EEPROM_H_
#define EEPROM_H_ 1


#if defined( EEP_AV)


/* Header includes */
//#include <Arduino.h>

//#include <Q/sys/_def.h>


/* Statische Definitions */


#define V_EP "~ee"

  #ifndef TWI_AV
  #include <Wire.h>
  #endif

  #define EEP_BASE  0x50    // 1010xxxx  Control Code 

  #define nEEP_16_AV 1       // <- 24C16 
  #define nEEP_256_AV 1     // <- 24C256


/* Dynamische Definitions */


#define EEP_ADR( _v)   (EEP_ADR_START+_v)



/* Routine Definitions */


/*!
 * ....
 */
extern bool EEP_saveValues();


/*!
 * ....
 */
extern bool EEP_serialValueBulk();



#ifdef EEP_16_AV



#endif


#ifdef EEP_256_AV



#endif




#endif
#endif 
//@
