void Bloom() {
  //Serial.println("Blooming");

  switch (MotorState) {
    case 0: // Motor
      if (startMotor == true) {
        myStepper.runSpeed();
        Serial.println("StepperRunning : " + StepSpeed);
      }
      
      if (SwitchLim1 == HIGH) {
        myStepper.stop();
        startMotor = false;
        MotorState = 1;
        //SwitchLim1 = HIGH;
        Serial.println("Stepper Stopped");
        Serial.println("FadeUp Begun");
      }
      break;
    case 1: // LED
      if (!FadeUpRunning) {
        fill_solid(leds, NUM_LEDS, CHSV(MaxHue, MaxSat, MaxVal));
        CurHue = MinHue; CurSat = MaxSat; CurVal = 0;
        FastLED.setBrightness(CurVal);
        Serial.println("LED FADEUP STARTDEFINITIONS");
        FadeUpRunning = true;
      }
      else if (CurVal < MaxVal) {
        if (ttime - lastValTime > ValT) {
          Serial.println(String("HSV: ") + CurHue + " : " + CurSat + " : " + CurVal);
          FastLED.setBrightness(CurVal);
          FastLED.show();
          CurVal++;
          lastValTime = ttime;
        }
      }
      else {
        Serial.println("FadeUpStopped");
        if (startMotor == false) {
          Serial.println("Flowerstate 2");
          MotorState = 0;
          FadeUpRunning = false;
          flowerState = 2;
        }
      }
      //Serial.println("Blooming");
      break;
  }
}
//This function is the startup function of the product. This will be the transition from resting to blossoming.
