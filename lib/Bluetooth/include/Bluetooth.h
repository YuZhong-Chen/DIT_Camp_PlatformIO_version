#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

#include <SoftwareSerial.h>

namespace BLUETOOTH {
extern SoftwareSerial BT;

void Init();
void AT_Mode();
}  // namespace BLUETOOTH

#endif