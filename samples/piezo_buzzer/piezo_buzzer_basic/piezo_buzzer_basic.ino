// define some frequencies for piano keys
// https://en.wikipedia.org/wiki/Piano_key_frequencies

#define NOTE_C3  131
#define NOTE_C4  262
#define NOTE_C5  523
#define NOTE_C6  1047

int buzzerPin = 13;

void setup(void)
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  // tone(pin, frequency, duration)
  
  tone(buzzerPin, NOTE_C3, 1000);
  delay(1000);

  tone(buzzerPin, NOTE_C4, 1000);
  delay(1000);
  
  tone(buzzerPin, NOTE_C5, 1000);
  delay(1000);
  
  tone(buzzerPin, NOTE_C6, 1000);
  delay(1000);
}
