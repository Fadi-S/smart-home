#include "Ultrasound.h"
#include "Wifi.h"
#include "Buzzer.h"
#include "Led.h"

//Ultrasound echo(14, 4);
// int distance;

Wifi wifi("Smart home", "password1234");

Buzzer buzzer(4);

Led yellowLed(14);
Led redLed(12);

bool loggedIn = false;
const String password = "1234";
int failedAttempts = 0;

void setup() {
  Serial.begin(115200);

  wifi.setup();

  Serial.println(wifi.getIpAddress());
}

void loop() {
  if(failedAttempts >= 3) {
    buzzer.toggle(500, 5);
    failedAttempts--;
  }

  String response = wifi.getResponse();
  if(response == "\0") {
    return;
  }

  if(!response.startsWith("/login") && !loggedIn) {
    wifi.setResponse("You are not logged In!");

    return;
  }

  if(response.startsWith("/login")) {
    int start = response.indexOf("password=");

    String inputPassword = response.substring(start+9, response.length());

    if(inputPassword != password) {
      wifi.setResponse("Wrong password");
      failedAttempts++;
      return;
    }

    loggedIn = true;
    failedAttempts = 0;
    wifi.setResponse("Logged In");
    buzzer.startFor(200);

    // TODO Open door

    return;
  }

  if(response == "/") {
    wifi.setResponse("Welcome home");
    return;
  }

  if(response == "/led/red") {
    redLed.toggle();
    wifi.setResponse(redLed.isOn() ? "1" : "0");
    return;
  }

  if(response == "/led/yellow") {
    yellowLed.toggle();
    wifi.setResponse(yellowLed.isOn() ? "1" : "0");
    return;
  }

  if(response == "/getTemperature") {
    wifi.setResponse("25");
    return;
  }

  if(response == "/logout") {
    loggedIn = false;
    return;
  }

  wifi.setResponse(response);
}
