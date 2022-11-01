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

const char*         _tx_msx_on     = TX_MSX_ON;
const char*         _tx_msx_off    = TX_MSX_OFF;

const char*         _tx_msx_head   = TX_MSX_HEAD;


String              _MSX0_head        = String("01234567");
bool                _MSX0_Has         = false;
bool                _MSX0_Had         = false;
bool                _MSX0_Values      = false;
byte                _MSX0_i2c         = 0;//<-- incase its I2C(TWI)


MSX_Set       _MSX_0    ={
                                  false,//v
                                  String( "--nMSX--"),//(By)
                                  //
                                  false,//has
                                  false,//had
                                  //
                                  0,//i2c
                              };
MSX_SN_Set       _MSX_sn0    ={
                                  false,
                                  //
                                  0.0,
                                  0.0,
                                  0.0
};


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


/* Routine Definitions */


/**
 * 
 */
bool _MSX_init( int8_t _v){
  //
  bool _f=false;

  
  #ifdef ADF_P280_AV
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

  return _f;
}




/*!
 *  find I2C of BMP/180[280] .. BME280 and start
 * @return true(found)
 */
bool _MSX_setup( byte _ix){
  //
  bool _f=false;
  byte _i2c;
      //
  //
#ifdef TWI_AV
  for( byte _i=0;(!_f)&(_i<_TWI_cou); _i++){
    _i2c=_TWI[_i];
#endif
    //
    if (_ix==0){
        _MSX0_i2c=-1;

#ifdef BMP_280_AV
#ifdef ADF_P280_AV
        if (BMP0_280.begin( _i2c)){
          _MSX0_i2c=_i2c;
            _MSX_0.head="";
            _MSX_0.head.concat( MSX_TX_P280);
          _f=true;
        }
#endif
#endif
//
#ifdef BME_280_AV
#ifdef JWA_E280_AV
        if (BME0_280.beginI2C( _i2c)){
          _MSX0_i2c=_i2c;
            _MSX_0.head="";
            _MSX_0.head.concat( MSX0_TX_E280);
          _f=true;
        }
#elif  ADF_E280_AV
        if (BME0_280.begin( _i2c)){
          _MSX0_i2c=_i2c;
            _MSX_0.head="";
            _MSX_0.head.concat( MSX0_TX_E280);
          _f=true;
        }
#endif
#endif
        }//ix=0
#ifdef TWI_AV
      }//while
#endif
  return _f;
}




/*!
 * read sensor[ix] values 
 *@param  _ix  .. sensor indexing [ix]
 */
bool _MSX_read( int8_t _ix){
  //

#ifdef BMP_280_AV
#ifdef ADF_P280_AV
    
    float     _TX =BMP0_280.readTemperature();
    float     _PX =BMP0_280.readPressure();
    _MSX_sn0.T= ((float)_TX)/BMP_T0_DIV;   // 1.0  -> C
    _MSX_sn0.P= ((float)_PX)/BMP_P0_DIV;   // 100.0  -> mB
    _MSX_sn0.F= -1.0;
    _MSX_sn0.v=true;
#endif
#endif

#ifdef BME_280_AV
#ifdef JWA_E280_AV
 
    int32_t   _TX =BME0_280.getTemperature();
    int32_t   _PX =BME0_280.getPressure();
    int32_t   _FX =BME0_280.getHumidity();
    _MSI_sn0.T= ((float)_TX)/BME_T0_DIV;   // 100.0  -> C
    _MSI_sn0.P= ((flaot)_PX)/BME_P0_DIV;   // 100.0  -> mB
    _MSI_sn0.F= ((float)_FX)/BME_F0_DIV;   // 1024.0 -> %
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
}



/*!
 * put sensor[ix] name info to com_line
 *@prama _ix  ..  Sensor[ix] indexed NC!
 */
void  _MSX_Name2Line( 
            bool _clr
            ,uint8_t _ix
            ){
    
}




//@