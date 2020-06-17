//-----DEPENDENCIES-----
#include "Settings.h"

//-----LIBRARIES-----
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//-----LED DEFINITIONS----
#define NUM_LEDS 7
#define DATA_PIN 4

//----INSTANTIATE OBJECTS----
CRGB leds[NUM_LEDS];// Define the array of leds

// Opretter en klient der kan forbinde til en specifik internet IP adresse.
WiFiClient espClient; // Initialiserer wifi bibloteket ESP8266Wifi, som er inkluderet under "nødvendige bibloteker"

// Opretter forbindelse til mqtt klienten:
PubSubClient client(mqtt_server, mqtt_port, callback, espClient); // Initialiserer bibloteket for at kunne modtage og sende beskeder til mqtt. Den henter fra definerede mqtt server og port. Den henter fra topic og beskeden payload

//----- MAIN CODE ------
void setup() {
  Serial.begin(BAUD_RATE);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  SensorSetup();
  wifiSetup();
  MQTTSetup();
}

void loop() {
  SensorController();
  MQTTLoop();
  flowerStateSwitch();
  //LEDloop();
}
