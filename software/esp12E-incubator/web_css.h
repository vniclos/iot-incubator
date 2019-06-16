//javascripts

#ifndef _WEB_CSS_H
#define _WEB_CSS_H
const char g_HTML_Web_CSS[] PROGMEM = R"=====(
+{ line-height: 1.6;}
.green{ background-color : #00aa00;}
.gray{background-color: #666;} 
.button {margin:5px;   display: inline-block; background: #4E9CAF;padding: 5px;  text-align: center;  border-radius: 5px;color: white;  font-weight: bold;}
.fldTitle{display:inline-block;  min-width:8rem;overflow:hidden;}
.fldValue{ display:inline-block; min-width:8rem;overflow:hidden; text-align:right;}
.circle {    background-color: red;
    border: 2px solid white;
    border-radius: 12px; /* one half of ( (border * 2) + height + padding ) */
    box-shadow: 1px 1px 1px black;
    color: white;
    font: bold 15px/13px Helvetica, Verdana, Tahoma;
    height: 16px; 
    padding: 4px 3px 0 3px;
    text-align: center;
    min-width: 14px;
    float: left;
    left: 25px;
    margin: 6px;
    position: relative;
   }
.red{ background:  radial-gradient( 5px -9px, circle, white 8%, red 26px );
    background:    -moz-radial-gradient( 5px -9px, circle, white 8%, red 26px );
    background:     -ms-radial-gradient( 5px -9px, circle, white 8%, red 26px );
    background:      -o-radial-gradient( 5px -9px, circle, white 8%, red 26px );
    background: -webkit-radial-gradient( 5px -9px, circle, white 8%, red 26px );}
.gray {
   background:             radial-gradient( 5px -9px, circle, white 8%, gray 26px );
   background:    -moz-radial-gradient( 5px -9px, circle, white 8%, gray 26px );
   background:     -ms-radial-gradient( 5px -9px, circle, white 8%, gray 26px );
   background:      -o-radial-gradient( 5px -9px, circle, white 8%, gray 26px );
   background: -webkit-radial-gradient( 5px -9px, circle, white 8%, gray 26px );
  }
)=====";
#endif
