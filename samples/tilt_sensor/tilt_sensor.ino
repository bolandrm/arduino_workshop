// This is just a basic example
// For a much more detailed example, see here:
// https://learn.adafruit.com/tilt-sensor/using-a-tilt-sensor

#define SENSOR_PIN 2

void setup() {
  Serial.begin(9600);

  // this sets the default pin value to "HIGH",
  // you can use a normal INPUT with an external pull up or pull
  // down resistor as well.
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}

void loop() {
  
  // The sensor completes the circuit when it is NOT tilted.
  
  if (digitalRead(SENSOR_PIN) == HIGH) {
    Serial.println("TILTED!!");
  } else {
    Serial.println("not tilted");
  }

  delay(500);
}
