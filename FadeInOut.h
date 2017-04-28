/* FadeInOut.h */

#include <FastLED.h>

typedef enum
 {
 LED_ConfigColor,
 LED_ConfigFade,
 LED_ConfigHalfOn,
 LED_ConfigTrace,
 LED_ConfigSz
 } LED_Config;

typedef enum
{
  InputChan0,
  InputChan1,
  InputChan2,
  InputChanSz
} InputChan;

typedef enum
{
  LED_Color_Red,
  LED_Color_Blue,
  LED_Color_Green,
  LED_Color_White,
  LED_Color_Purple,
  LED_Color_Yellow,
  LED_Color_Pink,
  LED_Color_Orange,
  LED_Color_Rainbow, // This is meant to indicate when a random mixture of colors are desired
  LED_Color_Multi,   // This is meant to indicate when it is desired to have the colors cycle through all of the avaiable colors above rainbow
  LED_Color_Black    // This is more of an "off mode", must remain at end of enum
} LED_Color;

typedef enum
 {
 LED_Mode0,
 LED_Mode1,
 LED_Mode2,
 LED_Mode3,
 LED_Mode4,
 LED_Mode5,
 LED_Mode6,
 LED_Mode7,
 LED_ModeSz
 } LED_Mode;
 
const int   C_LED_PIN =           13;      // This is data pin that is being used on the Arduino
#define     C_COLOR_ORDER         GBR      // This is color order in the LED strip RBG - radioshack
#define     C_CHIPSET             WS2812   // This is chipset in the led light strip TM1803 for Radioshack strip WS2812
const int   C_NUM_LEDS =          120;     // This is the number of LEDs in the light strip
const int   C_Chan0 =             5;       // This is channel 0 input, pin on the Arduino
const int   C_Chan1 =             6;       // This is channel 1 input, pin on the Arduino
const int   C_Chan2 =             7;       // This is channel 2 input, pin on the Arduino

const bool C_InputConfig[LED_ModeSz][InputChanSz] = 
  {
  /* InputChan0 InputChan1 InputChan2 */
   { false,     false,     false }, /* Mode0 */
   { false,     false,     true  }, /* Mode1 */
   { false,     true,      false }, /* Mode2 */
   { false,     true,      true  }, /* Mode3 */
   { true,      false,     false }, /* Mode4 */
   { true,      false,     true  }, /* Mode5 */
   { true,      true,      false }, /* Mode6 */
   { true,      true,      true  }  /* Mode7 */
  };

const float K_DelayBetweenUpdate = 5;       // This is the delay between brightness updates, in milliseconds
const int   K_LED_MaxBrightness =  255;     // This is the highest brightness of the leds, should not be higher than 255
const int   K_LED_MinBrightness =  1;       // This is the lowest brightness of the leds, should not be less than 0
const float K_Debounce =           50;      // This is the amount of time the input signal has to be high in order to determine that the input actually changed (milliseconds)
const int   K_PulseCounts =        1;       // This is the number of pulse counts befoe switching to the next color (really only useful for multi color mode...)
const float K_ShiftTime[LED_ModeSz] =       // This is the delay between color shifts for the trace mode (milliseconds)
  {
  25, /* Mode0 */
  15, /* Mode1 */
  25, /* Mode2 */
  15, /* Mode3 */
  15, /* Mode4 */
  15, /* Mode5 */
  25, /* Mode6 */
  15  /* Mode7 */
  };
  
const int   K_LightSpacing[LED_ModeSz] =    // This is the spacing between lights in the half on mode
  {
  3, /* Mode0 */
  6, /* Mode1 */
  3, /* Mode2 */
  3, /* Mode3 */
  10, /* Mode4 */
  3, /* Mode5 */
  3, /* Mode6 */
  3  /* Mode7 */
  };

const int K_LightSettings[LED_ModeSz][LED_ConfigSz] =
  {
  /* Color                   Fade   HalfOn   Trace */
   { int(LED_Color_Orange),   1,     0,       0 }, /* Mode0 - This should remain the default/off condition */
   { int(LED_Color_Green),     0,     1,       1 }, /* Mode1 */
   { int(LED_Color_Blue),   1,     0,       0 }, /* Mode2 */
   { int(LED_Color_Blue),    0,     1,       1 }, /* Mode3 */
   { int(LED_Color_Red),  1,     0,       0 }, /* Mode4 */
   { int(LED_Color_Red),  0,     1,       1 }, /* Mode5 */
   { int(LED_Color_White), 0,     0,       0 }, /* Mode6 */
   { int(LED_Color_Rainbow),   0,     0,       1 }  /* Mode7 */
  };
