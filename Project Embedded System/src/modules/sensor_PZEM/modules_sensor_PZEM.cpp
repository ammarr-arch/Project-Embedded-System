#include "module_sensor_PZEM.h"
#include <PZEM004Tv30.h>
#include "config/config.h"
#if defined(TARGET_ESP32)
  HardwareSerial PZEMSerial(2);
  PZEM004Tv30 pzem(PZEMSerial, PZEM_RX_PIN, PZEM_TX_PIN, 0xF8); 
  // 0xF8 = alamat default PZEM004T, bisa diganti kalau kamu ubah alamatnya
#elif defined(TARGET_UNO) || defined(TARGET_NANO)
  #include <SoftwareSerial.h>
  SoftwareSerial pzemSW(PZEM_RX_PIN, PZEM_TX_PIN);
  PZEM004Tv30 pzem(pzemSW);
#else
  #error "Board target belum didefinisikan untuk sensor PZEM!"
#endif


void setupSensor() {
  #if USE_SERIAL
    Serial.begin(115200);
    Serial.println(F("PZEM sensor initialized"));
  #endif

  #if defined(TARGET_ESP32)
    // Inisialisasi UART untuk komunikasi ke PZEM
    PZEMSerial.begin(9600, SERIAL_8N1, PZEM_RX_PIN, PZEM_TX_PIN);
  #endif
}


void readSensor(float &v, float &i, float &p, float &e, float &pf) {
  v  = pzem.voltage();
  i  = pzem.current();
  p  = pzem.power();
  e  = pzem.energy();
  pf = pzem.pf();

  if (isnan(v))  v  = 0;
  if (isnan(i))  i  = 0;
  if (isnan(p))  p  = 0;
  if (isnan(e))  e  = 0;
  if (isnan(pf)) pf = 0;
}
