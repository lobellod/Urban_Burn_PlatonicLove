void RGB_unsync(){
  EVERY_N_MILLISECONDS(1100){
    RGB_blink(&leds_1[0], NUM_LEDS_1);
  }
  EVERY_N_MILLISECONDS(1750){
    RGB_blink(&leds_2[0], NUM_LEDS_2);
  }
}
/*
//Program som fadear mellan RGB osynkat över hatten/stjälken
void topBottomFade(){
  static int J = 0;
  static int I = 0;
  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_array[J%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    I++;
  }
  
  EVERY_N_MILLISECONDS(50) {
    fadeToColor_interval(&leds[0], target_color, 5,0,55);
    fadeToColor_interval(&leds[0], target_color2, 8,55,109);
    fadeToColor_interval(&leds[0], target_color, 5,109,144);

  }
}

void topBottomFadewGlitter(int top_start, int top_end){
  static int J = 0;
  static int I = 0;
  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_array[J%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    I++;
  }
  
  EVERY_N_MILLISECONDS(50) {
    fadeToColor_interval(&leds[0], target_color, 5,0,top_start);
    fadeToColor_interval(&leds[0], target_color2, 8, top_start, top_end);
    fadeToColor_interval(&leds[0], target_color, 5,top_end,NUM_LEDS);

  }
   EVERY_N_MILLISECONDS(40) {
    addGlitter(200, top_start, top_end);
  }
}


void topBottomFadewConfetti(int top_start, int top_end){
  static int J = 0;
  static int I = 0;
  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_array[J%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    I++;
  }
  
  EVERY_N_MILLISECONDS(50) {
    fadeToColor_interval(&leds[0], target_color, 5,0,top_start);
    fadeToColor_interval(&leds[0], target_color2, 8, top_start, top_end);
    fadeToColor_interval(&leds[0], target_color, 5,top_end,NUM_LEDS);

  }
   EVERY_N_MILLISECONDS(40) {
    confetti(top_start, top_end);
  }
}


void topBottomFadewSinelon(int top_start, int top_end){
  static int J = 0;
  static int I = 0;
  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_arrayplus[J%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    target_color3 = RGB_array[(I+1)%3];
    I++;
  }
  
  
  EVERY_N_MILLISECONDS(50) {
    fadeToColor_interval(&leds[0], target_color, 5,0,top_start);
    fadeToColor_interval(&leds[0], target_color2, 8, top_start, top_end);
    fadeToColor_interval(&leds[0], target_color, 5,top_end,NUM_LEDS);

  }
   EVERY_N_MILLISECONDS(40) {
    sinelon(target_color3, top_start, top_end);
  }
}


void topBottomFadewSinelonwGlitter(int top_start, int top_end){
  static int J = 0;
  static int I = 0;
  EVERY_N_MILLISECONDS(5507){
    target_color = RGB_arrayplus[J%3];
    J++;
  }
  EVERY_N_MILLISECONDS(4370){
    target_color2 = RGB_array[I%3];
    target_color3 = RGB_array[(I+1)%3];
    I++;
  }
  
  
  EVERY_N_MILLISECONDS(50) {
    fadeToColor_interval(&leds[0], target_color, 5,0,top_start);
    fadeToColor_interval(&leds[0], target_color2, 8, top_start, top_end);
    fadeToColor_interval(&leds[0], target_color, 5,top_end,NUM_LEDS);

  }
   EVERY_N_MILLISECONDS(60) {
    sinelon(target_color3, top_start, top_end);
  }
  EVERY_N_MILLISECONDS(40) {
    addGlitter(150, top_start, top_end);
  }
}*/
