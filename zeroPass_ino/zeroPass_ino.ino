// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo tiltServo;  // create servo object to control a servo 
                  // a maximum of eight servo objects can be created 
Servo panServo;



int pos = 0;    // variable to store the servo position 

int irSensor = 0; // ir sensor pin
int irValue;

void setup() 
{ 
  Serial.begin(115200);
  tiltServo.attach(8);  // attaches the servo on pin 9 to the servo object 
  panServo.attach(9);  // attaches the servo on pin 9 to the servo object 
  tiltServo.write(80);
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    // tiltServo.write(pos);              // tell servo to go to position in variable 'pos' 
    // panServo.write(pos);              // tell servo to go to position in variable 'pos'
    irValue = analogRead(irSensor); 
    Serial.println(irValue);

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    // tiltServo.write(pos);              // tell servo to go to position in variable 'pos' 
    // panServo.write(pos);              // tell servo to go to position in variable 'pos' 
    irValue = analogRead(irSensor); 
    Serial.println(irValue);
   
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 
