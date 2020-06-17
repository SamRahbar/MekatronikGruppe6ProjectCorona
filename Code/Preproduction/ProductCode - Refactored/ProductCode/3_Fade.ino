void Fade(){
  //Serial.println("Fading");
  fill_solid(leds,NUM_LEDS,CRGB(100,100,100));
  FastLED.show();
  delay(1000);
}

//This function is the shutoff command. It will be the transition from Blossom to Resting.
