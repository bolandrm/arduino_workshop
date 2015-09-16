int buttonPin = 2;
volatile int state = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggle, RISING);
}

// the loop function runs over and over again forever
void loop() {
}

void toggle() {
  state = !state;

  if (state == HIGH) {
    Serial.println("button toggled ON");
  } else {
    Serial.println("button toggled OFF");
  }
}

