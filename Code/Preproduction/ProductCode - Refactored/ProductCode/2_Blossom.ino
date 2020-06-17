void Blossom(){
  //Serial.println("Blossoming");
  fill_solid(leds,NUM_LEDS,CRGB(color));
  FastLED.show();
}

//This function is the products idle on state. It will continuously run until nodered sends an inactivity message.
