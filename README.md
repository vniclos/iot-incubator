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
```cpp



Contac with me on facebook 
https://www.facebook.com/vicente.niclos
