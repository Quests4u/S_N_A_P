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

#define nOS_DELAY_AV 1


#define OS_STORE_AV 1


/* Statische Definitions */

#define  V_LOGO              "SNAP/"
//#define  V_DEV               "ED:" // <- defined by config!
#define  V_STORE             "sTo"
#define  V_VERSION           "~4.oo"




#define  DEBUG_AV            1

#define  H_                  0x1    // HIGH
#define  L_                  0x0    // LOW  -- WOT: BUG to bind #define HIGH/LOW

#define  DELAY_INIT          2000   // WOT: if LCD on dont use less than 1500ms



// Serial
#define SO_PARAM  1
#define  SIO_Baud              9600
#define  SO_hex                 '#'
#define  SO_csv                 ','
#define  SO_col                 '/'


#define     TX_NOVALUE         "~no values!"
#define     TX_SET             "~set!"
#define     TX_INIT            "~init!"
#define     TX_FAULT           "~fault!"


#define     TX_ONLINE          "~online @"
#define     TX_OFFLINE         "~offline!"


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





/* Dynamische Definitions */

//*** def(initions)

extern const char*         _tx_logo;//          = LOGO;
extern const char*         _tx_vers;//          = VERS;      

extern const char*         _tx_novalue;//               


// 
extern int                 OS_init_delay;//     = DELAY_INIT;

extern bool                OS_debug;//          = false;
extern bool                OS_info;//           = false;
extern bool                OS_nobreak;//         = false;//<-- no break


extern bool                OS_loop0;//          = false;
extern int                 OS_loop_i;//         = 0;


extern int                 OS_loop_max;//       = OS_LOOPS;
extern int                 OS_loop_put;//       = OS_TX_PUT;

extern int                 OS_loop_delay;//     = 100;

extern bool                OS_loop_refresh;//   = false;//inner [fast]/countdown loops to support VSI refresh fI.
extern short                 OS_loop_tdown;//   = -1;//task count down
extern long                OS_loop_tasks;//     = 0;//absolute livetime in Loop()'s


extern bool                OS_msx_sensor;//     =true//
extern bool                OS_msx_state;//      =true/ok false/need update! 


extern int                 OS_delay_split;//


struct API_set_t {
    //
    bool dbg;
    //
    bool vis;
    //
    int  percent;
    //
    bool  sensor;
};


extern bool                OS_bulk_putstd;



extern OS_bulk_u   OS_bulk;


/* Routine Definitions */

/*!
 * interuped delay,
 * (USE insteads of direct Delay(..))
 * 
 */
extern void  OS_delay( int _delay);




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

