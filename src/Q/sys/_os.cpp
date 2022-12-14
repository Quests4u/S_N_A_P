/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _def.h
* @brief      common tools
* @date       2022-07-01
* @version    v1.00
*
*/

#include <_config.h>



/* Statische Definitions */


/* Dynamische Definitions */
const char*         _tx_novalue       = TX_NOVALUE;
const char*         _tx_notexists      = TX_NOEXISTS;

int                 OS_init_delay     = DELAY_INIT;// reset info/logo delay (2000)

bool                OS_debug          = true;
bool                OS_info           = false;
bool                OS_nobreak        = false;

bool                OS_loop0          = false;

int                 OS_loop_i         = 0;// actual loop 
int                 OS_loop_max       = OS_LOOPS;// done loops per task (32)
int                 OS_loop_put       = OS_TX_PUT;// [MSX] put loops per task (3)

bool                OS_loop_refresh   = true;//
short               OS_loop_tdown     = -1;//task countdown
long                OS_loop_tasks     = 0;//absolut counts from last reset on


int                 OS_loop_delay     = 1;//100;

int                 OS_delay_split    = OS_DELAY_SPLIT;// WOT <- to prevent NMI Block!! (250)


bool                OS_msx_state      = false;//need update!
bool                OS_msx_sensor     = true;//sensors on



OS_param_set_t      OS_param0         ={
                      false
                      //
                      ,true
                      ,false
                      //
                      ,50
                      ,true
                      ,false
};



bool                OS_bulk_putstd    = OS_BULK_PUTSTD;




OS_bulk_u           OS_bulk;




/* Routine Definitions */


// OS storage





// *** delay

/*!
 * interuped delay,
 * (USE insteads of direct Delay(..))
 * 
 */
void  OS_delay( int _delay){
    //
#ifdef OS_DELAY_AV
    bool _f=true;
    while( _f){
        //
        if (_delay>OS_delay_split){
          //
          yield();
          //
          _delay=_delay-OS_delay_split;
          delay( OS_delay_split);
        }
        else{
          //
          _f=false;
          delay( _delay);
        }
    }//loop
#else
     delay( _delay);
#endif

}






//@