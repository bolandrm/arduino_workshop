/*
This example demonstrates a very simple use of the SevSeg library with a 4
digit display. It displays a counter that counts up, showing deci-seconds.
https://github.com/DeanIsMe/SevSeg
*/

#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
int buttonPin = 2;
unsigned long timer = millis();
int deciSeconds = 0;
volatile unsigned long lastButtonPress = 0;
volatile int buttonPressed = 0;
int timerActive = 0;

void setup() {
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressInterrupt, CHANGE);
  pinMode(buttonPin, INPUT_PULLUP);

  byte numDigits = 4;   
  byte digitPins[] = {A5, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
  sevseg.setNumber(0, 1);
}

void loop() {
  if (buttonPressed) {
    if (timerActive) {
      // stop the timer on the first button press
      timerActive = 0;
    } else if (deciSeconds == 0) {
       // start the timer if the timer is on 0
       timerActive = 1;
    } else {
      // reset the timer on the 2nd button press
      deciSeconds = 0;
      sevseg.setNumber(deciSeconds, 1);
    }
    
    buttonPressed = 0;
    timer = millis();
  }
  
  if (timerActive && millis() >= timer) {
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    timer += 100; 
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}

void buttonPressInterrupt() {
  if (millis() - lastButtonPress >= 300) {
    buttonPressed = 1;
    lastButtonPress = millis();
    Serial.println("Button pressed!");
  }
}

