#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
#define RELAYPIN 11

#define WARNLEDPIN 12
char tag[] ="020054BE12FA"; // Replace with your own Tag ID
char input[12];        // A variable to store the Tag ID being presented
int count = 0;        // A counter variable to navigate through the input[] character array
boolean flag = 0;     // A variable to store the Tag match status
void setup()
{Serial.begin(9600);
delay(10);
  mySerial.begin(9600);   // Initialise Serial Communication with the Serial Monitor
  pinMode(RELAYPIN,OUTPUT);pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  digitalWrite(RELAYPIN,LOW);// RELAY OUTPUT
  //pinMode(WARNLEDPIN,OUTPUT); //WRONG TAG INDICATOR
}
void loop()
{
  if(mySerial.available())// Check if there is incoming data in the RFID Reader Serial Buffer.
  {
    count = 0; // Reset the counter to zero
    /* Keep reading Byte by Byte from the Buffer till the RFID Reader Buffer is empty 
       or till 12 Bytes (the ID size of our Tag) is read */
    while(mySerial.available() && count < 12) 
    {
      input[count] = mySerial.read(); // Read 1 Byte of data and store it in the input[] variable
      count++; // increment counter
      delay(5);
    }
    /* When the counter reaches 12 (the size of the ID) we stop and compare each value 
        of the input[] to the corresponding stored value */
    if(count == 12) // 
    {
      count =0; // reset counter varibale to 0
      flag = 1;
      /* Iterate through each value and compare till either the 12 values are 
         all matching or till the first mistmatch occurs */
      while(count<12 && flag !=0)  
      {
        if(input[count]==tag[count])
        flag = 1; // everytime the values match, we set the flag variable to 1
        else
        flag= 0; 
                               /* if the ID values don't match, set flag variable to 0 and 
                                  stop comparing by exiting the while loop */
        count++; // increment i
      }
    }
    if(flag == 1) // If flag variable is 1, then it means the tags match
    {if(digitalRead(RELAYPIN)==LOW)
      { Serial.println("Access Allowed!");
      digitalWrite(RELAYPIN,HIGH);
        }
        else{
      //Serial.println("Access Allowed!");
      //digitalWrite(RELAYPIN,HIGH);
      
      
      Serial.println("Access Denied");
      digitalWrite(RELAYPIN,LOW);}
     // delay (5000);
      //digitalWrite (RELAYPIN,LOW);
    }
    else
    {

      Serial.println("Access Denied");
      digitalWrite(RELAYPIN,LOW);// Incorrect Tag Message
//while(flag==0)
//{digitalWrite(RELAYPIN,HIGH);
//delay(300);digitalWrite(RELAYPIN,LOW);
//delay(300);if(mySerial.available())
//break;
//}
      //digitalWrite(WARNLEDPIN,HIGH);
      //delay(5000);
      //digitalWrite(WARNLEDPIN,LOW);
    }
    /* Fill the input variable array with a fixed value 'F' to overwrite 
    all values getting it empty for the next read cycle */
    for(count=0; count<12; count++) 
    {
      input[count]= 'F';
    }
    count = 0; // Reset counter variable
  }
}
