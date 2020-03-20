int pinButton = 4;
int LED = 2;
int state = HIGH;
int oldStateButton = 1;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  int stateButton = digitalRead(pinButton);

  if(stateButton == 0 && oldStateButton != stateButton)
    state = state ? LOW : HIGH;
  oldStateButton = stateButton;
  digitalWrite(LED, state);
}
