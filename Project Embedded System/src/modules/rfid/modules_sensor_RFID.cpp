#include "modules_sensor_RFID.h"

RFIDHandler::RFIDHandler()
  : rfid(RFID_SS_PIN, RFID_RST_PIN), ledState(false) {}

void RFIDHandler::begin() {
  SPI.begin();
  rfid.PCD_Init();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println(F("RFID siap digunakan."));
}

bool RFIDHandler::checkCard() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return false;
  }
  return true;
}

String RFIDHandler::readUID() {
  String uidString = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uidString += "0";
    uidString += String(rfid.uid.uidByte[i], HEX);
  }
  uidString.toUpperCase();
  rfid.PICC_HaltA();  // Hentikan komunikasi
  return uidString;
}

void RFIDHandler::blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(150);
  }
}