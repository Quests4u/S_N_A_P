/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       os.h
* @details    Global Definitions [abstracts for main also]
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup GLOBAL
 * @brief <a href="https://">Product Overview</a>
 */



#ifndef OS_H_
#define OS_H_ 1


/* Header includes */
#include <math.h>

#include <Q/sys/lang/NumberBuffer.h>
#include <api.h>


#define nOS_DELAY_AV 1


#define nOS_STORE_AV 1

#define nOS_MSX_DELAY_AV 1


/* Statische Definitions */

#define  V_LOGO              "SNAP^"
#define  V_STORE             "sTo"
#define  V_VERSION           "_5.2o"




#define  DEBUG_AV            1

#define  H_                  0x1    // HIGH
#define  L_                  0x0    // LOW  -- WOT: BUG to bind #define HIGH/LOW

#define  DELAY_INIT          2000   // WOT: if LCD on dont use less than 1500ms


#define  SO_hex                 '#'
#define  SO_csv                 ','
#define  SO_col                 '/'
#define  OS_at                  '@'
#define  OS_AT                  "@"


#define     TX_STORE           "osS" OS_AT



#define     TX_NOVALUE         "~noVal!"
#define     TX_NOEXISTS        "~noExt!"

#define     TX_OK              "~ok!"
#define     TX_ERR             "~err!"


#define     TX_ONLINE          "~on " OS_AT
#define     TX_OFFLINE         "~off!"





// OS

#define  OS_LOOPS              32
#define  OS_TX_PUT             3


#define  OS_DELAY_INFO        587//866


#define  OS_DELAY_SLOW       103//533   mS
#define  OS_DELAY_FAST       87//266    mS


#define  OS_DELAY_SPLIT       250//ms


#define  OS_BULK_PUTSTD      false            // if none stored use std




// data bulk
union OS_bulk_u{
  OS_bulk_t   t;
  uint8_t     b[sizeof(OS_bulk_t)];
};



/*!
 * main <-> api state intercom
 * [bool]   dbg
 * [bool]   vis
 * [bool]   put
 * [int]    percent
 * [bool]   sensor
 * [bool]   led
 * 
 */
struct OS_param_set_t {
    //
    bool dbg;
    //
    bool vis;
    bool put;
    //
    int  percent;
    //
    bool  sensor;
    //
    bool  led;
};



template<typename T>
struct OS_Buffer_t{
   //
   T*             t;
   int8_t         i;
   int8_t         m;
   //
   int8_t         M;
   bool           has;

};









/* Dynamische Definitions */

//*** def(initions)

extern const char*         _tx_logo;//          = LOGO;
extern const char*         _tx_vers;//          = VERS;      


extern const char*         _tx_store;//  = Store;



extern const char*         _tx_novalue;//               
extern const char*         _tx_notexists;//               

extern const char*         _tx_on;//
extern const char*         _tx_off;//

extern const char*         _tx_ok;//
extern const char*         _tx_err;//





// 
extern uint16_t             OS_init_delay;//     = DELAY_INIT;

extern bool                OS_debug;//          = false;
extern bool                OS_info;//           = false;
extern bool                OS_nobreak;//         = false;//<-- no break


extern bool                OS_loop0;//          = false;
extern int8_t              OS_loop_i;//         = 0;
extern int8_t              OS_loop_max;//       = OS_LOOPS;
extern int8_t              OS_loop_put;//       = OS_TX_PUT;


extern bool                OS_loop_refresh;//   = false;//inner [fast]/countdown loops to support VSI refresh fI.
extern int16_t              OS_loop_tdown;//   = -1;//task count down

extern uint16_t             OS_loop_delay;//     = 100;
extern uint16_t            OS_delay_split;//


extern uint64_t            OS_loop_tasks;//     = 0;//absolute livetime in Loop()'s


extern bool                OS_msx_sensor;//     =true//
extern bool                OS_msx_state;//      =true/ok false/need update! 





extern OS_param_set_t      OS_param0;//   Dyn. Parameter set 



extern bool                OS_bulk_putstd;


extern NumberBuffer_set_t  OS_NB;


extern OS_bulk_u   OS_bulk;








/* Routine Definitions */


/*!
 *
 */
extern uint8_t OS_str_Blen( 
                     uint8_t* _q_B0,
                     //
                     int8_t   _q_max
                  );


/*!
 *
 */
extern uint8_t OS_str_Btrim( 
                     uint8_t* _q_B0,
                     int8_t   _q_ofs,
                     //
                     bool     _q_start,
                     bool     _q_end,
                     //
                     int8_t   _q_max
                  );





/*!
 *
 */
extern bool OS_str_BhasC( 
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     const char* _q_C, 
                     bool        _q_Gk,
                     //
                     int8_t      _q_max
                  );


/*!
 *
 */
extern uint8_t OS_str_BaddC( 
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs, 
                     const char* _q_C, 
                     //
                     int8_t      _q_max
                  );


/*!
 *
 */
extern uint8_t OS_str_BaddB( 
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     uint8_t*    _q_B1,
                     //
                     int8_t      _q_max
                     //
                  );



extern uint8_t OS_str_BaddV(
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     char        _q_v,
                     //
                     int8_t      _q_max
   );

   

extern uint8_t OS_str_BaddV(
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     bool        _q_v,
                     //
                     int8_t      _q_max
   );
   
   
   
extern uint8_t OS_str_BaddN(
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     int64_t     _q_v,
                     //
                     int8_t      _q_base,
                     int8_t      _q_max
   );
   
   
extern uint8_t OS_str_BaddR(
                     uint8_t*    _q_B0,
                     int8_t      _q_ofs,
                     double      _q_v,
                     //
                     int8_t      _q_dcp,
                     int8_t      _q_max
   );
   
   
extern void   OS_str_clr(
                     uint8_t*    _q_B0 
   );







/*!
 * interuped delay,
 * (USE insteads of direct Delay(..))
 * 
 */
extern void  OS_delay( int16_t _delay);




//** storage

/*!
 * fill with std values
 * needs to be defined!
 */
extern void _OS_fillStdValues();


/*!
 * save values 
 * needs to be defined!
 */
extern void _OS_fillValues2Bulk();
          

/*!
 * load values
 * needs tobe defined!
 */
extern void _OS_fillBulk2Values();
          




#endif 

