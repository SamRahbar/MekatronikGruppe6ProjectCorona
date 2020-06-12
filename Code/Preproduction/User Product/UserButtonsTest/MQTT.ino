void MQTTSetup(){
  client.setServer(mqtt_server, mqtt_port); // Forbinder til mqtt serveren (defineret længere oppe)
  client.setCallback(callback); // Ingangsætter den definerede callback funktion hver gang der er en ny besked på den subscribede "cmd"- topic
}

void MQTTLoop(){
  // Hvis der opstår problemer med forbindelsen til mqtt broker oprettes forbindelse igen ved at køre client loop
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}



// Definerer callback funktionen der modtager beskeder fra mqtt
// OBS: den her funktion kører hver gang MCU'en modtager en besked via mqtt
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length) {

  // Konverterer indkomne besked (topic) til en string:
  String topic;
  topic = String(byteArraytopic);
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("] ");
  // Konverterer den indkomne besked (payload) fra en array til en string:
  // Topic == Temperaturmaaler, Topic == Kraftsensor
  if (topic == recievingTopic) { // OBS: der subscribes til et topic nede i reconnect-funktionen. I det her tilfælde er der subscribed til "LOCK". Man kan subscribe til alle topics ved at bruge "#"
    payload = ""; // Nulstil payload variablen så forloopet ikke appender til en allerede eksisterende payload
    for (int i = 0; i < length; i++) {
      payload += (char)byteArrayPayload[i];
      // For-loop: tag hvert tegn i hele længden af den inkomne besked, og konverter denne til en char. Append tegnene 1 efter 1:
      // Eksempel:
      // Besked = Study Abroad
      // Length = 12
      // Loop 1 = "S"
      // Loop 2 = "St" osv.
      // Loop (length) = "Study Abroad"
    }


    // Depending on payload message, set at state for the OLED to display a specific message
    if (payload == "ONE") { // Collect fresh weather data every 5 minutes
      ledState = 1;
    }
    if (payload == "TWO") { // 3 hour forecast
      ledState = 2;
    }
    if (payload == "THREE") { // 6 hour forecast
      ledState = 3;
    }
    if (payload == "FOUR") { // 9 hour forecast
      ledState = 4;
    }
    else { // If the signal from the mqtt is not one of the available options, give a message to the mqtt server and pass
      Serial.println(payload);
      client.publish("Status", "Unknown message");
      delay(100);
    }
  }
}
