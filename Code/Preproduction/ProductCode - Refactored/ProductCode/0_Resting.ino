void Resting(){
    //Serial.println("Resting");
    fill_solid(leds,NUM_LEDS,CRGB(0,0,0));
    FastLED.show();
}


//This function runs when the Product is resting, that means when it is inactive.
