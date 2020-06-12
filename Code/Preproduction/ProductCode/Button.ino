
void buttonSetup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void buttonController() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {
    var = 1;
  }
  if (buttonState2 == HIGH) {
    var = 2;
  }

  if (var != lastVar) {
    switch (var) {
      case 1:
        client.publish(sendingTopic, "ONE");
        lastVar = 1;
        break;
      case 2:
        client.publish(sendingTopic, "TWO");
        lastVar = 2;
        break;
    }
    Serial.println(lastVar);
  }
}
