#include "Ultrasound.h"
#include "Wifi.h"

//Ultrasound echo(2, 3);
int distance;

Wifi wifi("Smart home", "password1234");

void setup() {
  Serial.begin(115200);

  wifi.setup();

  Serial.println(wifi.getIpAddress());
}

void loop() {
  String response = wifi.getResponse();
  if(response == "\0") {
    return;
  }

  if(response == "/") {
    wifi.setResponse("Welcome home");
    return;
  }

  if(response == "/getTemperature") {
    wifi.setResponse("25");
    return;
  }

  wifi.setResponse(response);
}
