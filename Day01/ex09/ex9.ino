const int pinRelay = 7;
const int pinButton = 4;
int oldStateButton = 1;
int state = HIGH;

void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinRelay, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int stateButton = digitalRead(pinButton);

  Serial.println(state);
  if(stateButton == 0 && oldStateButton != stateButton)
    state = state ? LOW : HIGH;
  digitalWrite(pinRelay, state);
  oldStateButton = stateButton;
}
