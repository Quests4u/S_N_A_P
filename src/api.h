/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       api0.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup Application
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef API_H_
#define API_H_ 1


/* Header includes */
#include <Q/sys/_os.h>

#define nAPI_AV 1


   #define nAPI0_INSTALL_AV
   #define nAPI1_INSTALL_AV
   #define nAPI2_INSTALL_AV
   #define nAPI3_INSTALL_AV
   
   

/* Statische Definitions */



#define  TX_NOTITLE    "[API:~]"


#define  API_MAX  4




/* Dynamische Definitions */
extern const char*  _tx_noapiname;



/*!
 * Bases Clase for APIs
 */
class ApiBase{


   

   private:
   
   
   public:

   bool         Has=false;
   bool         Had=false;
   
   int8_t       IX= -1;
   const char*  Title;

   

   ApiBase();
   ApiBase( const char* _Title);

  
   virtual bool  Cmd( int8_t _ix);
   virtual bool  Setup( int8_t _ix);
   virtual bool  Prepare( int8_t _ix);
   virtual bool  Refresh( int8_t _ix);
   virtual bool  Loop( int8_t _ix);
   virtual bool  Task( int8_t _ix);



};//apiBase








extern bool  API_install(
         const char*  _Title
         ,ApiBase* _api
);



/* Routine Definitions */
extern bool  APIxNoCall( int8_t _ix);




extern bool  APIxInstall(
         ApiBase* _api
);




/*!
 * setup each reset
 */
extern void  API_cmd( int8_t _ix);


/*!
 * setup each reset
 */
extern void  API_setup( int8_t _ix);


/*!
 * prepare each loop
 */
extern void  API_prepare( int8_t _ix);

/*!
 * refresh each loop
 */
extern void  API_refresh( int8_t _ix);

/*!
 * each loop
 */
extern void  API_loop( int8_t _ix);

/*!
 * each task[one per all loops]
 */
extern void  API_task( int8_t _ix);




#endif 
//@
