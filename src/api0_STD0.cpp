/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api0_STD0.h>




/* Statische Definitions */

/* Dynamische Definitions */



/* Routine Definitions */




// class: std



class API_std0:  public ApiBase{

private:
 
   int8_t  _c0=0;
   int8_t  _c1=0;

   int     _cou=0;

   #define  HAS_PIN_AV 1

   #if defined( ESP8266_AV)
   uint8_t _pin=D6;  // MISO
   #elif defined( RASP_AV)
   uint8_t _pin=A2;  // GP28
   #else
   uint8_t _pin=A0;  //AVR
   
   #endif

   bool    _blink=false;

   
   NumberBuffer_set_t  _nB= {};
     
   
   

public:


API_std0( const char* _Title):
      ApiBase( _Title){
      
}




/*!
 * ....
 */
bool  Setup( int8_t _ix){

Serial.println( "->setup");

   //
   OS_loop_delay  =1500;
   OS_debug       =true;
   //
   OS_loop_max    =8;
   OS_loop_put    =2;
   

#if defined(HAS_PIN_AV)
   pinMode( _pin, OUTPUT);
#endif

   
   return true;
}



/*!
 * ....
virtual bool  Prepare( int8_t _ix){

   if (OS_loop_i==0){
      //
      Serial.println("\n -->prepare");
      //
      OS_loop_refresh=true;
   }
   //
   return true;
}
*/



/*!
 * once triggert with "OS_loop_refresh"
 * (been reseted by call to API_refresh())
 *@see OS_loop_refresh
virtual bool  Refresh( int8_t _ix){


   

   //
   return true;
}
 */






/*!
 *  each delay
 */
virtual bool  Loop( int8_t _ix){
   //
   
   if (OS_loop_i==0){
      //
      Serial.println(" -->loopX");
   }
   
   int8_t _z=OS_loop_i & 0x07;
   Serial.print( _z);
   
    //vis_line.concat( _z);
    //_VIS_print( 0, true, 0, -1);



  if (_LED0.state){
    _LED0.state=false;
  }
  else{
    _LED0.state=true;
  }
  //
  _LED_sw( 0, _LED0.state);
  
  
  //
  if (OS_param0.put){
    //
    Serial.print( '.');
    //
    //_VIS_print( 0, true, 1, -1);
  }

   return true;
}//loop


/*!
 * each task 
 */
virtual bool  Task( int8_t _ix){

   //
   Serial.print( "\n-->Task#");



   /*
      Serial.println( "-->NB_test: ");
      //
    
         Serial.print( " (int)-> ");
            //
            int64_t _N=-234567;
            Serial.print( " N: _{");
               Serial.print( (char*)_nB.getN( _N, -1, -1, -1));
            Serial.print( "}_ ");
         Serial.println();
            //
         
            double _R=-12345.9876;
            Serial.print( " R: _{");
               Serial.print( (char*)_nB.getR( _R, -1, -1, 3));
            Serial.print( "}_ ");
         Serial.println();
      */    
      
      // OS:str test
      
      Serial.println( "--> OS_test ");
      /*
         Serial.print( "0.) ");
         Serial.print( (char*)com_line);
      Serial.println();
      
      uint8_t _n=0;
      com_line[_n++]=' ';
      com_line[_n++]='A';
      com_line[_n++]='b';
      com_line[_n++]=0;
      //
         Serial.print( "a.) ");
         Serial.print( OS_str_Blen( com_line, CMD_L_MAX));
         Serial.print( " ->");
         Serial.print( (char*)com_line);
      Serial.println();
      */
      //      
      /*
      OS_str_clr( SO_line);
         Serial.print( "c.) trim [");
            OS_str_BaddC( SO_line, -1, "  0123  ", SO_LINE_MAX);
            Serial.print( (char*)SO_line);
         Serial.print( "] _{");

            OS_str_Btrim( SO_line, 0, true, true, SO_LINE_MAX);         
            Serial.print( (char*)SO_line);
         Serial.print( "}_");
      Serial.println();
      */
     
      /*
      OS_str_clr( SO_line);
      
         Serial.print( "d.) bool [");

            OS_str_BaddV( SO_line, -1, false, SO_LINE_MAX);
            OS_str_BaddV( SO_line, -1, '|', SO_LINE_MAX);
            OS_str_BaddV( SO_line, -1, true, SO_LINE_MAX);
            Serial.print( (char*)SO_line);
         Serial.print( "] ");
      Serial.println();
        */
      
      /*
      OS_str_clr( SO_line);
      
         Serial.print( "e.) int [");

            int64_t _N=-0;
            OS_str_BaddN( SO_line, -1, _N, -1, SO_LINE_MAX);
            Serial.print( (char*)SO_line);
         Serial.print( "] ");
         
      Serial.println();
      */

      /*
      OS_str_clr( SO_line);
      
         Serial.print( "f.) double [");

            //double _R=-123450.987;
            double _R=-0.00345678;
            OS_str_BaddR( SO_line, -1, _R, 6, SO_LINE_MAX);
            Serial.print( (char*)SO_line);
         Serial.print( "] ");
         
      Serial.println();
      */
     
      //
      OS_str_clr( SO_line);
      

         /*
         Serial.print( "g.) cmp [");
         
            OS_str_clr( com_line);
            OS_str_BaddC( com_line, -1, "osload", CMD_LINE_MAX);
            OS_str_Btrim( com_line, -1, true, true, CMD_LINE_MAX);
            bool _f=false;
            Serial.print( (char*)com_line);
            Serial.print( '(');
               _f=OS_str_BhasC( com_line, 0, "OSload", false, CMD_LINE_MAX);
               Serial.print( _f);
            Serial.print( '|');
               _f=OS_str_BhasC( com_line, 0, "OSsave", false, CMD_LINE_MAX);
               Serial.print( _f);
            Serial.print( ')');
         Serial.print( "] ");
         */
      Serial.println();
      

     /*
      OS_str_clr( SO_line);
         Serial.print( "h.) CMD [");

         const char* _sC={ "OSload@"};
         uint8_t  _i=0;
         uint8_t  _m=strlen( _sC);
         char   _c;
         for ( ;_i<_m; _i++){
            //
            _c=_sC[_i];
            //
            COM_serialParser( _i, _c);
            //
            
         }//loop
      Serial.println();

      */

      OS_str_clr( SO_line);
         Serial.print( "h.) blink");

#if defined(HAS_PIN_AV)
         //pinMode( _pin, OUTPUT);
         //
         uint8_t _sw=_c0 & 0x01;
         int8_t _level   =_sw ? HIGH:LOW;
         //
         if (_sw>0){
            //
            digitalWrite( _pin, _level);
         }  
         else{
            //
            digitalWrite( _pin, _level);
         } 
         Serial.print( "pin[");
            Serial.print( _pin, HEX);
            Serial.print( '=');
            Serial.print( _sw);
         Serial.print( ']');
#endif

      Serial.println();



    
      OS_str_clr( vis_line);
         OS_str_BaddC( vis_line, -1, "-> cou:", 20);
         OS_str_BaddN( vis_line, -1, _c0, -1, 20);
         //
      _VIS_print( 0, true, 0, -1);



    
   _c0++;
   if (_c0>9){
      _c0=0;
      _c1++;
      if (_c1>9){
         _c1=0;
         _cou=0;
      }
   }   
   //
   Serial.print( _c1);
   Serial.print( _c0);
   //
   Serial.println();

   _cou++;
   //
   
 
   
   return true;
}//task




};//std



// -- installation
#if   defined( API0_STD0_AV)
   ApiBase*  Api0=new API_std0("STD0_#0");
#elif defined( API1_STD0_AV)
   ApiBase*  Api1=new API_std0("STD0_#1");
      #define API1_INSTALL_AV 1
#elif defined( API2_STD0_AV)
   ApiBase*  Api2=new API_std0("STD0_#2");
      #define API2_INSTALL_AV 1
#elif defined( API3_STD0_AV)
   ApiBase*  Api3=new API_std0("STD0_#3");
      #define API3_INSTALL_AV 1
#endif




//@