/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       NumberBuffer.h
* @brief      number(format) drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/sys/lang/NumberBuffer.h>



/* Statische Definitions */


const char*  OS_TX_HEX = "0123456789ABCDEF";
const char*  OS_TX_DEC = "0123456789";
const char*  OS_TX_OCT = "01234567";
const char*  OS_TX_BIN = "_1";
//
const char*  OS_TX_VZ  = "-+.e";




/* Dynamische Definitions */




/* Routine Definitions */


/*!
 *  ziffer[_i] -> char
 *@param  _i    .. _ziffer  
 *@param  _base  .. [HEX/OCT/BIN]DEC 
 */
char    Number_ix2char( 
                  int8_t _i
                  ,int8_t _base
                  ){
   //
   char _c=0;
   _i=abs(_i);
   //
   switch( _base){
   
   case HEX:
         _i=_i & 0x0F;
         _c=OS_TX_HEX[_i];
      break;
      
   case OCT:
         _i=_i &0x07;
         _c=OS_TX_OCT[_i];
      break;
   case BIN:
         _i=_i &0x01;
         _c=OS_TX_BIN[_i];
      break;

   case DEC:
   default:
         _i=_i>9 ? 9:_i;
         _c=OS_TX_DEC[_i];
      break;
   }
   return _c;
}//char



// -----


/*!
 * number = number % digit -> rest 
 */
int8_t Number_mod64_n(
                  NumberBufferBase_t* _   
                        ){
   //
   int8_t _m= (*_->n_) % _->nBase;
   //
   *_->n_  = (*_->n_)/_->nBase;
   //
   return _m;
}//mod

 
 
 
char  Number_ix2char( 
                  NumberBufferBase_t* _,   
                  int8_t _i
                  ){
   return Number_ix2char( _i, _->nBase);
}//char
   
   
   
   
   
void  Number_start_nB(
                  NumberBufferBase_t* _,
                  //   
                  bool     _NR
                  ,int8_t  _base
                  ,int8_t  _pad
                  ,int8_t  _dcp
                  ){
   //
   //int8_t _x=_NR  ? 1:_->M-1;
   int8_t _x= _->M >> 1;// --> M shr 1 = M/2  start middest!
   //
   _->nNR=_NR;
   _->nPad=_pad;
   //
   if (_base<2){
      _base=DEC;
   }
   _->nBase=_base;
   //
   uint8_t  _d=(_dcp<0) ? 0:_dcp;
            _d=(_d>=8) ? 8:_d;
   _->dcp=_d;
      uint32_t _D=1;
      for( int8_t _i=0; _i<_d; _i++){
            _D=_D*_base;
      } 
   _->dcpX=_D;
   //
   _->i=_x;
   _->m=_x;
   //
   _->t[_x]=0;
}





uint8_t  Number_insert_nB(
                  NumberBufferBase_t* _,   
                  char _c 
                  ){
   //
   _->t[_->m]=_c;
   //
   // normal  ->
   if (_c!=0){
      if (_->nNR){
         //
         if (_->m<_->M){
            //
            _->m++;
         }
      }
      //
      // reverse <-
      else{
         if (_->m>0){
            //
            _->m--;
         }
      }
   }
   //
   return _->m;
}//insert






uint8_t*  Number_end_nB(
                  NumberBufferBase_t* _
                     ){
   //
   if (_->nNR){
      //
      _->t[_->m]=0;
      _->nB_=(uint8_t*)&_->t[_->i];
      //
      
   }
   else{
      //
      uint8_t _m=_->i+1;
      _->t[_m]=0;
      _->i=++_->m;//<- one back
      _->m=_m;
      _->nB_=(uint8_t*)&_->t[_->i];//
   }
   //
   return _->nB_;
}//ptr















//@