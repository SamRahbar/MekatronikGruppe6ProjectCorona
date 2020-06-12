void stateSwitch() {

  switch (flowerState) {
    case 0: // resting
      resting();
      break;
    case 1: // wake up
      wakeup();
      flowerState = 2;
      break;
    case 2: // blossom
      blossom();
      break;
    case 3: // fade
      fade();
      flowerState = 0;
      break;
  }
}
