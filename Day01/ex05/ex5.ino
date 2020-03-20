int pinPot = A0;
int LED = 3;

void setup() {
  pinMode(pinPot, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int statePot = analogRead(pinPot);

  Serial.println(statePot);
  analogWrite(LED, statePot / 4);
}
