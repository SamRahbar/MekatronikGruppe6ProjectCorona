void MicroSwitchSetup() {
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  attachInterrupt(Switch1, MicroSwitchStates, CHANGE);
  attachInterrupt(Switch2, MicroSwitchStates, CHANGE);
}

void MicroSwitchStates() {
  SwitchLim1 = digitalRead(Switch1);
  SwitchLim2 = digitalRead(Switch2);
}
