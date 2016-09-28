/*
 * POE Lab 2 - 3D scanner
 *
 *
 */

#include <stdlib.h>
#include <Servo.h>

// create servo object to control a servo
// a maximum of eight servo objects can be created
Servo servoLeft;  // left of the irSensor when system is facing forward
int servoLeftPos = 0;
Servo servoRight; // right of the irSensor when system is facing forward
int servoRightPos = 0;

int irSensor = 0; // ir sensor pin
int irValue = 0;

// time related
unsigned long interval = 750;
unsigned long time;
unsigned long prev_time = 0;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(19200);
  servoLeft.attach(31);  // attaches the left servo on pin 31 to the servo object
  servoRight.attach(33);  // attaches the right servo on pin 33 to the servo object

  servoLeft.write(servoLeftPos + 90);
  servoRight.write(-servoRightPos + 90 + 3); //+3 is temp as servo offset
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

    // package serial data
    printSerialData();

    // move servos to next position
    moveNextPos();
  }
}


void irSensorRead()
{
  // irSensorRead reads the sensor 5 times and returns the average

  // reset value of irValue
  irValue = 0;

  // read from the irSensor 5 times
  for (int i = 0; i < 5; i++)
  {
    irValue += analogRead(irSensor);
  }

  // divide the value of irValue by 5 to find the average

  irValue = irValue / 5;
}


void gridPos()
{
  // grid position gives sequential positions in a grid like sweep a pattern
  static int gridSize = 20; // length of side of square grid
  static int servoLeftPos = -gridSize;
  static int incrementDirection = 1;
  static int servoRightPos = -gridSize;

  if (servoLeftPos >= -gridSize && servoLeftPos <= gridSize)
  {
    // general behavior is to move servoLeftPos
    servoLeftPos += incrementDirection;
  }
  else
  {
    horiDirection *= -1;
    servoLeftPos += incrementDirection;
    servoRightPos += 1;
  }
}


void moveNextPos()
{
  // getNextPos moves the servos to a random location between -30 and +30
  // degrees. Our default position is 90 degrees so we can use relative angles
  // to make our math easier

  servoLeft.write(servoLeftPos + 90);
  servoRight.write(-servoRightPos + 90 + 3); //+3 is temp as servo offset

}


void printSerialData()
{
  // printSerialData prints the positions of the servos and the irValue followed
  // by a new line
  Serial.print(servoLeftPos); // pan
  Serial.print(",");
  Serial.print(servoRightPos); // tilt
  Serial.print(",");
  Serial.println(irValue); // irValue
}
