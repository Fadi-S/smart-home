#include "Led.h"
#include "Buzzer.h"


Led led1(9);

Buzzer buzzer(7);

void setup() {
  Serial.begin(115200);
  while (!Serial);

}


void loop() {
  char content = Serial.read();
  
  if (content == '\n' || content == '\0') return;

  Serial.println(content);

  if(content == 'l') {
    led1.toggle();
  }

  if(content == 'b') {
    buzzer.startFor(200);
  }

  if(content == 'a') {
    buzzer.toggle(500, 5);
  }
}
