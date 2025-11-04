#pragma once

#include <ArduinoJson.h>

// Inisialisasi WiFi
void initWiFi(const char* ssid, const char* password);

// Kirim data ke server (POST JSON)
bool sendDataToServer(const char* serverUrl);

// Getter status koneksi
bool isWiFiConnected();
