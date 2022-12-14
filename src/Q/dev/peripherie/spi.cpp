/*! 
* Copyrights by @Edtronix-LABs 1992-2022
*
* @file       Q/spi.h
* @brief      spi drivers
* @date       2022-07-01
* @version    v1.00
*
*/

#include <Q/dev/peripherie/spi.h>


#if defined(SPI_AV)




#if defined(AVR_AV) //  AT NANO => AT328P!!
SPI_pin_t   SPI_pin0 ={
  #if defined(TFT_AV) & defined(TFT_GFX_AV)
                DF_GFX_BL//BL //D6
  #else
                6//D6
  #endif
                ,7//RST   //D7

                ,8//RS/DC //D8
                ,9//CS    //D9

                ,PIN_SPI_MISO//D11
                ,PIN_SPI_MOSI//D12

                ,PIN_SPI_SCK//D13
                ,PIN_SPI_SS//

              };
#elif defined(ESP8266_AV) // WEMOS D1 Lite => ESP8266 V1!

SPI_pin_t   SPI_pin0 ={
                -1//5//DF_GFX_BL D1
                
                ,D0//16  (0)//RST //DF_GFX_RST //D0

                ,D3//00  (16) //RS/DC D3
                ,D8//15//CS D8

                ,MISO//12   //MISO  //D7
                ,MOSI//13   //MOSI  //D6
                
                ,SCK//14    //SCK   //D5
                ,SS//15     //SS    //
              };

#elif defined(RASP_AV) // WEMOS D1 Lite => ESP8266 V1!

SPI_pin_t   SPI_pin0 ={
                21//GP21 //DF_GFX_BL 
                
                ,22//GP22 //RST //DF_GFX_RST

                ,20//GP20 //RS/DC
                ,17//GP17 //CS

                ,MISO//GP16   //MISO 
                ,MOSI//GP19   //MOSI 
                
                ,SCK//GP18    //SCK 
                ,-1//     //SS 
              };

#endif



/* Dynamische Definitions */





/* Routine Definitions */
bool SPI_setup(void){
  //
  SPI.begin();
  //
  OS_delay( 100);
  return true;
}









#endif//SPI
//@