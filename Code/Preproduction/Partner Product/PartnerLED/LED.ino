void LEDloop() {

  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));

  switch (state) {
    case 0:
      break;
    case 1:
      leds[0] = CRGB(99, 245, 66);
      break;
    case 2:
      leds[1] = CRGB(245, 120, 66);
      break;
    case 3:
      leds[3] = CRGB(245, 120, 66);
      break;
    case 4:
      leds[4] = CRGB(245, 120, 66);
      break;
  }

  FastLED.show();
}
