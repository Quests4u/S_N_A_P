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

   OS_loop_delay  =500;
   OS_debug       =true;

}


/*!
 * each wait stop 
 */
void  API0_task(){

   Serial.print("Task:");
   Serial.print( 0x77);
   

   bool _f=TWI_port( 0x77);
   Serial.print( " <- ");
   Serial.println( _f);

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
  //
  if (SO_para){
    //
    Serial.println( SO_line);
  }



}






//@