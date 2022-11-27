/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       cmd.h
* @brief      commando line 
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/sys/tools/cmd.h>

#if defined( COM_AV)


/* Statische Definitions */


/* Dynamische Definitions */

String            comP        = String("01234567");    // command
int               comP_i      = 0;
int               com_m       = 8;


//
bool              comPD       = true;                   // proc/data
bool              comPD_en    = true;                   // -> (Data) use char 
                                                       // incase ignore until next synch (,:,@)

String            comD        = String( "01234567");  // data
int               comD_i      = 0;
int               comD_m      = 10;


int               comDcou     = 0;
// %0..%2[3]
String            com_d0       = String("01234567");
int               com_i0       = -1;
  bool              com_i0Has  = false;
bool              com_f0       = false;
  bool              com_f0Has  = false;

#if defined(  CP_COMI1)
String            com_d1       = String("01234567");
int               com_i1       = -1;
  bool              com_i1Has  = false;
bool              com_f1       = false;
  bool              com_f1Has  = false;
#endif

#if defined( CP_COMI2)
String            com_d2       = String("01234567");
int               com_i2       = -1;
  bool              com_i2Has  = false;
bool              com_f2       = false;
  bool              com_f2Has  = false;
#endif


#if defined( CP_COMI3)
String            com_d3       = String("01234567");
int               com_i3       = -1;
  bool              com_i3Has  = false;
bool              com_f3       = false;
  bool              com_f3Has  = false;
#endif

// com-string/ix/info
bool              comHas      = false;
int               comIX       = -1;
bool              comDelayed  = false;
//

const char*       com_NONE    =  COM_NONE;
const char*       com_DONE    =  COM_DONE;
const char*       comH_NONE   = COMH_NONE;


const char*            com_A[]   ={ 
                      COM_HELP,

                      //
                      COM_VERS,
                      COM_DEBUG,
#if defined( WDT_AV) & defined( WDT_COM_AV)
                      COM_RESET,
#endif                               
                      //
#if defined( VIS_AV) & defined( VIS_COM_AV)
                      COM_A_VIS,
                      COM_Z_VIS,
                      COM_T_VIS,
                      COM_P_VIS,
                      COM_F_VIS,
#endif
                      //
#ifdef OS_STORE_AV
                      COM_OS_SAVE,
                      COM_OS_LOAD,
                      COM_OS_STD,


#endif//store


#ifdef EP_AV
#endif


#ifdef EEP_AV
#endif


                      //
#if defined( PWM_AV) & defined( PWM_COM_AV)
                      COM_T_PWM,
                      COM_P_PWM,
                      COM_F_PWM,
                      COM_2_PWM,
#endif


#if defined( SIO_AV) & defined( SIO_COM_AV)
                      COM_SO_PARA,

    #if defined( SIO_COM_SESTU_AV)
                      COM_SESTU_PARA,
    #endif

#endif
                      //
                      COM_LOOP_PARA
                      ,COM_NOBREAK
                      //
                      };



const char*          com_H[]   ={
                      COMH_HELP,

                      //
                      COMH_VERS,
                      COMH_DEBUG,
#if defined( WDT_AV) & defined( WDT_COM_AV)
                      COMH_RESET,

#endif                                   
                      //

#if defined( VIS_AV) & defined( VIS_COM_AV)
                      COMH_A_VIS,
                      COMH_Z_VIS,
                      COMH_T_VIS,
                      COMH_P_VIS,
                      COMH_F_VIS,
#endif
                      //
#if defined( OS_STORE_AV)
                      COMH_OS_SAVE,
                      COMH_OS_LOAD,
                      COMH_OS_STD,


#endif //store


#ifdef EP_AV

#endif


#ifdef EEP_AV

#endif



                      //
#if defined( PWM_AV) & defined( PWM_COM_AV)
                      COMH_T_PWM,
                      COMH_P_PWM,
                      COMH_F_PWM,
                      COMH_2_PWM,
#endif

#if defined( SIO_AV) & defined( SIO_COM_AV)
                      COMH_SO_PARA,

    #if defined( SIO_COM_SESTU_AV)
                      COMH_SESTU_PARA,
    #endif

#endif
                      //
                      COMH_LOOP_PARA
                      ,COMH_NOBREAK
                      //
                      };





/*!
*
*/
int               com_I[]  ={
                      COMI_HELP,
                      //
                      COMI_VERS,
                      COMI_DEBUG,
#if defined( WDT_COM_AV)
                      COMI_RESET,
#endif                  

                      //
#if defined( VIS_AV) & defined( VIS_COM_AV)
                      COMI_A_VIS,
                      COMI_Z_VIS,
                      COMI_T_VIS,
                      COMI_P_VIS,
                      COMI_F_VIS,
#endif
                      //
#if defined( OS_STORE_AV)
                      COMI_OS_SAVE,
                      COMI_OS_LOAD,
                      COMI_OS_STD,

#endif//store


#ifdef EP_AV

#endif


                      //
#if defined( PWM_AV) & defined( PWM_328_AV)
                      COMI_T_PWM,
                      COMI_P_PWM,
                      COMI_F_PWM,
                      COMI_2_PWM,
#endif
      
#if defined( SIO_AV) & defined( SIO_COM_AV)
                      COMI_SO_PARA,

    #if defined( SIO_COM_SESTU_AV)
                      COMI_SESTU_PARA,
    #endif

#endif

                      //
                      COMI_LOOP_PARA
                      ,COMI_NOBREAK
                      //
                  };




int               com_am  = sizeof(com_I)/sizeof(COMI_HELP);//-1;//<-- init with setup  
int               com_ai  = 0;


String            com_line        = String("01234567890123456789");//19By input puffer
int               com_lineDelay   = OS_DELAY_INFO;
String            com_para_put    = "01234567";//8By Puffer ParaPut



// CParser:
bool              cpHas      = false;
int               cp_0base  = 10;
int               cp_0       = 0;
bool              cp_0sgn    = true;//pos[neg]




/* Routine Definitions */




bool cpReset( bool _sgn){
    //
    cpHas     =false;
    cp_0      =0;
    cp_0sgn   =_sgn;// pos/neg
    cp_0base  =10;
  //
  return true;
}


      int _cpAdd( 
            char _c,
            int  _ofs
            ){
        int _i=0;
          //
          if (cpHas){
            //
            cp_0=cp_0*cp_0base;
          }
          else{
            //
            cpReset( cp_0sgn);
            cpHas=true;
          }
          _i=_c-_ofs;
          cp_0+=_i;
          //
        return _i; 
      }



bool cpCParse( 
            char _c
            ){
    //
    bool _f=false;
    //
    // Gk: -> just k
    if ((_c>=65)&&//'A'
        (_c<=91)){//'Z'
      _c+=0x20;// 'a'
    }
    // select Num
    switch( _c){
      //
    case '+':
            //cp_0sgn=true;
          break;
    case '!':
    case '-':
            cp_0sgn=!cp_0sgn;
            //cp_0sgn=false;
          break;          

    case '0':
    case '1':
          if (cp_0base==CP_BIN){//2
            //
            _cpAdd( _c, 48);// '0'
            break;
          }
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
          _cpAdd( _c, 48);// '0'
        break;
    case 'b':
          if ((cpHas)&& 
              (cp_0==0)){ // "0b"
            //
            cp_0base=CP_BIN;//2
            break;
          }
    case 'a':
    case 'c':
    case 'e':
    case 'f':
          if (cp_0base==CP_HEX){//16
            //
            _cpAdd( _c, 97);// 'a'
          }
          else{
            _f=cpHas;
          }
        break;
        //
    case 'x':
          if ((cpHas)&& 
              (cp_0==0)){ // "0x"
            //
            cp_0base=CP_HEX;
          }
          else{
            //
            _f=cpHas;
          }
        break;
    default:
          _f=cpHas;
        break;
    }
    //
    return _f;
}





// COM:  ***********


/*!
 *
 */
bool COM_reset(){
    //
    comP    = "";
    comP_i   = 0;
    comD    = "";
    comD_i  = 0;
    //
    comPD     = true;
    comPD_en  = true;
    comDcou   = 0;
    //
    com_d0   = "";
      com_i0   = -1;
        com_i0Has = false;
      com_f0   = false;
        com_f0Has = false;
#ifdef CP_COMI1
    com_d1   = "";
      com_i1   = -1;
        com_i1Has = false;
      com_f1   = false;
        com_f1Has = false;
#endif
#ifdef CP_COMI2
    com_d2   = "";
      com_i2   = -1;
        com_i2Has = false;
      com_f2   = false;
        com_f2Has = false;
#endif
#ifdef CP_COMI3
    com_d3   = "";
      com_i3   = -1;
        com_i3Has = false;
      com_f3   = false;
        com_f3Has = false;
#endif
    //
    cpReset( true);
    //
    comHas  = false;
    comIX   = COMI_NONE;
    com_ai  = -1;
    //
    return true;
}


     /*!
      * parse command/data char?
      *@parm _c .. char
      */
      bool _comCParseI( 
                    char _c
                    ){ 
        //
        bool _f=cpCParse( _c);
          //
            if (_f){
              //
              // bool
              bool _fB=(cp_0==0)||(cp_0==1);
              // pos[neg]
              if (!cp_0sgn){
                //
                cp_0=-cp_0;
              }
              //
              switch( comDcou){
            case 0: com_i0=cp_0;//_cp0;
                    com_i0Has=true;
                    if (_fB){
                      com_f0=cp_0==1;
                      com_f0Has=true;
                    }
                break;
  #ifdef CP_COMI1
            case 1: com_i1=cp_0;
                    com_i1Has=true;
                    if (_fB){
                      com_f1=cp_0==1;
                      com_f1Has=true;
                    }
                break;
  #endif
  #ifdef CP_COMI2
            case 2: com_i2=cp_0;
                    com_i2Has=true;
                    if (_fB){
                      com_f2=cp_0==1;
                      com_f2Has=true;
                    }
                break;
  #endif
  #ifdef CP_COMI3
            case 3: com_i3=cp_0;
                    com_i3Has=true;
                    if (_fB){
                      com_f3=cp_0==1;
                      com_f3Has=true;
                    }
                break;
  #endif
              }//switch
              //
              cpReset( true);
            }
        return _f;
      } 



      /*!
       * check if its Boolean Value
       *@param _isBool .. 
       */
      bool _comBV( bool _isBool){
              // true:true
              if (comD==CP_TRUE){
                  return true;
              }
              else if (comD==CP_ON){
                  return true;
              }
              // true:false
              if (comD==CP_FALSE){
                  return _isBool;
              }
              if (comD==CP_OFF){
                  return _isBool;
              }
              //
              return false;  
      }

    

      /*!
       * Data char parse bool/int/double
       * and add it (deca/hexa wise)
       */
      bool _comDAdd(){ 
              //
              //bool _fB=_comHasB();
              bool _fB=_comBV( true);
              //
              switch( comDcou){
            case 0: com_d0=comD;
                    if (_fB){
                      com_f0    =_comBV( false);
                      com_f0Has =true;
                    }
                break;
    #ifdef CP_COMI1
            case 1: com_d1=comD;
                    if (_fB){
                      com_f1    =_comBV( false);
                      com_f1Has =true;
                    }
                break;
    #endif
    #ifdef CP_COMI2
            case 2: com_d2=comD;
                    if (_fB){
                      com_f2    =_comBV( false);
                      com_f2Has =true;
                    }
                break;
    #endif
    #ifdef CP_COMI3
            case 3: com_d3=comD;
                    if (_fB){
                      com_f3    =_comBV( false);
                      com_f3Has =true;
                    }
                break;
    #endif
              default:
                comDcou--;
              }
              comDcou++;
              //
              comD="";
              comD_i=0;
        return true;  
      } 




/*!
 *  parse _c and concats com proc/date [true/false] 
 *  @return true  .. a full com is complete to execute
 */
bool COM_parseChar( 
            char _c
            ){
      //
      bool _f=false,
           _fC=false,
           _fSep=false;

      // select:
      switch( _c){
        // .. eoC
    case '\n':
    case  '@':
    case  ';':
          for (int _i=0;_i<com_am; _i++){
            //
            // if (com_A[_i]==comP){
            //
            if (strcasecmp( com_A[_i], comP.c_str())==0){
              //
              com_ai=_i;
              comIX=com_I[_i];
              comHas=true;
              //
              if (_comCParseI( '@')){
                //
              }
              _comDAdd();
            }
          }
          //
          _f=comHas;
        break;
        // .. param
    case '=':
    case ':':
          if (comPD){
            //
            comPD=false;
            comPD_en=true; 
          }
        break;
    case ',':
    case '|':
          if (!comPD){
            //
            _fSep=true;
            comPD_en=true; 
          }
          else{
            //
            comPD_en=false; 
          }
     default:
          _fC=true;
        break;
    }

    // add:
    if (comPD){
      //
      if (comP_i<com_m){
        //
        if (comPD_en){
          //
          if (isWhitespace(_c)){
            //
            // -> exclude pre^WS on comP
          }
          else{
            //
            comP+=_c;
            comP_i++;
          }
        }
      }
    }
    else{
      //
      if ((comPD_en)&&
          (comD_i<comD_m)){  
        //
        if (_comCParseI( _c)){
          //
          if (!_fSep){
            //
            comPD_en=false; //--> no parse until sep
            _fC=false;
          }
        }
        if (_fSep){
          //
          _comDAdd();
        }
        else{
          //
          if (_fC){
            //
            comD+=_c;
            comD_i++;
          }
        } 
        //
      }
    }
    //
  return _f;
}



      /*!
       * check bool: has /  int: min<(max+_d) 
       *@param _d .. differnc 
       */
      bool _COM_checkMinLTMax( int _d){
        //
        //bool _f=false;
        bool _f=com_f0Has;
          if ((com_i0Has)&
              (com_i1Has)){
            //
            if (com_i1>(com_i0+_d)){
              _f=true;
            }
          }
        return _f;
      }


      /*!
       * find com_ai(index) for com_I[] value
       *@param  _comI   ..  value of com_I[] 
       *@return [ai .. index]
       */
      int _COM_ai4com_I( int _comI){
          //
          int _ai=0;
          //
          for (int _i=0;_i<com_am; _i++){
              //
              if (com_I[_i]==_comI){
                //
                _ai=_i;
                break;
              }
          }
          return _ai;
      }



      /*!
       * put comI[indexed] name/param  to com_line
       *@param _clr  .. clear com_line
       *@param _comI .. comI[ndex]
       */
      void _COM_NamePara2Line( 
                    bool _clr,
                    int _comI
                    ){
         // 
          if (_clr){
            com_line="";
          }
          //
          com_ai=_COM_ai4com_I( _comI);
            _COM_MinMax2Line( com_ai);
          //
      }


      
      /**
       * com_line: fill with com_* parameter [min,max]
       *@param  _ai   ..  com_ai <- index <- com_A[] = com_I[]
       */
      void _COM_MinMax2Line( int _ai){
        //
          com_line.concat( com_A[_ai]);
          com_line.concat( ':');
          com_line.concat( ' ');
              switch( com_I[_ai]){
        #ifdef SIO_SESTU_AV
          case COMI_SESTU_PARA:
                com_line.concat( '>');
                com_line.concat( SeStu0.v);
              break;
        #endif
        #ifdef PWM_COM_AV
        #ifdef PWM_328_AV
        #ifdef PWM_AD_AV
          case COMI_EP_T_PWM:
                com_line.concat( (int)pwm_t_0);
                com_line.concat( ',');
                com_line.concat( (int)pwm_t_M);
              break;
          case COMI_EP_P_PWM:
                com_line.concat( (int)pwm_p_0);
                com_line.concat( ',');
                com_line.concat( (int)pwm_p_M);
              break;
          case COMI_EP_F_PWM:
                com_line.concat( (int)pwm_f_0);
                com_line.concat( ',');
                com_line.concat( (int)pwm_f_M);
              break;
          case COMI_EP_2_PWM:
                com_line.concat( (int)_PWM_DAC_null);
                com_line.concat( '%');
              break;
        #endif
        #endif
        #endif
            }//switch
      }//Get 




/*!
 * execute element selected from comIX.
 * enabled by comHas
 * @return true .. %done
 */
bool COM_exec(){
    //
    COM_set_t _={
        true//f
        ,comIX
        //
        ,true//OS_debug,//vis
        ,true//,false//so
        //
        ,true//cls <- before vis
        ,true//false,//addCl
        //
        ,false//consumed
    };
    //
    int   _i=0
          //,_len
    ;
    //
    com_line="";
    com_para_put="";
    //
    if (comHas){
      //
      _=_COM_execute( _);
      //
      if (_.consumed){
        _.ix=COMI_NONE;
      }
      //
      switch( _.ix){
        //
  case COMI_NONE:
  default:
          com_line.concat( comH_NONE);
          _.add=false;
          _.f=false;
        break;
  

        // debug just onable
  case COMI_DEBUG:
          if (com_f0Has){
            //
            OS_debug=com_f0;
          }
          else{
            com_para_put.concat( OS_debug);
          }
          //
          break;
  case COMI_LOOP_PARA:
          if (com_i0Has){
            //
            OS_loop_max=com_i0;
            if (OS_loop_max<2){
              OS_loop_max=2;
            }
            if (OS_loop_max>0xFFF){
              OS_loop_max=0xFFF;
            }
          }
          else{
            com_para_put.concat( OS_loop_max);
          }
          //
          break;
  case COMI_NOBREAK:
          if (com_f0Has){
            //
            OS_nobreak=com_f0;
          }
          else{
            com_para_put.concat( OS_nobreak);
          }
          break;
#ifdef COM_DEBUG_AV
          // test
#ifdef COM_TEST_AV                      
        
  case COMI_TEST:
          com_line=">";
          com_line.concat( com_i0);
          com_line.concat( '|');
          com_line.concat( com_d0);
          com_line.concat( ';');
          com_line.concat( com_i1);
          com_line.concat( '|');
          com_line.concat( com_d1);
          com_line.concat( ';');
    #ifdef CP_COMI2
          com_line.concat( com_i2);
          com_line.concat( '|');
          com_line.concat( com_d2);
          com_line.concat( ';');
    #endif
          com_line.concat( com_am);
          //
          _.f=true;
        break;
#endif          

#ifdef EP_TEST_AV
  case COMI_EPTEST:
          //
          if (com_f0Has){
            //
            if (com_f0){
              //
              // put check
              //_EP_setPrem();
                //
              _.add=true;
              _.f=true;
              //
            }
            else{
              //
              // read 
              _EP_getPrem();
              //
              int __f=-1;
              if (_EP_checkPrem()){
                //
                __f=2;
              }
              if (_EP_checkBulk()){
                //
                __f=3;
              }
              //
              int _m=sizeof(EP_prem_t);
              com_line.concat( _m);
                com_line.concat( ';');
              com_line.concat( EP_prem.t.prem);
                com_line.concat( ';');
              com_line.concat( __f);
                com_line.concat( ';');
              //
             _.f=true;
            }
            //
          }
          //
          break;
#endif
        //
#endif
        // show logo 
  case COMI_VERS:
          //
          com_line.concat( _tx_logo);
          com_line.concat( _tx_vers);
          //
          Serial.println( com_line);
          TWI_scanner( true);
          //
      #ifdef VIS_AV
          Serial.println( _VIS0_head);
      #endif

      #ifdef MSX_AV
          if (_MSX0_Has){
            Serial.print( _MSX_0.head);
            Serial.print( _tx_msx_on);
            Serial.print( SO_hex);
            Serial.println( _MSX0_i2c, HEX);
          }
          else{
            Serial.println( _tx_msx_off);
          }
      #endif


      #ifdef SIO_SESTU_AV
            _COM_NamePara2Line( true, COMI_SESTU_PARA);
            Serial.println( com_line);
      #endif
      
      #ifdef PWM_COM_AV
      #ifdef PWM_328_AV
      #ifdef PWM_AD_AV
            _COM_NamePara2Line( true, COMI_EP_T_PWM);
            Serial.println( com_line);
            _COM_NamePara2Line( true, COMI_EP_P_PWM);
            Serial.println( com_line);
            _COM_NamePara2Line( true, COMI_EP_F_PWM);
            Serial.println( com_line);
            _COM_NamePara2Line( true, COMI_EP_2_PWM);
            Serial.println( com_line);
      #endif
      #endif
      #endif

          com_line="";
          com_line.concat( COMH_VERS);//<-- info
          _.SO=false;
          _.add=false;
        break;

        // show help info
  case COMI_HELP:
          _i=0;// <-- index in
          //
          if (_i==0){
            //
            Serial.println( COMH_HELP);
            for (int _i=1; _i<com_am; _i++){
              //
              Serial.print( com_A[_i]);
              Serial.print( '=');
              Serial.println( com_H[_i]);
            }
          }
          
          //
          _.add=false;
          _.vis=false;
          _.SO=false;
          //_.f=true;
        break;

#ifdef COM_RESET
  case COMI_RESET:
          
          com_line.concat( COMH_RESET);
         
          //
#ifdef WDT_AV 
    #ifdef AVR_AV      
          wdt_disable();
          wdt_enable( WDTO_500MS);
    #elif ESP32_AV
          ESP.restart();
    #endif
          //
          // auto reboots with next delay...->
          //
#endif
        break;
#endif

// OS_store::
#ifdef OS_STORE_AV

  case COMI_OS_SAVE:
          //
#ifdef EP_AV
        // EEProm: put(save)
          if (EP_saveValues()){
            //
          }
          else
#elif defined(FLASH_AV) & defined(FLASH_FS_AV)
          if (FS_saveValues( )){
            //
          }
          else
#endif
          {
            com_line.concat( _tx_novalue);
            _.add=false;
          }
          //
        break;

        // OS_store: get(set to loaded)
  case COMI_OS_LOAD:
          //
#if   defined(EP_AV)
          if (EP_loadValues( true)){
            //
          }
          else
#elif defined(FLASH_AV) & defined(FLASH_FS_AV)
          if (FS_loadValues( true)){
            //
          }
          else
#endif
          {
            //
            com_line.concat( _tx_novalue);
            _.add=false;
          }
        break;

        //  get(reset to std)
  case COMI_OS_STD:
          //
#if   defined( EP_AV)
          _.f=EP_loadValues( false);
#elif defined(FLASH_AV) & defined(FLASH_FS_AV)
          _.f=FS_loadValues( false);
#else
          _OS_fillStdValues();
#endif
          break;
#if defined( EP_AV) 
  #if defined(COM_EP_LEN_AV)
  case COMI_EP_LEN:
          int _len=sizeof( EP_prem_t)+sizeof( OS_bulk);
          com_line.concat( _len);
          _.add=false;
          break;
  #endif        
  #if defined( EP_COM_DATA_AV)
        //  get(reset to std)
  case COMI_EP_DATA:
          //
          com_line.concat( EP_data_read0);
          _.add=false;
          break;
  #endif
#endif

#endif

        // on auto: show->T 
#if defined( VIS_AV) & defined( VIS_COM_AV)
  case COMI_A_VIS:
          _vis_ms_setup=VIS_MS_AUTO;
          //
        break;
  case COMI_Z_VIS:
          _vis_ms_setup=VIS_MS_ROTATE;
          //
        break;
  case COMI_T_VIS:
          _vis_ms_setup=VIS_MS_T;
          //
        break;
        // on auto: show->P 
  case COMI_P_VIS:
          _vis_ms_setup=VIS_MS_P;
           //
        break;
        // on auto: show->F 
  case COMI_F_VIS:
          _vis_ms_setup=VIS_MS_F;
          //
        break;
#endif

#if defined( PWM_AV) & defined( PWM_COM_AV)
  case COMI_T_PWM:
  case COMI_P_PWM:
  case COMI_F_PWM:
  case COMI_2_PWM:
          if (_COM_checkMinLTMax(10)){
              //
        #if defined( PWM_328_AV) & defined( PWM_AD_AV)
              switch( comIX){
          case COMI_T_PWM:
                pwm_t_0=com_i0;
                pwm_t_M=com_i1;
              break;
          case COMI_P_PWM:
                pwm_p_0=com_i0;
                pwm_p_M=com_i1;
              break;
          case COMI_F_PWM:
                pwm_f_0=com_i0;
                pwm_f_M=com_i1;
              break;
          case COMI_2_PWM:
                _PWM_DAC_null=com_f0 ? PWM_DAC_NONENULL:PWM_DAC_LOW;
              break;
              }
        #endif
          }
          //
          _COM_MinMax2Line( com_ai);
     
          _.add=false;
        break;
    
#endif

#if defined( SIO_AV) & defined( SIO_COM_AV)
  case COMI_SO_PARA:
          if (com_f0Has){
            //
            SO_para=com_f0;
          }
          else{
            com_para_put.concat( SO_para);
          }
          //
        break;

#if defined( SIO_SESTU_AV) 
  case COMI_SESTU_PARA:
          if (com_f0Has){
            //
            SeStu0.v=com_f0;
          }
          else{
            com_para_put.concat( SeStu0.v);
          }
          //
        break;
#endif

#endif

      }//comIX


      // -> put parsed result -> [pr,ix]
        if (_.add){
          //
          if ((com_ai>-1)&&
              (com_ai<com_am)){
            //
            bool _hasPara=false;
            com_line.concat( com_A[com_ai]);
            if (com_d0.length()>0){
              //
              _hasPara=true;
              com_line.concat( '<');
              com_line.concat( com_d0);
            }
    #ifdef CP_COMI1
            if (com_d1.length()>0){
              //
              _hasPara=true;
              com_line.concat( ',');
              com_line.concat( com_d1);
            }
    #endif
    #ifdef CP_COMI2
            if (com_d2.length()>0){
              //
              _hasPara=true;
              com_line.concat( ",..");
            }
    #endif
            if (!_hasPara){
              if (com_para_put.length()>0){
                //
                com_line.concat( '=');
                com_line.concat( com_para_put);
              }
              else{
                com_line.concat( com_DONE);
              }
            }
          }
          else{
            //
            com_line.concat( com_NONE);
          }
          //
        }
        //
#ifdef VIS_AV
        //
      vis_line="";
      if (_.vis){
        //
        vis_line.concat( com_line);
        //
        OS_loop_refresh=_.clr;
        _VIS_print( 0, true, _.clr ? -1:0, com_lineDelay);
        vis_line="";
      }
#endif
      // Out: Serial[CL]
        if (_.SO){
          //
          Serial.println( com_line);
        }
      //
    }
    // HadCom
    return _.f;
}





/**
 * Serial: data in Evt
 */
/*
void serialEvent(){
  //
  int   _m=Serial.available();
  char  _c=0;
  int   _iC=0;
    //
    //SI_line="";
    comReset();
    //
    for ( ;_m>0; _m--){
      //
      _c=(char)Serial.read();
      if (COM_parseChar( _c)){
        //
        if (COM_exec()){
          //
          _iC++;
          // <-- done/check/ oelse!
        }
        //
        comReset();
      }
    }
}
*/

/*!
 * get serial chars and parse and connect them and execute.
 *@param _i  .. pos of char wihle burst in
 *@param _c  .. char[i] within the burst
 */
void COM_serialParser( int _i, char _c){
  //
  if (_i<=0){
    COM_reset();
  }
      if (COM_parseChar( _c)){
        //
        if (COM_exec()){
          //
          // <-- done/check/ oelse!
        }
        //
        COM_reset();
      }
}




#endif//COM
//@