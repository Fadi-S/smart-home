#include <cstdlib>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Wifi.h"

WiFiServer server(80);

Wifi::Wifi(String ssid, String password) {
  _ssid = ssid;
  _password = password;
}

void Wifi::setup() {
  WiFi.begin(_ssid.c_str(), _password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  _ipAddress = WiFi.localIP().toString();

  server.begin();
}

String Wifi::getIpAddress() {
  return _ipAddress;
}

void Wifi::setResponse(String response) {
  String s = "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n\r\n\r\n";
  
  s += "{\"response\": \"";
  s += response;
  s += "\"}";
  _client.print(s);
}

String Wifi::getResponse() {
  _client = server.available();
  if (!_client) {
    return "\0";
  }

  while(!_client.available()) {
    delay(1);
  }

  String req = _client.readStringUntil('\r');
  _client.flush();

  req = req.substring(4, req.length()-1);

  return req.substring(0, req.indexOf(" HTTP"));
}