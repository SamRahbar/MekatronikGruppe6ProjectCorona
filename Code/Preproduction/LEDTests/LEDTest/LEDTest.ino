#include <FastLED.h>
//-----LED DEFINITIONS----
#define NUM_LEDS 9
#define DATA_PIN 4

//-----MICROSWITCHES------
#define Switch1 D7
#define Switch2 D8
void ICACHE_RAM_ATTR MicroSwitchStates1();
void ICACHE_RAM_ATTR MicroSwitchStates2();

volatile int StatePick = 0;

void MicroSwitchSetup() {
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  attachInterrupt(Switch1, MicroSwitchStates1, CHANGE);
  attachInterrupt(Switch2, MicroSwitchStates2, CHANGE);
}

void MicroSwitchStates1() {
  StatePick = 4;
  //  if (StatePick >= 0) {
  //    if (StatePick <= 1) {
  //      StatePick ++;
  //    }
  //  }
}

void MicroSwitchStates2() {
  StatePick = 0;
}

//----INSTANTIATE OBJECTS----
CRGB leds[NUM_LEDS];// Define the array of

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  MicroSwitchSetup();
}

void loop() {
  switchState();
  //Serial.println("StatePick = " + StatePick);
}

void switchState() {
  switch (StatePick) {
    case 0: //Off
      fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
      FastLED.show();
      break;
    case 1: //FadingDown
      Serial.println("FadingDown");
      fadeDown(10);
      StatePick = 0;
      break;
    case 2: //FadingUp
      Serial.println("FadingUp");
      fadeUp(10);
      StatePick = 0;
      break;
    case 3: //FadinUpAndDown
      Serial.println("FadingUpThenDown");
      fadeUp(10);
      fadeDown(10);
      StatePick = 0;
      break;
    case 4:
      breathe();
      break;
  }
}

void fadeDown(int LightSpeed) {
  fill_solid(leds, NUM_LEDS, CRGB(255, 0, 0));
  FastLED.setBrightness(255);
  for (int i = 255; i > 1; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(LightSpeed);
  }
}

void fadeUp(int LightSpeed) {
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 255));
  FastLED.setBrightness(0);
  for (int i = 0; i <= 255; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(LightSpeed);
  }
}

void breathe(){
  fadeUp(0);
  fadeDown(0);
}
