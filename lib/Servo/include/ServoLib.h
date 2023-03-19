#ifndef _SERVO_LIB_H_
#define _SERVO_LIB_H_

#include <Arduino.h>
#include <Servo.h>

// Servo
#define SERVO_1_PIN A0
#define SERVO_2_PIN A1
#define SERVO_3_PIN A2

namespace SERVO {

void Init();
void Write(int num, int angle);

};  // namespace SERVO

#endif