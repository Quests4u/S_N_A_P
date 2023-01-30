/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @brief      application     
* @date       2022-07-01
* @version    v1.00
*
*/

#include <api.h>




/* Statische Definitions */


/* Dynamische Definitions */
const char* _tx_noapiname  = TX_NOTITLE;





ApiBase*       APIb[] ={
   
       NULL
      ,NULL
      ,NULL
      ,NULL

};
int8_t            api_am   =0;
  
  
  

/* Routine Definitions */



bool  APIxNoCall( int8_t _ix){

Serial.println( "->Api:NoCall");

   return true;
}


/*!
 *
 */
int8_t APIxNext( 
             bool _none
            ,bool _set
            ){
    //
    int8_t _ai=-1;
    ApiBase* _api;
    for (int8_t _i=0; _i<API_MAX; _i++){
      //
      _api=APIb[_i];
      //
      if (_api==NULL){     
        //
        _ai=_i;
        break;
      }
      //
    }//loop
    //
      if ((_set)
         &(_ai>=0)
         ){
         //
         if (_ai==api_am){
            api_am=_ai+1;
         }
         else if (_ai>api_am){
            api_am=_ai;
         }
         //
      }//set
   //   
   return _ai;
}




/*!
 *
 */
bool APIxInstall(
      ApiBase* _api
){
    //
    bool _f=false;
    //
    if (_api!=NULL){
      //index
      int8_t _ai =APIxNext( true, true);
#if (SIO_AV)
      Serial.print( "install@");
         Serial.print( _ai);
            Serial.print( ": ");
#endif
      //
      if (_ai>=0){
         //
         if (_api->Title==NULL){
            //
            _api->Title=_tx_noapiname;
         }
#if (SIO_AV)
               Serial.println( _api->Title);
#endif
         //
         APIb[_ai]=_api;
         //
            _api->Has=true;
         //
         
         _f=true;
      }//has
      else{
#if (SIO_AV)
               Serial.println( _tx_notexists);
#endif
      }
   }//!null
   return _f;
}//install




// class::API




   ApiBase::ApiBase(){
      //
      Title= _tx_noapiname;
   }

   
   ApiBase::ApiBase( const char* _Title){
      //
      Title= _Title;
   }
   
   

  
      


   bool  ApiBase::Cmd( int8_t _ix){
      //
      return false;
   }
   bool  ApiBase::Setup( int8_t _ix){
      //
      return false;
   }
   bool  ApiBase::Prepare( int8_t _ix){
      //
      return false;
   }
   bool  ApiBase::Refresh( int8_t _ix){
      //
      return false;
   }
   bool  ApiBase::Loop( int8_t _ix){
      //
      return false;
   }
   bool  ApiBase::Task( int8_t _ix){
      //
      return false;
   }








// **  interface

/*!
 * put cmd each start
 */
bool  _hasAPICmd=false;
void  API_cmd( int8_t _ix){


   if (!_hasAPICmd){
      //
      for (int _i=0; _i<api_am; _i++){
         //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Cmd(_ix);
         }
         //
      }//loop
      //
      _hasAPICmd=true;
   }//
}


/*!
 * setup(refresh) each start
 */
void  API_setup( int8_t _ix){
   
      for (int _i=0; _i<api_am; _i++){
         //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Setup(_ix);
         }
         //
      }//loop
}//setup





/*!
 * prepare each loop
 */
void  API_prepare( int8_t _ix){

      for (int _i=0; _i<api_am; _i++){
         //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Prepare(_ix);
         }
         //
      }//loop
}//prepare



/*!
 *  visual/mesure/check refresh
 */
void  API_refresh( int8_t _ix){
   //
   Serial.println( "->API:refresh");
      
       for (int _i=0; _i<api_am; _i++){
        //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Refresh(_ix);
         }
         //
      }//loop
}//refresh



/*!
 *  each delay
 */
void  API_loop( int8_t _ix){
   //
      for (int _i=0; _i<api_am; _i++){
         //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Loop(_ix);
         }
         //
      }//loop
}//loop



/*!
 * each wait stop 
 */
void  API_task( int8_t _ix){

 
      //
      for (int _i=0; _i<api_am; _i++){
         //
         if (APIb[_i]!=NULL){
            //
            APIb[_i]->Task(_ix);
         }
         //
      }//loop
}//task






/*!
 *
 */
 bool API_install(
         const char* _Title
         ,ApiBase* _api
            ){
   bool _f=false;
        
      if (_api){
         //
         //_api->Title=_Title;
         //
         _f=APIxInstall( _api);
      }    
            
   return _f;
}// install


//@