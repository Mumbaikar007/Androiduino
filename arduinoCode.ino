/*
* Adding code for data transfer using Bluetooth,currently only Integer transfer
*/

#include<SoftwareSerial.h>

#define rx 10
#define tx 11

SoftwareSerial BT(rx,tx); //RX,TX

void incomingBTdata();

void setup() {
 Serial.begin(9600);
 BT.begin(9600);
}

void loop() {
  

}

void incomingBTdata(){
  while(!BT.available());
  char a;
  a = BT.read();
    switch (a)
    {
       case '1': // put main code here
                break;
       case '2': // put main code here
                break;
      case '3':  // put main code here
                break;
      case '4': // put main code here
               break;
    }
    delay(10);
  }
}
