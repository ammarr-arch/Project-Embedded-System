#include "config/config.h"

#if USE_WIFI
#include "../data/module_data.h"  // ambil JSON builder
#include <WiFi.h>                 // library ESP32
#include <HTTPClient.h>
static bool wifiConnected = false;  // ✅ tambahkan global flag

void initWiFi(const char* ssid, const char* pass) {
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");

  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    wifiConnected = false;
    Serial.println("\nWiFi connection failed!");
  }
}

bool sendDataToServer(const char* serverUrl) {
  if (!wifiConnected || WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected, cannot send data.");
    return false;
  }

  String payload = buildSensorJSON();

  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(payload);

  #if USE_SERIAL
    Serial.print("Sent JSON: ");
    Serial.println(payload);
    Serial.print("Response: ");
    Serial.println(httpResponseCode);
  #endif

  http.end();
  return (httpResponseCode > 0 && httpResponseCode < 400);
}

#endif  // USE_WIFI
