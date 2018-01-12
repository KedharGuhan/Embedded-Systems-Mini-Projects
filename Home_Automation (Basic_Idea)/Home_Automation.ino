/*
 Press a to get LDR data
 Press b to get Temperature Data
 Press c to get Obstacle Data(IR Detection)

 B Kedhar Guhan
 */



#define IR 2      // digital pin for ir sensor

int detection = HIGH;
int ldrPin = A0;
int tempPin = A1;
int ldr = 0;// initialization to no obstacle

void setup() 
{
  Serial.begin (9600);     
  pinMode(IR, INPUT);
}

void loop() {  

if(Serial.available() > 0)
{
  detection = digitalRead(IR);
  ldr = analogRead(A0);
  float voltage = analogRead(A1);
  float temp =  voltage;
  
  int s = Serial.read();
  switch(s)
  {
    case 'a':
    Serial.print("LDR: "); Serial.println(ldr);
    delay(100);
    break;
    
    case 'b':
    Serial.print("Temp: "); Serial.println(temp);
    delay(100);
    break;
    
    case 'c':
    if(detection == LOW)
      Serial.print("there is an obstacle!\n");
    else Serial.print("No obstacle!\n");
    delay(100);
  }
}
}
