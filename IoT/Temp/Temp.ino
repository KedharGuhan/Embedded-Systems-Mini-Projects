/*
    PLAY Embedded demos - Copyright (C) 2014-2016 Carmine Forino

    This file is part of PLAY Embedded demos.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#include<ThingSpeak.h>
#include<ESP8266WiFi.h>

const char* ssid     = "Spateznet";
const char* password = "abc123@#$";
unsigned long channelID = 383797;
const char* WriteAPIKey = "xxXx";
WifiClient client;

int temp = 0;

void setup() 
{
  Serial.begin (115200);     
  pinMode(A0, INPUT);
  delay(100);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);                     //IMP
  
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
  ThingSpeak.begin(client);                     //IMP
 
}

void loop() 
{  
  temp = analogRead(A0);
  ThingSpeak.writeField(channelID, 7, temp, );
  delay(20000);
}
