#include "config/config.h"

#if USE_WIFI   // ✅ hanya compile kalau WiFi dipakai

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "module_dashboard_web.h"
#include "../data/module_data.h"
#include "../wifi/module_wifi.h"

#if USE_WIFI

// WebServer ESP32 di port 80
static WebServer server(80);

static String buildHtmlPage() {
  String page = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  page += "<title>ESP32 Sensor Dashboard</title>";
  page += "<style>body{font-family:Arial;text-align:center;} .card{border:1px solid #ccc;padding:20px;margin:20px;border-radius:10px;display:inline-block;}</style>";
  page += "<script>async function refreshData(){let res=await fetch('/data');let json=await res.json();document.getElementById('temp').innerText=json.temperature;document.getElementById('hum').innerText=json.humidity; if(json.light!==undefined){document.getElementById('light').innerText=json.light;} setTimeout(refreshData,2000);} window.onload=refreshData;</script>";
  page += "</head><body><h1>ESP32 Sensor Dashboard</h1>";
  page += "<div class='card'><h2>Temperature</h2><p><span id='temp'>--</span> °C</p></div>";
  page += "<div class='card'><h2>Humidity</h2><p><span id='hum'>--</span> %</p></div>";
  #if USE_SENSOR_LDR
  page += "<div class='card'><h2>Light</h2><p><span id='light'>--</span></p></div>";
  #endif
  page += "</body></html>";
  return page;
}

void initWebDashboard() {
  server.on("/", []() {
    server.send(200, "text/html", buildHtmlPage());
  });

  server.on("/data", []() {
    String json = buildSensorJSON();
    server.send(200, "application/json", json);
  });

  server.begin();
  #if USE_SERIAL
    Serial.println("Web Dashboard started at http://" + WiFi.localIP().toString());
  #endif
}

void handleWebDashboard() {
  server.handleClient();
}

#endif

#endif  // USE_WIFI