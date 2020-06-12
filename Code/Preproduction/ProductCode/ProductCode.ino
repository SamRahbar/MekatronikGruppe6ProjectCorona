//-----LIBRARIES-----
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
// #include <SPI.h> // Not necessary?


// -------IS IT PRODUCT A OR PRODUCT B?------
// Change these variables depending on which product it is
const char* ssid = "Ellens iPhone"; //Network name
const char* password = "karamellen"; //Wifi-password
const char *recievingTopic = "toA"; // Subscribes to this topic
const char *sendingTopic = "fromA"; // Sends messages with this topic
const char *uniqueID = "A"; // Unique MQTT-ID




//-----MQTT SPECIFIC-----
const char *mqtt_server = "hairdresser.cloudmqtt.com"; //The name of the mqtt site
const int mqtt_port = 15721; // Defines the mqtt port
const char *mqtt_user = "Sam"; // Defines the mqtt username
const char *mqtt_pass = "Sam"; //Defines the mqtt code
String payload; // Definerer variablen 'payload' i det globale scope (payload er navnet på besked-variablen)




//-----FUNCTION SETUP-----
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length); // Placeholder for the callback function for later use. The function itself comes later

// Opretter en klient der kan forbinde til en specifik internet IP adresse.
WiFiClient espClient; // Initialiserer wifi bibloteket ESP8266Wifi, som er inkluderet under "nødvendige bibloteker"

// Opretter forbindelse til mqtt klienten:
PubSubClient client(mqtt_server, mqtt_port, callback, espClient); // Initialiserer bibloteket for at kunne modtage og sende beskeder til mqtt. Den henter fra definerede mqtt server og port. Den henter fra topic og beskeden payload






//-----LED SPECIFIC-----
int ledState = 0;

// How many leds in your strip?
#define NUM_LEDS 7
// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 4
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];






int flowerState = 0;  // 0 - resting. 1 - wake up. 2 - blossom. 3 - fade.



//-----BUTTON SPECIFIC-----
const int buttonPin1 = D1;
const int buttonPin2 = D2;

int buttonState1 = 0;
int buttonState2 = 0;

int lastVar = 0;   // the previous reading from the input pin
int var = 0;


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  buttonSetup();
  wifiSetup();
  MQTTSetup();
}

void loop() {
  buttonController();      // DON'T CLICK THE SAME BUTTON TWICE IN A ROW
  MQTTLoop();
  //LEDloop();

  stateSwitch();
}
