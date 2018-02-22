
# include<SoftwareSerial.h>

#define rx 10
#define tx 11

SoftwareSerial BT(rx,tx); //RX,TX


void setup() {

  Serial.begin(9600);
  BT.begin(38400);

}

char ReadFromBluetooth (){
  
  while(!BT.available());
  Serial.println("Wait");

  char digit = BT.read();
  if ( !(digit >= '0' && digit <= '9') ){
    Serial.println("Enter Again !");
    digit = ReadFromBluetooth ();
  }
  
  return digit;
  
}

int CheckBluetoothCommand() {
  
  int number = 0;
  
  for ( int i = 0; i < 3; i ++){
    
    char digit = ReadFromBluetooth();

    Serial.println(digit);
    
    number = ( number * 10 ) + ( digit - '0');       
  
  }

  Serial.println(number);
  return number;
  
}

void loop() {

  int a = CheckBluetoothCommand();
  
  a += 5;
  
  Serial.println(a);

}
