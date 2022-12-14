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



#ifdef TWI_SCAN_AV


#include <Wire.h>





/* Dynamische Definitions */



// -- in general
byte            _TWI[TWI_MAX]  = {   0x66,0x67,
                                      0x76,0x77,
                                      0x3C,0x3D,
                                      0x07,0x0D,
                                      0x78,0x7D
                                  };
byte                 _TWI_cou      = 0;                          
byte                 _TWI_max      = TWI_MAX;

const char*         _tx_twi_dev    = TX_TWI_DEV;//"device = ";
const char*         _tx_twi_max    = TX_TWI_MAX;//"[!]";






/* Routine Definitions */





bool TWI_port( byte _i2c){
    if (_i2c>0){
      Wire.beginTransmission( _i2c);
      byte _ex=Wire.endTransmission();
      return (_ex==0);
    }
    return false;
}



void  TWI_scanner( bool _show){
  //
  byte _i2c,
       _cou=0;
  bool _valid;
       
  //
  if (_show){
    //
    Serial.println("TWI:");
  }
  for( _i2c=TWI_SCAN_B0; _i2c<=TWI_SCAN_E0; _i2c++){
    //
    if (TWI_port( _i2c)){
      //
      _valid=_cou<_TWI_max;
      //
      if (_show){
          //
          Serial.print( _tx_twi_dev);
          //Serial.print( TX_TWI_DEV);
          if (!_valid){
            Serial.print( _tx_twi_max);
            //Serial.print( TX_TWI_MAX);
          }
          Serial.print( SO_hex);
          Serial.println( _i2c,HEX);
          //
      }
      //
      _TWI[_cou]=_i2c;
      _cou++;
      //
    }//has
    //
  }//loop
  //
  if (_cou==0){
    if (_show){
      Serial.println( _tx_novalue);
      //Serial.println( TX_VX_NONE);
      
    }
  }
  _TWI_cou=_cou;

}





#endif
#endif
//@