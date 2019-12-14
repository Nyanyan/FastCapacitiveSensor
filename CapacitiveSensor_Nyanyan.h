#ifndef __CapacitiveSensor_Nyanyan_h__
#include "Arduino.h"

class CapacitiveSensor {
public:
  void begin(int send, int receive, double voltage, int frequency, int breakthreshold, double exceptratio);
  double touch();

private:
  const int FREQUENCY;
  const int BREAKTHRESHOLD;
  const double EXCEPTRATIO;
  const int SEND;
  const int RECEIVE;
  const double VOLTAGE;
}

#endif