/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       flash.h
* @brief      flash lite files drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/storage/flash.h>

#if defined(FLASH_AV)


/* Statische Definitions */


/* Dynamische Definitions */

String          FS_bulk_file       = String( FS_BULK_FILE);


bool            FS_bulk_putstd     = false;


/* Routine Definitions */


/*!
 * Has `FS_bulk_file'?
 */
bool FS_setup(){
    //
#if defined( SIO_AV)
    SO_line.concat( "sFS(");
#endif
    //
    LittleFSConfig _cfg;
    _cfg.setAutoFormat( false);
    //
    LittleFS.setConfig( _cfg);
    bool _f=LittleFS.begin( );
    if (!_f){
      //  
      LittleFS.format();
#if defined( SIO_AV)
        SO_line.concat( "~fmt");
#endif        
      _f=LittleFS.begin();
    }
    //
#if defined( SIO_AV)
      SO_line.concat( "!)\n");
#endif
    //
    OS_delay( 100);
  return _f;
}





/*!
 * Has `FS_bulk_file'?
 */
bool FS_existsValues(){
    //
    return LittleFS.exists( FS_bulk_file);
}





/*!
 *  @param _read .. true/false [read from FLASH_FS. / use std.]
 */
bool FS_loadValues( bool _read){
  //
  bool _f     =false;
  bool _fData =false;
  // 
  if (_read){
    //
    File _fs=LittleFS.open( FS_bulk_file, "r");
    if (!_fs){
      //
    }
    else{
      //
      int  _m = sizeof(OS_bulk_t);
        //
        _fData=_fs.read( OS_bulk.b, _m);
        //      
      _fs.close();
    }
  }
  else{
    //
    _OS_fillStdValues();
    _f=true;
  }
  // 
  if (_fData){
    //
    _OS_fillBulk2Values();
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


bool FS_saveValues(){
  //
  bool _f=false;
  //
    // fillin var -> store
    _OS_fillValues2Bulk();
    // set Valid
    OS_bulk.t.Valid=true;
      //
    File _fs=LittleFS.open( FS_bulk_file, "w+");
    //
    if (!_fs){  
    }
    else{    
      int  _m = sizeof(OS_bulk_t);
      
        bool _fData=_fs.write( OS_bulk.b, _m);
        _fs.close();
        //
      _f=_fData;
    }//
  return _f;
}







#endif
//@