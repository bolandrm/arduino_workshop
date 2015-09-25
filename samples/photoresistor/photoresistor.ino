// Nightlight!
// If the photo resistor reads less than a certain value,
// turn on the LED.
// This is very similar to the force sensitive resistor:
// https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

int prPin = A0;
int ledPin = 2;
int prReading = 0;

// You might need to tweak this number.  Look at the readings
// in the console, and move your hand on/off the sensor.  Try to
// pick out a value where you want to LED to be off.
int pinOffValue = 850;

void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);  
}

void loop() {
  prReading = analogRead(prPin); 

  Serial.print("Analog reading = ");
  Serial.println(prReading);     // the raw analog reading
  
  // If the photo resistor reads less than a certain value,
  // turn on the LED.
  if (prReading < pinOffValue) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(400);
}
