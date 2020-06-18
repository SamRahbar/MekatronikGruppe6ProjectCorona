void StepperSetup() {
  // set the maximum speed, acceleration factor,
  myStepper.setMaxSpeed(3500);
  myStepper.setAcceleration(500);
  myStepper.setSpeed(1500);
  myStepper.moveTo(1300);
}
