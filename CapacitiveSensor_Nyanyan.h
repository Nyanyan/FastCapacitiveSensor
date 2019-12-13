#include "Arduino.h"

#ifndef FREQUENCY
#define FREQUENCY 20
#endif

#ifndef BREAKTHRESHOLD
#define BREAKTHRESHOLD 50
#endif

namespace CapasitiveSensor {
  void begin();
  double touch(int send, int receive);
}
