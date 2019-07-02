#include "FastLED.h"

#define NUM_LEDS 28 
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup() 
{
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW);
  Serial.println("Initialized");
}

int data = 5;

void loop() 
{
  while (Serial.available())
  {
  data = Serial.read();
  }
  if (data == '1')
  {
    for(int i=0; i<NUM_LEDS; i++)
    {
        leds[i] = CHSV(160, 255, 128);
        leds[i+1] = CHSV(160, 255, 128);
        FastLED.show();
        delay(50);
        leds[i] = CHSV(0,0,0);
        FastLED.show();
    }
    digitalWrite (LED_BUILTIN, HIGH);
  }
  else if (data == '0')
  {
    for(int i=NUM_LEDS; i>=0; i--)
    {
        leds[i] = CHSV(160, 255, 128);
        leds[i-1] = CHSV(160, 255, 128);
        FastLED.show();
        delay(50);
        leds[i] = CHSV(0,0,0);
        FastLED.show();
    }
    digitalWrite (LED_BUILTIN, LOW);
  }
  else if (data == '5')
  {
    for(int i=0; i<NUM_LEDS; i++)
    {
        leds[i] = CHSV(160, 255, 128);
        leds[i+1] = CHSV(160, 255, 128);
        FastLED.show();
        delay(50);
    }
    digitalWrite (LED_BUILTIN, HIGH);
  }
}
