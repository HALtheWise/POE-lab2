/*
 * POE Lab 2 - 3D scanner
 *
 *
 */

#include <stdlib.h>
// #include <Servo.h>

// Servo tiltServo;  // create servo object to control a servo
// Servo panServo;   // a maximum of eight servo objects can be created

int irSensor = 0; // ir sensor pin
int irValue = 0;

// time related
unsigned long interval = 1000;
unsigned long time;
unsigned long prev_time = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(19200);
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

    // save current irSensor value
    irSensorRead();

    // move servos to next position


    // package serial data
    printSerialData();
  }
}

int irSensorRead()
{
  // irSensorRead reads the sensor 5 times and returns the average

  // reset value of irValue
  irValue = 0;

  // read from the irSensor 5 times
  for (int i = 0; i < 5; i++)
  {
    irValue += analogRead(irSensor);
  }

  // return value of irValue / 5 to average the readings
  return (irValue/5);
}

// void getNextPos()
// {
//   static int panServoPos = 0;
//   static int tiltServoPos = 0;
// }
//

void printSerialData()
{
  // printSerialData prints the positions of the servos and the irValue followed
  // by a new line
  Serial.println(irValue);
}
