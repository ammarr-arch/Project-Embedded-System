#include "config/config_requirement.h"

#if USE_SD
#include <SD.h>

static File logFile;

void setupLogging() {
  if (!SD.begin(SD_CS_PIN)) {
    #if USE_SERIAL
      Serial.println(F("SD Card init failed!"));
    #endif
    return;
  }

  #if USE_SERIAL
    Serial.println(F("SD Card initialized."));
  #endif

  // Buat header kalau file belum ada
  if (!SD.exists("/log.csv")) {
    logFile = SD.open("/log.csv", FILE_WRITE);
    if (logFile) {
      logFile.println(F("timestamp_s,voltage_V,current_A,power_W,energy_kWh,pf"));
      logFile.close();
    }
  }
}

void logToSD(float v, float i, float p, float e, float pf) {
  logFile = SD.open("/log.csv", FILE_WRITE);

  if (logFile) {
    unsigned long t = millis() / 1000;

    // tulis baris CSV
    logFile.print(t); logFile.print(",");
    logFile.print(v, 1); logFile.print(",");
    logFile.print(i, 2); logFile.print(",");
    logFile.print(p, 0); logFile.print(",");
    logFile.print(e, 2); logFile.print(",");
    logFile.println(pf, 2);

    logFile.close();
  } else {
    #if USE_SERIAL
      Serial.println(F("Failed to open log.csv"));
    #endif
  }
}

#endif   // <=== ini penting! penutup untuk #if USE_SD