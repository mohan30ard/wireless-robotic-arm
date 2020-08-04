#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8);

const byte rxAddr[] = "0xE8E8F0F0E1LL";
Servo finger1 ;
int servopin1 = 4;
int msg[1];

int data; //data variable
int pos; //position variable
void setup()
{
  while (!Serial);
  Serial.begin(9600);
  finger1.attach(servopin1);
  pinMode(servopin1, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    //char text[11] = {0};
    //radio.read(&text, sizeof(text));
    
    //Serial.println(text);
     radio.read(&msg, sizeof(msg));
     //data=msg[0];
     //Serial.println(data);
     //finger1.write(data);
       if(msg[0] <21 && msg[0]>10){
      data = msg[0], pos=map(data, 11, 20, 0, 180);
      finger1.write(pos);
      Serial.println(pos);
    }
     
  }
}
