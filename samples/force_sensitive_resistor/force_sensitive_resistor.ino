// Force Sensitive Resistor Demo
// The harder you press, the brighter the LED becomes.
// Inspired by:
// https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

int fsrPin = A0;
int ledPin = 3;
int fsrReading = 0;
int outputValue = 0;

// You might need to tweak this number.  Look at the readings
// in the console, and move your hand on/off the sensor.  Try to
// pick out a value where you want to LED to be off.
int fsrMin = 0;
int fsrMax = 830;

void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(fsrPin, INPUT);
}

void loop() {
  fsrReading = analogRead(fsrPin); 

  Serial.print("Analog reading = ");
  Serial.println(fsrReading);     // the raw analog reading

  fsrReading = constrain(fsrReading, fsrMin, fsrMax);

  outputValue = map(fsrReading, fsrMin, fsrMax, 0, 255);
  analogWrite(ledPin, outputValue);
  
  delay(200);
}
