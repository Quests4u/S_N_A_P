/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       eep.h
* @brief      ext eprom drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/storage/eep.h>



/* Statische Definitions */


/* Dynamische Definitions */


/* Routine Definitions */



bool EEP_saveValues(){
  //
  bool _f=false;



  return _f;
}

/**
 */
bool EEP_serialValueBulk(){
  //
  bool _f=false;



  return _f;
}



#ifdef EEP_16_AV


    /** 24C16 (2048x8)
     */
    byte get_EEPx16( int _adr){
      //
      byte _data = 0xFF;
      int  _aa   = (_adr >> 8) & 0x07;
      int  _cc   = EEP_BASE+(_aa << 1)+1;//<- RD
      {
        Wire.beginTransmission( _cc);
          Wire.write((int)(_adr & 0xFF)); // LSB
        Wire.endTransmission();
        //
        Wire.requestFrom(_adr,1);
        if (Wire.available()){
          //
          _data = Wire.read();
        }
      }
      return _data;
    }//get
    void set_EEPx16( unsigned int _adr, byte _data ) {
      //
      int  _aa   = (_adr >> 8) & 0x07;
      int  _cc   = EEP_BASE+(_aa << 1);//<- WR
      {
        Wire.beginTransmission( _cc);
          Wire.write((int)(_adr & 0xFF)); // LSB
          Wire.write( _data);
        Wire.endTransmission();
      }
      delay(5);
    }//set

#endif



#ifdef EEP_256_AV

    /** 24C256 (16384x8)
     */
    byte get_EEPx256( int _adr){
      //
      byte _data      = 0xFF;
      int  _aa        = ((_adr >> 16) & 0x03);
      int  _cc        = EEP_BASE + (_aa << 1) +1;//<-- RD    
      {
        Wire.beginTransmission( _cc);
          Wire.write((int)(_adr >> 8));   // MSB
          Wire.write((int)(_adr & 0xFF)); // LSB
        Wire.endTransmission();
        //
        Wire.requestFrom( _adr,1);
        //
        if (Wire.available()){
          //
          _data = Wire.read();
        }
      }
      return _data;
    }//get
    void set_EEPx256( unsigned int _adr, byte _data ) {
      //
      int  _aa        = ((_adr >> 16) & 0x03);
      int  _cc        = EEP_BASE + (_aa << 1);//<-- WR    
      {
        Wire.beginTransmission( _cc);
          Wire.write((int)(_adr>> 8));   // MSB
          Wire.write((int)(_adr & 0xFF)); // LSB
          Wire.write( _data);
        Wire.endTransmission();
      }
      delay(5);
    }//set



#endif






//@