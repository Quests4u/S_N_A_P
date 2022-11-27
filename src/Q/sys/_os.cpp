/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       _def.h
* @brief      common tools
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/_config.h>



/* Statische Definitions */


/* Dynamische Definitions */
const char*         _tx_novalue = TX_NOVALUE;

int                 OS_init_delay     = DELAY_INIT;

bool                OS_debug          = false;
bool                OS_info           = false;
bool                OS_nobreak        = false;

bool                OS_loop0          = false;

int                 OS_loop_i         = 0;
int                 OS_loop_max       = OS_LOOPS;
int                 OS_loop_put       = OS_TX_PUT;

bool                OS_loop_refresh   = true;//
short               OS_loop_tdown     = -1;//task countdown
long                OS_loop_tasks     = 0;//abslot count from reset


int                 OS_loop_delay     = 1;//100;

int                 OS_delay_split    = OS_DELAY_SPLIT;


bool                OS_msx_state      = false;//need update!
bool                OS_msx_sensor     = true;//sensors on


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