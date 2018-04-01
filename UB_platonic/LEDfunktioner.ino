/*//Tar "startindex" och ljusstyrka och uppdaterar slingan
void FillLEDsFromPaletteColors( uint8_t colorIndex, uint8_t brightness)
{    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

//Skapar en palett med två olika färger, tar "Hue" från gyrot och skapar de två färgerna med en offset på 128
void ReturnNewPalette(uint8_t Hue){
    uint8_t  Hue1 = Hue;
    uint8_t  Hue2 = Hue + 128;
    CRGB color1 = CHSV( Hue1, 255, 255);
    CRGB color2  = CHSV( Hue2, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   color1,   color1,  color2, color2,
                                   color1, color1, color2,  color2,
                                   color1,  color1,  color2,  color2,
                                   color1, color1, color2,  color2 );
}






void twoColorTrace(uint8_t startIndex, uint8_t hue){
    ReturnNewPalette(hue);
    uint8_t brightness = 255;
    FillLEDsFromPaletteColors(startIndex, brightness);
}*/



void RGB_blink(CRGB *leds_p, int num_leds){
  static int i;
  fill_solid(leds_p,num_leds,RGB_array[i%3]);
  i++;
  }


void cycleColorArray(CRGB *leds_p, CRGB *color_Array, int arrayLength, int num_leds){
  static int i;
  fill_solid(leds_p,num_leds,color_Array[i%arrayLength]);
  i++;
}


void fadeToColor( CRGB *leds_p, CRGB fadeIntoRGB, uint8_t fadeVal, int num_leds){
  for(int i;i<num_leds;i++){
    if(leds_p[i].r<fadeIntoRGB.r){
      leds_p[i] += CRGB( fadeVal, 0 ,0);
      leds_p[i] &= CRGB( fadeIntoRGB.r, 255, 255);
    }
    else if(leds_p[i].r>fadeIntoRGB.r){
      leds_p[i] -= CRGB( fadeVal, 0, 0);
      leds_p[i] |= CRGB( fadeIntoRGB.r, 0, 0);
    }
    if(leds_p[i].g<fadeIntoRGB.g){
      leds_p[i] += CRGB( 0, fadeVal, 0);
      leds_p[i] &= CRGB (255, fadeIntoRGB.g, 255);
    }
    else if(leds_p[i].g>fadeIntoRGB.g){
      leds_p[i] -= CRGB( 0, fadeVal, 0);
      leds_p[i] |= CRGB( 0, fadeIntoRGB.g, 0);
    }
    if(leds_p[i].b<fadeIntoRGB.b){
      leds_p[i] += CRGB( 0, 0, fadeVal);
      leds_p[i] &= CRGB( 255, 255, fadeIntoRGB.b);
    }
    else if(leds_p[i].b>fadeIntoRGB.b){
      leds_p[i] -= CRGB( 0, 0, fadeVal);
      leds_p[i] |= CRGB( 0, 0, fadeIntoRGB.b);
    }
  }  
}

void fadeToColor_interval( CRGB *leds_p, CRGB fadeIntoRGB, uint8_t fadeVal, int start_LED, int end_LED){
  for(int i=start_LED;i<end_LED;i++){
    if(leds_p[i].r<fadeIntoRGB.r){
      leds_p[i] += CRGB( fadeVal, 0 ,0);
      leds_p[i] &= CRGB( fadeIntoRGB.r, 255, 255);
    }
    else if(leds_p[i].r>fadeIntoRGB.r){
      leds_p[i] -= CRGB( fadeVal, 0, 0);
      leds_p[i] |= CRGB( fadeIntoRGB.r, 0, 0);
    }
    if(leds_p[i].g<fadeIntoRGB.g){
      leds_p[i] += CRGB( 0, fadeVal, 0);
      leds_p[i] &= CRGB (255, fadeIntoRGB.g, 255);
    }
    else if(leds_p[i].g>fadeIntoRGB.g){
      leds_p[i] -= CRGB( 0, fadeVal, 0);
      leds_p[i] |= CRGB( 0, fadeIntoRGB.g, 0);
    }
    if(leds_p[i].b<fadeIntoRGB.b){
      leds_p[i] += CRGB( 0, 0, fadeVal);
      leds_p[i] &= CRGB( 255, 255, fadeIntoRGB.b);
    }
    else if(leds_p[i].b>fadeIntoRGB.b){
      leds_p[i] -= CRGB( 0, 0, fadeVal);
      leds_p[i] |= CRGB( 0, 0, fadeIntoRGB.b);
    }
  }  
}

void addGlitter(CRGB *leds_p, fract8 chanceOfGlitter, int mins, int maxs) 
{
  if( random8() < chanceOfGlitter) {
    leds_p[ random(mins,maxs) ] += CRGB::White;
  }
}

void confetti(CRGB *leds_p, int mins, int maxs) 
{
  int pos = random(mins, maxs);
  leds_p[pos] += CHSV( hue + random8(64), 200, 255);
}

void sinelon(CRGB *leds_p, CRGB targetColor, int mins, int maxs)
{
  int pos = beatsin16(13,mins,maxs);
  leds_p[pos] = targetColor;
}
