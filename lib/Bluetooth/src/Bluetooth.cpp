// Arduino
#include <Arduino.h>

// Includes
#include "Bluetooth.h"
#include "LCD.h"

// Bluetooth Pin
#define BLUETOOTH_RX_PIN 6
#define BLUETOOTH_TX_PIN 7

namespace BLUETOOTH {

int SERIAL_BAUD_RATE = 9600;
int BLUETOOTH_BAUD_RATE = 115200;

SoftwareSerial BT(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

void Init() {
    BT.begin(BLUETOOTH_BAUD_RATE);
}

// NOTE: This function will not return.
void AT_Mode() {
    SoftwareSerial BT_AT_Mode(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

    Serial.begin(SERIAL_BAUD_RATE);
    BT_AT_Mode.begin(BLUETOOTH_BAUD_RATE);

    char Data;
    Serial.println("Start AT mode");

    while (true) {
        // Read data from Serial port.
        if (Serial.available()) {
            Data = Serial.read();
            BT_AT_Mode.print(Data);
        }

        // Read data from Bluetooth.
        if (BT_AT_Mode.available()) {
            Data = BT_AT_Mode.read();
            Serial.print(Data);
        }
    }
}

void Check_Connection(SoftwareSerial *BT_AT_Mode) {
    int RetryDelay = 0;
    int RetryCount = 0;

    while (BT_AT_Mode->available()) {
        BT_AT_Mode->readString();
    }

    // Check Connection
    RetryDelay = RetryCount = 0;
    BT_AT_Mode->write("AT\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            if (ReceiveData.substring(0, 2) == "OK") {
                Serial.println("Connection Success.");
                break;
            }
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to connect bluetooth module. Retry ...");
            RetryCount++;
            if (RetryCount == 6) {
                Serial.println("Change baud rate to 38400.");
                BLUETOOTH_BAUD_RATE = 38400;
                BT_AT_Mode->begin(BLUETOOTH_BAUD_RATE);
                delay(100);
                BT_AT_Mode->write("AT\r\n");
                RetryDelay = 0;
                RetryCount = 0;
            } else if (RetryCount == 3) {
                Serial.println("Change baud rate to 115200.");
                BLUETOOTH_BAUD_RATE = 115200;
                BT_AT_Mode->begin(BLUETOOTH_BAUD_RATE);
                delay(100);
                BT_AT_Mode->write("AT\r\n");
                RetryDelay = 0;
            } else {
                BT_AT_Mode->write("AT\r\n");
                RetryDelay = 0;
            }
        }

        delay(1);
    }
}

void Check_Basic_Info(SoftwareSerial *BT_AT_Mode) {
    int RetryDelay = 0;

    while (BT_AT_Mode->available()) {
        BT_AT_Mode->readString();
    }

    // Check Basic Info
    Serial.println("");
    Serial.println("Check bluetooth module info.");

    // NAME
    RetryDelay = 0;
    BT_AT_Mode->write("AT+NAME?\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            for (int i = 1; i < ReceiveData.length(); i++) {
                if (ReceiveData[i] != '\n') {
                    Serial.print(ReceiveData[i]);
                } else {
                    break;
                }
            }
            break;
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to get NAME info. Retry ...");
            BT_AT_Mode->write("AT+NAME?\r\n");
            RetryDelay = 0;
        }

        delay(1);
    }

    // UART
    RetryDelay = 0;
    BT_AT_Mode->write("AT+UART?\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            for (int i = 1; i < ReceiveData.length(); i++) {
                if (ReceiveData[i] != '\n') {
                    Serial.print(ReceiveData[i]);
                } else {
                    break;
                }
            }
            break;
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to get UART info. Retry ...");
            BT_AT_Mode->write("AT+UART?\r\n");
            RetryDelay = 0;
        }

        delay(1);
    }

    // Address
    RetryDelay = 0;
    BT_AT_Mode->write("AT+ADDR?\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            for (int i = 1; i < ReceiveData.length(); i++) {
                if (ReceiveData[i] != '\n') {
                    Serial.print(ReceiveData[i]);
                } else {
                    break;
                }
            }
            break;
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to get ADDR info. Retry ...");
            BT_AT_Mode->write("AT+ADDR?\r\n");
            RetryDelay = 0;
        }

        delay(1);
    }

    // Role
    RetryDelay = 0;
    BT_AT_Mode->write("AT+ROLE?\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            for (int i = 1; i < ReceiveData.length(); i++) {
                if (ReceiveData[i] != '\n') {
                    Serial.print(ReceiveData[i]);
                } else {
                    break;
                }
            }
            break;
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to get ROLE info. Retry ...");
            BT_AT_Mode->write("AT+ROLE?\r\n");
            RetryDelay = 0;
        }

        delay(1);
    }

    // Password
    RetryDelay = 0;
    BT_AT_Mode->write("AT+PSWD?\r\n");
    while (true) {
        if (BT_AT_Mode->available()) {
            String ReceiveData = BT_AT_Mode->readString();
            for (int i = 1; i < ReceiveData.length(); i++) {
                if (ReceiveData[i] != '\n') {
                    Serial.print(ReceiveData[i]);
                } else {
                    break;
                }
            }
            break;
        } else if (++RetryDelay >= 1000) {
            Serial.println("Fail to get PSWD info. Retry ...");
            BT_AT_Mode->write("AT+PSWD?\r\n");
            RetryDelay = 0;
        }

        delay(1);
    }
}

// NOTE: This function will not return.
void Setup_Mode() {
    SoftwareSerial BT_AT_Mode(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

    Serial.begin(SERIAL_BAUD_RATE);
    BT_AT_Mode.begin(BLUETOOTH_BAUD_RATE);

    char Data;
    Serial.println("Start to Setup mode.");

    Check_Connection(&BT_AT_Mode);
    // Check_Basic_Info(&BT_AT_Mode);

    // AT Mode
    Serial.println("");
    Serial.println("--------------------------------");
    Serial.println("Start AT Mode.");
    while (true) {
        // Read data from Serial port.
        if (Serial.available()) {
            String ReceiveData = Serial.readString();
            if (ReceiveData.substring(0, 5) == "NAME ") {
                // Set Name
                String TransmitData = "AT+NAME=" + ReceiveData.substring(5) + "\r\n";
                BT_AT_Mode.write(TransmitData.c_str());
                delay(50);

                // Set UART Baud rate to 115200
                TransmitData = "AT+UART=115200,0,0\r\n";
                BT_AT_Mode.write(TransmitData.c_str());
                delay(50);

                // Set ROLE to slave mode (0)
                TransmitData = "AT+ROLE=0\r\n";
                BT_AT_Mode.write(TransmitData.c_str());
                delay(50);

                // Set Password to Name
                TransmitData = "AT+PSWD=\"" + ReceiveData.substring(5) + "\"\r\n";
                BT_AT_Mode.write(TransmitData.c_str());
                delay(50);

                TransmitData = "Set Name to " + ReceiveData.substring(5);
                Serial.println(TransmitData.c_str());
                delay(50);

                // Check Info
                Check_Basic_Info(&BT_AT_Mode);
                delay(100);

                Serial.println("--------------------------------");

            } else if (ReceiveData.substring(0, 5) == "CHECK") {
                Check_Basic_Info(&BT_AT_Mode);
                delay(100);

                Serial.println("--------------------------------");
            } else if (ReceiveData.substring(0, 2) == "AT") {
                String TransmitData = ReceiveData;

                for (int i = 0; i < ReceiveData.length(); i++) {
                    if (ReceiveData[i] != '\r' || ReceiveData != '\n') {
                        TransmitData[i] = ReceiveData[i];
                    } else {
                        break;
                    }
                }

                TransmitData = TransmitData + "\r\n";
                BT_AT_Mode.write(TransmitData.c_str());

                while (true) {
                    if (BT_AT_Mode.available()) {
                        ReceiveData = BT_AT_Mode.readString();
                        Serial.print(ReceiveData.c_str());
                        break;
                    } else if (Serial.available()) {
                        while (Serial.available()) {
                            ReceiveData = Serial.readString();
                        }
                        break;
                    }
                }

                Serial.println("--------------------------------");
            }
        }

        // Read data from Bluetooth.
        if (BT_AT_Mode.available()) {
            Data = BT_AT_Mode.read();
            Serial.print(Data);
        }
    }
}

void ReadBluetooth() {
    SoftwareSerial BT_Mode(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

    Serial.begin(SERIAL_BAUD_RATE);
    BT_Mode.begin(BLUETOOTH_BAUD_RATE);

    char data;

    while (true) {
        if (BT_Mode.available()) {
            data = BT_Mode.read();
            Serial.print(data);
        }
    }
}

String angle;
String strength;
String button;

void Read() {
    if (BT.available()) {
        String value = BT.readStringUntil('#');

        if (value.length() == 7) {
            angle = value.substring(0, 3);
            strength = value.substring(3, 6);
            button = value.substring(6, 8);

            LCD::print(button);
        }
        BT.flush();
    }
}

/**
 * Because ios doesn't support Bluetooth 2.1 or below,
 * so you need to replace HC-05 with HM-10.
 *
 * You can download the app from apple's app store, called "ArduinoBlue".
 * Be careful, don't download the V2 version, it may not work.
 *
 */
void ReadDataFromHM10() {
    SoftwareSerial HM10(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

    Serial.begin(SERIAL_BAUD_RATE);
    HM10.begin(BLUETOOTH_BAUD_RATE);

    uint8_t input;

    int inputLength = 2;
    int inputSignal[inputLength] = {0};
    int currentInputLength = -1;
    bool isStartDrive = false;
    bool isStartButton = false;

    while (true) {
        if (HM10.available()) {
            input = HM10.read();

            if (input == 251) {
                isStartDrive = true;
            } else if (input == 252) {
                isStartButton = true;
            } else if (input == 250) {
                if (isStartDrive) {
                    // throttle
                    Serial.print(map(abs(inputSignal[0]), 0, 50, 0, 100));
                    Serial.print(" ");

                    // steering
                    if (inputSignal[0] == 0) {
                        Serial.print("0");
                        Serial.println("");
                    } else if (inputSignal[0] >= 0) {
                        if (inputSignal[1] >= 0) {
                            Serial.print(map(50 - abs(inputSignal[1]), 0, 50, 0, 90));
                            Serial.println("");
                        } else {
                            Serial.print(map(abs(inputSignal[1]), 0, 50, 90, 180));
                            Serial.println("");
                        }
                    } else {
                        if (inputSignal[1] >= 0) {
                            Serial.print(map(abs(inputSignal[1]), 0, 50, 270, 360));
                            Serial.println("");
                        } else {
                            Serial.print(map(50 - abs(inputSignal[1]), 0, 50, 180, 270));
                            Serial.println("");
                        }
                    }

                    currentInputLength = -1;
                    isStartDrive = false;
                } else if (isStartButton) {
                    Serial.print(inputSignal[0]);
                    Serial.println("");

                    currentInputLength = -1;
                    isStartButton = false;
                }
            } else if (isStartDrive || isStartButton) {
                if (currentInputLength + 1 < inputLength) {
                    // Sometime, ArduinoBlue will set the sign bit to 1, so check the value of data.
                    // If it happens, directly set the sign bit to 0, and you will get the correct data.
                    if (isStartDrive && abs(input - 49) > 50) {
                        input = input % 128;
                    }
                    inputSignal[++currentInputLength] = (isStartDrive) ? input - 49 : input;
                }
            }
        }
    }
}

}  // namespace BLUETOOTH
