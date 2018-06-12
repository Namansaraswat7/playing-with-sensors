 int receive=0;
int lightstate=0;
int state=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()>0)
{receive=Serial.read();  }
if(receive=='1'&& lightstate==0)
  {digitalWrite(7,HIGH);
receive=0;
lightstate=1;
//digitalWrite(8,LOW);
  }
  if (receive=='1'&& lightstate==1)
  {
    digitalWrite(7,LOW);
    lightstate=0;
    receive=0;
    }
    if(receive=='8'&&state==0)
{digitalWrite(8,HIGH);
state=1;

  }
   if(receive=='9'&&state==1)
  {
    digitalWrite(8,LOW);
    state=0;
    }
}
