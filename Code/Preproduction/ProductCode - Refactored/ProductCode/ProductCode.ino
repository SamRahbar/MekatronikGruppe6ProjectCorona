//-----DEPENDENCIES-----
#include "Settings.h"

//-----LIBRARIES-----
#include <FastLED.h>
#include <AccelStepper.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//-----LED DEFINITIONS----
#define NUM_LEDS 12
#define DATA_PIN 4

//----INSTANTIATE OBJECTS----
CRGB leds[NUM_LEDS];// Define the array of leds

// Opretter en klient der kan forbinde til en specifik internet IP adresse.
WiFiClient espClient; // Initialiserer wifi bibloteket ESP8266Wifi, som er inkluderet under "nødvendige bibloteker"

// Opretter forbindelse til mqtt klienten:
PubSubClient client(mqtt_server, mqtt_port, callback, espClient); // Initialiserer bibloteket for at kunne modtage og sende beskeder til mqtt. Den henter fra definerede mqtt server og port. Den henter fra topic og beskeden payload

// Creates an instance of stepper motor object
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

//----- MAIN CODE ------
void setup() {
  Serial.begin(BAUD_RATE);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  SensorSetup();
  wifiSetup();
  MQTTSetup();
  StepperSetup();
  MicroSwitchSetup();
}

void loop() {
  //Serial.println(String("Switch 1 : ") + digitalRead(Switch1) + String(" || Switch 2 : ") + digitalRead(Switch2));
  //Serial.println(String("SwitchLim 1 : ") + digitalRead(SwitchLim1) + String(" || SwitchLim 2 : ") + digitalRead(SwitchLim2));
  ttime = millis();
  MQTTLoop();
  flowerStateSwitch();
  LEDLoop();
}
