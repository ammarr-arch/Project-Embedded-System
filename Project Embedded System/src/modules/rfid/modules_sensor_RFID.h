#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

// ========================
// Pin Configuration (gunakan dari config_requirement.h jika ada)
// ========================
#ifndef RFID_SS_PIN
  #define RFID_SS_PIN  5    // pin SDA / SS RFID
#endif

#ifndef RFID_RST_PIN
  #define RFID_RST_PIN 22   // pin RST RFID
#endif

#ifndef LED_PIN
  #define LED_PIN 2         // pin LED indikator
#endif

// ========================
// Kelas RFIDHandler
// ========================
class RFIDHandler {
public:
  RFIDHandler();

  void begin();            // Inisialisasi RFID dan LED
  bool checkCard();        // Mengecek apakah kartu baru terdeteksi
  String readUID();        // Membaca UID kartu
  void blinkLED(int times); // Menyalakan LED untuk notifikasi

private:
  MFRC522 rfid;
  bool ledState;
};