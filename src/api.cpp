/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api.h>




/* Statische Definitions */


/* Dynamische Definitions */



  

/* Routine Definitions */



/*!
 * ....
void  API_parameter( 
                  int         _ix
                  ,API_set_t  _api
                  ){

#ifdef API0_AV
  API0.percent    =_api.percent;
  API0.dbg        =_api.dbg;
  API0.vis        =_api.vis;
  API0.sensor     =_api.sensor;
  API0.led        =_api.led;
#endif

#ifdef API1_AV
  API1.percent    =_api.percent;
  API1.dbg        =_api.dbg;
  API1.vis        =_api.vis;
  API1.sensor     =_api.sensor;
  API1.led        =_api.led;
#endif
}
 */




/*!
 * ....
 */
void  API_prepare( int _ix){

   #if defined(API0_AV)
         API0_prepare();
   #endif

   #if defined(API1_AV)
         API1_prepare();
   #endif
}

/*!
 * each wait stop 
 */
void  API_task( int _ix){

   #if defined(API0_AV)
         API0_task();
   #endif

   #if defined(API1_AV)
         API1_task();
   #endif

}



/*!
 *  visual/mesure/check refresh
 */
void  API_refresh( int _ix){
   //
   #if defined(API0_AV)
         API0_refresh();
   #endif

   #if defined(API1_AV)
         API1_refresh();
   #endif

}

/*!
 *  each delay
 */
void  API_loop( int _ix){
   //
   #if defined(API0_AV)
         API0_loop();
   #endif

   #if defined(API1_AV)
         API1_loop();
   #endif

}






//@