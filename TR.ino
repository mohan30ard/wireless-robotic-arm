#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte rxAddr[] = "0xE8E8F0F0E1LL";

int msg[1];

//define the flex sensor input pins
int flex_5 = A1;
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A5;

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;
void setup()
{
  Serial.begin(9600);
  radio.begin();
  pinMode(flex_5 , INPUT);
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
}

void loop()
{
  //const char text[] = "Hello World";
  //radio.write(&text, sizeof(text));

  flex_5_val = analogRead(flex_5); 
  Serial.print(flex_5_val);                           //175 - 0
  //int pos1 = map(flex_5_val, 70 , 150 , 11 , 20);
  flex_5_val = map(flex_5_val, 60 , 140 , 11 , 20);
  Serial.print(",\t");
  flex_5_val = constrain(flex_5_val , 11 , 20 );
  //pos1 = pos1/30;
  //pos1 = pos1 * 30;
  Serial.println(flex_5_val);
  msg[0] = flex_5_val;
  radio.write(  &msg, sizeof(msg) );
  
  //Serial.print(",\t");
    flex_4_val = analogRead(flex_4);
    
   // Serial.print(flex_4_val);                         //175 - 0
  flex_4_val = map(flex_4_val, 1023, 0, 11, 20);
  msg[0] = flex_4_val;
  //radio.write( &msg, sizeof(msg) );

    }
