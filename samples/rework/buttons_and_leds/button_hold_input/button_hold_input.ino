int buttonPin = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("button ON");
  } else {
    Serial.println("button OFF");
  }

  delay(1000);
}
