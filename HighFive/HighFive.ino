/*
* Adding code for data transfer using Bluetooth,currently only Integer transfer
*/

#include<SoftwareSerial.h>


#define rx 10
#define tx 11

SoftwareSerial BT(rx,tx); //RX,TX


void setup() {
  
  Serial.begin(9600);
  BT.begin(38400);
  Serial.println ( "Bluetooth Ready" );
}


void loop() {

  while(!BT.available());
  
  char a;
  a = BT.read();

  Serial.println(a);
  int eureka = a - '0' + 5;
  char result = eureka + '0';

  BT.write(result);

}

