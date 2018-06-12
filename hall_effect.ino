void setup() {
  pinMode(A0,INPUT);
 Serial.begin(9600);
 
  
  }
int z;
void loop() {
  z=analogRead(A0);
  //z=digitalRead()
Serial.println(z);

}
