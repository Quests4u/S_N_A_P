/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _muster.h
* @brief      muster drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/~/_muster.h>




/* Statische Definitions */


/* Dynamische Definitions */

#ifdef xAPI_AV

extern API_set_t      API0{
                false,
                false,
                //
                0,//0
                50//%
};

#endif


/* Routine Definitions */


#ifdef xAPI0_AV

/*!
 * ....
 */
void  API0_prepare( int _ix){

}

/*!
 * ....
 */
void  API0_task( int _ix){

}

/*!
 * ....
 */
void  API0_refresh( int _ix){

}

/*!
 * ....
 */
void  API0_loop( int _ix){
    
}


#endif


//@