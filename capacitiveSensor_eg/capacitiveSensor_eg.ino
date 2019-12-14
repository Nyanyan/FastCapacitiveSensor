#define FREQUENCY 10000
#define BREAKTHRESHOLD 1000
#define EXCEPTRATIO 0.1
#include <CapacitiveSensor_Nyanyan.h>

#define receivepin A0
#define sendpin A1

void setup() {
  pinMode(receivepin, INPUT);
  pinMode(sendpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(CapacitiveSensor::touch(sendpin, receivepin, 5));
}
