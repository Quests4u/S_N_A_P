/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       ep.h
* @brief      internal eeprom drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/storage/ep.h>


#if defined(EP_AV)


/* Statische Definitions */
#include <EEPROM.h>






/* Dynamische Definitions */

const char*             _tx_EP    = TX_EP;



int                     EP_prem_adr        = EP_ADR( 0);


int                     EP_data_adr        = EP_DATA_ADR_START;



EP_prem_u               EP_prem;


int EP_bulk_adr         = EP_ADR( sizeof( EP_prem_t));




/* Routine Definitions */



// Handles

      void _EP_resetPrem(){
        //
        EP_prem.t.Valid  = false;
  #if defined( EP_AV)
        memcpy( EP_prem.t.prem, EP_PREM_N, EP_PREM_L);
        memcpy( EP_prem.t.sum, EP_SUM_N  , EP_SUM_L);
  #endif
        //
      }
      
      
      
      void _EP_getPrem(){
        //
          uint8_t   _b  = 0;
          int16_t  _m  = sizeof(EP_prem_t);
          int16_t  _o  = -1;
          for( int16_t _i=0; _i<_m; _i++){
            //
            _o=_i+EP_prem_adr;
            _b=EEPROM.read( _o);
            EP_prem.b[_i]=_b;
          } 
      }
      
      
      void _EP_setPrem(){
        //
        EP_prem.t.Valid  = true;
        memcpy( EP_prem.t.prem, EP_PREM, EP_PREM_L);
        memcpy( EP_prem.t.sum, EP_SUM, EP_SUM_L);
        //
          uint8_t  _b   = 0;
          int16_t _m   = sizeof(EP_prem_t);
          int16_t _o   = -1;
          for( int16_t _i=0; _i<_m; _i++){
            //
            _o=_i+EP_prem_adr;
            _b=EEPROM.read( _o);
            if (EP_prem.b[_i]!=_b){
              //
              _b=EP_prem.b[_i];
              EEPROM.write( _o, _b);
            }
          } 
      }
      
      
      
      bool _EP_checkPrem(){
        //
          //
  #if defined( EP_AV)
          int16_t  _m=EP_SUM_L;
          int16_t _i=memcmp( EP_prem.t.sum, EP_SUM, _m);
          //
          return (_i==0);
  #else
        //}
        return false;
  #endif
      }
    
      bool _EP_checkBulk(){
        //
  #if defined( EP_AV)
        //if (OS_bulk.t.Valid){
        if (OS_bulk.t.has){
          //
          int16_t  _m=EP_PREM_L;
          int16_t _i=memcmp( OS_bulk.t.prem, EP_PREM, _m);
          return (_i==0);
          //
        }
  #endif
        return false;
      }



/**
 *  @param _read .. true/false [read from EEP. / use std.]
 */
bool EP_loadValues( bool _read){
  //
  bool _f     =false;
  bool _fData =false;
  // select
  if (_read){
    //
    _EP_getPrem();
    //
    if (_EP_checkPrem()){
      //
      uint8_t _b    = 0;
        int16_t  _m = sizeof(OS_bulk_t);
        int16_t  _o = -1;
        for( int16_t _i=0; _i<_m; _i++){
          //
          _o=_i+EP_bulk_adr;
          _b=EEPROM.read( _o);
          OS_bulk.b[_i]=_b;
        }       
      _fData=_EP_checkBulk();
    }
    else{
      //
      _EP_resetPrem();
    }
  }
  else{
    //
    _OS_fillStdValues();
    _f=true;
  }
  // 
  // strategie
  // fill in bulk -> var
  if (_fData){
    //
    _OS_fillBulk2Values();
    OS_bulk.t.has=true;
    _f=true;
  }
  else{
    if (OS_bulk_putstd){
      //
      _OS_fillStdValues();
    }
  }
  //
  return _f;
}


bool EP_saveValues(){
  //
  bool _f=false;
  //
  // prem: refreah
  _EP_setPrem();
  //
    // fillin var -> store
    _OS_fillValues2Bulk();
    // put closing prem;
  #if defined(EP_AV)
    memcpy( OS_bulk.t.prem, EP_PREM, EP_PREM_L);
  #endif
    // set Valid
    //OS_bulk.t.Valid=true;
    OS_bulk.t.has=true;
      //
      uint8_t _b    = 0;
        int16_t  _m = sizeof(OS_bulk_t);
        int16_t  _o = -1;
        for( int _i=0; _i<_m; _i++){
          //
          _o=_i+EP_bulk_adr;
          _b=EEPROM.read( _o);
          if (OS_bulk.b[_i]!=_b){
            //
            _b=OS_bulk.b[_i];
            EEPROM.write( _o, _b);
          }
        }
      //
      _f=true;
  return _f;
}








#endif
//@