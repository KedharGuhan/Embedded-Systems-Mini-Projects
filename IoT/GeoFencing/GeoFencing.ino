/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"
#include "TinyGPS++.h"
TinyGPSPlus gps;

/************************ Starts Here *******************************/
double hmlat = 10.544430;
double hmlong = 76.223078;
double Lat, Long;
// set up the 'digital' feed
AdafruitIO_Feed *alert = io.feed("alert");

void setup() {

  // set button pin as an input
  

  // start the serial connection
  Serial.begin(9600);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

while(Serial.available()>0){

  gps.encode(Serial.read());
}
 if (gps.location.isUpdated())
  {
     Lat = gps.location.lat();
     Long = gps.location.lng();
  }
 int current;
 current = (hmlat - Lat)+(hmlong - Long);

   if(current!=0){
  alert->save(current);
   }
  
}
