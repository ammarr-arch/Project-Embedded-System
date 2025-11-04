#include <Arduino.h>
#include "module_sensor_LDR.h"
#include "config/config.h"

#if USE_SENSOR_LDR
  static int ldrPin = SENSOR_LDR_PIN;  // simpan pin global
#endif

void initSensorLDR(int pin)
{
#if USE_SENSOR_LDR
    ldrPin = pin;
    pinMode(ldrPin, INPUT);
#endif
}

void readSensorLDR()
{
#if USE_SENSOR_LDR
    int val = analogRead(ldrPin);
    Serial.print("LDR -> ");
    Serial.println(val);
#endif
}

int getLightLevel()
{
#if USE_SENSOR_LDR
    return analogRead(ldrPin);
#else
    return -1;  // default jika sensor tidak aktif
#endif
}
