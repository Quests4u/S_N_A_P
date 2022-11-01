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

#include <EEPROM.h>



/* Statische Definitions */






/* Dynamische Definitions */

int EP_prem_adr        = EP_ADR( 0);


bool                   EP_none_putstd     = EP_NONE_PUTSTD;

const char*            EP_sum0            = EP_SUM;
const char*            EP_sum_n0          = EP_SUM_N;

const char*            EP_prem0           = EP_PREM;
const char*            EP_prem_n0         = EP_PREM_N;

const char*            EP_data_read0      = EP_DATA_READ;

int                    EP_data_adr        = EP_DATA_ADR_START;



EP_prem_u  EP_prem;


int EP_bulk_adr     = EP_ADR( sizeof( EP_prem_t));


EP_bulk_u   EP_bulk;



/* Routine Definitions */

/** insert fillxxx  meth. with std/load/save values! ***/

/*
          void _EP_fillStdValues(){ 
            //
          }

          void _EP_fillValues2Bulk(){
            //
          }

          void _EP_fillBulk2Values(){
            // 
          }
*/



// Handles

      void _EP_resetPrem(){
        //
        EP_prem.t.Valid  = false;
        memcpy( EP_prem.t.prem, EP_PREM_N, EP_PREM_L);
        memcpy( EP_prem.t.sum, EP_SUM_N  , EP_SUM_L);
        //
      }
      void _EP_getPrem(){
        //
          uint8_t   _b  = 0;
          int  _m  = sizeof(EP_prem_t);
          int  _o  = -1;
          for( int _i=0; _i<_m; _i++){
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
          int _m   = sizeof(EP_prem_t);
          int _o   = -1;
          for( int _i=0; _i<_m; _i++){
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
        if (EP_prem.t.Valid){
          //
          int  _m=EP_SUM_L;
          int _i=memcmp( EP_prem.t.sum, EP_SUM, _m);
          //
          //WOT:! 
          //_i=1;
          return (_i==0);
        }
        return false;
      }
    
      bool _EP_checkBulk(){
        //
        if (EP_bulk.t.Valid){
          //
          int  _m=EP_PREM_L;
          int _i=memcmp( EP_bulk.t.prem, EP_PREM, _m);
          //
          return (_i==0);
        }
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
        int  _m = sizeof(EP_bulk_t);
        int  _o = -1;
        for( int _i=0; _i<_m; _i++){
          //
          _o=_i+EP_bulk_adr;
          _b=EEPROM.read( _o);
          EP_bulk.b[_i]=_b;
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
    _EP_fillStdValues();
    _f=true;
  }
  // 
  // strategie
  // fill in bulk -> var
  if (_fData){
    //
    _EP_fillBulk2Values();
    _f=true;
  }
  else{
    if (EP_none_putstd){
      //
      _EP_fillStdValues();
      //_f=true??? maybe
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
    _EP_fillValues2Bulk();
    // put closing prem;
    memcpy( EP_bulk.t.prem, EP_PREM, EP_PREM_L);
    // set Valid
    EP_bulk.t.Valid=true;
      //
      uint8_t _b    = 0;
        int  _m = sizeof(EP_bulk_t);
        int  _o = -1;
        for( int _i=0; _i<_m; _i++){
          //
          _o=_i+EP_bulk_adr;
          _b=EEPROM.read( _o);
          if (EP_bulk.b[_i]!=_b){
            //
            _b=EP_bulk.b[_i];
            EEPROM.write( _o, _b);
          }
        }
      //
      _f=true;
  return _f;
}









//@