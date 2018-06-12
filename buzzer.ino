void setup() {
  Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(13,OUTPUT);
}

void loop() {
  int v=analogRead(A0);
  Serial.println(v);
  delay(100);
  if(v<=500)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);

}
