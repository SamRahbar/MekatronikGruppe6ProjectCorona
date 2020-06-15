//-----LIBRARIES-----
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
// #include <SPI.h> // Not necessary?


//-------IS IT PRODUCT A OR PRODUCT B?------
// Change these variables depending on which product it is
const char* ssid = "iPhone"; //Network name
const char* password = "yus0304sen"; //Wifi-password
const char *recievingTopic = "toB"; // Subscribes to this topic
const char *sendingTopic = "fromB"; // Sends messages with this topic
const char *uniqueID = "B"; // Unique MQTT-ID

//----- FLOWER STATES -----
int flowerState = 0;

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
String hex;
long color;

// How many leds in your strip?
#define NUM_LEDS 7
#define DATA_PIN 4

// Define the array of leds
CRGB leds[NUM_LEDS];

//-----Sensor SPECIFIC-----
const int Sensor = D1;

int SensorState1 = 0;
int lastVar = 0;   // the previous reading from the input pin
int var = 0;

//----- MAIN CODE ------
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  SensorSetup();
  wifiSetup();
  MQTTSetup();
}

void loop() {
  SensorController();      // DON'T CLICK THE SAME BUTTON TWICE IN A ROW
  MQTTLoop();
  flowerStateSwitch();
}
