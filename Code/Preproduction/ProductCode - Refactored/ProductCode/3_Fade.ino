void Fade() {
  //Serial.println("Fading");

  switch (MotorState) {
    case 0: // Motor
      if (startMotor == true) {
        myStepper.runSpeed();
        Serial.println("StepperRunning : " + StepSpeed);
      }

      if (SwitchLim2 == HIGH) {
        myStepper.stop();
        startMotor = false;
        MotorState = 1;
        //SwitchLim2 = HIGH;
        Serial.println("Stepper Stopped");
        Serial.println("FadeDown Begun");
      }
      break;
    case 1: // LED
      if (!FadeDownRunning) {
        fill_solid(leds, NUM_LEDS, CHSV(MaxHue, MaxSat, CurVal));
        FastLED.setBrightness(CurVal);
        Serial.println("LED FADEDOWN STARTDEFINITIONS");
        FadeDownRunning = true;
      }
      else if (CurVal > 0) {
        if (ttime - lastValTime > ValT) {
          Serial.println(String("HSV: ") + CurHue + " : " + CurSat + " : " + CurVal);
          FastLED.setBrightness(CurVal);
          FastLED.show();
          CurVal--;
          lastValTime = ttime;
        }
      }
      else {
        Serial.println("FadeDownStopped");
        if (startMotor == false) {
          MotorState = 0;
          FadeDownRunning = false;
          flowerState = 0;
        }
      }
      break;
  }
}
//This function is the shutoff command. It will be the transition from Blossom to Resting.
