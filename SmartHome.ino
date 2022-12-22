#include "Wifi.h"
#include "LCD.h"
#include "Led.h"
#include "Temperature.h"
#include "Water.h"
#include <SoftwareSerial.h>


Wifi wifi("Smart home", "password1234");
Water waterLevel(A0, 14);

Led led1('1');
Led led2('2');
Led led3('3');
Led led4('4');

LCD lcd1(1);

Temperature temp(12);

bool loggedIn = false;
const String password = "1234";
int failedAttempts = 0;

void setup() {
  Serial.begin(115200);
  
  Serial1.begin(115200);

  wifi.setup();

  lcd1.setup();

  temp.setup();

  waterLevel.setup();

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
    Serial1.println("d");
    Serial1.println("b");

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

  if(response == "/led/1") {
    wifi.setResponse(led1.isOn() ? "1" : "0");
    led1.toggle();
    Serial1.println("1");
    return;
  }

  if(response == "/led/2") {
    wifi.setResponse(led2.isOn() ? "1" : "0");
    led2.toggle();
    Serial1.println("2");
    return;
  }

  if(response == "/led/3") {
    wifi.setResponse(led3.isOn() ? "1" : "0");
    led3.toggle();
    Serial1.println("3");
    return;
  }

  if(response == "/led/4") {
    wifi.setResponse(led4.isOn() ? "1" : "0");
    led4.toggle();
    Serial1.println("4");
    return;
  }

  if(response == "/buzz") {
    wifi.setResponse("Buzzed");
    Serial1.println("b");
    return;
  }

  if(response == "/getTemperature") {
    String temperature = temp.get();
    wifi.setResponse(temperature);

    int waterL = waterLevel.get();

    lcd1.setText1("T: " + temperature + "C" + " W:" + waterL);
    return;
  }


  if(response == "/door") {
    wifi.setResponse("1");
    Serial1.println("d");
    return;
  }

  if(response == "/garage") {
    wifi.setResponse("1");
    Serial1.println("g");
    return;
  }

  if(response == "/logout") {
    loggedIn = false;
    wifi.setResponse("Logged Out");
    return;
  }

  wifi.setResponse(response);
}
