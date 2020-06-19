void Bloom() {
  Serial.println("Blooming");
  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();

  myStepper.move(StepDistance);
  while (myStepper.distanceToGo() > 0) {
    if (SwitchLim1 == HIGH || SwitchLim2 == HIGH) {
      myStepper.stop();
      break;
    }
    myStepper.run();
  }
}

//This function is the startup function of the product. This will be the transition from resting to blossoming.
