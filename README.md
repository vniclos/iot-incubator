# IOT Incubator


![alt text](https://github.com/vniclos/iot-incubator/blob/master/img/smartphone.jpg "Incubator IOT" )

## Hardware

- 1 ESP-12e Four relays module  (https://www.tindie.com/stores/Armtronix/)
- 1 DHT22
- 1 Resistance 10k
- 1 Silicone resistance

Note:
On ESP32 is better not use ADC2 pins becouse is used
for wifi functions.

## Software
- Arduino IDE

## I have develop a simple class interface.

### You can get 
% Humidity .
Temperature


### Easy config ###
You need change values for connect to your wifi, and set temperature and hysteresis
Its, a personal use without garanties, 

```cpp
//================================================================
// CHANGE THIS VALUES FOR YOUR NEEDS
//================================================================
float g_prg_temperature = 31.0f;             // your incubation temp
float g_prg_Hysteresis = 1.0f;               // 1ºC more or less (good live for relays),
const char* g_WiFiSsid = "XXXXXXXXXXX";       // name of your wifi
const char* g_WiFiPassword = "xxxxxxxxxx";   // password of your wifi
const char* g_hostname = "iot-incubator";
IPAddress g_NetIp(192, 168, 1, 100);
IPAddress g_NetGateway(192, 168, 1, 1);
IPAddress g_NetSubnet(255, 255, 255, 0);
//================================================================
```

## Hardware 

Dht22 need   conect 10k resistence betwen data and +3.3v
  
  The pines are definied on _defines.h, show below
  
  ```cpp
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
#define MOD_PIN_RELE_0 4 
#define MOD_PIN_RELE_1 12 
#define MOD_PIN_RELE_2 13
#define MOD_PIN_RELE_3 14

#define INTERVAL_RELAY 5000
#endif
```

## Schematic
![alt text](https://github.com/vniclos/iot-incubator/blob/master/img/incubator-schema.png "Incubator IOT" )

Contac with me on facebook 
https://www.facebook.com/vicente.niclos
