//inkluderer nødvendige bibloteker
//-----WIFI SPECIFIC-----
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Definerer id og password til netværksforbindelse som NodeMCU anvender
const char* ssid = "XKEYSCORE #C-137"; //Network name
const char* password = "arduinocode"; //Wifipassword
//dlink-79BC-5GHz uygqk50992

// Definerer information til mqtt serveren
const char *mqtt_server = "hairdresser.cloudmqtt.com"; //The name of the mqtt site
const int mqtt_port = 15721; // Defines the mqtt port
const char *mqtt_user = "Sam"; // Defines the mqtt username
const char *mqtt_pass = "Sam"; //Defines the mqtt code

String payload; // Definerer variablen 'payload' i det globale scope (payload er navnet på besked-variablen)

/////// FUNKTIONSOPSÆTNING ////////

// Opretter en placeholder for callback-funktionen til brug senere. Den rigtige funktion ses længere nede.
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length);

// Opretter en klient der kan forbinde til en specifik internet IP adresse.
WiFiClient espClient; // Initialiserer wifi bibloteket ESP8266Wifi, som er inkluderet under "nødvendige bibloteker"

// Opretter forbindelse til mqtt klienten:
PubSubClient client(mqtt_server, mqtt_port, callback, espClient); // Initialiserer bibloteket for at kunne modtage og sende beskeder til mqtt. Den henter fra definerede mqtt server og port. Den henter fra topic og beskeden payload

/////// FUNKTIONSOPSÆTNING SLUT /////////


//-----BUTTON SPECIIC-----
const int buttonPin1 = D1;
const int buttonPin2 = D2;
const int buttonPin3 = D3;
const int buttonPin4 = D4;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

int lastVar = 0;   // the previous reading from the input pin
int var = 0;

//------INITIALISATION DONE-----

void setup() {
  buttonSetup();
  wifiSetup();
  MQTTSetup();
  Serial.begin(9600);
}

void loop() {
  buttonController();      // DON'T CLICK THE SAME BUTTON TWICE IN A ROW
  MQTTLoop();
}
