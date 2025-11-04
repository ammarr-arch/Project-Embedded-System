#include <Arduino.h>
#include "module_dashboard.h"
#include "config/config.h"

#if USE_SENSOR_DHT
  #include "modules/sensor_DHT/module_sensor_DHT.h"
#endif

#if USE_SENSOR_LDR
  #include "modules/sensor_LDR/module_sensor_LDR.h"
#endif

#if USE_SENSOR_LM35
  #include "modules/sensor_LM35/module_sensor_LM35.h"    
#endif

void showDashboard() {
  #if USE_SERIAL
    Serial.println(F("===== Dashboard ====="));

    // --- DHT Sensor (Temp & Humidity) ---
    #if USE_SENSOR_DHT
      Serial.print(F("Temp (DHT): "));
      Serial.print(getTemperature());
      Serial.print(F(" °C, Hum: "));
      Serial.print(getHumidity());
      Serial.println(F(" %"));
    #else
      Serial.println(F("DHT: null"));
    #endif

    // --- LDR Sensor (Light Intensity) ---
    #if USE_SENSOR_LDR
      Serial.print(F("Light (LDR): "));
      Serial.println(getLightLevel());
    #else
      Serial.println(F("Light: null"));
    #endif

    // --- LM35 Sensor (Analog Temperature) ---
    #if USE_SENSOR_LM35
      Serial.print(F("Temp (LM35): "));
      Serial.print(getTemperatureLM35());
      Serial.println(F(" °C"));
    #else
      Serial.println(F("LM35: null"));
    #endif

    Serial.println(F("======================"));
  #endif
}
