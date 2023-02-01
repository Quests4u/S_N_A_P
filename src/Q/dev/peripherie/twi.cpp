/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       Q/twi.h
* @brief      two wire [i2c] drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/peripherie/twi.h>


#if defined(TWI_AV)





#include <Wire.h>





/* Dynamische Definitions */


const char*          _tx_TW   = TX_TW;



// -- in general
uint8_t            _TWI_REF[TWI_MAX]  = {    
                                 0x3C,0x3D,
                                 0x07,0x0D,
                                 0x66,0x67,
                                 0x76,0x77,
                                 0x78,0x7D,
                                 0x00
                     };
uint8_t             _TWI[TWI_MAX];    
uint8_t             _TWI_cou      = 0;                          

uint16_t            _TWI_timeout   = TWI_TIMEOUT;





/* Routine Definitions */
/*!
 * TWI setup
 */
bool TWI_setup( int8_t _ix){
  //
  bool _f=false;
  Wire.begin();
  Wire.setTimeout( _TWI_timeout);
  //
  _f=true;
  OS_delay( 200);
  //
  return _f;
}



/*!
 * TWI test a port!
 */
bool TWI_port( uint8_t _i2c){
    uint8_t _ex=0;  
    if (_i2c>0){
        //
        //
        Wire.beginTransmission( _i2c);
        OS_delay( 20);
        _ex=Wire.endTransmission( false);
        //
      return (_ex==0);

        //uint8_t requestBytesRead = Wire.requestFrom( _i2c, 1);        
        //bool _f=requestBytesRead==1;
        //return _f;
    }
    return false;
}


#if defined( TWI_SCAN_AV)


void  TWI_scanner( bool _show){
  //
  uint8_t   _i2c,
            _cou;
  //
  _cou   =0;
  if (_show){
    //
    Serial.print( _tx_TW);
    Serial.print( '~');
  }
  //
  for( int8_t _i=0; _i<TWI_MAX; _i++){
      //
      _i2c=_TWI_REF[_i];
      //
      if (TWI_port( _i2c)){
         //
         _TWI[_cou]=_i2c;
         _cou++;
         //
         if (_show){
            //
            //Serial.println();
            Serial.print( ',');
            //Serial.print( SO_hex);
            Serial.print( OS_at);
            Serial.print( _i2c, HEX);
            //
         }//show
      }//has
   }//loop
   //
      if (_show){
         Serial.println();
      }
   _TWI_cou=_cou;
   //
}

#endif




#endif
//@