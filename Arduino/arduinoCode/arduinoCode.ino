/*
* Adding code for data transfer using Bluetooth,currently only Integer transfer
*/

#include<SoftwareSerial.h>
# include "infixToPostfix.h"

#define rx 10
#define tx 11

SoftwareSerial BT(rx,tx); //RX,TX

String equation;
void incomingBTdata();

void setup() {
  
  Serial.begin(9600);
  BT.begin(38400);
  equation = "";
  
}

bool isOperator ( char a){
  return ( a == '+' || a == '-' || a == '*' || a == '/' || a== '(' || a == ')' ) ? true : false;
}

void loop() {


  while(!BT.available());
  
  char a;
  a = BT.read();

  //Serial.print(a);

  
  if ( a == '@'){

    Serial.print ( "Equation is : ");
    Serial.println( equation );

    String postfix = MakePostfix( equation ); 
    
    Serial.print ( "Postfix is : ");
    Serial.println( postfix );

    int answer = SolvePostfix ( postfix );
    
    Serial.print( "Answer is: ");
    Serial.println ( answer );

    BT.write(answer);
    
    equation = "";
  
  }
  else {

    if ( (a >= '0' && a <= '9') || isOperator(a) )
      equation += a;
    
  }
  


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
