Project/
├── platformio.ini
└── src/
    ├── main.cpp
    ├── submain.h
    ├── config/
    │   ├── config_requirement.h   ; hanya ini yang diedit user
    │   └── config.h               ; wrapper + validasi
    ├── modules/
    │   ├── sensor_DHT/
    │   │   ├── module_sensor_DHT.cpp
    │   │   └── module_sensor_DHT.h
    │   ├── sensor_LDR/
    │   │   ├── module_sensor_LDR.cpp
    │   │   └── module_sensor_LDR.h
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