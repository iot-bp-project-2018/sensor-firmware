#ifndef MQTT_h
#define MQTT_h

#include "Arduino.h"
#include "Datagram.h"
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>

class MQTT {
  public:
    MQTT();
    void loop();
    void setServer(char* server);
    Datagram datagram;
    PubSubClient _mqtt; //dirty, make private
  private:
    void _checkConnection();
    bool _isReconnecting;
    char _server[30];
    WiFiClient _espClient;
    Ticker _reconnectTicker;
    static void _reconnectTimeout(MQTT* mqtt);
    void _callback(char* topic, byte* payload, unsigned int length);

    unsigned long timestamp;
    Ticker _timestampTicker;
    static void _timestampCallback(MQTT* mqtt);
};

#endif
