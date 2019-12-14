#include <FastCapacitiveSensor.h>
FastCapacitiveSensor sensor1;

void setup() {
  pinMode(A1, INPUT);
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
  sensor1.begin(A0, A1, 5.0, 20, 10, 0.2);
}

void loop() {
  Serial.println(sensor1.touch());
}
