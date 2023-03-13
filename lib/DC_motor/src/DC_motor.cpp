#include "DC_motor.h"

#include <Arduino.h>

namespace DC_MOTOR {

void Init() {
    pinMode(MOTOR_A_ENABLE, OUTPUT);
    pinMode(MOTOR_A_DIR, OUTPUT);
    pinMode(MOTOR_B_ENABLE, OUTPUT);
    pinMode(MOTOR_B_DIR, OUTPUT);
}

// DIR: 1 is Forward.
void Motor_A_Run(int DIR, int PWM) {
    digitalWrite(MOTOR_A_DIR, DIR ? HIGH : LOW);
    analogWrite(MOTOR_A_ENABLE, PWM);
}

void Motor_B_Run(int DIR, int PWM) {
    digitalWrite(MOTOR_B_DIR, DIR ? HIGH : LOW);
    analogWrite(MOTOR_B_ENABLE, PWM);
}

void Forward(int PWM) {
    Motor_A_Run(1, PWM);
    Motor_B_Run(1, PWM);
}

void Backward(int PWM) {
    Motor_A_Run(0, PWM);
    Motor_B_Run(0, PWM);
}

void Stop() {
    Motor_A_Run(0, 0);
    Motor_B_Run(0, 0);
}

void Right(int PWM) {
    Motor_A_Run(0, PWM);
    Motor_B_Run(1, PWM);
}

void Left(int PWM) {
    Motor_A_Run(1, PWM);
    Motor_B_Run(0, PWM);
}

}  // namespace DC_MOTOR