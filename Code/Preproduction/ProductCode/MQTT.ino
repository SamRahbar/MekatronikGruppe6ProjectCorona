void MQTTSetup() {
  client.setServer(mqtt_server, mqtt_port); // Forbinder til mqtt serveren (defineret længere oppe)
  client.setCallback(callback); // Ingangsætter den definerede callback funktion hver gang der er en ny besked på den subscribede "cmd"- topic
}

void MQTTLoop() {
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
    }

    String data[2];
    bool curQot = false;
    int curDat = 0;
    for (int i = 0; i < payload.length(); i++) {
      //Checks if we are inside qotation marks
      if (payload[i] == '"'){
        if(curQot == false){
          curQot = true;
        }
        else{
          curQot = false;
          curDat++;
        }
      }
      //Fills out string with contents inside quotations
      if (curQot){
        data[curDat] = data[curDat] + payload[i];
      }
    }

    //Removes first quotation mark of each datapoint.
    data[0].remove(0,1);
    data[1].remove(0,1);

    Serial.println("Data array = " + data[0] + " : " + data[1]);
     
    //---- Color data converter----
    hex = "0x" + data[1]; //Converts incoming string to readable hex
    Serial.println("Hex = " + hex);
    color = strtol(hex.c_str(), NULL, 0); //Converts string to long

    
    // Depending on payload message, set at state for the OLED to display a specific message
    if (data[0] == "ONE") { // Collect fresh weather data every 5 minutes
      ledState = 1;
    }
    if (data[0] == "TWO") { // 3 hour forecast
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
