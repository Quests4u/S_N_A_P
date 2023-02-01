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

uint8_t            comP_t[CMD_PARA_MAX+2]     = { 0};//String("01234567");    // command
uint8_t*           comP       =&comP_t[0];
int8_t            comP_i      = 0;
//int8_t            com_m       = CMD_P_MAX;


//
bool              comPD       = true;                   // proc/data
bool              comPD_en    = true;                   // -> (Data) use char 
                                                       // incase ignore until next synch (,:,@)

uint8_t            comD_t[CMD_DATA_MAX+2] = { 0};
uint8_t*           comD       =&comD_t[0];
int8_t            comD_i      = 0;


int               comDcou     = 0;
// %0..%2[3]
uint8_t          com_d0_t[CMD_DATA_MAX+2] = { 0};
uint8_t*          com_d0       =&com_d0_t[0];
int16_t               com_i0   = -1;
  bool              com_i0Has  = false;
bool              com_f0       = false;
  bool              com_f0Has  = false;

#if defined(  CP_COMI1)
uint8_t           com_d1_t[CMD_DATA_MAX+2] = {0};
uint8_t*          com_d1       =&com_d1_t[0];
int16_t               com_i1   = -1;
  bool              com_i1Has  = false;
bool              com_f1       = false;
  bool              com_f1Has  = false;
#endif

#if defined( CP_COMI2)
uint8_t            com_d2_t[CMD_DATA_MAX+2] = {0};
uint8_t*          com_d2       =&com_d2_t[0];
int16_t               com_i2       = -1;
  bool              com_i2Has  = false;
bool              com_f2       = false;
  bool              com_f2Has  = false;
#endif


#if defined( CP_COMI3)
uint8_t            com_d3_t[CMD_DATA_MAX+2] = {0};
uint8_t*            com_d3       =&com_d3_t[0];
int16_t               com_i3       = -1;
  bool              com_i3Has  = false;
bool              com_f3       = false;
  bool              com_f3Has  = false;
#endif

// com-string/ix/info
bool              comHas      = false;
int16_t           comI        = -1;
bool              comDelayed  = false;
//

const char*       com_NONE    =  COM_NONE;
const char*       com_DONE    =  COM_DONE;
const char*       comH_NONE   = COMH_NONE;



// *** STD COMMANDOS

CMD_TX_set_t          CMDx_HELP   =
              { 
                      COMI_HELP
                      ,COM_HELP
                      ,COMH_HELP
              };
                      //
CMD_TX_set_t          CMDx_VERS   =
              {
                      COMI_VERS
                      ,COM_VERS
                      ,COMH_VERS
              };
CMD_TX_set_t          CMDx_DEBUG   =
              {
                      COMI_DEBUG
                      ,COM_DEBUG
                      ,COMH_DEBUG
              };
#if defined( WDT_AV) & defined( WDT_COM_AV)
CMD_TX_set_t          CMDx_RESET   =
              {
                      COMI_RESET
                      ,COM_RESET
                      ,COMH_RESET
              };
#endif                               
                      //

                      //
#if defined( OS_STORE_AV)
CMD_TX_set_t          CMDx_OS_SAVE   =
              {
                      COMI_OS_SAVE
                      ,COM_OS_SAVE
                      ,COMH_OS_SAVE
              };
CMD_TX_set_t          CMDx_OS_LOAD   =
              {
                      COMI_OS_LOAD
                      ,COM_OS_LOAD
                      ,COMH_OS_LOAD
              };
CMD_TX_set_t          CMDx_OS_STD   =
              {
                      COMI_OS_STD
                      ,COM_OS_STD
                      ,COMH_OS_STD
              };


#endif//store


#ifdef EP_AV
#endif


#ifdef EEP_AV
#endif


                      //
#if defined( PWM_AV) & defined( PWM_COM_AV)
CMD_TX_set_t          CMDx_T_PWM   =
              {
                      COMI_T_PWM
                      ,COM_T_PWM
                      ,COMH_T_PWM
              };
CMD_TX_set_t          CMDx_P_PWM   =
              {
                      COMI_P_PWM
                      ,COM_P_PWM
                      ,COMH_P_PWM
              };
CMD_TX_set_t          CMDx_H_PWM   =
              {
                      COMI_H_PWM
                      ,COM_H_PWM
                      ,COMH_H_PWM
              };
CMD_TX_set_t          CMDx_2_PWM   =
              {
                      COMI_2_PWM
                      ,COM_2_PWM
                      ,COMH_2_PWM
              };
#endif


#if defined( SIO_AV) & defined( SIO_COM_AV)
CMD_TX_set_t          CMDx_SO_PARA   =
              {
                      COMI_SO_PARA
                      ,COM_SO_PARA
                      ,COMH_SO_PARA
              };

    #if defined( SIO_COM_SESTU_AV)
CMD_TX_set_t          CMDx_SESTU_PARA   =
              {
                      COMI_SESTU_PARA
                      ,COM_SESTU_PARA
                      ,COMH_SESTU_PARA
              };
    #endif

#endif

                      //
CMD_TX_set_t          CMDx_LOOP_PARA   =
              {
                      COMI_LOOP_PARA
                      ,COM_LOOP_PARA
                      ,COMH_LOOP_PARA
              };
CMD_TX_set_t          CMDx_NOBREAK   =
              {
                      COMI_NOBREAK
                      ,COM_NOBREAK
                      ,COMH_NOBREAK
              };

CMD_TX_set_t          CMDx_NULL   =
              {
                      COMI_NULL
                      ,COM_NULL
                      ,COMH_NULL
              };
CMD_TX_set_t          CMDx_NONE   =
              {
                      COMI_NONE
                      ,COM_NONE
                      ,COMH_NONE
              };
                      //
// END: STD COMMANDOS


CMD_TX_set_t*          CMDx_NULLptr=&CMDx_NULL;
CMD_TX_set_t*          CMDx_NONEptr=&CMDx_NONE;
CMD_TX_set_t*          CMDx[]   ={
       &CMDx_HELP
      ,&CMDx_VERS
      ,&CMDx_DEBUG
      //
      // WDT
#if defined( WDT_AV) & defined( WDT_COM_AV)
      ,&CMDx_RESET
#endif
      //
      // VIS
#if defined( VIS_AV) & defined( VIS_COM_AV)
      //,&CMDx_A_VIS
      //,&CMDx_Z_VIS
#endif
      //
      // STORE
#if defined( OS_STORE_AV)
      ,&CMDx_OS_LOAD
      ,&CMDx_OS_SAVE
      ,&CMDx_OS_STD
#endif
      //
      // PWM
#if defined( PWM_AV) & defined( PWM_COM_AV)
      ,&CMDx_T_PWM
      ,&CMDx_P_PWM
      ,&CMDx_H_PWM
      ,&CMDx_2_PWM
#endif
      //
      // SIO
#if defined( SIO_AV) & defined( SIO_COM_AV)
      ,&CMDx_SO_PARA
    #if defined( SIO_COM_SESTU_AV)
      ,&CMDx_SESTU_PARA
    #endif
#endif

      ,&CMDx_LOOP_PARA
      ,&CMDx_NOBREAK


      ,CMDx_NULLptr
      ,CMDx_NULLptr
      ,CMDx_NULLptr
      ,CMDx_NULLptr
      //
      ,CMDx_NULLptr
      ,CMDx_NULLptr
      ,CMDx_NULLptr
      ,CMDx_NULLptr
};
int8_t            CMDx_max= sizeof(CMDx)/sizeof(CMDx_NONEptr);//(CMDx_NULLptr);

int8_t            com_am  = 1;
int8_t            com_ai  = 0;




uint8_t           com_line_t[CMD_LINE_MAX+2] = {0};
uint8_t*          com_line        =&com_line_t[0];
int16_t               com_lineDelay   = OS_DELAY_INFO;
uint8_t           com_para_put[CMD_INPUT_MAX+2] = {0};



// CParser:
bool              cpHas      = false;
int8_t            cp_0base  = 10;
int16_t           cp_0       = 0;// int value
double            cp_R       = 0.0;// float value
bool              cp_0sgn    = true;//pos[neg]




/* Routine Definitions */




bool cpReset( bool _sgn){
    //
    cpHas     =false;
    cp_0      =0;
    cp_R      =0.0;
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
    if ((_c>=65)  //'A'
       &(_c<=91)){//'Z'
      _c+=0x20;// 'a'
    }
    // select Num
    switch( _c){
      //
    case '+':
          break;
    case '!':
    case '-':
            cp_0sgn=!cp_0sgn;
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


  int CMDxNext( bool _none){
    //
    int _ia=-1;
    CMD_TX_set_t* _cmd;
    for (int _i=0; _i<CMDx_max; _i++){
      //
      _cmd=CMDx[_i];
      //
      if (_cmd==CMDx_NULLptr){     
        //
        _ia=_i;
        break;
      }
      if (_none){
        if (_cmd==CMDx_NONEptr){     
          //
          _ia=_i;
          break;
        }
      }//none
      //
    }
    return _ia;
  }



/*!
 * CMD/COM setup
 */
bool CMD_setup( 
                  int8_t _ix
            ){
    //
    bool _f =false;
    com_ai  =0;
    com_am  =0;
    //
    int _am =CMDxNext( false);
    if (_am>0){
      //
      com_am=_am;
      _f=true;
    }//has
    //
    return _f;
}



/*!
 *
 */
bool CMDxAdd(     
               CMD_TX_set_t* _cmd
            ){
    //
    bool _f=false;
    //
    if (_cmd){
      //
      int _ai =CMDxNext( true);
      if (_ai>0){
        //
        CMDx[_ai]=_cmd;
        //
        if (_ai==com_am){
          com_am=_ai+1;
        }
        else if (_ai>com_am){
          com_am=_ai;
        }
        _f=true;
      }//has
    }//is
    //

    return _f;
}







/*!
 *
 */
bool COM_reset(){
    //
    //comP    = "";
      OS_str_clr( comP);
    
    comP_i   = 0;
    //comD    = "";
      OS_str_clr( comD);
    comD_i  = 0;
    //
    comPD     = true;
    comPD_en  = true;
    comDcou   = 0;
    //
    //com_d0   = "";
      com_d0[0]  = 0;
      com_i0   = -1;
        com_i0Has = false;
      com_f0   = false;
        com_f0Has = false;
#ifdef CP_COMI1
    //com_d1   = "";
      com_d1[0] = 0;
      com_i1   = -1;
        com_i1Has = false;
      com_f1   = false;
        com_f1Has = false;
#endif
#ifdef CP_COMI2
   //com_d2   = "";
      com_d2[0] = 0;
      com_i2   = -1;
        com_i2Has = false;
      com_f2   = false;
        com_f2Has = false;
#endif
#ifdef CP_COMI3
    //com_d3   = "";
    com_d3[0]   = 0;
      com_i3   = -1;
        com_i3Has = false;
      com_f3   = false;
        com_f3Has = false;
#endif
    //
    cpReset( true);
    //
    comHas  = false;
    comI    = COMI_NONE;
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
              //OS_str_Btrim( comD, 0, true, true, CMD_DATA_MAX);
              //if (comD==CP_TRUE){
              if        (OS_str_BhasC( comD, 0, CP_TRUE, false, CMD_DATA_MAX)){
                  return true;
              }
              //else if (comD==CP_ON){
              else if   (OS_str_BhasC( comD, 0, CP_ON,false, CMD_DATA_MAX)){
                  return true;
              }
              // true:false
              //if (comD==CP_FALSE){
              if        (OS_str_BhasC( comD, 0, CP_FALSE, false, CMD_DATA_MAX)){
                                return _isBool;
              }
              //if (comD==CP_OFF){
              if        (OS_str_BhasC( comD, 0, CP_OFF, false, CMD_DATA_MAX)){
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
              bool _fB=_comBV( true);
              //
              switch( comDcou){
            case 0: //com_d0=comD;
                    OS_str_BaddB( com_d0, 0, comD, CMD_DATA_MAX);
                    if (_fB){
                      com_f0    =_comBV( false);
                      com_f0Has =true;
                    }
                break;
    #ifdef CP_COMI1
            case 1: //com_d1=comD;
                    OS_str_BaddB( com_d1, 0, comD, CMD_DATA_MAX);
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
              //comD="";
                  OS_str_clr( comD);
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
         //
            for (int _i=0;_i<com_am; _i++){
               //
               if (OS_str_BhasC( comP, 0, CMDx[_i]->TX, false, CMD_PARA_MAX)){
                  //
                  com_ai=_i;
                  comI=CMDx[_i]->I;
                  comHas=true;
                  //
                  _comCParseI( '@');
                  //
                  _comDAdd();
                  //
                  //break;
               }//has
            }//loop
         Serial.println( );
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
      //if (comP_i<com_m){
      if (comP_i<CMD_PARA_MAX){
        //
        if (comPD_en){
          //
          if (isWhitespace(_c)){
            //
            // -> exclude pre^WS on comP
          }
          else{
            //
            //comP+=_c;
            OS_str_BaddV( comP, comP_i, _c, CMD_PARA_MAX);
            comP_i++;
          }
        }
      }
    }
    else{
      //
      if ((comPD_en)&&
          //(comD_i<comD_m)){  
          (comD_i<CMD_DATA_MAX)){  
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
               OS_str_BaddV( comD, comD_i, _c, CMD_DATA_MAX);
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
      bool _COM_checkMinLTMax( int8_t _d){
        //
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
      int8_t _COM_ai4com_I( int16_t _comI){
          //
          int8_t _ai=-1;
          //
          for (int _i=0;_i<com_am; _i++){
              //
              if (CMDx[_i]->I==_comI){
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
                    bool      _clr,
                    int16_t   _comI
                    ){
         // 
          if (_clr){
            com_line[0]=0;
          }
          //
          int8_t _ai=_COM_ai4com_I( _comI);
          if (_ai>=0){
            //
            _COM_MinMax2Line( _ai);
          }
          else{
            _ai=0;
            OS_str_BaddC( com_line, -1, _tx_notexists, CMD_LINE_MAX);
          }
          com_ai=_ai;
      }


      
      /**
       * com_line: fill with com_* parameter [min,max]
       *@param  _ai   ..  com_ai <- index <- com_A[] = com_I[]
       */
      void _COM_MinMax2Line( int8_t _ai){
        //
          OS_str_BaddC( com_line, -1, CMDx[_ai]->TX, CMD_LINE_MAX);
          OS_str_BaddC( com_line, -1, ": ", CMD_LINE_MAX);
            //
              switch( CMDx[_ai]->I){
        #ifdef SIO_SESTU_AV
          case COMI_SESTU_PARA:
                  OS_str_BaddV( com_line, -1, '>', CMD_LINE_MAX);
                  OS_str_BaddV( com_line, -1, SeStu0.v, CMD_LINE_MAX);
                  //                  
              break;
        #endif
        #if defined( PWM_AV) & defined( PWM_COM_AV) & defined( PWM_328_AV) & defined( PWM_AD_AV)
          case COMI_T_PWM:
                  OS_str_BaddN( com_line, -1, pwm_t_0, -1, CMD_LINE_MAX);
                  OS_str_BaddV( com_line, -1, ',', CMD_LINE_MAX);
                  OS_str_BaddN( com_line, -1, pwm_t_M, -1, CMD_LINE_MAX);
               //               
              break;
          case COMI_P_PWM:
                  OS_str_BaddN( com_line, -1, pwm_p_0, -1, CMD_LINE_MAX);
                  OS_str_BaddV( com_line, -1, ',', CMD_LINE_MAX);
                  OS_str_BaddN( com_line, -1, pwm_p_M, -1, CMD_LINE_MAX);
               //               
              break;
          case COMI_H_PWM:
                  OS_str_BaddN( com_line, -1, pwm_h_0, -1, CMD_LINE_MAX);
                  OS_str_BaddV( com_line, -1, ',', CMD_LINE_MAX);
                  OS_str_BaddN( com_line, -1, pwm_h_M, -1, CMD_LINE_MAX);
               //               
              break;
          case COMI_2_PWM:
                  OS_str_BaddN( com_line, -1, _PWM_DAC_null, -1, CMD_LINE_MAX);
                  OS_str_BaddV( com_line, -1, '%', CMD_LINE_MAX);
               //
              break;
        #endif
            }//switch
      }//Get 




/*!
 *@param _  act. com[] set
 */
CMD_PARSE_set_t  COM_actions( 
                     CMD_PARSE_set_t _
               ){
  //
  int8_t _ai=_COM_ai4com_I( _.I);
  if (_ai>0){
    //
    if (CMDx[_ai]->ActionParse){
      //
      _.consumed=true;
      _=CMDx[_ai]->ActionParse(_);
    }
    //
  }
  //
  return _;
}





/*!
 * execute element selected from comIX.
 * enabled by comHas
 * @return true .. %done
 */
bool COM_exec(){
    //
    CMD_PARSE_set_t _={
        true//f
        ,comI//I
        //
        ,true//vis[ual_out]
        ,true//S[erial]O[ut]
        //
        ,true//cls <- before vis
        ,true//addParam(result)
        //
        ,false//consumed
    };
    //
    int8_t   
         _i=0
    ;
    //
    com_line[0]=0;
    com_para_put[0]=0;
    //
    if (comHas){
      //
      _=COM_actions( _);
      //
      if (!_.consumed){
        //
        switch( _.I){
          //
  case COMI_NONE:
  default:
            OS_str_BaddC( com_line, -1, comH_NONE, CMD_LINE_MAX);
            _.addParam=false;
            _.f=false;
          break;
  

          // debug just onable
  case COMI_DEBUG:
            if (com_f0Has){
               //
               OS_debug=com_f0;
            }
            else{
               OS_str_BaddV( com_line, -1, OS_debug, CMD_LINE_MAX);
            }
            //
            break;


  case COMI_LOOP_PARA:
            if (com_i0Has){
              //
              OS_loop_max=com_i0 & 0xFF;
              if (OS_loop_max<2){
                OS_loop_max=2;
              }
            }
            else{
               OS_str_BaddN( com_para_put, -1, OS_loop_max, -1, CMD_INPUT_MAX);
            }
            //
            break;


  case COMI_NOBREAK:
            if (com_f0Has){
               //
               OS_nobreak=com_f0;
            }
            else{
               OS_str_BaddV( com_para_put, -1, OS_nobreak, CMD_INPUT_MAX);
            }
            break;



          // show vers/logo/help 
  case COMI_VERS:
            //
            OS_str_BaddC( com_line, -1, _tx_logo, CMD_LINE_MAX);
            OS_str_BaddC( com_line, -1, _tx_vers, CMD_LINE_MAX);
            //
            Serial.println( (char*)&com_line[0]);
    
      #if defined(TWI_SCAN_AV)
            TWI_scanner( true);
      #endif
            //
      #if defined( VIS_AV)
            //
            Serial.print(  _tx_vis_nul);
            Serial.println( (char*)_VIS0_head);
      #endif

      #if defined( MSX_AV)
            if (_MSX0_Has){
              Serial.print( (char*)_MSX_0.head);
              Serial.print( _tx_on);
              Serial.println( _MSX0_i2c, HEX);
            }
            else{
              Serial.println( _tx_off);
            }
      #endif

      #if defined( SIO_SESTU_AV)
              _COM_NamePara2Line( true, COMI_SESTU_PARA);
              Serial.println( (char*)com_line);
      #endif
      
      
      #if defined( PWM_AV) & defined(PWM_COM_AV) & defined( PWM_328_AV) & defined( PWM_AD_AV)
            _COM_NamePara2Line( true, COMI_T_PWM);
            Serial.println( (char*)com_line);
            _COM_NamePara2Line( true, COMI_P_PWM);
            Serial.println( (char*)com_line);
            _COM_NamePara2Line( true, COMI_H_PWM);
            Serial.println( (char*)com_line);
            _COM_NamePara2Line( true, COMI_2_PWM);
            Serial.println( (char*)com_line);
      #endif

            //com_line="";
            OS_str_clr( com_line);
            //com_line.concat( COMH_VERS);//<-- info
            OS_str_BaddC( com_line, -1, COMH_VERS, CMD_LINE_MAX);
            _.SO=false;
            _.addParam=false;
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
                Serial.print( CMDx[_i]->TX);
                Serial.print( '=');
                Serial.println( CMDx[_i]->hlp);
              }//loop
            }// has
            //
            _.addParam=false;
            _.vis=false;
            _.SO=false;
          break;



#if defined( COM_RESET)
  case COMI_RESET:
            //
            //com_line.concat( COMH_RESET);
            OS_str_BaddC( com_line, -1, COMH_RESET, CMD_LINE_MAX);
                      
#if defined( WDT_AV)

    #if defined( AVR_AV)
            wdt_disable();
            wdt_enable( WDTO_500MS);
    #elif defined( ESP8266_AV)
            ESP.restart();
    #elif defined( RASP_AV )
            rp2040.restart();
    #endif
            //
            // auto reboots with next delay...->
            //
#endif
          break;
#endif

// OS_store::
#if defined( OS_STORE_AV)

  case COMI_OS_SAVE:
          //
#if defined( EP_AV)
        // EEProm: put(save)
            if (EP_saveValues()){
              //
            }
            else
#elif defined(FLASH_AV) & defined(FLASH_FS_AV)

            OS_str_BaddC( com_line, -1, _tx_FS, CMD_LINE_MAX);
            if (!FS0.has){
              //
              FS_setup();
            }
            //
            if (FS_saveValues( )){
              //
            }
            else
#endif
            {
              OS_str_BaddC( com_line, -1, _tx_novalue, CMD_LINE_MAX);
            _.addParam=false;
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

            OS_str_BaddC( com_line, -1, _tx_FS, CMD_LINE_MAX);
            if (!FS0.has){
              //
              FS_setup();
            }
            //
            if (FS_loadValues( true)){
              //
            }
            else
#endif
            {
              //
              OS_str_BaddC( com_line, -1, _tx_novalue, CMD_LINE_MAX);
            _.addParam=false;
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
              OS_str_BaddN( com_line, -1, _len, CMD_LINE_MAX);
              _.addParam=false;
            break;
  #endif    


  #if defined( EP_COM_DATA_AV)
        //  get(reset to std)
  case COMI_EP_DATA:
              //
              OS_str_BaddC( com_line, -1, EP_data_read0, CMD_LINE_MAX);
              _.addParam=false;
            break;
  #endif
#endif

#endif


#if defined( PWM_AV) & defined( PWM_COM_AV)
  case COMI_T_PWM:
  case COMI_P_PWM:
  case COMI_H_PWM:
  case COMI_2_PWM:
              if (_COM_checkMinLTMax(10)){
                //
        #if defined( PWM_328_AV) & defined( PWM_AD_AV)
                //switch( comIX){
                switch( _.I){
          case COMI_T_PWM:
                  pwm_t_0=com_i0;
                  pwm_t_M=com_i1;
                break;
          case COMI_P_PWM:
                  pwm_p_0=com_i0;
                  pwm_p_M=com_i1;
                break;
          case COMI_H_PWM:
                  pwm_h_0=com_i0;
                  pwm_h_M=com_i1;
                break;
          case COMI_2_PWM:
                  _PWM_DAC_null=com_f0 ? PWM_DAC_NONENULL:PWM_DAC_LOW;
                break;
                }//comIX
          #endif
              }//check
              //
              _COM_MinMax2Line( com_ai);
              _.addParam=false;
            break;
    
#endif

#if defined( SIO_AV) & defined( SIO_COM_AV)
  case COMI_SO_PARA:
            if (com_f0Has){
              //
              SO_para=com_f0;
            }
            else{
              //com_para_put.concat( SO_para);
              OS_str_BaddV( com_para_put, -1, SO_para, CMD_INPUT_MAX);
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
              //com_para_put.concat( SeStu0.v);
              OS_str_BaddV( com_para_put, -1, SeStu0.v, CMD_INPUT_MAX);
            }
            //
          break;
#endif

#endif

        }//comIX
      }//consumed


      // -> put parsed result -> [pr,ix]
        if (_.addParam){
          //
          if ((com_ai>-1)&&
              (com_ai<com_am)){
            //
            bool _hasPara=false;
              OS_str_BaddC( com_line, -1, CMDx[com_ai]->TX, CMD_LINE_MAX);
            if (OS_str_Blen( com_d0, CMD_DATA_MAX)>0){
              //
              _hasPara=true;
              OS_str_BaddV( com_line, -1, '=', CMD_LINE_MAX);
              OS_str_BaddB( com_line, -1, com_d0, CMD_LINE_MAX);
            }
    #ifdef CP_COMI1
            if (OS_str_Blen( com_d1, CMD_DATA_MAX)>0){
              //
              _hasPara=true;
              OS_str_BaddV( com_line, -1, ',', CMD_LINE_MAX);
              OS_str_BaddB( com_line, -1, com_d1, CMD_LINE_MAX);
            }
    #endif
    #ifdef CP_COMI2
            if (com_d2.length()>0){
              //
              _hasPara=true;
              OS_str_BaddV( com_line, -1, ',', CMD_LINE_MAX);
              OS_str_BaddB( com_line, -1, com_d2, CMD_LINE_MAX);
            }
    #endif
            if (!_hasPara){
              if (OS_str_Blen(com_para_put, CMD_INPUT_MAX)>0){
                //
                OS_str_BaddV( com_line, -1, '=', CMD_LINE_MAX);
                OS_str_BaddB( com_line, -1, com_para_put, CMD_LINE_MAX);
              }
              else{
                OS_str_BaddC( com_line, -1, com_DONE, CMD_LINE_MAX);
              }
            }
          }
          else{
            //
            OS_str_BaddC( com_line, -1, com_NONE, CMD_LINE_MAX);
            
          }
          //
        }
        //
#ifdef VIS_AV
        //
      OS_str_clr( vis_line);
      if (_.vis){
        //
        OS_str_BaddB( vis_line, -1, com_line, VIS_LINE_MAX);
        //
        OS_loop_refresh=_.clr;
        _VIS_print( 0, true, _.clr ? -1:0, com_lineDelay);
        OS_str_clr( vis_line);
      }
#endif
      // Out: Serial[CL]
        if (_.SO){
          //
          Serial.println( (char*)com_line);
        }
      //
    }
    // HadCom
    return _.f;
}





/*!
 * get serial chars and parse and connect them and execute.
 *@param _i  .. pos of char wihle burst in
 *@param _c  .. char[i] within the burst
 */
void COM_serialParser( 
                     int8_t _i, 
                     char _c
               ){
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