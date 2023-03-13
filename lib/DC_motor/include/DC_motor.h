#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

// DC Motor
#define MOTOR_A_ENABLE 10
#define MOTOR_A_DIR 12
#define MOTOR_B_ENABLE 11
#define MOTOR_B_DIR 13

namespace DC_MOTOR {

void Init();

void Motor_A_Run(int DIR, int PWM);
void Motor_B_Run(int DIR, int PWM);

void Forward(int PWM);
void Backward(int PWM);
void Stop();
void Right(int PWM);
void Left(int PWM);

}  // namespace DC_MOTOR

#endif