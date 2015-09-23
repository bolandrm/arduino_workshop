/*
This example demonstrates a very simple use of the SevSeg library with a 4
digit display. It displays a counter that counts up, showing deci-seconds.
https://github.com/DeanIsMe/SevSeg
*/

#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
unsigned long timer = millis();
int deciSeconds = 0;

void setup() {
  byte numDigits = 4;   
  byte digitPins[] = {A5, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  if (millis() >= timer) {
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    timer += 100; 
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}
