void MQTTParser() {

  //-----STRING ARRAY PARSER-----
  String data[10];//Defines array of information expected
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
  Serial.println(data[1]);
  //Removes first quotation mark of each datapoint since they are included during the processing step.
  data[0].remove(0, 1); //Message
  data[1].remove(0, 1); //H1
  data[2].remove(0, 1); //S1
  data[3].remove(0, 1); //V1
  data[4].remove(0, 1); //H2
  data[5].remove(0, 1); //S2
  data[6].remove(0, 1); //V2
  data[7].remove(0, 1); //HTime
  data[8].remove(0, 1); //STime
  data[9].remove(0, 1); //VTime
  data[10].remove(0, 1); //MotorSpeed

  //Serial.println("Data array = " + data[0] + " : " + data[1]);

  //---- COLOR DATA CONVERTER----
  //----HUE----
  if (data[1].toInt() > data[4].toInt()) {
    MaxHue = data[1].toInt();
    MinHue = data[4].toInt();
  }
  else {
    MaxHue = data[4].toInt();
    MinHue = data[1].toInt();
  }

  //----SAT----
  if (data[2].toInt() > data[5].toInt()) {
    MaxSat = data[2].toInt();
    MinSat = data[5].toInt();
  }
  else {
    MaxSat = data[5].toInt();
    MinSat = data[2].toInt();
  }

  //----VAL----
  if (data[3].toInt() > data[6].toInt()) {
    MaxVal = data[3].toInt();
    MinVal = data[6].toInt();
  }
  else {
    MaxVal = data[6].toInt();
    MinVal = data[3].toInt();
  }

  //Serial.println(String("MaxHue = ") + MaxHue + " : MinHue = " + MinHue);
  //Serial.println(String("MaxSat = ") + MaxSat + " : MinSat = " + MinSat);
  //Serial.println(String("MaxVal = ") + MaxVal + " : MinVal = " + MinVal);


  //----COLOR TIME DEFINERS-----
  HueT = data[7].toInt();
  SatT = data[8].toInt();
  ValT = data[9].toInt();

  //----STEPPER ACCEL DEFINE-----
  //StepSpeed = data[10].toInt();
  //myStepper.setSpeed(data[10].toInt());
  //Serial.println("Stepper Acceleration = " + StepSpeed);

  if (data[0] == "Bloom") {
    myStepper.setSpeed(StepSpeed);//StepSpeed);
    myStepper.setCurrentPosition(0);
    myStepper.moveTo(100);
    startMotor = true;
    flowerState = 1;
  }
  else if (data[0] == "Fade") {
    myStepper.setSpeed(-StepSpeed);//-StepSpeed);
    myStepper.setCurrentPosition(0);
    myStepper.moveTo(100);
    startMotor = true;
    flowerState = 3;
  }
  else if (data[0] == "DataRefresh") {
    Serial.print("DataRefreshed");
  }
  else { // If the signal from the mqtt is not one of the available options, give a message to the mqtt server and pass
    Serial.println(payload);
    client.publish("Status", "Unknown message");
    delay(100);
  }
}
