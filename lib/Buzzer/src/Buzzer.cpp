#include "Buzzer.h"

#include <Arduino.h>

namespace BUZZER {

const int SCALE_Do = 523;
const int SCALE_Re = 587;
const int SCALE_Mi = 659;
const int SCALE_Fa = 698;
const int SCALE_So = 784;
const int SCALE_La = 880;
const int SCALE_Si = 988;

void Init() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void Tone(int t) {
    tone(BUZZER_PIN, t);
}

void CloseTone() {
    noTone(BUZZER_PIN);
}

}  // namespace BUZZER