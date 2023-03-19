#include "ServoLib.h"

namespace SERVO {

Servo servo_[3];

void Init() {
    servo_[0].attach(SERVO_1_PIN);
    servo_[1].attach(SERVO_2_PIN);
    servo_[2].attach(SERVO_3_PIN);
}

void Write(int num, int angle) {
    if (angle >= 0 && angle <= 180) {
        servo_[num].write(angle);
    }
}

};  // namespace SERVO
