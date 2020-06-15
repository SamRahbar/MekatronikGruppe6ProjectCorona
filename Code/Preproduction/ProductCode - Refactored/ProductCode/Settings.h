#define VERSION_ID F( "Dynamic Corona Flower 2020")
#define BAUD_RATE 9600

//-------PRODUCT IDENTIFICATION------
// Change these variables depending on which product it is
const char* ssid = "iPhone"; //Network name
const char* password = "yus0304sen"; //Wifi-password
const char *recievingTopic = "toB"; // Subscribes to this topic
const char *sendingTopic = "fromB"; // Sends messages with this topic
const char *uniqueID = "B"; // Unique MQTT-ID

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
const int Sensor = D1; //Sensor datapin
int SensorState1 = 0; //Sensors current state
int lastVar = 0;   // the previous reading from the input pin
int var = 0;  //current reading saved

//----- FLOWER STATES -----
int flowerState = 0;

//-----FUNCTION SETUP-----
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length); // Placeholder for the callback function for later use. The function itself comes later
