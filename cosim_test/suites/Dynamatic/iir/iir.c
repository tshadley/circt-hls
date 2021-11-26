// RUN: dyn_incrementally_lower %s

#include "iir.h"
int iir(int y[1000], int x[1000], int a, int b) {
  int i;
  int tmp = y[0];
  for (i = 1; i < 1000; i++) {
    tmp = a * tmp + b * x[i];
    y[i] = tmp;
  }
  return tmp;
}