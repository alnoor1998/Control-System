#include <Servo.h>
Servo servo_9;
const int TrigPin = 10;
const int EchoPin = 11;
long duration, height; 
void setup()
{
  //Initialize serial communication:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  servo_9.attach(9); //Servo motor attached to pin 8 
}

void loop()
{
  //The ultrasonic sensor will be places at 50 height,
  //it will measure the distace to the box
  //If the distance is 20 , it is a box with 30 height 
  //If the distance is 30 , it is a box with 20 height
  //If the distance is 40 , it is a box with 10 height 
  
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);
  //Convert the time into a distance
  height= (duration/2)/29.1;
 
  if ( height <= 20 && height >= 0 )
  {
  servo_9.write(30);
  }
  else if( height <= 30 && height > 20 )
  {
  servo_9.write(90);
  }
  else if ( height <= 40 && height > 30 )
  {
  servo_9.write(150);
  }
  else 
  {
  servo_9.write(0);
  }
  
}