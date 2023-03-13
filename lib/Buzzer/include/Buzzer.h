#ifndef _BUZZER_H_
#define _BUZZER_H_

// Buzzer
#define BUZZER_PIN 4

namespace BUZZER {

extern const int SCALE_Do;
extern const int SCALE_Re;
extern const int SCALE_Mi;
extern const int SCALE_Fa;
extern const int SCALE_So;
extern const int SCALE_La;
extern const int SCALE_Si;

void Init();

void Tone(int t);
void CloseTone();

}  // namespace BUZZER

#endif