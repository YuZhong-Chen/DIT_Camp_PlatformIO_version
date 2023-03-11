// Arduino Library
#include <Arduino.h>

// Other Library
#include "Bluetooth.h"

// *************** Global Variable ***************

void setup() {
    Serial.begin(9600);

    BLUETOOTH::Init();

    BLUETOOTH::AT_Mode();
}

void loop() {
}