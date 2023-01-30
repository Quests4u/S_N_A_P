/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       Flash.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Flash Files FileSystem
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef FLASH_H_
#define FLASH_H_ 1


#if defined(FLASH_AV)
/* Header includes */

#include <SDFS.h>
#include <LittleFS.h>


#define nFLASH_AV 1
    #define nFLASH_FS_AV 1


/* Statische Definitions */


#define  TX_FS                  "FS:"

#define  FS_FILE_MAX            20

#define  FS_BULK_FILE           "/" V_DEV V_STORE ".bin"


#define  FS_GET_ATSTART         1




struct FLASH_file_t{

            bool     has;
            bool     had;
            //
            bool     hasStore;
            //
            FSInfo*  Info;

};





/* Dynamische Definitions */

extern const char*            _tx_FS;     

extern const char*              FS_bulk_file;//


//extern bool                   FS_none_putstd;//     = FS_NONE_PUTSTD;

extern FLASH_file_t           FS0;//





extern  FSInfo                FS_drive;//  

/* Routine Definitions */



// Handles
/*!
 *
 */
extern bool FS_setup();





// Handles
/*!
 *
 */
extern bool FS_existsValues();


/*!
 * load values
 * @param _read  .. true/false  read/std
 */
extern bool FS_loadValues( bool _read);
/*!
 * save values
 */
extern bool FS_saveValues();






#endif
#endif 
//@
