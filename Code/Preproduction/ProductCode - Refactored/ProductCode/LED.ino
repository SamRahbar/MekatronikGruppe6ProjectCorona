void LEDloop() {

  fill_solid(leds, NUM_LEDS, CRGB(0x000000));

  switch (ledState) {
    case 0:
      break;
    case 1:
      leds[0] = CRGB(color);
      break;
    case 2:
      leds[1] = CRGB(color);
      break;
    case 3:
      leds[3] = CRGB(color);
      break;
    case 4:
      leds[4] = CRGB(color);
      break;
  }

  FastLED.show();
}
