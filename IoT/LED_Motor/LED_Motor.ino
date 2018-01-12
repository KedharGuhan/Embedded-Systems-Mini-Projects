/*
 Regularly get updates of LED 1 state, LED 2 state, brightness of vLED, and speed of motor.
 These values belong to different fields in a channel.
 Since theres only one Analog Output Pin in the NodeMCU, the value denoting the brightness of vLED 
 is also the speed of the motor. So it depends on what is connected to the NodeMCU - LED or a MOTOR.
 */


#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
 
//Replace your wifi credentials here
const char* ssid     = "Spateznet";
const char* password = "abc123@#$";
 
unsigned long channelID = 383797;

/*
  led1 = field 1
  led2 = field 2
  aled = field 3
  motor = field 4
 */
 
unsigned int led1 = 1;
unsigned int led2 = 2;
unsigned int vled = 3;
unsigned int motor = 4;
 
WiFiClient  client;
  
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(D1, OUTPUT);
  digitalWrite(D1, 0);
  pinMode(D5, OUTPUT);
  pinMode(A0, OUTPUT);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);
 
}

void loop() {

int led_1 = ThingSpeak.readFloatField(channelID, led1);
int led_2 = ThingSpeak.readFloatField(channelID, led2);
int variable_led = ThingSpeak.readFloatField(channelID, vled);
int motor_speed = ThingSpeak.readFloatField(channelID, led1);

  if(led_1){
    digitalWrite(D1, 1);
    Serial.println("LED1 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(D1, 0);
    Serial.println("LED1 is Off..!");
  }  
  
  if(led_2){
    digitalWrite(D5, 1);
    Serial.println("LED2 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(D5, 0);
    Serial.println("LED2 is Off..!");
  }

  analogWrite(A0, variable_led);

  Serial.print("LED1: "); Serial.print(led_1); Serial.print("\t"); 
  Serial.print("LED2: "); Serial.print(led_2); Serial.print("\t"); 
  Serial.print("variable LED: "); Serial.print(variable_led); Serial.print("\t"); 
  Serial.print("Motor: "); Serial.println(motor_speed);
  delay(10);

}
