// Back up sensor
// Adapted from
// http://www.makeuseof.com/tag/how-to-make-a-simple-arduino-alarm-system/#

#include <NewPing.h>
#include <NewTone.h>
 
#define TRIGGER_PIN  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
#define ALARM 3
#define TONE_VAL  1047
 
void setup(){
  pinMode(ALARM, OUTPUT);
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.  
}
 
void loop(){
  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int distance = uS / US_ROUNDTRIP_CM * 0.393701; // inches
  Serial.println(distance);

  if (distance < 20 && distance != 0) {
    int toneTime = distance * 10;
    NewTone(ALARM, TONE_VAL, toneTime);
    delay(toneTime * 2 + 50);
  } else {
    noNewTone();
    delay(50);
  }
}
