/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       adc.h
* @brief      analoge drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/io/adc.h>

#if defined(ADC_AV)

/* Statische Definitions */




/* Dynamische Definitions */

/*!
 *  AVR:  ADC[0] Port=A6
 *        ADC[1] Port=A7
 */
ADC_set_t   ADCx[] = {
    {
    ADC_UX_HAS  // has port
    ,false      // had r/w

    //
    ,true       // r=true w=false
    ,ADC_UX     //A6  GIO port
    //
    ,0.0        // delta
    ,0.0        // act. value
    ,0//10      // act. steps    
    //
    ,ADC_STEPS  //1024      10b=1024, 8bit=256 usw
    ,ADC_FX     //5.0/1024  U/step factor
    ,ADC_KX     //4.75/5.0  Korrectur
    //
    ,0          //0     NC: step min
    ,ADC_STEPS  //1024  NC: step max  

    ,-1         // no AN
    //
    },
    {
    ADC_UREF_HAS// has port
    ,false      // had r/w

    //
    ,true       // r=true w=false
    ,ADC_UREF//A7,         // GIO port
    //
    ,0.0         // delta
    ,0.0        // act. value
    ,0//10      // act. steps    
    //
    ,ADC_STEPS  //1024      10b=1024, 8bit=256 usw
    ,ADC_FX     //5.0/1024  U/step factor
    ,ADC_KX     //4.75/5.0  Korrectur
    //
    ,0          // NC: step min
    ,ADC_STEPS  // NC: step max  
    //
    ,-1         // no AN
    }
};
int8_t   ADCxcount=2;


/*!
 * std. -1 AVR: Port= A0
 */
ANT_set_t    ANTx[]={
    //
    { //#0
    ANT_C_HAS  // has
    ,false  // had
    //
    ,true   // polarity = true / ! false
    ,-1     // mux (multiplex with V or other ADCs)

    ,false  // 0/1 LOW/HIGH false/true  -> NC: -1=Threestate
    ,ANT_PORT_SIGN// A0     // signalPort

    ,0.0    // hysterese (0=off)
    ,0.0    // old value 

    ,0      // IX
    ,NULL   //*ADC_set_t <- ADCscr (for HX)

    ,ANT_REF_SOFT//false  refSoft 
    ,NULL   //*ADC_set_t <- Adcref (for soft trigger / hard wired with ANT_ISR)
    ,NULL   //.     *Action(ix)  <- when toggle[HX]
    }
};
int8_t   ANTxcount=1;



 ADC_set_t*  _ADC_Ux    =&ADCx[0];
 ADC_set_t*  _ADC_Uref  =&ADCx[1];

 ANT_set_t*    _ANT_c   =&ANTx[0];






/* Routine Definitions */







#if defined( ADC_ANT_AV)


/*!
 *  on/off  state (Trigger)
 */
bool  ANTstate( ANT_set_t* _ant){
    //
    bool _sw=false;
    
#if defined(AVR_AV) & defined(ADC_ANT_ISR_AV)

    _sw=!(ACSR & (1<<ACO));// Ax > Aref => 1
    if (_ant!=NULL){
        _ant->SW=_sw;
    }
    
#else

    // cmp:: soft[Ref]
    /*
    if (_ant->Adc!=NULL){
        //
        if  ((_ant->refSoft)
            &(_ant->Ref!=NULL)
            ){
        
        }//cmp
    }//has
    */

#endif
    return _sw;
}//state




    /*!
     *  
     */
    ANT_set_t*  ANTptr(
                    int8_t _ix
                ){
        ANT_set_t* _an=NULL;
        //
        if  ((_ix>=0)
            &(_ix<ANTxcount)
            ){
            //
            _an=&(ANTx[_ix]);
        }
        //
        return _an;
    }

    
    /*!
     *
     */
    bool  ANTset( ANT_set_t* _ant){
        //
        bool _f=false;
        if (_ant!=NULL){
            //
            bool    _sw     =_ant->SW;
                    _sw     =_ant->Polarity ? _sw:!_sw;
            int8_t _level   =_sw ? HIGH:LOW;
            
            //
            bool _fPort     =_ant->Port>0;
            bool _fAct      =_ant->Action!=NULL;

                // do:signalPort
                if (_fPort){
                    //
                    digitalWrite( _ant->Port, _level);
                }//port

                // do:Action
                if  (_fAct){
                    //
                    //int8_t _ix=_an->ix;
                    _ant->Action( _ant->ANTix);
                }//act
            //
            _f=true;
        }//has
        return _f;
    }//update


    /*!
     *
     */
    bool  ANTsoft( ANT_set_t* _ant){
        //
        bool _f=false;
        if (_ant!=NULL){
            if  (!_ant->refSoft){ return _f;}
            //
            bool _fAdc      =_ant->Adc!=NULL;
            bool _fRef      =_ant->Ref!=NULL;
            if ((_fAdc)
                &(_fRef)
                ){
                //
                ADC_set_t* _adc =_ant->Adc;
                ADC_set_t* _ref =_ant->Ref;
                //
                if (_ant->HX!=0){
                    //
                    // released!
                    if (!_ant->had){
                        //
                        bool   _sw=_ant->HX<0;//release rise/fall +HX/-HX
                        double _dV=_adc->V-_ref->V;
                        //
                        // rise (to triggerValue)
                        if (_sw){
                            _f=_dV>=0;// trigger if above _sw=1
                        }
                        // fall (to triggerValue)
                        else{
                            _f=_dV<=0;// trigger if below _sw=0
                        }
                        // trigger: has
                        if (_f){
                            _ant->SW=true;
                            //
                            _ant->had=true;// deactivate
                            _ant->V  =_adc->V;
                            //
                        }//trigger
                        //
                    }//had trigger
                }// just with HX
            }//!NULL    
            //
        }//ant
        return _f;
    }//



    /*!
     *
     */
    bool  ANTrelease( ANT_set_t* _ant){
        //
        bool _f=false;
        if (_ant!=NULL){
            //
            bool _fAdc      =_ant->Adc!=NULL;
            if  ((_fAdc)
                &(_ant->HX!=0)
                ){
                //
                ADC_set_t* _adc =_ant->Adc;
                ADC_set_t* _ref =_ant->Ref;
                //
                if (_ant->had){
                    //
                    bool   _sw=_ant->HX<0;//release rise/fall +HX/-HX
                    double _dV=_adc->V -_ant->V;
                    if (_ref!=NULL){
                        if (_ref->has){
                           _dV=_adc->V -_ref->V;       
                        }
                    }//ref
                    //
                    // rise (from below)
                    if (_sw){
                        _f=_dV<_ant->HX;// release if below _sw=1
                    }
                    // fall (from above)
                    else{
                        _f=_dV>_ant->HX;// release if above _sw=0
                    }
                    //
                    if (_f){
                        _ant->SW =!_sw;
                        _ant->had=false;// activate
                        //
                     }
                }//had
            }//adc
            else{
                _ant->had=false;
                _f=true;  
            }
            //
        }//an
        return _f;
    }//update





#if defined( ADC_ANT_ISR_AV)


    /*!
     *
     */
    bool ANTvector( ANT_set_t* _ant){
        //
        bool _f=false;
        //
        if (_ant!=NULL){
            //
            // state
            bool _sw        =ANTstate( _ant);     
            bool _fSet      =true;
            //
            // Toggle
            if (_ant->Adc!=NULL){
                //
                ADC_set_t* _adc =_ant->Adc;
                ADChandler( _adc, true, false);
                //
                if (!_ant->had){
                    //
                    if (_ant->HX!=0){
                        //
                        bool _rf=_ant->HX<0;
                        // rise
                        if (_rf){
                            //
                            if (_sw){
                                _ant->had=true;
                                _ant->V  =_adc->V;
                            }
                        }
                        // fall
                        else{
                            if (!_sw){
                                _ant->had=true;
                                _ant->V  =_adc->V;
                            }
                        }//
                        //
                    }//HX!=0
                }//had
                else{
                    _fSet   =false;
                }
                //
            }//adc

            // do:Adc
            if (_fSet){
                //
                ANTset( _ant);
            }
        }//has

        return _f;
    }





#if defined( AVR_AV) 

   #if defined( ADC_ANT_AV) & defined( ADC_ANT_ISR_AV)

    ANT_set_t*    ANT01_isr=ANTptr(0);

    ISR(ANALOG_COMP_vect ) {
        //
        ANTvector( ANT01_isr);
        //
    }

   #endif
   
#elif defined(ESP8266_AV)





#endif




#endif



 

/*!
 *
 */
bool    ANTbegin(
                int8_t _ix
                        ){
    bool _f=false;
    ANT_set_t* _ant=ANTptr( _ix);
    //
    if  (_ant==NULL){ return _f;}

        // Adc
        if (_ant->Adc!=NULL){
            //
            _ant->Adc->ANTix=_ix;
        }
        
        // Ref
        if (_ant->Ref!=NULL){
            //
            _ant->Ref->ANTix=_ix;
        }

        // signalOut
        //
        int8_t _O=_ant->Port;
        if (_O>0){
            //
            pinMode( _O, OUTPUT);
        }//
        //
        // AN-settings
        //
#if defined( AVR_AV) 

   #if defined( ADC_ANT_ISR_AV) & not defined( PWM_AV)
        //
        // Using ADC[0] / ADC[1] => WOT!  ANI0 = Uref, ANI1 = Ux .. !used reverse due to reverse cmpOP +in(ANI1) -in(ANI0) connectiones
        DIDR1 |= (1<<AIN0D);        // Disable Digital Inputs at AIN0 and AIN1
        //
        // !WOT: switches off used ADC[] or even dont work yet!
        // MUX <- A0-X
        if      ((_ant->Mux>=ADC_MUX_AD)
                &(_ant->Mux<ADC_MUX_INNER)
                ){
            //
	        ADCSRA &= ~(1<<ADEN);
            ADCSRB |= (1<<ACME);	//Set ACME bit in ADCSRB to use external analog input at AIN1 -ve input
	        ADMUX  =
                (0 << REFS1)|       // B7
                (0 << REFS1)|       // B6
                                    // internal - external scr
                                    // 0 0 .. Aref,Internal Vref
                                    // 0 1 .. AVcc as ARef
                                    // 1 0 .. --
                                    // 1 1 ..  Internal 1.1V Ref

                ((_ant->Mux )& 0x0F)|
                                    // 0-7[8] .. AN0

                0;
        }
        else{
            //
            // use ADC[0] as AIN1
	        ADCSRA |= (1<<ADEN);    // use AIN1    
            ADCSRB &= ~(1<<ACME);   // no mux with A0-AX
        }
        //
	    ACSR = 
	        (0 << ACD) |    // false:   [Not] Analog Comparator
	        (0 << ACBG) |   // false:   Analog Comparator Bandgap Select: AN0 is applied to the positive input
	        (0 << ACO) |    // false:    Analog Comparator Output Invert [OFF/ON]
	    #if defined( ADC_ANT_ISR_AV)
	        (1 << ACI) |    // true:    Analog Comparator Interrupt Flag: Clear Pending Interrupt by setting the bit
            (1 << ACIE) |   // true:    Analog Comparator Interrupt
        #else
	        (0 << ACI) |    // true:    Analog Comparator Interrupt Flag: Clear Pending Interrupt by setting the bit
            (0 << ACIE) |   // true:    Analog Comparator Interrupt
        #endif 
	        (0 << ACIC) |   // false:   Analog Comparator ext. Input Capture
	        (0 << ACIS1)| 
            (0 << ACIS0)|   // 1/1: Analog Comparator Interrupt Mode: 
                            //     Comparator ISR on
                            //     0/0 Output Toggle
                            //     1/1 Positiv Rising Edge
            0;
        // --> BG inner source
        if      (_ant->Mux>=ADC_MUX_INNER){
            //
            // use ADC[1] as ref => AN0 
	        ACSR |=(1 << ACBG);// true:   Analog Comparator Bandgap Select: AN0 is cut from the positive input
            ADMUX = _ant->Mux;// NC
        }
      
   #endif

    _f=true;
#elif defined(ESP8266_AV)

    _f=true;

#elif defined(RASP_AV)

    //
    _f=true;

#endif
    //
    if (_f){
        //
        ANTstate( _ant);
        ANTset( _ant);
    }
    //
    return _f;
}











/*!
 * adc* value handler
 *@param    _hanVx      .. read adc values( dif/abs aso)
 *@param    _hanAN      .. update values AN(release aso.)
 *@return   [double]    .. act. value V
 */
double  ADChandler( 
                     ADC_set_t*  _adc
                    ,bool       _hanVx
                    ,bool       _hanANT
                    ){
    //
    double  _V=-1;
    if (!_adc){ return _V;}
    //
            _V=_adc->V;
    double  _oV=_V;
    int     _v=_adc->v;
    //
    if ((_adc->has)
        &(_adc->Port>0)){
        //
        if (_hanVx){
            //
            if (_adc->rw){
                //
                _v=analogRead( _adc->Port);
            }
        }//Vx
        // 
        _V=_adc->Fx*_adc->Kx*_v;
        //
        _adc->v=_v;
        _adc->V=_V;
        _adc->dV=_V-_oV;
        //
    #if defined( ADC_ANT_AV)
        //
        if (_hanANT){
            //
            ANT_set_t* _ant=ANTptr(_adc->ANTix);
            //
            if (ANTsoft( _ant)){
                  //
                  Serial.println( "-> triggered!");
                  //
                  ANTset( _ant);
            }
            else if (ANTrelease( _ant)){
                  //
                  Serial.println( "-> release!");
                  //
                  ANTset( _ant);
            }
        }//AN
        //
    #endif

    }//has
    ;
    return _V;
}//refresh



#endif//ANT







/*!
 *  
 */
bool  ADC_setup(){
    //
    //
    
#if defined( ADC_ANT_AV)
    //
    _ANT_c->Adc=_ADC_Ux;
    _ANT_c->Ref=_ADC_Uref;
    //
    _ADC_Ux->ANTix=0;
    _ADC_Uref->ANTix=0;
    //
    _ANT_c->HX=-0.5;
    //

#endif

    return true;
}//








#endif//ADC
//@