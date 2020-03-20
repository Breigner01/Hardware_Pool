//int pinButton = 4;
int LED = 2;
int state = HIGH;

void setup() {
  //pinMode(pinButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  //Serial.begin;
}

void loop() {
  state = state ? LOW : HIGH;
  digitalWrite(LED, state);
  delay(1000);
}
