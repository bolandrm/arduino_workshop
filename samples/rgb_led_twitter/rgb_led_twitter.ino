/*
Derived from an adafruit tutorial
https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
char received[32];
boolean newData = false;
 
void setup() { 
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

  setColor(0, 0, 255);  // initially blue
}
 
void loop() {

  while (Serial.available() > 0) {
    // look for the next valid integers in the incoming serial stream:
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    
    if (Serial.read() == '\n') {
      setColor(red, green, blue);
    }
  }
}
 
void setColor(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
