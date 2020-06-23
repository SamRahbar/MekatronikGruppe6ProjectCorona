#include <FastLED.h>
//-----LED DEFINITIONS----
#define NUM_LEDS 9
#define DATA_PIN 4

//-----TIME DEFINITIONS----
long ttime;
long lastHueTime = 0;
long lastSatTime = 0;
long lastValTime = 0;

static uint8_t CurHue = 255 ;
static uint8_t CurSat = 255;
static uint8_t CurVal = 255;
bool HueFlip = false;
bool SatFlip = false;
bool ValFlip = false;

bool FadeUpRunning = false;
bool FadeDownRunning = false;

//----INSTANTIATE OBJECTS----
CRGB leds[NUM_LEDS];// Define the array of

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  ttime = millis();
  HueFader(50, 255,230);
  SatFader(50, 255,0);
  ValFader(50, 255,0);
}
