// Arduino Library
#include <Arduino.h>
#include <ArduinoSTL.h>

// Other Library
#include "Bluetooth.h"
#include "Buzzer.h"
#include "DC_motor.h"
#include "LCD.h"
#include "ServoLib.h"

void setup() {
    BUZZER::Init();
    LCD::Init();
    BLUETOOTH::Init();
    DC_MOTOR::Init();
    SERVO::Init();
}

void loop() {
    BLUETOOTH::Read();

    if (BLUETOOTH::button[0] == '1') {
        DC_MOTOR::Forward(255);
    } else if (BLUETOOTH::button[0] == '2') {
        DC_MOTOR::Right(255);
    } else if (BLUETOOTH::button[0] == '3') {
        DC_MOTOR::Backward(255);
    } else if (BLUETOOTH::button[0] == '4') {
        DC_MOTOR::Left(255);
    } else {
        DC_MOTOR::Stop();
    }
}
