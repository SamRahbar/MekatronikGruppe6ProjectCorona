
void buttonSetup() {
  pinMode(Sensor, INPUT);
}

void buttonController() {

  SensorState1 = digitalRead(Sensor);

  if (SensorState1 == HIGH) {
    var = 1;
  }
  else if (SensorState1 == LOW) {
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
