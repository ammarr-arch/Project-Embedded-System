Project/
├── platformio.ini
└── src/
    ├── main.cpp
    ├── submain.h
    ├── config/
    │   ├── config_requirement.h   ; hanya ini yang diedit user
    │   └── config.h               ; wrapper + validasi
    ├── modules/
    |   ├── cloud_iot
    |   |   ├── module_cloudiot.cpp
    │   │   └── module_cloudiot.h
    |   ├── waterleak
    |   |   ├── module_sensor_waterleak.cpp
    │   │   └── module_sensro_waterleak.h
    |   ├── buzzer
    |   |   ├── module_buzzer.cpp
    │   │   └── module_buzzer.h
    │   ├── sensor_DHT/
    │   │   ├── module_sensor_DHT.cpp
    │   │   └── module_sensor_DHT.h
    │   ├── sensor_LDR/
    │   │   ├── module_sensor_LDR.cpp
    │   │   └── module_sensor_LDR.h
    |   ├── sensor_LM35
    |   |   ├── module_sensor_LM35.cpp
    │   │   └── module_sensor_LM35.h
    |   ├── sensor_PZEM
    |   |   ├── modules_sensor_PZEM.cpp
    │   │   └── modules_sensor_PZEM.h
    |   ├── led
    |   |   ├── module_LED.cpp
    │   │   └── module_LED.h
    |   ├── lcd
    |   |   ├── module_LCD.cpp
    │   │   └── module_LCD.h
    |   ├── relay
    |   |   ├── module_relay.cpp
    │   │   └── module_relay.h
    |   ├── rfid
    |   |   ├── module_SD.cpp
    │   │   └── module_SD.h
    |   ├── sd
    |   |   ├── module_SD.cpp
    │   │   └── module_SD.h
    │   ├── wifi/
    │   │   ├── module_wifi.cpp
    │   │   └── module_wifi.h
    │   └── serial/
    │   │   ├── module_serial.cpp
    │   │   └── module_serial.h
    │   └── data/
    │   │   ├── module_data.cpp
    │   │   └── module_data.h
    │   └── dashboard/
    │       ├── module_dashboard_web.cpp
    │       ├── module_dashboard_web.h
    │       ├── module_dashboard.cpp
    │       └── module_dashboard.h