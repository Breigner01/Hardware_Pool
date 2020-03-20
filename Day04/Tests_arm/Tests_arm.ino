#include <Servo.h>

Servo myservo1;
Servo myservo2;
int pos = 0;

const int potPin1 = 13;
const int potPin2 = 12;
const int servoPin1 = 14;
const int servoPin2 = 27;

void setup()
{
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);
  Serial.begin(9600);
}

void loop()
{
  int valuePot1 = map(analogRead(potPin1), 0, 4095, 0, 180);
  int valuePot2 = map(analogRead(potPin2), 0, 4095, 0, 180);

  myservo1.write(valuePot1);
  myservo2.write(valuePot2);
}
