#include "Arduino.h"

#ifndef FREQUENCY
#define FREQUENCY 20
#endif

#ifndef BREAKTHRESHOLD
#define BREAKTHRESHOLD 50
#endif

namespace CapasitiveSensor {
  double touch(int send, int receive, double voltage);
}
