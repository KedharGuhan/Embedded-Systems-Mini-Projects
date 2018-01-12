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
#define segA 2//connecting segment A to PIN2
#define segB 3// connecting segment B to PIN3
#define segC 4// connecting segment C to PIN4
#define segD 5// connecting segment D to PIN5
#define segE 6// connecting segment E to PIN6
#define segF 7// connecting segment F to PIN7
#define segG 8// connecting segment G to PIN8

#define IR1 13      // car incoming
#define IR2 12      //car outgoing
int detection1 = HIGH;
int detection2 = HIGH;
// initialization to no obstacle
int cars = 5;

void setup() 
{
  Serial.begin (9600);      // used for communication between the Arduino serial port and a PC
  pinMode(IR2, INPUT);
  pinMode(IR1, INPUT);
  Serial.println("5 cars inside");
  for (int i=2;i<9;i++)
  {
    pinMode(i, OUTPUT);// taking all pins from 2-8 as output
  }
}

void loop() 
{  
  detection2 = digitalRead(IR2);
  detection1 = digitalRead(IR1); // read the value from the sensor
  
  if(detection1 == LOW && cars>0)
  {
    cars--;
    Serial.print(cars); Serial.println(" cars inside");
  }
  
  if(detection2 == LOW && cars<9)
  {
    cars++;
    Serial.print(cars); Serial.println(" cars inside");
  }
  
  delay(1000);     // you can change this time
  
  switch (carsz)
  {
 
  case 0://when count value is zero show”0” on disp
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(segG, HIGH);
  break;

 

  case 1:// when count value is 1 show”1” on disp

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  break;

 

  case 2:// when count value is 2 show”2” on disp

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);

   break;

 

  case 3:// when count value is 3 show”3” on disp

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
  break;

 

  case 4:// when count value is 4 show”4” on disp
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  break;

 

  case 5:// when count value is 5 show”5” on disp
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  break;

 

  case 6:// when count value is 6 show”6” on disp
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
  break;

 

  case 7:// when count value is 7 show”7” on disp
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  break;

 

  case 8:// when count value is 8 show”8” on disp
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  break;

 

  case 9:// when count value is 9 show”9” on disp
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  break;
}
  
}
