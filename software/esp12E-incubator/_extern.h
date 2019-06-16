#ifndef _EXTERN_H
#define _EXTERN_H
extern  ESP8266WebServer g_server;
extern float g_prg_temperature ;
extern float g_prg_Hysteresis ;
extern float g_prg_temperature_min ;
extern float g_prg_temperature_max ;
extern ClsMod_Sns_DHT22 g_Mod_Sns_DHT22;
extern ClsMod_Act_Relay g_Mod_Act_Relay[4];
extern void handleROOT();
extern void handleJS();
extern void handleCSS();
extern void handleNotFound();
//extern String fncHtmlRefreshRelay(unsigned int Irelay);
extern  void fncWeb_handleRefresh();
extern String fncHtml_buildPage();


#endif
