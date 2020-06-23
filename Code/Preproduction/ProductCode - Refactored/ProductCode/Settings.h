#define VERSION_ID F( "Dynamic Corona Flower 2020")
#define BAUD_RATE 9600

//-------PRODUCT IDENTIFICATION------
// Change these variables depending on which product it is
const char* ssid = "XKEYSCORE #C-137"; //Network name
const char* password = "arduinocode"; //Wifi-password
const char *recievingTopic = "toB"; // Subscribes to this topic
const char *sendingTopic = "fromB"; // Sends messages with this topic
const char *uniqueID = "B"; // Unique MQTT-ID

//-----MQTT SETTINGS-----
const char *mqtt_server = "hairdresser.cloudmqtt.com"; //The name of the mqtt site
const int mqtt_port = 15721; // Defines the mqtt port
const char *mqtt_user = "Sam"; // Defines the mqtt username
const char *mqtt_pass = "Sam"; //Defines the mqtt passcode
String payload; // Definerer variablen 'payload' i det globale scope (payload er navnet på besked-variablen)

//-----TIME DEFINITIONS----
long ttime;

bool startMotor = false;
bool FadeUpRunning = false;
bool FadeDownRunning = false;

//-----LED SETTINGS-----
String hex; //Used to convert hex to long
long color; //Saved value

long lastHueTime = 0;
long lastSatTime = 0;
long lastValTime = 0;

bool HueFlip = false;
bool SatFlip = false;
bool ValFlip = false;

int MaxHue = 255;
int MinHue = 0;

int MaxSat = 255;
int MinSat = 250;

int MaxVal = 255;
int MinVal = 100;

int CurHue = 0;
int CurSat = 0;
int CurVal = 0;

int HueT = 20;
int SatT = 100;
int ValT = 100;

//-----SENSOR SETTINGS-----
const int SensorPin = D1; //Sensor datapin
void ICACHE_RAM_ATTR SensorModeChange(); //Interrupt Method

//-----MOTOR SETTINGS------
#define dirPin D6
#define stepPin D5
#define StepDistance 500
#define StepMaxSpeed 1000
#define StepAccel 500
int StepSpeed = 1000;
int MotorState = 1;

#define motorInterfaceType 1

//-----MICROSWITCHES------
#define Switch1 D8
#define Switch2 D8
void ICACHE_RAM_ATTR MicroSwitchStates();
volatile int SwitchLim1 = 0;
volatile int SwitchLim2 = 0;

//----- FLOWER STATES -----
int flowerState = 0;

//-----FUNCTION SETUP-----
void callback(char* byteArraytopic, byte* byteArrayPayload, unsigned int length); // Placeholder for the callback function for later use. The function itself comes later
