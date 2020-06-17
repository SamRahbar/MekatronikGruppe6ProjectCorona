void SensorSetup() {
  pinMode(SensorPin, INPUT);
  //attachInterrupt(D1, SensorModeChange, CHANGE);
}


void SensorController() {
  SensorState1 = digitalRead(SensorPin);

  if (SensorState1 == HIGH) {
    var = 1;
  }
  else if (SensorState1 == LOW) {
    var = 2;
  }

  if (var != lastVar) {
    switch (var) {
      case 1:
        client.publish(sendingTopic, "Bloom");//Sends if motion has stopped being sensed
        lastVar = 1;
        break;
      case 2:
        client.publish(sendingTopic, "Bloom");//Sends if motion has been sensed
        lastVar = 2;
        break;
    }
    Serial.println(lastVar);
  }
}
