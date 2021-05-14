#include <Arduino.h>

void setup() {
  pinMode(D5, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  Serial.println(x);
  if (x<=500) {
    digitalWrite(D5,HIGH);
  } else {
    digitalWrite(D5,LOW);
  }

}

