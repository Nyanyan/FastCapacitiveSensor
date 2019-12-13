#include "CapacitiveSensor_Nyanyan.h"
#include <math.h>

static void swap(float* a, float* b) {
  float t = *a;
  *a = *b;
  *b = t;
}

static void sort(float* array) {
  int size = sizeof(array) / sizeof(float);
  for(int i = 0;i < size;i++)
    for(int j = size - 1;j > i; j--)
      if(array[j] < array[j - 1])
        swap(&array[j], &array[j - 1]);
}

int CapasitiveSensor::touch(int send, int receive) {
  float touchthreshold = 600;
  const int  t = 20;
  float VAL1[t];
  float VAL2[t];
  float breakthreshold = 50;

  for (int i = 0; i < t; i++) {
    float val1 = 0;
    float val2 = 0;
    unsigned long tmp;
    digitalWrite(PAD1OUT, HIGH);
    tmp = micros();
    while (analogRead(PAD1IN) < pad1inthreshold) {
      val1 = micros() - tmp;
      if (val1 > breakthreshold) {
        int tim = micros() - tmp;
        int vol = analogRead(PAD1IN);
        float gamma = -log(1 - vol / (pad1inthreshold / 0.9)) / tim;
        val1 = -log(1 - 0.9) / gamma;
        break;
      }
    }
    digitalWrite(PAD1OUT, LOW);

    delayMicroseconds(200);

    digitalWrite(PAD2OUT, HIGH);
    tmp = micros();
    while (analogRead(PAD2IN) < pad2inthreshold) {
      val2 = micros() - tmp;
      if (val2 > breakthreshold) {
        int tim = micros() - tmp;
        int vol = analogRead(PAD2IN);
        float gamma = -log(1 - vol / (pad1inthreshold / 0.9)) / tim;
        val2 = -log(1 - 0.9) / gamma;
        break;
      }
    }
    digitalWrite(PAD2OUT, LOW);

    delayMicroseconds(200);

    if (val1 > 0 && val2 > 0) {
      VAL1[i] = val1;
      VAL2[i] = val2;
    } else
      i--;
  }
  sort(VAL1);
  sort(VAL2);
  float VAL1sum = 0;
  float VAL2sum = 0;
  int except = t * 0.1 + 1;
  for (int i = except;i < t - except;i++) {
    VAL1sum += VAL1[i];
    VAL2sum += VAL2[i];
  }
  int tmp = t - 2 * except;
  //Serial.print(VAL1sum / tmp);
  //Serial.print("\t");
  //Serial.print(VAL2sum / tmp);
  //Serial.println("\t");
  //NyanTimer::printLCD(0,0,String(VAL1sum / tmp));
  //NyanTimer::printLCD(0,1,String(VAL2sum / tmp));
  //NyanTimer::printLCD(7,0,String(threshold1));
  //NyanTimer::printLCD(7,1,String(threshold2));
  if (VAL1sum >= touchthreshold * tmp && VAL2sum >= touchthreshold * tmp)
    return 1;
  else if (VAL1sum >= touchthreshold * tmp && VAL2sum < touchthreshold * tmp)
    return 2;
  else if (VAL1sum < touchthreshold * tmp && VAL2sum >= touchthreshold * tmp)
    return 3;
  else
    return 0;
}