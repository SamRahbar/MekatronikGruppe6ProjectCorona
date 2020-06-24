void Fade() {
  //Serial.println("Fading");

  Serial.print("StepperRunning : ");
  Serial.println(myStepper.distanceToGo());
  if (myStepper.distanceToGo() == -10) {
    Serial.println("StepperTopped");
    //myStepper.stop();
    startMotor = false;
    FadeDown = true;
  }

  if (FadeDown) {
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
        FadeDown = false;
        startMotor = false;
        flowerState = 0;
      }
    }
  }
  myStepper.run();


  //  switch (MotorState) {
  //    case 0: //Motor StartMove
  //      if (SwitchLim1 == HIGH) {
  //        Serial.println("MotorMoveOffSwitch");
  //        myStepper.runSpeed();
  //      }
  //      else {
  //        MotorState = 1;
  //        Serial.println("Stepper Off of switch");
  //      }
  //      break;
  //    case 1: // Motor
  //if (SwitchLim1 == HIGH) {
  //        myStepper.stop();
  //        MotorState = 2;
  //        //SwitchLim1 = HIGH;
  //        Serial.println("Stepper Stopped");
  //        Serial.println("FadeUp Begun");
  //      }
  //      else {
  //        myStepper.runSpeed();
  //        Serial.println("StepperRunning");
  //      }
  //      break;
  //    case 2: // LED
  //      if (!FadeDownRunning) {
  //        fill_solid(leds, NUM_LEDS, CHSV(MaxHue, MaxSat, CurVal));
  //        FastLED.setBrightness(CurVal);
  //        Serial.println("LED FADEDOWN STARTDEFINITIONS");
  //        FadeDownRunning = true;
  //      }
  //      else if (CurVal > 0) {
  //        if (ttime - lastValTime > ValT) {
  //          Serial.println(String("HSV: ") + CurHue + " : " + CurSat + " : " + CurVal);
  //          FastLED.setBrightness(CurVal);
  //          FastLED.show();
  //          CurVal--;
  //          lastValTime = ttime;
  //        }
  //      }
  //      else {
  //        Serial.println("FadeDownStopped");
  //        if (startMotor == false) {
  //          MotorState = 0;
  //          FadeDownRunning = false;
  //          flowerState = 0;
  //        }
  //      }
  //      break;
  //  }
}
//This function is the shutoff command. It will be the transition from Blossom to Resting.
