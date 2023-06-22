#include <FastCapacitiveSensor.h>
FastCapacitiveSensor sensor1;
FastCapacitiveSensor sensor2;

void setup() {
  pinMode(A0, OUTPUT); // the send pin should be a pin that can be used with the digitalWrite() function
  pinMode(A1, INPUT);  // the receive pin MUST be an analog pin. The library uses analogRead() internally.
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
  sensor1.begin(A0, A1, 5.0, 10, 10, 0.2);
  sensor2.begin(A2, A3, 5.0, 10, 10, 0.2);
}

void loop() {
  Serial.print(sensor1.touch());
  Serial.print("\t");
  Serial.println(sensor2.touch());
}
