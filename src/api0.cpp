/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api0.h>




/* Statische Definitions */


/* Dynamische Definitions */




  

/* Routine Definitions */


/*!
 * ....
 */
void  API0_prepare(){

   OS_loop_delay=500;

}



/*!
 * each wait stop 
 */
void  API0_task(){

  

}

/*!
 *  visual/mesure/check refresh
 */
void  API0_refresh(){
   //


}

/*!
 *  each delay
 */
void  API0_loop(){
   //
   
  SO_line="S::Led ";
  if (_LED0.state){
    _LED0.state=false;
    //
    //SerialUSB.println( "U::Led OFF");
    SO_line.concat("(ON!)");
    //
  }
  else{
    _LED0.state=true;
    //
    SO_line.concat( "(OFF!)");
    //SerialUSB.println( "U::Led ON");
    //
  }
  //
  _LED_sw( 0, _LED0.state);
  Serial.println( SO_line);



}






//@