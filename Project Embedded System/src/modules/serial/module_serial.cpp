#include <Arduino.h>
#include "module_serial.h"
#include "config/config.h"

void initSerial(int baud)
{
#if USE_SERIAL
    Serial.begin(baud);
#endif
}
