/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Application
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef API1_MSX0_H_
#define API1_MSX0_H_ 1


/* Header includes */

/* Statische Definitions */

/* Dynamische Definitions */

/* Routine Definitions */

/*!
 *@see WOT: API_install_WOT() [api.h]
 */
#if   defined(API0_MSX0_AV)
   extern ApiBase* Api0;
      #define API0_INSTALL_AV 1
#elif defined(API1_MSX0_AV)
   extern ApiBase* Api1;
      #define API1_INSTALL_AV 1
#elif defined(API2_MSX0_AV)
   extern ApiBase* Api2;
      #define API2_INSTALL_AV 1
#elif defined(API3_MSX0_AV)
   extern ApiBase* Api3;
      #define API3_INSTALL_AV 1
#endif 





#endif 
//@
