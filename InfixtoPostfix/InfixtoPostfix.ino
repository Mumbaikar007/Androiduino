
# include "infixToPostfix.h"

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

  String a;
  while(Serial.available()) {

    a= Serial.readString();// read the incoming data as string
    
    Serial.println(MakePostfix(a));

  }
}
