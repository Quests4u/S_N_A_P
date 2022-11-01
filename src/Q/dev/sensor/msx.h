/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       msx.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup SENSOR BMP180 BMP280 BME280
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/sys/_config.h>


#ifndef MSX_H_
#define MSX_H_ 1


/* Header includes */
//#include <Arduino.h>

#include <Q/sys/_def.h>



//TEST
#define nMSX_AV

#define nMSX_PIN_AV


    #define nBMP_280_AV 1
        #define nADF_P280_AV 1
            #define nADF_P280_SPI 1


    #define nBME_280_AV 1
        #define nJWA_E280_AV 1
        #define nADF_E280_AV 1
  


/* Statische Definitions */


#define SEALEVELPRESSURE_HPA (1013.25)



#ifdef PIN_AV


#ifdef PIN_328_AV

#ifdef MSX_PIN_AV


#define  PIN_MS_DA_00           A0            // A0(i)    = PC0
#define  PIN_MS_DA_99           A1            // A1(i)    = PC2

#define  PIN_MS_SENSOR          A3            // A2(i)    = PC2

#define  PIN_MS_DEBUG           A2            // A3(i)    = PC3

#endif


#endif//328


#endif//PIN




// Posch:

#ifdef BMP_280_AV
  #define V_MSX0 "~p280"
  #define MSX_TX_P280 "Bmp280"

  #include <Q/dev/peripherie/twi.h>  

#ifdef ADF_P280_AV
  #include <Adafruit_BMP280.h>

    #ifdef ADF_P280_SPI

#define BMP_SCK                 (13)
#define BMP_MISO                (12)
#define BMP_MOSI                (11)
#define BMP_CS                  (10)

    #endif

  #define  BMP_T0_DIV            1.0
  #define  BMP_P0_DIV            100.0
  //#define  BMP_F0_DIV            1024.0



#endif



#ifdef BME_280_AV
  #define V_MSX1 "~e280"
  #define MSX_TX_E280 "Bme280"

  #include <Q/dev/peripherie/twi.h>  

#ifdef JWA_E280_AV  // Jan Wasserbauer
  //
  #include <Bme280BoschWrapper.h>

// Posch BME280 (T/P/F)
  #define  BME_T0_DIV            100.0
  #define  BME_P0_DIV            100.0
  #define  BME_F0_DIV            1024.0

#endif



#ifdef ADF_E280_AV
  //
  #include <Adafruit_Sensor.h>
  #include <Adafruit_BME280.h>

  #define  BME_T0_DIV            1.0
  #define  BME_P0_DIV            100.0
  #define  BME_F0_DIV            1.0

#endif

#endif


#endif



#define     TX_MSX                 "SN"

#define     TX_MSX_ON              ":" TX_ONLINE
#define     TX_MSX_OFF             TX_MSX ":" TX_OFFLINE

#define     TX_MSX_HEAD            "@/T/P/H,"




struct  MSX_Set{
  //
  bool  v;
  String head;
  //
  bool  has;
  bool  had;
  //
  byte  i2c;
  //
};


struct MSX_SN_Set{
  //
  bool v;
  //
  float T;
  float P;
  float F;
  //
};


/* Dynamische Definitions */


extern const char*         _tx_msx_off;//         

extern const char*         _tx_msx_head;//
extern const char*         _tx_msx_on;//


extern bool                _MSX0_Has;//         = false;
extern bool                _MSX0_Had;//         = false;
extern bool                _MSX0_Values;//      = false;
extern byte                _MSX0_i2c;//         = 0;
                           //^-  incase its I2C(TWI)

extern MSX_SN_Set         _MSX_sn0;//
extern MSX_Set            _MSX_0;//


#ifdef BMP_280_AV

#ifdef ADF_P280_AV
extern Adafruit_BMP280 BMP0_280;
#endif

#endif


#ifdef BME_280_AV

#ifdef JWA_E280_AV
extern Bme280BoschWrapper  BME0_280;        (true);
#endif

#ifdef ADF_E280_AV
extern Adafruit_BME280     BME0_280;
#endif

#endif



/* Routine Definitions */


/*!
 * @param _v  .. NC
 */
extern bool _MSX_init( int8_t _v);


/*!
 *  find I2C of BMP/180[280] .. BME280 and start
 *
 * @param  _ix .. MSX[ix] <- just 0 supported at moment
 * @return true(found)
 */
extern bool _MSX_setup( byte _ix);


/*!
 * @param  _ix .. MSX[ix] <- just 0 supported at moment
 * @return true(completed)
 */
extern bool _MSX_read( int8_t _ix);



/*!
 * put sensor[ix] name info to com_line
 *@prama _ix  ..  Sensor[ix] indexed NC!
 */
extern void  _MSX_Name2Line( 
            bool _clr
            ,uint8_t _ix
            );




#endif 
//@
