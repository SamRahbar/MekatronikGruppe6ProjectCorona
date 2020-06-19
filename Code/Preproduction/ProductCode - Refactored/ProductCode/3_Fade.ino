void Fade() {
  Serial.println("Fading");
  fill_solid(leds, NUM_LEDS, CRGB(100, 100, 100));
  FastLED.show();

  myStepper.move(-StepDistance);
  while (myStepper.distanceToGo() < 0) {
    if (SwitchLim1 == HIGH || SwitchLim2 == HIGH) {
      myStepper.stop();
      break;
    }
    myStepper.run();
  }
}

//This function is the shutoff command. It will be the transition from Blossom to Resting.
