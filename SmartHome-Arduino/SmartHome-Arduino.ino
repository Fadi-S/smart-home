#include "Led.h"
#include "Buzzer.h"
#include <Servo.h>

Led led1(9);
Led led2(2);
Led led3(5);
Led led4(4);

Buzzer buzzer(7);

int doorOpenAngle = 0;
int doorCloseAngle = 180;
int doorPin = 6;
bool doorOpen = false;
int positionDoor = 0;
Servo door;

int garageOpenAngle = 0;
int garageCloseAngle = 90;
int garagePin = 11;
bool garageDoorOpen = false;
int positionGarage = 0;
Servo garage;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  garage.attach(garagePin);

  door.attach(doorPin);
  door.write(doorCloseAngle);
}


void loop() {
  if(! Serial.available()) return;
  
  char content = Serial.read();
  
  if (content == '\n' || content == '\0') return;

  Serial.println(content);

  if(content == '1') {
    led1.toggle();
  }

  if(content == '2') {
    led2.toggle();
  }

  if(content == '3') {
    led3.toggle();
  }

  if(content == '4') {
    led4.toggle();
  }

  if(content == 'b') {
    buzzer.startFor(200);
  }

  if(content == 'a') {
    buzzer.toggle(200, 5);
  }


  if(content == 'o') {
    if(doorOpen)
      door.write(doorCloseAngle);
    else
      door.write(doorOpenAngle);

     doorOpen = !doorOpen;
  }
  
  if(content == 'g') {
    if(garageDoorOpen) 
      garage.write(garageCloseAngle);
    else
      garage.write(garageOpenAngle);

     garageDoorOpen = !garageDoorOpen;
  }
}
