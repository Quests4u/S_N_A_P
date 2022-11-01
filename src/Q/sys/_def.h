/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       def.h
* @details    Global Definitions [abstracts for main also]
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup GLOBAL
 * @brief <a href="https://">Product Overview</a>
 */



#ifndef DEF_H_
#define DEF_H_ 1


/* Header includes */



/* Statische Definitions */

#define  LOGO                "SNAP_AT"
#define  V_BASE              "&3.o1"



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


#define     TX_NOVALUE         "no values!"

#define     TX_ONLINE          "online @"
#define     TX_OFFLINE         "offline!"


// OS
#define  OS_LOOPS              32
#define  OS_TX_PUT             3


#define  OS_DELAY_INFO        587//866


#define  OS_DELAY_SLOW       103//533
#define  OS_DELAY_FAST       87//266




/* Dynamische Definitions */

//*** def(initions) [_def.h]

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



/* Routine Definitions */



#endif 

