#include <Arduino.h>

#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>

void setup() {
  pinMode(A5, OUTPUT);

}

int melody[] = {
  NOTE_F3, NOTE_A3, NOTE_G3, NOTE_G3, NOTE_G2, NOTE_F3, NOTE_F3, NOTE_A2, 
  NOTE_A2, NOTE_G3, NOTE_G3, NOTE_G2, NOTE_G2, NOTE_F3, NOTE_F3, NOTE_A3, 
  NOTE_G3, NOTE_G3, NOTE_G2, NOTE_F3, NOTE_F3, NOTE_E3, NOTE_E3, NOTE_D3, 0 
};

int noteDurations[] = {
  2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 2, 4, 4, 4, 4, 4, 1, 2, 
};

void loop() {
  for(int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++){
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(A5, melody[thisNote], noteDuration);
    int pauseB = noteDuration * 1.3;
    delay(pauseB);
  }
  delay(3000);
}
