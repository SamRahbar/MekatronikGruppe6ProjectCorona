void StepperSetup() {
  // set the maximum speed, acceleration factor,
  myStepper.setMaxSpeed(StepMaxSpeed);
  //myStepper.setAcceleration(StepAccel);
  myStepper.setSpeed(500);
  //myStepper.moveTo(1000);
}
