// Arduino
#include <Arduino.h>

// Includes
#include "Bluetooth.h"
#include "LCD.h"

// Bluetooth Pin
#define BLUETOOTH_RX_PIN 0
#define BLUETOOTH_TX_PIN 1

namespace BLUETOOTH {

SoftwareSerial BT(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

void Init() {
    BT.begin(38400);
}

// NOTE: This function will not return.
void AT_Mode() {
    SoftwareSerial BT_AT_Mode(8, 9);
    char Data;
    LCD::println("Start AT mode");

    while (true) {
        // Read data from Serial port.
        if (Serial.available()) {
            Data = Serial.read();
            BT_AT_Mode.print(Data);
        }

        // Read data from Bluetooth.
        if (BT_AT_Mode.available()) {
            Data = BT_AT_Mode.read();
            LCD::print(Data);
        }
    }
}

void Read() {
    if (BT.available()) {
        String value = BT.readStringUntil('#');

        if (value.length() == 7) {
            String angle = value.substring(0, 3);
            String strength = value.substring(3, 6);
            String button = value.substring(6, 8);

            LCD::print(angle);
        }
        BT.flush();
    }
}

}  // namespace BLUETOOTH
