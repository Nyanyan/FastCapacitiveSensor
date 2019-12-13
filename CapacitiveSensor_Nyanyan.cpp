#include "CapacitiveSensor_Nyanyan.h"
#include <math.h>

static void swap(double* a, double* b) {
  double c = *a;
  *a = *b;
  *b = c;
}

static void sort(double* array) {
  int size = sizeof(array) / sizeof(double);
  for(int i = 0;i < size;i++)
    for(int j = size - 1;j > i; j--)
      if(array[j] < array[j - 1])
        swap(&array[j], &array[j - 1]);
}

double CapasitiveSensor::touch(int send, int receive, double voltage) {
  double VAL[FREQUENCY];
  double INPUTTHRESHOLD = voltage * 1024 / 5 * 0.9;

  for (int i = 0; i < FREQUENCY; i++) {
    float val = 0;
    unsigned long tmp;
    digitalWrite(send, HIGH);
    tmp = micros();
    while (analogRead(receive) < INPUTTHRESHOLD) {
      val = micros() - tmp;
      if (val > BREAKTHRESHOLD) {
        int tim = micros() - tmp;
        int vol = analogRead(receive);
        float gamma = -log(1 - vol / (INPUTTHRESHOLD / 0.9)) / tim;
        val = -log(1 - 0.9) / gamma;
        break;
      }
    }
    digitalWrite(send, LOW);
    delayMicroseconds(10);

    if (val > 0) {
      VAL[i] = val;
    } else
      i--;
  }
  sort(VAL);
  double VALsum = 0;
  int except = FREQUENCY * EXCEPTRATIO + 1;
  for (int i = except;i < FREQUENCY - except;i++)
    VALsum += VAL[i];
  int tmp = FREQUENCY - 2 * except;
  //Serial.print(VAL1sum / tmp);
  //Serial.print("\t");
  //Serial.print(VAL2sum / tmp);
  //Serial.println("\t");
  //NyanTimer::printLCD(0,0,String(VAL1sum / tmp));
  //NyanTimer::printLCD(0,1,String(VAL2sum / tmp));
  //NyanTimer::printLCD(7,0,String(threshold1));
  //NyanTimer::printLCD(7,1,String(threshold2));
  return VALsum / tmp;
}