// Arduino Library
#include <Arduino.h>
#include <ArduinoSTL.h>

// Other Library
#include "Bluetooth.h"
#include "Buzzer.h"
#include "DC_motor.h"
#include "LCD.h"

void setup() {
    BUZZER::Init();
    LCD::Init();
    BLUETOOTH::Init();
    DC_MOTOR::Init();
}

void loop() {
    BLUETOOTH::Read();
}
