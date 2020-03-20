int pinPot = A0;
int LED = 2;
int state = HIGH;

void setup() {
  pinMode(pinPot, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int statePot = analogRead(pinPot);

  Serial.println(statePot);
  state = state ? LOW : HIGH;
  digitalWrite(LED, state);
  delay(statePot);
}
