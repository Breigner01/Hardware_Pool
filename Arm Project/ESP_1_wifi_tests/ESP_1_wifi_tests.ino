#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32_Server";
const char* password = "Over9000";

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);
  Serial.println();
  
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  bool status;

  server.begin();

  server.on("/hand", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "coucou hand");
  });

  server.on("/middle", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "coucou middle");
  });

  server.on("/base", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "coucou base");
  });

  server.on("/orientation", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "coucou orientation");
  });
}
 
void loop()
{
  
}
