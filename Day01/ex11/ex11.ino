#include "BluetoothSerial.h"

const int trigPin = 18;
const int echoPin = 19;
const int LED = 4;
long duration;
int distance;
int state = HIGH;

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  state = distance <= 30 ? HIGH : LOW;
  digitalWrite(LED, state);
  SerialBT.print("Distance: ");
  SerialBT.println(distance);
}
