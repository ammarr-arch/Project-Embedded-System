#include <Arduino.h>
#include "config/config.h"

#if USE_SENSOR_DHT
  #include <DHT.h>
  #include "module_sensor_DHT.h"

  static DHT dht(SENSOR_DHT_PIN, DHT_TYPE);  // hanya aktif kalau DHT dipakai
  static float lastTemp = NAN;
  static float lastHum = NAN;

  void initSensorDHT(int pin) {
    dht.begin();
    #if USE_SERIAL
      Serial.println(F("DHT sensor initialized"));
    #endif
  }

  void readSensorDHT() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h) && !isnan(t)) {
      lastHum = h;
      lastTemp = t;
    }

    #if USE_SERIAL
      if (isnan(t) || isnan(h)) {
        Serial.println(F("DHT read failed"));
      } else {
        Serial.print(F("DHT -> Temp: "));
        Serial.print(t);
        Serial.print(F(" *C  Hum: "));
        Serial.println(h);
      }
    #endif
  }

  float getTemperature() { return lastTemp; }
  float getHumidity()    { return lastHum; }

#else
  // Dummy jika sensor tidak dipakai
  void initSensorDHT(int pin) {}
  void readSensorDHT() {}
  float getTemperature() { return -1; }
  float getHumidity()    { return -1; }
#endif
