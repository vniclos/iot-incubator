//javascripts
// validator https://jshint.com/
//https://codebeautify.org/jsviewer
#ifndef _WEB_JS_H
#define _WEB_JS_H
const char g_HTML_Web_JS[] PROGMEM = R"=====(
function fncGetHtml(pDivTarget, pURL) {
 var xhttp;
 xhttp = new XMLHttpRequest();
 xhttp.onreadystatechange = function() {
  if (xhttp.readyState == 4 && xhttp.status == 200) {
   document.getElementById(pDivTarget).innerHTML = xhttp.responseText;
   var date = new Date();
   var vDate = "<span class=\"fldValue\">" + date.toDateString() +"</span>";
   var vTime = "<span class=\"fldValue\">" + date.toLocaleTimeString()+"</span";
   document.getElementById('scnTime').innerHTML =vTime;
   document.getElementById('scnDate').innerHTML =vDate;
  }
 };
 xhttp.open("GET", pURL, true);
 xhttp.send();
}
)=====";
#endif
