// Arduino
#include <Arduino.h>

// Includes
#include "Bluetooth.h"

// Bluetooth Pin
#define BLUETOOTH_RX_PIN 0
#define BLUETOOTH_TX_PIN 1

namespace BLUETOOTH {

SoftwareSerial BT(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

void Init() {
    // Baud rate need to be modified. (38400)
    BT.begin(9600);
}

// NOTE: This function will not return.
void AT_Mode() {
    char Data;

    while (true) {
        // Read data from Serial port.
        if (Serial.available()) {
            Data = Serial.read();
            BT.print(Data);
        }

        // Read data from Bluetooth.
        if (BT.available()) {
            Data = BT.read();
            Serial.print(Data);
        }
    }
}

}  // namespace BLUETOOTH
