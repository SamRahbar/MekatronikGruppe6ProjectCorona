void MQTTParser() {

  //-----STRING ARRAY PARSER-----
  String data[3];//Defines array of information expected
  bool curQot = false;//Bool to detect if we are inside quotation marks
  int curDat = 0;//Int to keep track of current data index
  for (int i = 0; i < payload.length(); i++) { //Splits up the string array we receive from NodeRed into a stringarray we can use in arduino
    //Checks if we are inside qotation marks
    if (payload[i] == '"') {
      if (curQot == false) {
        curQot = true;
      }
      else {
        curQot = false;
        curDat++;
      }
    }
    //Fills out string with contents inside quotations
    if (curQot) {
      data[curDat] = data[curDat] + payload[i];
    }
  }

  //Removes first quotation mark of each datapoint since they are included during the processing step.
  data[0].remove(0, 1);
  data[1].remove(0, 1);
  data[2].remove(0, 1);

  Serial.println("Data array = " + data[0] + " : " + data[1]);

  //---- COLOR DATA CONVERTER----
  hex = "0x" + data[1]; //Converts incoming string to readable hex
  Serial.println("Hex = " + hex);
  color = strtol(hex.c_str(), NULL, 0); //Converts string to long

  //----STEPPER ACCEL DEFINE-----
  myStepper.setSpeed(data[2].toInt());
  Serial.println("Stepper Acceleration = " + StepSpeed);
  
  if (data[0] == "Bloom") {
    flowerState = 1;
  }
  else if (data[0] == "Fade") {
    flowerState = 3;
  }
  else if (data[0] == "DataRefresh"){
    Serial.print("DataRefreshed");
  }
  else { // If the signal from the mqtt is not one of the available options, give a message to the mqtt server and pass
    Serial.println(payload);
    client.publish("Status", "Unknown message");
    delay(100);
  }
}
