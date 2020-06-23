void HueFader(int t, int MinHue, int MaxHue) {
  if (ttime - lastHueTime > t) {
    FastLED.showColor(CHSV(CurHue, CurSat, CurVal));
    if (CurHue >= MaxHue) {
      HueFlip = true;
    }
    if (CurHue <= MinHue) {
      HueFlip = false ;
    }

    if (!HueFlip) {
      CurHue++;
    }
    else if (HueFlip) {
      CurHue--;
    }
    lastHueTime = ttime;
  }
}

void SatFader(int t, int MinSat, int MaxSat) {
  if (ttime - lastHueTime > t) {
    FastLED.showColor(CHSV(CurHue, CurSat, CurVal));
    if (CurSat >= MaxSat) {
      SatFlip = true;
    }
    if (CurSat <= MinSat) {
      SatFlip = false ;
    }

    if (!SatFlip) {
      CurSat++;
    }
    else if (SatFlip) {
      CurSat--;
    }
    lastSatTime = ttime;
  }
}

void ValFader(int t, int MinVal, int MaxVal) {
  if (ttime - lastHueTime > t) {
    FastLED.showColor(CHSV(CurHue, CurSat, CurVal));
    if (CurVal >= MaxVal) {
      ValFlip = true;
    }
    if (CurVal <= MinVal) {
      ValFlip = false ;
    }

    if (!ValFlip) {
      CurVal++;
    }
    else if (ValFlip) {
      CurVal--;
    }
    lastSatTime = ttime;
  }
}
