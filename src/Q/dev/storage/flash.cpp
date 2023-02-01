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


const char*           _tx_FS      = TX_FS; 
const char*          FS_bulk_file =  FS_BULK_FILE;

//bool            FS_bulk_putstd     = false;


/* WOT .. weird/corrupt readings of FS Info!!
FSInfo        FS0_info= FSInfo{
        1000,//size_t totalBytes;
            0,//size_t usedBytes;
         16,//size_t blockSize;
         64,//size_t pageSize;
         4,//size_t maxOpenFiles;
        128//size_t maxPathLength;
};
*/

FLASH_file_t    FS0  = {
              false         //  has
              ,false        //  had
              //  
              ,false        // store
              ,true         // fmt
              //,&FS0_info  //  info

};





/* Routine Definitions */




/*!
 * Has `FS_bulk_file'?
 */
bool FS_existsValues(){
    //
    //return LittleFS.exists( (char*)FS_bulk_file);
    return LittleFS.exists( FS_bulk_file);
}




    void _FS_notfound( bool _Sout){
#if defined( SIO_AV)
      if (_Sout){
         OS_str_BaddV( SO_line, -1, '<', SO_LINE_MAX);
         OS_str_BaddC( SO_line, -1, FS_bulk_file, SO_LINE_MAX);
         OS_str_BaddC( SO_line, -1, _tx_notexists, SO_LINE_MAX);
      }
#endif
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
    FS0.hasStore=FS_existsValues();
    if (FS0.hasStore){
        File _fs=LittleFS.open( FS_bulk_file, "r");
        if (!_fs){
          FS0.hasStore=false;
        }
        else{
          int  _m = sizeof(OS_bulk_t);
          //
          _fData=_fs.read( OS_bulk.b, _m);
          OS_bulk.t.has=_fData;
          //      
          _fs.close();
        }//open
    }//exists
  }//read
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
    OS_bulk.t.has=true;
      //
    File _fs=LittleFS.open( FS_bulk_file, "w+");
    //
    if (!_fs){ 
      //
      //_FS_notfound( true);
      FS0.hasStore=false;
    }
    else{    
      FS0.hasStore=false;
      int  _m = sizeof(OS_bulk_t);
        bool _fData=_fs.write( OS_bulk.b, _m);
        OS_bulk.t.has=_fData;
        _fs.close();
        //
      _f=_fData;
    }//
  return _f;
}




/*!
 */
bool FS_setup(){
    //
    LittleFSConfig _cfg=new LittleFSConfig();
    _cfg.setAutoFormat( true);
    //
    LittleFS.setConfig( _cfg);
    bool _f=LittleFS.begin();
    if (!_f){
      //  
      _f=LittleFS.format();
      if (_f){
        _f=LittleFS.begin();
      }
      else{
        FS0.hasFmt=false;
      }
    }
    //
    // resume
    if (_f){ 
      //
      FS0.has=true;
      //LittleFS.info(  *FS0.Info);
    }//
    //
    OS_delay( 100);
  return _f;
}









#endif
//@