#ifndef Wifi_h
#define Wifi_h

#include <Arduino.h>
#include <ESP8266WiFi.h>

class Wifi {

  public:
    Wifi(String ssid, String password);

    void setup();

    void setResponse(String response);

    String getResponse();

    String getIpAddress();

  private:
    String _ssid;
    String _password;
    String _ipAddress;
    WiFiClient _client;
};

#endif