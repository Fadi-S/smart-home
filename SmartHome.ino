
int IR1 = A4;

int led = 13;

void setup() {
  Serial.begin(115200);
  
  pinMode(IR1, INPUT);

  pinMode(led, OUTPUT);
}

void loop() {
  int sensorStatus = digitalRead(IR1);

  if(sensorStatus==1) {
    digitalWrite(led, ! digitalRead(led));
  }
}
