#include "config/config_requirement.h"
#if USE_WIFI
#include <WiFi.h>
#include <HTTPClient.h>

void setupCloud(){
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  while(WiFi.status()!=WL_CONNECTED){ delay(500); Serial.print("."); }
  Serial.println("WiFi OK");
}

void sendToCloud(float v,float i,float p,float e,float pf){
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    String url=String("http://")+CLOUD_SERVER+"/update?api_key="+CLOUD_API_KEY+
               "&field1="+String(v)+"&field2="+String(i)+
               "&field3="+String(p)+"&field4="+String(e)+
               "&field5="+String(pf);
    http.begin(url); int code=http.GET();
    Serial.println(code>0?"Cloud OK":"Cloud FAIL"); http.end();
  }
}
#endif