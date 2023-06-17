#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

#include <SoftwareSerial.h>

// Addr: 20:4:320b7f
// Name: DIT_Junior_Camp
// UART Baud rate: 38400

namespace BLUETOOTH {
extern SoftwareSerial BT;
extern String angle;
extern String strength;
extern String button;

void Init();
void AT_Mode();
void Setup_Mode();
void Read();

void Check_Basic_Info(SoftwareSerial *BT_AT_Mode);
void Check_Connection(SoftwareSerial *BT_AT_Mode);

}  // namespace BLUETOOTH

#endif