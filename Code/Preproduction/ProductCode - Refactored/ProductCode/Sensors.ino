void SensorSetup() {
  pinMode(SensorPin, INPUT);
    attachInterrupt(SensorPin, SensorModeChange, CHANGE);
}

void SensorModeChange(){
  client.publish(sendingTopic, "Bloom");
}
