#include <FastLED.h>

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

#define LED_PIN1     3
#define LED_PIN2     4
#define NUM_STICKS_1    30
#define NUM_STICKS_2    12
#define NUM_LEDS      30
#define NUM_LEDS_1   NUM_STICKS_1*NUM_LEDS
#define NUM_LEDS_2   NUM_STICKS_2*NUM_LEDS
#define BRIGHTNESS  200
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define UPDATES_PER_SECOND  100

CRGB leds_1[NUM_LEDS_1];
CRGB leds_2[NUM_LEDS_2];
//CRGB *leds_p = &leds;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;


uint8_t startIndex = 0;
uint8_t hue = 0;
int toggle = 0;
uint16_t tdelay = 50;

unsigned long pre_time = 0;
unsigned long execution_time = 0;

//-----------Color Arrays----------------------
CRGB mixed_colors[6] = {CRGB::HotPink, CRGB::Indigo, CRGB::LimeGreen, CRGB::Navy, CRGB::OrangeRed, CRGB::Purple};
CRGB RGB_array[3] = {CRGB::Red, CRGB::Green, CRGB::Blue};
CRGB RGB_arrayplus[6] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::DarkOliveGreen, CRGB::DarkMagenta, CRGB::Fuchsia};
//-----------------------------------------

CRGB target_color = CRGB::HotPink;
CRGB target_color2 = CRGB::Blue;
CRGB target_color3 = CRGB::Red;

void setup() {
  delay(1000);
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds_1, NUM_LEDS_1).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds_2, NUM_LEDS_2).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentBlending = LINEARBLEND;

  fill_solid( leds_1, NUM_LEDS_1, CRGB::Red);
  fill_solid( leds_2, NUM_LEDS_2, CRGB::Green);
  FastLED.show();
  delay(3000);



}

void loop() {
  // put your main code here, to run repeatedly:
  EVERY_N_MILLISECONDS(100) {
    startIndex = startIndex + 1;
    hue = hue + 1;
  }
  EVERY_N_MILLISECONDS(20000){
    toggle = random(4);
  }

  unsyncFadeSinStick(toggle);
  //RGB_unsync();
  //topBottomFadewSinelonwGlitter(NUM_LEDS_1, NUM_LEDS_2);
/*  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_array[J%3];
    target_color2 = RGB_array[(J+1)%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    I++;
  }
  
  EVERY_N_MILLISECONDS(tdelay) {
    pre_time = micros();

    //RGB_blink(&leds[0]);
    //cycleColorArray(&leds[0], &RGB_array[0], ARRAY_SIZE(RGB_array));
    fadeToColor_interval(&leds[0], target_color, 5,0,55);
    fadeToColor_interval(&leds[0], target_color2, 5,56,109);
    fadeToColor_interval(&leds[0], target_color, 5,110,144);
    execution_time = micros() - pre_time;
    Serial.print("Execution time:         ");
    Serial.println(execution_time);
  }*/

  //twoColorTrace(startIndex,hue);
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}
