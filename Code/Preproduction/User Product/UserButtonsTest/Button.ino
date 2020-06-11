
void buttonSetup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
}

void buttonController() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  if (buttonState1 == LOW) {
    var = 1;
  }
  if (buttonState2 == LOW) {
    var = 2;
  }
  if (buttonState3 == LOW) {
    var = 3;
  }
  if (buttonState4 == LOW) {
    var = 4;
  }

  if (var != lastVar) {
    switch (var) {
      case 1:
        client.publish("FromMCU", "ONE");
        lastVar = 1;
        break;
      case 2:
        client.publish("FromMCU", "TWO");
        lastVar = 2;
        break;
      case 3:
        client.publish("FromMCU", "THREE");
        lastVar = 3;
        break;
      case 4:
        client.publish("FromMCU", "FOUR");
        lastVar = 4;
        break;
    }
    Serial.println(lastVar);
  }
}
