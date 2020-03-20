#include <DHTesp.h>

DHTesp dht;

const int pinDHT = 5;

void setup()
{
  dht.setup(pinDHT, DHTesp::DHT11);
  pinMode(pinDHT, INPUT);
  Serial.begin(9600);
}

void loop()
{
  TempAndHumidity TnH = dht.getTempAndHumidity();
  Serial.println("T°: " + String(TnH.temperature) + " H: " + String(TnH.humidity));
  delay(2000);
}
