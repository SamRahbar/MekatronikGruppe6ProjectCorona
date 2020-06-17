void Bloom(){
  //Serial.println("Blooming");
  fill_solid(leds,NUM_LEDS,CRGB(255,255,255));
  FastLED.show();
  delay(2000);
}

//This function is the startup function of the product. This will be the transition from resting to blossoming.
