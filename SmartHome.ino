#include "Ultrasound.h"
#include "Wifi.h"
#include "Buzzer.h"
#include "Led.h"
#include "LCD.h"
#include "Temperature.h"
#include <SoftwareSerial.h>


Wifi wifi("Smart home", "password1234");

Led yellowLed('l');

LCD lcd1(1);

Temperature temp(5);

bool loggedIn = false;
const String password = "1234";
int failedAttempts = 0;

void setup() {
  Serial.begin(115200);
  
  Serial1.begin(115200);

  wifi.setup();

  lcd1.setup();

  Serial.println(wifi.getIpAddress());
}

void loop() {
  if(failedAttempts >= 3) {
    // buzzer.toggle(500, 5);
    failedAttempts--;
    Serial1.println("a");
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
    // buzzer.startFor(200);
    Serial1.println("b");

    // TODO Open door

    return;
  }

  if(response == "/") {
    wifi.setResponse("Welcome home");
    return;
  }

  if(response.startsWith("/text")) {
    int start = response.indexOf("line=");

    String text = response.substring(start+5, response.length());
    text.replace("+", " ");

    lcd1.setText2(text);

    wifi.setResponse(text);
    return;
  }

  if(response == "/led/yellow") {
    Serial1.println("l");

    yellowLed.toggle();
    wifi.setResponse(yellowLed.isOn() ? "1" : "0");
    return;
  }

  if(response == "/buzz") {
    Serial1.println("b");
    wifi.setResponse("Buzzed");
    return;
  }

  if(response == "/getTemperature") {
    String temperature = temp.get();

    lcd1.setText1("Temp: " + temperature + "C");
    wifi.setResponse(temperature);
    return;
  }

  if(response == "/logout") {
    loggedIn = false;
    wifi.setResponse("Logged Out");
    return;
  }

  wifi.setResponse(response);
}
