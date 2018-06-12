#include<TinyGPS++.h>
#include<SoftwareSerial.h>
SoftwareSerial serial_connection(10,9);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
serial_connection.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
while(serial_connection.available())
{
  gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated())
  {
    Serial.println(gps.speed.kmph());
    }
}
