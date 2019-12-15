# FastCapacitiveSensor

## Introduction

This library for Arduino enable you to use capacitive sensors. This library is faster than any other libraries before.

## Requirement

This library uses math.h.

## How it works

### Basic construction

Capacitive sensors are pseudo capacitors.

## Usage

See also example program.

### Include

```c++
#include <FastCapacitiveSensor.h>
```

### Define a class

```c++
FastCapacitiveSensor sensor1;
```

### Execute begin function

```c++
sensor1.begin(A0, A1, 5.0, 10, 10, 0.2);
```

arguments:

```c++
void begin(sendPin, receivePin, maxVoltage, frequency, breakThreshold, excludeRatio);
```

maxVoltage is the voltage of the sendPin.

frequency is how many times the touch function tries sensing.

breakThreshold is the threshold of breaking sensing. The unit is micro seconds. the touch function finish sensing on the breakThreshold time, and after that, calculate the expected time of sensing.

excludeRatio is the ratio of exclusion of sensed values. Must be larger than or the same as 0 and smaller than 0.5.

### Sense

```c++
sensor1.touch()
```

The return value is the sensed (or calculated) time in units of micro seconds. The type is double.