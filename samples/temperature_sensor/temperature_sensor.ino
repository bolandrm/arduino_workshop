// LM35 Temperature Sensor
// http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/

int val;
int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(tempPin);
  float mv = (val / 1024.0) * 5000; 
  float cel = mv / 10;
  float farh = (cel * 9) / 5 + 32;

  Serial.print(cel);
  Serial.print("*C");
  Serial.println();

  Serial.print(farh);
  Serial.print("*F");
  Serial.println();

  delay(1000);
}
