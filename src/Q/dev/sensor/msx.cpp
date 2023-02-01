/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       MSX.h
* @brief      sensor drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/sensor/msx.h>




/* Statische Definitions */


/* Dynamische Definitions */

const char*         _tx_msx        = TX_MSX;
const char*         _tx_msx_head   = TX_MSX_HEAD;


bool                _MSX0_Has         = false;
bool                _MSX0_Had         = false;
bool                _MSX0_Values      = false;
uint8_t             _MSX0_i2c         = 0;//<-- incase its I2C(TWI)


//uint8_t     MSX_0_head_b[MSX_HEAD_MAX+2]  = { 0};
MSX_set_t       _MSX_0    ={
                                  false,//has
                                  false,//had
                                  //
                                  0,//i2c
                                  //
                                  false,//v
//                                  &MSX_0_head_b[0],//(By)
                                  _tx_msx
                                  //
                              };
MSX_snv_t       _MSX_sn0    ={
                                  false,
                                  //
                                  0.0,
                                  0.0,
                                  0.0
};


MSX_value_t     MSXVx[ MSXVX_MAX]   ={


};




#if defined( MSX_EN_AV)
// --- beg: sensor objects


#ifdef BMP_280_AV

#ifdef ADF_P280_AV

Adafruit_BMP280 BMP0_280; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);


#endif

#endif


#ifdef BME_280_AV

#ifdef JWA_E280_AV
Bme280BoschWrapper  BME0_280        (true);
//--> Dont try!! -> Bme280BoschWrapper  BME280_1        (true);

#endif

#ifdef ADF_E280_AV
Adafruit_BME280     BME0_280;
//--> Dont try!! -> Adafruit_BME280     BME280_1;
#endif


#endif


//------ end: sensor object  
#endif

/* Routine Definitions */


/**
 * 
 */
bool _MSX_setup( int8_t _ix){
  //
  bool _f=false;
  //
  #if defined( MSX_EN_AV)
  //--- enable
  //
  #if defined( ADF_P280_AV)
  /*
    BMP0_280.setSampling(
                  Adafruit_BMP280::MODE_FORCED,     
                  // Operating Mode. 
                  Adafruit_BMP280::SAMPLING_X2,     
                  // Temp. oversampling 
                  Adafruit_BMP280::SAMPLING_X16,    
                  // Pressure oversampling 
                  Adafruit_BMP280::FILTER_X16,      
                  // Filtering. 
                  Adafruit_BMP280::STANDBY_MS_500   
                  // Standby time. 
    );
  */
    BMP0_280.setSampling(
                  Adafruit_BMP280::MODE_FORCED
    );
    _f=true;
  #endif
  //
  #ifdef ADF_E280_AV
    _f=true;
  #endif
  //
  #ifdef JWB_E280_AV
    _f=true;
  #endif


  OS_delay( 100);
  //--- enable
  #endif

  return _f;
}




/*!
 *  find I2C of BMP/180[280] .. BME280 and start
 * @return true(found)
 */
bool _MSX_prepare( int8_t _ix){
  //
  bool _f=false;
  //
#if defined( MSX_EN_AV)
  uint8_t _i2c;
//---- enable

#ifdef TWI_AV
  for( uint8_t _i=0;(!_f)&(_i<_TWI_cou); _i++){
    _i2c=_TWI[_i];
#endif
    //
    if (_ix==0){
      _MSX0_i2c=_i2c;

#ifdef BMP_280_AV
#ifdef ADF_P280_AV
        if (BMP0_280.begin( _i2c)){
            _MSX_0.i2c=_i2c;
            //
            //OS_str_clr( _MSX_0.head);
            //OS_str_BaddC( _MSX_0.head, -1, MSX_TX_P280, MSX_HEAD_MAX);
            //
          _f=true;
        }
#endif
#endif
//
#ifdef BME_280_AV
#ifdef JWA_E280_AV
        if (BME0_280.beginI2C( _i2c)){
          _MSX0_i2c=_i2c;
            //
            //OS_str_clr( _MSX_0.head);
            //OS_str_BaddC( _MSX_0.head, -1, MSX_TX_E280, MSX_HEAD_MAX);
            //            
          _f=true;
        }
#elif  ADF_E280_AV
        if (BME0_280.begin( _i2c)){
          _MSX0_i2c=_i2c;
            //
            //OS_str_clr( _MSX_0.head);
            //OS_str_BaddC( _MSX_0.head, -1, MSX_TX_E280, MSX_HEAD_MAX);
            //           
          _f=true;
        }
#endif
#endif
        }//ix=0
#ifdef TWI_AV
      }//while
#endif

//-- enable
#endif
  return _f;
}




/*!
 * read sensor[ix] values 
 *@param  _ix  .. sensor indexing [ix]
 */
bool _MSX_read( int8_t _ix){
  //
#if defined( MSX_EN_AV)
//--- enable

#if defined( BMP_280_AV) & defined( ADF_P280_AV)
    
    float     _TX =BMP0_280.readTemperature();
    float     _PX =BMP0_280.readPressure();
    _MSX_sn0.T= ((float)_TX)/BMP_T0_DIV;   // 1.0  -> C
    _MSX_sn0.P= ((float)_PX)/BMP_P0_DIV;   // 100.0  -> mB
    _MSX_sn0.H= -1.0;
    _MSX_sn0.v=true;
#endif

#ifdef BME_280_AV
#ifdef JWA_E280_AV
 
    int32_t   _TX =BME0_280.getTemperature();
    int32_t   _PX =BME0_280.getPressure();
    int32_t   _HX =BME0_280.getHumidity();
    _MSI_sn0.T= ((float)_TX)/BME_T0_DIV;   // 100.0  -> C
    _MSI_sn0.P= ((flaot)_PX)/BME_P0_DIV;   // 100.0  -> mB
    _MSI_sn0.H= ((float)_HX)/BME_F0_DIV;   // 1024.0 -> %
    _MSI_sn0.v=true;
#endif
#ifdef ADF_E280_AV

    float   _TX =BME0_280.readTemperature();
    float   _PX =BME0_280.readPressure();
    float   _FX =BME0_280.readHumidity();
    _MSX_sn0.T= ((float)_TX)/BME_T0_DIV;   // 1.0  -> C
    _MSX_sn0.P= ((float)_PX)/BME_P0_DIV;   // 100.0  -> mB
    _MSX_sn0.F= ((float)_F)/BME_F0_DIV;   // 1.0 -> %
    _MSX_sn0.v=true;
#endif
#endif
      //
  
  return _MSX_sn0.v;


//--- enable
#endif
  return false;
}



/*!
 * put sensor[ix] name info to com_line
 *@prama _ix  ..  Sensor[ix] indexed NC!
void  _MSX_Name2Line( 
            bool _clr
            ,int8_t _ix
            ){
    
}
*/



//#endif
//@