#define VERSION_ID F( "Dynamic Corona Flower 2020")
#define BAUD_RATE 9600

//-------PRODUCT IDENTIFICATION------
// Change these variables depending on which product it is
const char* ssid = "XKEYSCORE #C-137"; //Network name
const char* password = "arduinocode"; //Wifi-password
const char *recievingTopic = "toA"; // Subscribes to this topic
const char *sendingTopic = "fromA"; // Sends messages with this topic
const char *uniqueID = "A"; // Unique MQTT-ID

//-----MQTT SETTINGS-----
const char *mqtt_server = "hairdresser.cloudmqtt.com"; //The name of the mqtt site
const int mqtt_port = 15721; // Defines the mqtt port
const char *mqtt_user = "Sam"; // Defines the mqtt username
const char *mqtt_pass = "Sam"; //Defines the mqtt passcode
String payload; // Definerer variablen 'payload' i det globale scope (payload er navnet på besked-variablen)

//-----LED SETTINGS-----
int ledState = 0;
String hex; //Used to convert hex to long
long color; //Saved value

//-----SENSOR SETTINGS-----
const int SensorPin = D1; //Sensor datapin
void ICACHE_RAM_ATTR SensorModeChange(); //Interrupt Method

//-----MOTOR SETTINGS------
const int dirPin = D6;
const int stepPin = D5;
int StepperAccel;
#define motorInterfaceType 1

//----- FLOWER STATES -----
int flowerState = 0;

//-----FUNCTION SETUP-----
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length); // Placeholder for the callback function for later use. The function itself comes later
