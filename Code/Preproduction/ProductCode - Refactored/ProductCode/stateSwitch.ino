void flowerStateSwitch() {
  switch (flowerState) {
    case 0: // Resting
      Resting();
      break;
    case 1: // Bloom
      Bloom();
      flowerState = 2;
      break;
    case 2: // Blossom
      Blossom();
      break;
    case 3: // Fade
      Fade();
      flowerState = 0;
      break;
  }
}
