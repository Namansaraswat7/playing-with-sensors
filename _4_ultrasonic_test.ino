long duration1;
int distanceInch1, distanceCm1;
long duration2;
int distanceInch2, distanceCm2;long duration3;
int distanceInch3, distanceCm3;long duration4;
int distanceInch4, distanceCm4;
const int echoPin1 = 30;
const int echoPin2 = 31;const int echoPin3 = 32;const int echoPin4 = 33;
void setup() {
Serial.begin(9600);
DDRA=255;
DDRC=0;// put your setup code here, to run once:
DDRL=255;
}

void loop() {
 PORTL=0b11000000;
PORTA=0;
 delayMicroseconds(2);
 PORTA=0b00001111;
 delayMicroseconds(10);
 PORTA=0;
 duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distanceCm1= duration1*0.034/2;
  //distanceInch1= distanceCm1/2.53;
   duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distanceCm2= duration2*0.034/2;
   duration3 = pulseIn(echoPin3, HIGH);
  // Calcuating the distance
  distanceCm3= duration3*0.034/2;
   duration4 = pulseIn(echoPin4, HIGH);
  // Calculating the distance
  distanceCm4= duration4*0.034/2;

  Serial.print(distanceCm1);
   Serial.print("  ");
   Serial.print(distanceCm2);
   Serial.print("  ");
   Serial.print(distanceCm3);
   Serial.print("  ");
   Serial.print(distanceCm4);
   Serial.println("\n");
}
