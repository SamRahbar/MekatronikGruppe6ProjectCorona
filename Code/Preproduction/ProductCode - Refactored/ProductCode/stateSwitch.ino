void flowerStateSwitch() {
  switch (flowerState) {
    case 0: // Resting
      Resting();
      //Serial.println("Resting");
      break;
    case 1: // Bloom
      Bloom();
      //Serial.println("Blooming");
      break;
    case 2: // Blossom
      Blossom();
      //Serial.println("Blossoming");
      break;
    case 3: // Fade
      Fade();
      //Serial.println("Fading");
      break;
  }
}
