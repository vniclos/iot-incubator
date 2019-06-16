#ifndef _WEB_HANDLE_H
#define _WEB_HANDLE_H
#include "_defines.h"
#include "web_root.h"
#include "web_js.h"
#include "web_css.h"
#include "_extern.h"
//=================================================
void handleROOT() {
  // Serial.println("handleROOT");
  digitalWrite(LED_BUILTIN, 1);
  Serial.println(" --------------------Serial quita fncConfigLineUpdate()");
  
  g_server.send(200, "text/html", g_HTML_Web_root);
  digitalWrite(LED_BUILTIN, 0);
}
//=================================================
void handleJS() {
  // Serial.println("handleJS");
  digitalWrite(LED_BUILTIN, 1);
  g_server.send(200, "application/javascript", g_HTML_Web_JS);
  digitalWrite(LED_BUILTIN, 0);
}
void handleCSS() {
   Serial.println("handleCSS");
  digitalWrite(LED_BUILTIN, 1);
  g_server.send(200, "text/css", g_HTML_Web_CSS);
  digitalWrite(LED_BUILTIN, 0);
}

String fncHtmlRefreshRelay(unsigned int Irelay)
{
  String szColor = "";
  String szStatus = "";
  String szCommands = "";
  szStatus=" "+String(Irelay)+" ";
  if (g_Mod_Act_Relay[Irelay].fncGetSts() == RELAY_ON)
  {
    szColor = "green";
    szStatus += "ON";
  }
  else
  {
    szColor = "gray";
    szStatus = +"OFF";
  }
  szCommands += "\n<div class=\"circle " + szColor + "\">" + szStatus + "</div>&nbsp;";

  // szCommands += "\n<a class=\"button\" href=\"relayset?id=" + String(Irelay) + "&value=1\">on</a>";
  // szCommands += "\n<a  class=\"button\"  href=\"relayset?id=" + String(Irelay) + "&value=0\">off</a></p>";

  return szCommands;
}
//==============================================
String   fncHtml_buildRefresh()
{
   String szReply = "";
  //String szReply = "<!DOCTYPE html><<html lang=\"es\">><head> <meta charset=\"UTF-8\" />";
  //szReply += "\n<h2>Testudines.org. IOT Incubator controller</h2> ";
 // szReply += "\<a  class=\"button\"  href=\"/\">Refresh</a></p>";
  szReply += "\n<fieldset><legend>Sensors:</legend>";
  szReply += "\n<b>Actual</b>";
  szReply += "\n<br/><span class=\"fldTitle\">Date = </span><span id=\"scnDate\" class=\"fldValue\"></span>";
  szReply += "\n<br/><span class=\"fldTitle\">Time = </span><span id=\"scnTime\" class=\"fldValue\"></span>";
  szReply += "\n<br/><span class=\"fldTitle\">Temperature = </span><span class=\"fldValue\">"          + String(g_Mod_Sns_DHT22.m_cTemC) + " ºC</span>";
  szReply += "\n<br/><span class=\"fldTitle\">Humdidity =</span><span class=\"fldValue\">"              + String(g_Mod_Sns_DHT22.m_cHum) + " %</span>";
  szReply += "\n<br/><br/><b>Programmed temperature</b>";
  szReply += "\n<br/><span class=\"fldTitle\">Average =</span><span class=\"fldValue\">"  + String(g_prg_temperature)     + " ºC</span>";
  szReply += "\n<br/><span class=\"fldTitle\">Hysteresis =</span><span class=\"fldValue\">"   + String(g_prg_Hysteresis) + " ºC</span>";
  szReply += "\n<br/><span class=\"fldTitle\">Minimum =</span><span class=\"fldValue\">"   + String(g_prg_temperature_min) + " ºC </span>";
  szReply += "\n<br/><span class=\"fldTitle\">Maximum =</span><span class=\"fldValue\">"  + String(g_prg_temperature_max) + " ºC</span>";
  szReply += "\n</fieldset>";
  szReply += "\n<fieldset><legend>Heaters:</legend>";
  for (int i = 0; i < 4; i++)
  {
    szReply += fncHtmlRefreshRelay(i);
  }
  szReply += "\n</fieldset>";
 // szReply += "\n</body></html>";
  return szReply;
}

void handleRefresh() {
  digitalWrite(LED_BUILTIN, 1);
  g_server.send(200, "text/html", fncHtml_buildRefresh());
  digitalWrite(LED_BUILTIN, 0);
}

void handleNotFound() {
  digitalWrite(LED_BUILTIN, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += g_server.uri();
  message += "\nMethod: ";
  message += (g_server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += g_server.args();
  message += "\n";
  for (uint8_t i = 0; i < g_server.args(); i++) {
    message += " " + g_server.argName(i) + ": " + g_server.arg(i) + "\n";
  }
  g_server.send(404, "text/plain", message);
  digitalWrite(LED_BUILTIN, 0);
}
//====================================
// web temperature set
//====================================
void handleTempSet() {
  digitalWrite(LED_BUILTIN, 1);
  String sTemp = g_server.arg("t");
  g_prg_temperature = sTemp.toFloat();
  g_server.send(200, "text/html", "ok");
  digitalWrite(LED_BUILTIN, 0);
}
//====================================
// web relay set
//====================================
void handleRelaySet()
{
  digitalWrite(LED_BUILTIN, 1);
  String szRelayId = g_server.arg("id");
  String szRelayValue = g_server.arg("value");
  unsigned short usRelayId = szRelayId.toInt();
  unsigned short usRelayValue = szRelayValue.toInt();
  Serial.println("Recibido");
  Serial.println("fncWeb_handleRelaySet id=" + szRelayId + " value " + szRelayValue);
  g_Mod_Act_Relay[usRelayId].fncSetSts(usRelayValue);
  g_server.send(200, "text/html", fncHtml_buildPage());
  digitalWrite(LED_BUILTIN, 0);

}
#endif
