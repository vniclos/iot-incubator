#ifndef _ST_DEFINES_H
#define _ST_DEFINES_H
// Config for connect to your wifi
// change adapting to your wifi.
// ---------------------------------------------
#define STD_DEBUG_SNS_DHT
#define STD_DEBUG_ACT_RELAY

const unsigned int RELAY_ON =HIGH ;
const unsigned int RELAY_OFF= LOW;
//----------------------------------------------
// SENSOR TEMPERATURE
#define INTERVAL_DHT22 5000
#define DHTTYPE DHT22
//----------------------------------------------
// DEFINES PIN OF SENSOR AND ACTUATORS
#define PIN_DHT22 2
//#define  LED_BUILTIN 13

//..................................
#define MOD_PIN_RESET 5 // todo revisar
//..................................
// RELES 
#define MOD_PIN_RELE_0 4 //5
#define MOD_PIN_RELE_1 12 //14
#define MOD_PIN_RELE_2 13
#define MOD_PIN_RELE_3 14

#define INTERVAL_RELAY 5000
#endif
