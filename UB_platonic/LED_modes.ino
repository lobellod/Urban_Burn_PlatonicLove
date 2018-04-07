void RGB_unsync(){
  static int g;
  static int h;
  EVERY_N_MILLISECONDS(2300){
    g++;
  }
  EVERY_N_MILLISECONDS(1150){
    h++;
  }
  fill_solid(leds_p,num_leds,RGB_array[g%3]);
  fill_solid(leds_p,num_leds,RGB_array[h%3]);
}

void unsyncFadeSinStick(int toggle){
  static int I = 0;
  EVERY_N_MILLISECONDS(5000){
    I++;
  }
  
  EVERY_N_MILLISECONDS(50){
  fadeToColor( &leds_1[0], RGB_arrayplus[I%6], 5, NUM_LEDS_1);
  fadeToColor( &leds_2[0], RGB_arrayplus[(I+1)%6], 5, NUM_LEDS_2);
  }
  EVERY_N_MILLISECONDS(70){
    if (toggle==0){
      sinelonStick(&leds_1[0], CRGB::White, NUM_STICKS_1);}
  else if(toggle==1){
      sinelonStick(&leds_2[0], CRGB::White, NUM_STICKS_2);
    }
    else if(toggle==2){
      sinelonStick(&leds_1[0], CRGB::White, NUM_STICKS_1);
      sinelonStick(&leds_2[0], CRGB::White, NUM_STICKS_2);
    }
  }
}

void twoColorChase(){
  static uint8_t Index = 0;
  EVERY_N_MILLISECONDS(70){
  Index += beatsin8(3, 1, 3);
  } 
  FillLEDsFromPaletteColors(&leds_1[0], NUM_LEDS_1, Index);
  FillLEDsFromPaletteColors(&leds_2[0], NUM_LEDS_2, Index);
}

void fullFadeChase(){
  static int next = 0;
  static int toggleSwitch = 1;
  static CRGB fadeToThis = CHSV(255,255,255);
  EVERY_N_MILLISECONDS(5000){
    if(toggleSwitch==0){
        next = (next+1)%2;
    } 
    if (toggleSwitch==1){ 
        fadeToThis = CHSV(random(256),255,255);
    }
    toggleSwitch = (toggleSwitch+1)%2;
  }
  
  EVERY_N_MILLISECONDS(50){
  if (next==0){
     fadeToColor(&leds_1[0], fadeToThis, 2, NUM_LEDS_1);
  }
  else if (next==1){
      fadeToColor(&leds_2[0], fadeToThis, 2, NUM_LEDS_2);
  }
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

*/
