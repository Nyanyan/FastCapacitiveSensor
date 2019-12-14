#ifndef __FastCapacitiveSensor_h__
#define __FastCapacitiveSensor_h__

#include "Arduino.h"

class FastCapacitiveSensor {
public:
  FastCapacitiveSensor();
  void begin(int send, int receive, double voltage, int frequency, int breakthreshold, double exceptratio);
  double touch();

private:
  int FREQUENCY;
  int BREAKTHRESHOLD;
  double EXCEPTRATIO;
  int SEND;
  int RECEIVE;
  double VOLTAGE;
};

#endif