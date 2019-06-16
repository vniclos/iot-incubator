//------------------------------------------
//web_setup.h
//configure web url with events handlers
//and start web service
//------------------------------------------
#ifndef WEBSETUP_H
#define WEBSETUP_H
#include "_defines.h"
#include "web_root.h"
#include "web_js.h"
#include "web_css.h"
#include "web_handle.h"
#include "_extern.h"




extern ESP8266WebServer g_server;
void fnc_Web_Setup() {
  Serial.println("fnc_Web_Setup in");
  g_server.on("/", handleROOT);
  g_server.on("/js.js", handleJS);
  g_server.on("/css.css", handleCSS);
  g_server.on("/refresh", handleRefresh);
  g_server.onNotFound(handleNotFound);
  g_server.begin();
  Serial.println("fnc_Web_Setup out");
}
#endif
