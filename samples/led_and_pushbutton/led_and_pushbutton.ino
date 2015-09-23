void setup() {
  pinMode(2, INPUT);   // Button
  pinMode(4, OUTPUT);  // LED
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(4, HIGH); // LED ON
  } else {
    digitalWrite(4, LOW);  // LED OFF
  }
}
