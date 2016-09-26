int irSensor = 0; // ir sensor pin
int irValue;

void setup() 
{ 
  Serial.begin(19200);
} 

void loop()
{
  irValue = analogRead(irSensor); 
  Serial.println(irValue);
}
