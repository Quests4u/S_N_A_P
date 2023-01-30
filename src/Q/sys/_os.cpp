/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _def.h
* @brief      common tools
* @date       2022-07-01
* @version    v1.00
*
*/

#include <_config.h>



/* Statische Definitions */


/* Dynamische Definitions */
const char*         _tx_store         = TX_STORE; 

//const char*         _tx_dev           = TX_DEV; 
//const char*         _tx_max           = TX_MAX; 

const char*         _tx_novalue       = TX_NOVALUE;
const char*         _tx_notexists     = TX_NOEXISTS;

const char*         _tx_on            = TX_ONLINE;
const char*         _tx_off           = TX_OFFLINE;

const char*         _tx_ok            = TX_OK;
const char*         _tx_err           = TX_ERR;





uint16_t            OS_init_delay     = DELAY_INIT;// reset info/logo delay (2000)

bool                OS_debug          = true;
bool                OS_info           = false;
bool                OS_nobreak        = false;

bool                OS_loop0          = false;

int8_t             OS_loop_i         = 0;// actual loop 
int8_t             OS_loop_max       = OS_LOOPS;// done loops per task (32)
int8_t             OS_loop_put       = OS_TX_PUT;// [MSX] put loops per task (3)

bool               OS_loop_refresh   = true;//
int16_t            OS_loop_tdown     = -1;//task countdown

uint16_t            OS_loop_delay     = 1;//100;
uint16_t            OS_delay_split    = OS_DELAY_SPLIT;// WOT <- to prevent NMI Block!! (250)

uint64_t            OS_loop_tasks     = 0;//absolut counts from last reset on

bool                OS_msx_state      = false;//need update!
bool                OS_msx_sensor     = true;//sensors on



OS_param_set_t      OS_param0         ={
                      //
                      false     // dbg
                      //
                      ,true     // vis
                      ,false    // put
                      //
                      ,50       // percent (use)
                      ,true     // sensor
                      ,false    // led
};



bool                OS_bulk_putstd    = OS_BULK_PUTSTD;




OS_bulk_u           OS_bulk;



NumberBuffer_set_t  OS_NB= {};



/* Routine Definitions */



//  OS_str: handles


   /*!
    *
    */
   uint8_t  _OS_str_2end( 
                        uint8_t*    _q_B0,
                        int8_t      _q_ofs,
                        uint8_t     _q_max
                        ){
      for( ; _q_ofs<_q_max; ++_q_ofs){
         if (_q_B0[_q_ofs]==0){
            break;
         }
      } 
      return _q_ofs;
   }
   
   
   
   
/*!
 *
 */
uint8_t OS_str_Blen( 
                     uint8_t*       _q_B0, 
                     //
                     int8_t         _q_max
                  ){
      return _OS_str_2end( _q_B0, 0, _q_max);
}
   



/*!
 *
 */
uint8_t OS_str_Btrim( 
                     uint8_t*       _q_B0,
                     int8_t         _q_ofs, 
                     //
                     bool           _q_start,
                     bool           _q_end,
                     //
                     int8_t         _q_max
                  ){
      uint8_t _i=0;
      uint8_t _j=0;
      char _c;
      //
      _q_ofs  = _q_ofs<0 ? 0:_q_ofs;
      // -->
      if (_q_start){
         //
         for( ;_q_ofs<_q_max; _q_ofs++){
            _c=_q_B0[_q_ofs];
            if (!isWhitespace(_c)){
               break;
            }
         }//loop
      }//
      _i=_q_ofs;
      //
      // <--
      uint8_t _q_len=_OS_str_2end( _q_B0, _q_ofs, _q_max);
         //
      if (_q_end){
         _q_len--;
         for( ; (_q_len>0) & (_q_len>_q_ofs);){
            _c=_q_B0[_q_len];
            if (!isWhitespace(_c)){
               break;
            }
            //
            _q_len--;
         }//loop
         _q_len++;
      }//
      //
      // transfer <->
      for( ; _i<_q_len; ){
         _c=_q_B0[_i];
         //
         _q_B0[_j]=_c;
         //
         _j++;
         _i++;
      }
      //
      _q_B0[_j]=0;
      return _j;
}
   




/*!
 *
 */
bool OS_str_BhasC( 
                  uint8_t*       _q_B0,
                  int8_t         _q_ofs, 
                  const char*    _q_C,
                  bool           _q_Gk,                  
                  // 
                  int8_t         _q_max
               ){
   //
   uint8_t _j=0;
   uint8_t _i=0;
   //
   _i  = _q_ofs<0 ? 0:_q_ofs;
   //   
   bool _q_has=false;
   uint8_t  _b;
   char     _c;
   //
   for (; _i<=_q_max; ){
      _b=_q_B0[_i];
      _c=_q_C[_j];
      //
      if (!_q_Gk){
         _b=(_b>=65) ? (_b<=91 ? (_b+32):_b):_b;
         _c=(_c>=65) ? (_c<=91 ? (_c+32):_c):_c;
      }
      //
      _q_has=true;
      //
      if (_b==0){
         //
         if (_c==0){
            break;
         }
         else{
            _q_has=false;
            break;
         }
      }
      else{
         // has
         if (_b!=_c){
            _q_has=false;
            break;
         }   
      }
      //
      _i++;
      _j++;
   }
   //
   return _q_has;
}//has



/*!
 *
 */
uint8_t OS_str_BaddC( 
                     uint8_t*       _q_B0, 
                     int8_t         _q_ofs,
                     const char*    _q_C, 
                     //
                     int8_t         _q_max
                  ){
   //
   uint8_t _j=0;
   uint8_t _i=0;
   //
   if (_q_ofs<0){
      _q_ofs=_OS_str_2end( _q_B0, 0, _q_max);
   }
   _i=_q_ofs;
   //
   bool    _q_end=false;
   uint8_t _b;
   char    _c;
   for( ;_i<(_q_max-1); ){
      //
      _b=_q_B0[_i];
      _c=_q_C[_j];
      //
      if (!_q_end){
         _q_end=_b==0;
      }
      //
      if (_c!=0){
         _q_B0[_i]=_c;
      }
      else{
         break;
      }
      //
      _i++;
      _j++;
   }//loop
   //
   if (_q_end){
      _q_B0[_i]=0;
   }
   //
   return _i;
}//BcopyC



/*!
 *
 */
uint8_t OS_str_BaddB( 
                     uint8_t*       _q_B0,
                     int8_t         _q_ofs, 
                     uint8_t*       _q_B1,
                     // 
                     int8_t         _q_max
                     //
                  ){
   //
   uint8_t _j=0;
   uint8_t _i=0;
   //
   if (_q_ofs<0){
      _q_ofs=_OS_str_2end( _q_B0, 0, _q_max);
   }
   _i=_q_ofs;
   //
   bool    _q_end=false;
   uint8_t _b0,_b1;
   for( ;_i<(_q_max-1); ){
      //
      _b0=_q_B0[_i];
      _b1=_q_B1[_j];
      //
      if (!_q_end){
         _q_end=_b0==0;
      }
      //
      if (_b1!=0){
         _q_B0[_i]=_b1;
      }
      else{
         break;
      }
      //
      _i++;
      _j++;
   }//loop
   //
   if (_q_end){
      _q_B0[_i]=0;
   }
   //
   return _i;
}
   


/*!
 *
 */
uint8_t OS_str_BaddV(
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     char        _q_v,
                     //
                     int8_t      _q_max
                     ){
   uint8_t _i=0;
   //
   if (_q_ofs<0){
      _q_ofs=_OS_str_2end( _q_B0, 0, _q_max);
   }
   _i=_q_ofs;
   //                     
   _q_B0[_i]=_q_v;
   _i++;
   _q_B0[_i]=0;
   return _i;
}
   



/*!
 *
 */
uint8_t OS_str_BaddV(
                     uint8_t*       _q_B0,
                     int8_t         _q_ofs,
                     bool           _q_v,
                     //
                     int8_t         _q_max
                     ){
      char _c=_q_v ? '1':'0';
      return OS_str_BaddV( _q_B0, _q_ofs, _c, _q_max);
}




/*!
 *
 */
uint8_t OS_str_BaddN(
                     uint8_t*       _q_B0,
                     int8_t         _q_ofs,
                     int64_t        _q_v,
                     //
                     int8_t         _q_base,
                     int8_t         _q_max
                     ){
      //
      uint8_t* _q_=OS_NB.getN( _q_v, _q_base, -1, -1);
      //
      uint8_t _i=OS_str_BaddB( _q_B0, _q_ofs, _q_, _q_max);
      //
   return _i;
}
   


/*!
 *
 */
uint8_t OS_str_BaddR(
                     uint8_t*       _q_B0,
                     int8_t         _q_ofs,
                     double         _q_v,
                     //
                     int8_t         _q_dcp,
                     int8_t         _q_max
                     ){
      //
      uint8_t* _q_=OS_NB.getR( _q_v, -1, -1, _q_dcp);
      //
      uint8_t _i=OS_str_BaddB( _q_B0, _q_ofs, _q_, _q_max);
      //
   return _i;
}
   



   
/*!
 *
 */
void     OS_str_clr(
                     uint8_t* _q_B0
                     ){
         _q_B0[0]=0;
}







// *** delay

/*!
 * interuped delay,
 * (USE insteads of direct Delay(..))
 * 
 */
void  OS_delay( int16_t _delay){
    //
#if defined( OS_DELAY_AV)
    bool _f=true;
    while( _f){
        //
        if (_delay>OS_delay_split){
          //
          yield();
          //
          _delay=_delay-OS_delay_split;
          delay( OS_delay_split);
        }
        else{
          //
          _f=false;
          delay( _delay);
        }
    }//loop
#else
     delay( _delay);
#endif

}



// OS storage





//@