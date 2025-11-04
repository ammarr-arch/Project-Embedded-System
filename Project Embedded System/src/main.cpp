#include "submain.h"

void setup() {
  #if USE_SERIAL
    Serial.begin(SERIAL_BAUD);
    delay(2000);
    Serial.println(F("=== System Booting ==="));
  #endif

  // Init sensor DHT
  #if USE_SENSOR_DHT
    initSensorDHT(SENSOR_DHT_PIN);
    #if USE_SERIAL
      Serial.println(F("DHT Sensor initialized"));
    #endif
  #endif

  // Init sensor LDR
  #if USE_SENSOR_LDR
    initSensorLDR(SENSOR_LDR_PIN);
    #if USE_SERIAL
      Serial.println(F("LDR Sensor initialized"));
    #endif
  #endif

  // Init WiFi + Web Dashboard
  #if USE_WIFI
    initWiFi(WIFI_SSID, WIFI_PASS);
    initWebDashboard();
    #if USE_SERIAL
      Serial.println(F("WiFi + Web Dashboard initialized"));
    #endif
  #endif
}

void loop() {
  // Baca sensor DHT
  #if USE_SENSOR_DHT
    readSensorDHT();
  #endif

  // Baca sensor LDR
  #if USE_SENSOR_LDR
    readSensorLDR();
  #endif

  // Tampilkan di Serial
  showDashboard();

  // Jika ada WiFi → update web dashboard
  #if USE_WIFI
    handleWebDashboard();
  #endif

  delay(2000); // sampling interval
}


