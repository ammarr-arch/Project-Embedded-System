#include "submain.h"
#include <SPI.h>
#include <MFRC522.h>
#include <PZEM004Tv30.h>
#include <LiquidCrystal_I2C.h>
#define SS_PIN  21
#define RST_PIN 22
MFRC522 rfid(SS_PIN, RST_PIN);
float suhuLM35 = 0.0;
float suhuDHT = 0.0;
float kelembapanDHT = 0.0;
int waterValue = 0;
int ldrValue   = 0;
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
void setup() {
  #if USE_SERIAL
    Serial.begin(115200);
    delay(2000);
    Serial.println(F("=== System Booting ==="));
  #endif

  // === Init LED ===
  #if USE_LED
    initLed();
    #if USE_SERIAL
      Serial.println(F("LED initialized"));
    #endif
  #endif
  // === Init RFID ===
  #if USE_SENSOR_RFID
    rfid.PCD_Init();
    #if USE_SERIAL
      Serial.println(F("RFID module initialized"));
    #endif
  #endif

  // === Init DHT ===
  #if USE_SENSOR_DHT
    initSensorDHT(SENSOR_DHT_PIN);
    #if USE_SERIAL
      Serial.println(F("DHT Sensor initialized"));
    #endif
  #endif

  // === Init LDR ===
  #if USE_SENSOR_LDR
    initSensorLDR(SENSOR_LDR_PIN);
  #endif

  // === Init LM35 ===
  #if USE_SENSOR_LM35
    initSensorLM35(SENSOR_LM35_PIN);
    #if USE_SERIAL
      Serial.println(F("LM35 Sensor initialized"));
    #endif
  #endif

  // === Init Water Leak ===
  #if USE_SENSOR_WATERLEAK
    initSensorWaterLeak(SENSOR_WATERLEAK_PIN);
    #if USE_SERIAL
      Serial.println(F("Water Leak Sensor initialized"));
    #endif
  #endif

  // === Init Relay ===
  #if USE_RELAY
    initRelay(RELAY_PIN);
    #if USE_SERIAL
      Serial.println(F("Relay initialized"));
    #endif
  #endif

  // === Init Buzzer ===
  #if USE_BUZZER
    initBuzzer(BUZZER_PIN);
    #if USE_SERIAL
      Serial.println(F("Buzzer initialized"));
    #endif
  #endif
}

void loop() {
  // === Baca LM35 ===
  #if USE_SENSOR_LM35
    readSensorLM35();
    suhuLM35 = getTemperatureLM35();
    #if USE_SERIAL
      Serial.print(F("Suhu LM35: "));
      Serial.print(suhuLM35);
      Serial.println(F(" °C"));
    #endif
  #endif

  // === Baca DHT ===
  #if USE_SENSOR_DHT
    readSensorDHT();
    suhuDHT = getTemperature();
    kelembapanDHT = getHumidity();

    #if USE_SERIAL
      Serial.print(F("Suhu DHT: "));
      Serial.print(suhuDHT);
      Serial.print(F(" °C | Kelembapan: "));
      Serial.print(kelembapanDHT);
      Serial.println(F(" %"));
    #endif
  #endif

  // === Baca Water Leak ===
  #if USE_SENSOR_WATERLEAK
    readSensorWaterLeak();
    waterValue = getWaterLeakLevel();
    #if USE_SERIAL
      Serial.print(F("Water Level: "));
      Serial.println(waterValue);
    #endif
  #endif

  // === Logika LED & Buzzer (berdasarkan suhu DHT) ===
  #if USE_SENSOR_DHT && USE_LED && USE_BUZZER
    if (suhuDHT > 35.0) {
      ledOn();
      buzzerOn();
      #if USE_SERIAL
        Serial.println(F("🔥 Suhu tinggi (DHT)! LED & Buzzer ON"));
      #endif
    } 
    else if (suhuDHT > 30.0) {
      ledOn();
      buzzerOff();
      #if USE_SERIAL
        Serial.println(F("⚠ Suhu hangat (DHT), LED ON, Buzzer OFF"));
      #endif
    } 
    else {
      ledOff();
      buzzerOff();
      #if USE_SERIAL
        Serial.println(F("✅ Suhu normal (DHT), LED & Buzzer OFF"));
      #endif
    }
  #endif

  // === Logika Buzzer & LED (jika suhu LM35 > 40°C) ===
  #if USE_SENSOR_LM35 && (USE_BUZZER || USE_LED)
    if (suhuLM35 > 40) {
      #if USE_BUZZER
        buzzerOn();
      #endif
      #if USE_LED
        ledOn();
      #endif
      #if USE_SERIAL
        Serial.println(F("🔥 Suhu tinggi (LM35)! LED & Buzzer ON"));
      #endif
    } else if (suhuLM35 > 35) {
      #if USE_BUZZER
        buzzerOff();
      #endif
      #if USE_LED
        ledOn();
      #endif
      #if USE_SERIAL
        Serial.println(F("⚠ Suhu agak tinggi (LM35), LED ON, Buzzer OFF"));
      #endif
    } else {
      #if USE_BUZZER
        buzzerOff();
      #endif
      #if USE_LED
        ledOff();
      #endif
      #if USE_SERIAL
        Serial.println(F("✅ Suhu normal (LM35), LED & Buzzer OFF"));
      #endif
    }
  #endif

  // === Logika Relay (jika water leak terdeteksi) ===
#if USE_RELAY && USE_SENSOR_WATERLEAK
  if (waterValue > 2000) {  // threshold bisa disesuaikan
    relayOn();
    #if USE_BUZZER
      buzzerOn();
    #endif
    #if USE_SERIAL
      Serial.println(F("⚠ Air Terdeteksi! Relay ON, Buzzer ON"));
    #endif
  } else {
    relayOff();
    #if USE_BUZZER
      buzzerOff();
    #endif
    #if USE_SERIAL
      Serial.println(F("✅ Tidak ada air, Relay OFF, Buzzer OFF"));
    #endif
  }
#endif


  // === Logika LDR ===
  #if USE_SENSOR_LDR
    readSensorLDR();
    ldrValue = getLightLevel();  // Fungsi dari module_sensor_LDR.h
    #if USE_SERIAL
      Serial.print(F("LDR Value: "));
      Serial.println(ldrValue);
    #endif

    // Logika LED berdasarkan kondisi cahaya
    if (ldrValue > 3000) {  // Semakin gelap semakin tinggi nilai LDR
      #if USE_LED
        ledOn();
      #endif
      #if USE_RELAY
        relayOn();  // Opsional: Hidupkan Relay ketika gelap
      #endif
    } else {
      #if USE_LED
        ledOff();
      #endif
      #if USE_RELAY
        relayOff();
      #endif
    }
  #endif
  
  #if USE_SENSOR_RFID && USE_LED
  // Cek apakah ada kartu RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Contoh: UID kartu valid (ganti dengan UID kartu kamu)
    byte validUID[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool isValid = true;
    for (byte i = 0; i < 4; i++) {
      if (rfid.uid.uidByte[i] != validUID[i]) {
        isValid = false;
        break;
      }
    }

    if (isValid) {
      // ✅ Kartu valid
      #if USE_LED
        ledOn();
      #endif
      #if USE_SERIAL
        Serial.println(F("✅ Kartu RFID valid! LED ON"));
      #endif
    } else {
      // ⚠ Kartu tidak dikenal
      #if USE_LED
        for (int i = 0; i < 3; i++) { // LED berkedip cepat 3x
          ledOn();
          delay(150);
          ledOff();
          delay(150);
        }
      #endif
      #if USE_SERIAL
        Serial.println(F("❌ Kartu RFID tidak dikenal! LED blink"));
      #endif
    }

    // Hentikan komunikasi dengan kartu
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  } else {
    // Tidak ada kartu
    #if USE_LED
      ledOff();
    #endif
    #if USE_SERIAL
      Serial.println(F("💤 Tidak ada kartu RFID, LED OFF"));
    #endif
  }
  #endif
#if USE_SENSOR_PZEM && USE_LCD
  // --- Variabel sensor PZEM ---
  float voltage = 0.0;
  float current = 0.0;
  float power   = 0.0;
  float energy  = 0.0;
  float pf      = 0.0;

  // --- Baca sensor ---
  readSensor(voltage, current, power, energy, pf);

  // --- Tampilkan di Serial (opsional untuk debug) ---
  #if USE_SERIAL
    Serial.println(F("=== Data PZEM004T ==="));
    Serial.print(F("V: "));  Serial.print(voltage); Serial.println(F(" V"));
    Serial.print(F("I: "));  Serial.print(current); Serial.println(F(" A"));
    Serial.print(F("P: "));  Serial.print(power);   Serial.println(F(" W"));
    Serial.print(F("E: "));  Serial.print(energy);  Serial.println(F(" Wh"));
    Serial.print(F("PF: ")); Serial.println(pf);
    Serial.println();
  #endif

  // --- Tampilkan di LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:"); lcd.print(voltage, 1); lcd.print("V ");
  lcd.print("I:"); lcd.print(current, 2); lcd.print("A");

  lcd.setCursor(0, 1);
  lcd.print("P:"); lcd.print(power, 0); lcd.print("W ");
  lcd.print("PF:"); lcd.print(pf, 2);

  // --- Logika Buzzer Berdasarkan Tegangan ---
  #if USE_BUZZER
    if (voltage > 240.0) {
      buzzerOn();
      #if USE_SERIAL
        Serial.println(F("⚠️ Tegangan tinggi! Buzzer ON"));
      #endif
    } 
    else if (voltage < 180.0) {
      buzzerOn();
      #if USE_SERIAL
        Serial.println(F("✅ Tegangan rendah, Buzzer ON"));
      #endif
    }
    else if (voltage < 240 && voltage >180){
      buzzerOff();
      #if USE_SERIAL
        Serial.println(F("✅ Tegangan normal, Buzzer OFF"));
    }
  #endif

  delay(1000);  // jeda baca
#endif
#endif
  showDashboard();

  delay(2000);
}
