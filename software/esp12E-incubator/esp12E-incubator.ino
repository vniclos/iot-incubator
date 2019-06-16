// =========================
// TESTUDINES.IOT
// INCUBATOR CONTROLLER PROJECT IOT
// Vicente Niclos
// ---------------------------------------------
#include "_defines.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <ESP8266mDNS.h>
#include "ClsMod_SNS_DHT22.h"
#include "ClsMod_Act_Relay.h"

#include "web_root.h"
#include "web_js.h"
#include "web_css.h"
#include "web_handle.h"
#include "web_setup.h"

//================================================================
// CHANGE THIS VALUES FOR YOUR NEEDS
//================================================================
float g_prg_temperature = 31.0f;             // your incubation temp
float g_prg_Hysteresis = 1.0f;               // 1ºC more or less (good live for relays),
const char* g_WiFiSsid = "testudines";       // name of your wifi
const char* g_WiFiPassword = "915265ABCD";   // password of your wifi
const char* g_hostname = "iot-incubator";
IPAddress g_NetIp(192, 168, 1, 100);
IPAddress g_NetGateway(192, 168, 1, 1);
IPAddress g_NetSubnet(255, 255, 255, 0);
//================================================================


ESP8266WebServer g_server(80);
unsigned int g_SetRelay = 0;
unsigned long g_interval_now = 0;
float g_prg_temperature_min = g_prg_temperature - g_prg_Hysteresis;
float g_prg_temperature_max = g_prg_temperature + g_prg_Hysteresis;
ClsMod_Sns_DHT22 g_Mod_Sns_DHT22;
//=====================================
//
//====================================
ClsMod_Act_Relay g_Mod_Act_Relay[4];

//===================================
// Web reply for http://vivivarium.local
//===================================




//===================================
// Set Config service wifi
//===================================
//
void fncSetupWifi()
{
  Serial.println("fncSetupWifi");
  WiFi.mode(WIFI_STA);

  WiFi.hostname(g_hostname);
  WiFi.begin(g_WiFiSsid, g_WiFiPassword);

  WiFi.config(g_NetIp, g_NetGateway, g_NetSubnet);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(g_WiFiSsid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
//===================================
// Set Config service MDNS
//===================================
void fncSetupMDNS()
{
  Serial.println("fncSetupMDNS");
  if (MDNS.begin(g_hostname)) {
    Serial.println("MDNS responder started at");
    Serial.println("http://" + String(g_hostname) + ".local");
  }
  MDNS.addService("http", "tcp", 80);
}
//===================================
// Set Config service web
//===================================

//===================================
// Set Config of services
//===================================
void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  Serial.println("Setup");
  fncSetupWifi();
  fncSetupMDNS();
  fnc_Web_Setup();
  g_interval_now = millis();
  g_Mod_Sns_DHT22.loop(g_interval_now);


  g_Mod_Act_Relay[0].setup(MOD_PIN_RELE_0, 0);
  g_Mod_Act_Relay[1].setup(MOD_PIN_RELE_1, 1);
  g_Mod_Act_Relay[2].setup(MOD_PIN_RELE_2, 2);
  g_Mod_Act_Relay[3].setup(MOD_PIN_RELE_3, 3);
  /*
    for (int i=0;i<4;i++)
    {

    g_Mod_Act_Relay[i].fncSetSts(RELAY_ON);

    delay(10000);
    }
  */
  for (int i = 0; i < 4; i++)
  {
    g_Mod_Act_Relay[i].fncSetSts(RELAY_OFF);


  }


}

void loop(void) {
  g_server.handleClient();

  g_interval_now = millis();

  g_Mod_Sns_DHT22.loop(g_interval_now);

  for (int i = 0; i < 4; i++)
  {
    //   g_prg_temperature_max
    g_Mod_Act_Relay[i].loop(g_interval_now, g_Mod_Sns_DHT22.m_fTempC, g_prg_temperature_min, g_prg_temperature_max);
  }

}
