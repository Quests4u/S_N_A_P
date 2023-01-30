/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       NumberBuffer.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup NumberBuffer, int, int8_t, int16_t, int32_t, int64_t
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef NUMBERBUFFER_H_
#define NUMBERBUFFER_H_ 1



/* Header includes */



/* Statische Definitions */

#if defined(AVR_328_AV)
   #define NB_MAX  28
#else
   #define NB_MAX  60
#endif


/*!
 *
 */
struct  NumberBufferBase_t{


   double      r=0.0;
   int8_t      dcp=3;
   uint32_t    dcpX=1000;         

   int64_t     n=0;
   int64_t*    n_=&n;
   
   uint8_t     noB=0;
   
   uint8_t     Bx[NB_MAX+3]={ 0};
   uint8_t*    nB_=&Bx[0];//  export

   uint8_t*    t=&Bx[0];
   int8_t      i=0;
   int8_t      m=0;
         //
   int8_t      M=NB_MAX;
   bool        has=true;


      bool     nNR=false;//   .. normal(++)/reverse(--) <- m = n mod base; is bulit reverse!!
      bool     nSIGN=false;// .. + | - is shown
      
      int8_t   nPad=-1;
      int8_t   nBase=DEC;
   
   
   // methodes

   
   

  

};//NumberBufferBase_t




extern const char*  OS_TX_HEX;
extern const char*  OS_TX_DEC;
extern const char*  OS_TX_OCT;
extern const char*  OS_TX_BIN;
//
extern const char*  OS_TX_VZ;





/* Dynamische Definitions */






/* Routine Definitions */



/*!
 *
 */
extern   char    Number_ix2char( 
                  int8_t _i
                  ,int8_t _base
                  );


/*!
 * number = number % digit -> rest 
 */
extern   int8_t Number_mod64_n(
                  NumberBufferBase_t* _   
                        );



/*!
 *
 */
extern char  Number_ix2char( 
                  NumberBufferBase_t* _,   
                  int8_t _i
                  );


/*!
 *
 */
extern void  Number_start_nB(
                  NumberBufferBase_t* _,
                  //   
                  bool     _NR
                  ,int8_t  _base
                  ,int8_t  _pad
                  ,int8_t  _dcp
                  );


/*!
 *
 */
extern uint8_t  Number_insert_nB(
                  NumberBufferBase_t* _,   
                  char _c 
                  );




/*!
 *
 */
extern uint8_t*  Number_end_nB(
                  NumberBufferBase_t* _  
                     );



/*!
 *

extern uint8_t*  Number_test(
                  NumberBufferBase_t* _  
                     );

*/



/*!
 *
 */
struct NumberBuffer_set_t: public NumberBufferBase_t{



   
      uint8_t* get(){
         //
         return nB_;
      };
   


   
      uint8_t* getN( 
            int64_t _
            ,int8_t _base
            ,int8_t _pad
            ,int8_t _dcp 
            ){
         //
         n=_;
         //
         Number_start_nB( this, false, _base, _pad, _dcp);
         //
         int8_t _i=0;
         char   _c=0;
         char   _sign=0;// sign
         //char   _D=0;// dot
         //
         bool _f=false;
         // signum
         if (n<0){
            _sign=OS_TX_VZ[0];
         }
         else if (nSIGN){
            _sign=OS_TX_VZ[1];
         }//
         //
         // normal:
         if (nNR){
            // 
            if (_sign>0){
               Number_insert_nB( this, _sign);
            }
         }
   
         // number
            int8_t _j=65;//WOT!
         while( !_f){
            //
            _i=Number_mod64_n( this);
            _c=Number_ix2char( this, _i);
            //
            Number_insert_nB( this, _c);
            //
            _f=(n==0)|(_j<0);
            _j--;
            
         }//loop
         //
         //
         // reverse:
         if (!nNR){
            // 
            if (_sign>0){
               Number_insert_nB( this, _sign);
            }
         }
         //
         // cut( i -> m);
         Number_end_nB( this);
         //
         return nB_;          
      };  



      /*!
       *
       */
      uint8_t* getR( 
            double _
            ,int8_t _base
            //
            ,int8_t _pad
            ,int8_t _dcp
            ){
         //
         r=_;
         Number_start_nB( this, false, _base, _pad, _dcp);
         //
         n=abs(_*dcpX);
         //
         uint8_t* _p=getN( n, _base, _pad, _dcp);
         //
         //
         uint8_t _l=m-i;
         //uint8_t _j=m-(dcp+1);
         uint8_t _j=m-dcp;
         /*
         Serial.print( '[');
         Serial.print( _j);
         Serial.print( '|');
         Serial.print(  i);
         Serial.print( ',');
         Serial.print( m);
         Serial.print( ';');
         Serial.print( _l);
         Serial.print( ']');
         */
            // after comma
                 if (_l<=dcp){
                    //
                    for( ; i>=_j; i--){
                       t[i-1]='0';
                    }
                    //
                 }
            
            // comma insert
            for( uint8_t _k=m; _k>=_j; _k--){
               t[_k+1]=t[_k];
            }
            t[_j]=OS_TX_VZ[2];
            
            // sign
            if (_<0){
               i--;
               t[i]=OS_TX_VZ[0];
            }
            else if (nSIGN){
               i--;
               t[i]=OS_TX_VZ[1];
            }//
         //
         // ptr
         _p=&t[i];
         nB_=_p;
         return _p;
      };      
   
   

      /*!
       *
      uint8_t* test( 
            double _
            ,int8_t _base
            //
            ,int8_t _pad
            ,int8_t _dcp
            ){
         //
         Number_start_nB( this, false, _base, _pad, _dcp);
         //
         //
         Serial.print( "dcp:[");
         Serial.print( dcp);
         Serial.print( "] <= ");
         Serial.print( dcpX);
         //
         r=_;
         n=_*dcpX;
         Serial.print( " !(");
         Serial.print( (int32_t)n);
         Serial.print( ")_N{");
         
         uint8_t* _p=getN( n, _base, _pad, _dcp);
         //
         Serial.print( (char*)_p);
         Serial.print( "}_(");
            Serial.print( i);
            Serial.print( '/');
            Serial.print( m);
            Serial.print( '/');
         
         uint8_t _d=m-dcp;
         for( uint8_t _i=m; _i>=_d; _i--){
            t[_i+1]=t[_i];
         }
         t[_d]=OS_TX_VZ[2];
         //
            Serial.print( dcp);
            Serial.print( '/');
            Serial.print( _d);
            Serial.print( ")_");

         return _p;
      };      
       */
   
   



         



         



   
};//NumberBuffer












#endif
//@
