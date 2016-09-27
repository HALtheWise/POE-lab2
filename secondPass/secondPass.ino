/*
 * POE Lab 2 - 3D scanner
 *
 *
 */

#include <stdlib.h>

// Servo tiltServo;  // create servo object to control a servo
//                   // a maximum of eight servo objects can be created
// Servo panServo;

int irSensor = 0; // ir sensor pin

// time related
unsigned long interval = 1000;
unsigned long time;
unsigned long prev_time = 0;

void setup()
{
  // put your setup code here, to run once:
  // Serial.begin(19200);
  // tiltServo.attach(8);  // attaches the servo on pin 8 to the servo object
  // panServo.attach(9);  // attaches the servo on pin 9 to the servo object
  // tiltServo.write(80);
}

void loop()
{
  // put your main code here, to run repeatedly:

  // begin interval time state
  time = millis();

  if (time - prev_time > interval)
  {
    // start next timer
    prev_time = time;

    // define local variables
    int irValue = 0;

    // save current irSensor value
    irValue = irSensorRead();

    // move servos to next position


    // package serial buffer
    int i = 0
    char buffer [50];
    i = sprintf (buffer, "%d, %d, %d", irValue, irValue, irValue);
    for(int l= 0; l<=i; l++)
    {
      Serial.print(buffer[l]);
    }
    Serial.print("\n");
  }
}

int irSensorRead()
{
  // irSensorRead reads the sensor 5 times and
  int irValue = 0;

  for (int i = 0; i < 5; i++)
  {
    irValue += analogRead(irSensor);
  }

  return (irValue/5);
}

void getNextPos()
{
  static int panServoPos = 0;
  static int tiltServoPos = 0;
}
