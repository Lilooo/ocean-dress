#include "FastLED.h"
//#include <avr/power.h>

const int NUM_LEDS_STRIPS = 10;
const int STRIPS_DATA = 9;
const int STRIP_DATA = A4;

CRGB led_strips[NUM_LEDS_STRIPS];
CRGB led_strip[NUM_LEDS_STRIPS];

void setup() {
  delay( 3000 ); // power-up safety delay
  // To make it work w/ an 8 Mhz proc (example : Lilypad Arduino)
 // clock_prescale_set(clock_div_2);
  FastLED.addLeds<NEOPIXEL, STRIPS_DATA>(led_strips, NUM_LEDS_STRIPS);
  FastLED.addLeds<NEOPIXEL, STRIP_DATA>(led_strip, NUM_LEDS_STRIPS);

}

void loop() {
  const int aqua = 100;
  const int blue = 160;
  const int wait = 100;

  color_fade(aqua, blue, wait);

}

//start HSV color, end HSV color, delay
void color_fade(uint16_t startColor, uint16_t endColor, uint8_t wait) {
  FastLED.clear();

  //loop around a color range from startColor to endColor
  for(int color = startColor; color < endColor; color++)
    push(color, wait);

  //loop around a color range from the end back to the start
  for(int color = endColor; color >startColor; color--)
    push(color, wait);
}

inline void push(int color, uint8_t wait) {
  for(int dot = 0; dot < NUM_LEDS_STRIPS; dot++)
    led_strips[dot].setHSV(color, 255, 127);
    FastLED.show();
  for(int dot = 0; dot < NUM_LEDS_STRIPS; dot++)
    led_strip[dot].setHSV(color, 255, 127);
    FastLED.show();
    FastLED.delay(wait);
}

