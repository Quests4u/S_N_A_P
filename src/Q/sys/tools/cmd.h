/**
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       cmd.h
* @date       2022-07-01
* @version    v1.00
*
*/

/*!
 * @defgroup TOOL
 * @brief <a href="https://">Product Overview</a>
 */
#include <_config.h>


#ifndef CMD_H_
#define CMD_H_ 1


#if defined( COM_AV)

/* Header includes */



//** TEST
#define nCOM_AV 1
    #define nDEBUG_COM_AV 1//<-- dbg
    #define nCOM_TEST_AV 1//<-- dbg

    #define nWDT_COM_AV 1
    #define nVIS_COM_AV 1
    #define nPWM_COM_AV 1
    #define nEP_COM_AV 1
        #define nEP_TEST 1//<-- dgb
        #define nEP_COM_DATA_AV 1
    #define nSIO_COM_AV 1
    #define nSIO_SESTU_COM_AV 1


// command parser
#define  CP_COMI0   1
#if defined(CP_COMI0)
  #define  CP_COMI1   1       // -> only max 2 param
  #if defined(CP_COMI1)
    #define   nCP_COM2   1
    #if defined( CP_COM2)
      #define   nCP_COM3   1
    #endif
  #endif
#endif







/* Statische Definitions */



#define COM_NONE                "[??]"
  #define  COMI_NONE             -1
#define COM_DONE                "(!)"
#define  COMH_NONE              "com?"


// help; put serial/display this informations
#define  COM_HELP              "help"
  #define  COMI_HELP             0x00
  #define  COMH_HELP             "[list]"


#ifdef DEBUG_COM_AV
  #ifdef COM_TEST_AV                      
    #define  COM_TEST            "CMtest"
      #define  COMI_TEST         0x01
      #define  COMH_TEST            "@"
  #endif
  #ifdef EP_TEST_AV
    #define  COM_EPTEST           "EPtest"
      #define  COMI_EPTEST       0x02
      #define  COMH_EPTEST          "@"
  #endif
#endif

// version:  serial/display build informations.
#define  COM_VERS              "info"
  #define  COMI_VERS             0x04
  #define  COMH_VERS             "[logo+info]"

// debug:  serial/display additional information on each switch
#define  COM_DEBUG             "debug"
  #define  COMI_DEBUG            0x06
  #define  COMH_DEBUG            "0[1]"

// os:  reboot/reset like hardware restart.
#if defined( WDT_AV) & defined( WDT_COM_AV)

#define  COM_RESET             "reset"
    #define  COMI_RESET          0x08
    #define  COMH_RESET          ">reboot"

#endif

// os:  s(pace_)loops
#define  COM_LOOP_PARA         "sloops" 
    #define  COMI_LOOP_PARA      0x0a
    #define  COMH_LOOP_PARA      "[n]"

#define  COM_NOBREAK           "nobreak" 
    #define  COMI_NOBREAK        0x0b
    #define  COMH_NOBREAK        "0[1]"




// LCD; parallel connected LCD(44xxx); visualize (T->P->F..rep) / static.display: T/P/F 
#if defined( VIS_AV) & defined( VIS_COM_AV)

#define  COM_A_VIS             "AVis"
  #define  COMI_A_VIS            0x100
  #define  COMH_A_VIS            "~auto"

#define  COM_Z_VIS             "ZVis"
  #define  COMI_Z_VIS            0x110
  #define  COMH_Z_VIS            "~rotate"

#define  COM_T_VIS             "TVis"
  #define  COMI_T_VIS            0x101
  #define  COMH_T_VIS            "show T"

#define  COM_P_VIS             "PVis"
  #define  COMI_P_VIS            0x102
  #define  COMH_P_VIS            "show P"

#define  COM_F_VIS             "FVis"
  #define  COMI_F_VIS            0x103
  #define  COMH_F_VIS            ">show F"

#endif


// OS Store; internal parameter store/load/std
#if defined( OS_STORE_AV)

#define  COM_OS_SAVE           "OSsave"
  #define  COMI_OS_SAVE          0x200
  #define  COMH_OS_SAVE            "~store now"

#define  COM_OS_LOAD           "OSload"
  #define  COMI_OS_LOAD          0x0201
  #define  COMH_OS_LOAD            "~set stored"

#define  COM_OS_STD            "OSstd"
  #define  COMI_OS_STD            0x202
  #define  COMH_OS_STD            "~set STD."

#endif//store


// [i]Eprom; internal parameter 
#if defined( EP_AV)

#endif



// [E]EPdata; external EEProm (no stub for that at moment! needs to be developed! :)
#if defined( EEP_AV)
 /*
  #if defined( EP_COM_DATA_AV)
    #define  COM_EP_DATA        "EPdata"
      #define  COMI_EP_DATA       0x211
      #define  COMH_EP_DATA         ">read data"
  #endif
  */
#endif



// [%0]pwm parameter for pwm output  min-max :  0(0[+2]V)-255[10V]
// in:  Tpwm=-2,60  ;.. 0=>(-2°C) -- 255=>(+60°C)
// out: Tpwm        ;.. display  Tpwm[-2,60]                                             
#if defined(PWM_AV) & defined( PWM_COM_AV)

  #define  COM_T_PWM          "Tpwm"
    #define  COMI_T_PWM          0x300
    #define  COMH_T_PWM            "[min,max]"

  #define  COM_P_PWM           "Ppwm"
    #define  COMI_P_PWM           0x301
    #define  COMH_P_PWM            "[min,max]"

  #define  COM_F_PWM           "Fpwm"
    #define  COMI_F_PWM           0x302
    #define  COMH_F_PWM            "[min,max]"

  #define  COM_EP_2_PWM           "2pwm"
    #define  COMI_2_PWM           0x303
    #define  COMH_2_PWM            ">0v[2v]"

#endif


//  S[erial]  put data regular to serial(usb) interface
#if defined( SIO_AV) & defined(  SIO_COM_AV)

#define  COM_SO_PARA               "Sout"
  #define  COMI_SO_PARA                0x400
  #define  COMH_SO_PARA                  "1[0]"


#ifdef SIO_COM_SESTU_AV
// Se[rial]Stu[dio]  compatible output
//  "/*%title%,%t,%p,%h*/"   ;.. frame informations to display with SeStu
//
// needs this JSON:
//   
//  {
//   "t":"%1",
//   "g":[
//      {
//         "t":"Sensor Readings",
//         "d":[
//            {
//               "t":   "Temperature",
//               "v":   "%2",
//               //"g": "true",
//               "w":   "bar",
//               "min": "0",
//               "max": "30",
//               "u":   "°C"
//            },
//            {
//               "t":   "Pressure",
//               "v":   "%3",
//               "u":   "KPa",
//               "min": "900",
//               "max": "1100",
//               "g":   "true"
//            },
//            {
//               "t":   "(rel.)Humidity",
//               "v":   "%4",
//               //"g": "true",
//               "w":   "gauge",
//               "min": "0",
//               "max": "100",
//               "u":   "%"
//            }
//         ]
//      },
//   ],
//  }
//
#define  COM_SESTU_PARA             "SeStu"
  #define  COMI_SESTU_PARA            0x500
  #define  COMH_SESTU_PARA              "1[0]"
#endif


#endif//SIO






// CParser
#define   CP_BIN                2
#define   CP_DEC                10
#define   CP_HEX                16

#define    CP_TRUE              "true"
#define    CP_FALSE             "false"

#define    CP_ON                "on"
#define    CP_OFF               "off" 



struct COM_set_t{
    //
    bool f;
    int  ix;
    //
    bool vis;
    bool SO;
    //
    bool clr;
    bool add;
    //
    bool consumed;
};



/* Dynamische Definitions */

extern const char*       com_H[];// 

extern int               com_I[];//

extern int               com_am;//  = -1;//<-- init with setup  
extern int               com_ai;//  = -1;


extern String            com_line;//        = String("01234567890123456789");//19By input puffer
extern int               com_lineDelay;//   = OS_DELAY_INFO;



/* Routine Definitions */



/*!
 *
 */
extern bool COM_reset();


/*!
 *  parse _c and concats com proc/date [true/false] 
 *  @return true  .. a full com is complete to execute
 */
extern bool COM_parseChar( 
            char _c
            );




extern COM_set_t  _COM_execute( COM_set_t _);      


/*!
 * execute element selected from comIX.
 * enabled by comHas
 * @return true .. %done
 */
extern bool COM_exec();




/*!
 * get serial chars and parse and connect them and execute.
 *@param _i  .. pos of char wihle burst in
 *@param _c  .. char[i] within the burst
 */
extern void COM_serialParser( 
                        int _i,
                        char _c);




// sub

      
      /*!
       * find com_ai(index) for com_I[] value
       *@param  _comI   ..  value of com_I[] 
       *@return [ai .. index]
       */
      extern int _COM_ai4com_I( int _comI);
      
      
      /**
       * com_line: fill with com_* parameter [min,max]
       *@param  _ai   ..  com_ai <- index <- com_A[] = com_I[]
       */
      extern void _COM_MinMax2Line( int _ai);
      


      /*!
       * put comI[indexed] name/param  to com_line
       *@param _clr  .. clear com_line
       *@param _comI .. comI[ndex]
       */
      extern void _COM_NamePara2Line( 
                    bool _clr,
                    int _comI
                    );
      





#endif
#endif 
//@
