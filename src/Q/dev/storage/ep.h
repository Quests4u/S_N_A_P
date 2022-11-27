/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       eprom.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup EEPROM
 * @brief <a href="https://">Product Overview</a>
 */
#include <Q/_config.h>


#ifndef EP_H_
#define EP_H_ 1


#if defined( EP_AV)

/* Header includes */
//#include <Arduino.h>



//#include <Q/sys/_def.h>


#define  nEP_AV 1


/* Statische Definitions */


//#define  EP_TEST_AV  1    //  <---§

#define  EP_ADR_START        0x04

#define  EP_DOUBLE_DIV       10.0

#define  EP_PREM             V_DEV V_STORE
  #define  EP_PREM_N         V_DEV
  #define  EP_PREM_L         sizeof(EP_PREM)
#define  EP_SUM              "Snap+08c15"
  #define  EP_SUM_N           "-/-"  
  #define  EP_SUM_L          sizeof(EP_SUM)

#define  EP_GET_ATSTART      1
  #define EP_GET_INIT        "EP: Init!"

//#define  EP_NONE_PUTSTD      false            // if none stored use std
 



    #define  EP_DATA_ADR_TIME       0x060 
    #define  EP_DATA_ADR_DATE       0x064 
    #define  EP_DATA_ADR_POS        0x068 

    #define  EP_DATA_ADR_START        0x06C 
    #define  EP_DATA_ADR_END          0x1F8

    #define  EP_DATA_FRAME            0x4 


    #define  EP_DATA_READ         "EP:data(csv)!"





#define EP_ADR( _v)   (EP_ADR_START+_v)


// Premisse to validate data

struct  EP_prem_t{
  //
  bool   Valid;
  //
  char   prem[6];

  char   sum[16];
  //                        
};
//
union EP_prem_u{
  EP_prem_t  t;
  uint8_t     b[sizeof(EP_prem_t)];
};
//







/* Dynamische Definitions */


extern bool                   EP_none_putstd;//     = EP_NONE_PUTSTD;

/*
extern const char*            EP_sum0;//            = EP_SUM;
extern const char*            EP_sum_n0;//          = EP_SUM_N;

extern const char*            EP_prem0;//           = EP_PREM;
extern const char*            EP_prem_n0;//         = EP_PREM_N;
*/


extern const char*            EP_data_read0;//      = EP_DATA_READ;


extern int                    EP_data_adr;//        = EP_DATA_ADR_START;



//extern EP_prem_u              EP_prem;







/* Routine Definitions */




// Handles
/*!
 * load values
 * @param _read  .. true/false  read/std
 */
extern bool EP_loadValues( bool _read);
/*!
 * save values
 */
extern bool EP_saveValues();




#endif 
#endif
//@
