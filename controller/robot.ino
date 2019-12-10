//This Arduino program drives a water dispenser robot.

//Header inclusions
#include <SoftwareSerial.h>
//Global vars
SoftwareSerial Blue(2,3);

//Pin definitions
int ena = 5;
int enb = 6;
 
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
long int data;
long int command1 = 92;// forward
long int command2 = 79; // left
long int command3 = 71; //  right
long int command4 = 91; //  Reverse
long int command5 = 10; // stop



char state = 0;



void setup(){

    //Define input pins

    //Define output pins
   Serial.begin(9600);
   Blue.begin(9600);
 
   pinMode(ena, OUTPUT);
   pinMode(enb, OUTPUT);
 
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);

    //Initialize devices
     analogWrite(ena, 255);
     analogWrite(enb, 255);
     delay(1000);
}

void loop(){
    while(Blue.available()==0) ;
{
   data = Blue.parseInt();
}
delay(100);
//Serial.print(data);
 
if (data == command1) // Forward
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //delay(100);
}
    
 if( data == command2) // left
 {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);
 }
 
 if( data == command3) // Right
 {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
 }
    
 if( data == command4) // Reverse
 {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
 }
 if( data == command5) // Stop
 {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
 }

}
