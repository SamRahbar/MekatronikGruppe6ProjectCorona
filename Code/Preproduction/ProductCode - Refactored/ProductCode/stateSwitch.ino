void flowerStateSwitch() {
  switch (flowerState) {
    case 0: // Resting
      Resting();
      Serial.println("Resting");
      break;
    case 1: // Bloom
      Bloom();
      Serial.println("Blooming");
      flowerState = 2;
      break;
    case 2: // Blossom
      Blossom();
      Serial.println("Blossoming");
      break;
    case 3: // Fade
      Fade();
      Serial.println("Fading");
      flowerState = 0;
      break;
  }
}
