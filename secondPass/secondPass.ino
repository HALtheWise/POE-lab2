/*
 * POE Lab 2 - 3D scanner
 *
 *
 */

#include <stdlib.h>
#include <Servo.h>

// create servo object to control a servo
// a maximum of eight servo objects can be created
Servo servoLeft;  // left of the irSensor facing forward
Servo servoRight; // right of the irSensor facing forward

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
  servoLeft.attach(8);  // attaches the servo on pin 8 to the servo object
  servoRight.attach(9);  // attaches the servo on pin 9 to the servo object
  servoLeft.write(90);
  servoRight.write(90);
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
    getNextPos();

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

void getNextPos()
{
  // getNextPos moves the servos to their next position. For now, just test
  // moving them
  static int servoLeftPos = 90;
  static int servoRightPos = 90;

  servoLeft.write(random(10,170));
  servoRight.write(random(10,170));

}


void printSerialData()
{
  // printSerialData prints the positions of the servos and the irValue followed
  // by a new line
  Serial.println(irValue);
}
