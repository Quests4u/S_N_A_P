/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _muster.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Muster
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/sys/_config.h>


#ifndef MUSTER_H_
#define MUSTER_H_ 1


/* Header includes */
//#include <Arduino.h>

#include <Q/sys/_def.h>


/* Statische Definitions */

#define nMUSTER_AV 1


/* Dynamische Definitions */


extern API_set_t      API0;



/* Routine Definitions */



#ifdef xAPI0_AV
/*!
 * ....
 */
extern void  API0_prepare( int _ix);

/*!
 * ....
 */
extern void  API0_task( int _ix);

/*!
 * ....
 */
extern void  API0_refresh( int _ix);

/*!
 * ....
 */
extern void  API0_loop( int _ix);


#endif





#endif 
//@
