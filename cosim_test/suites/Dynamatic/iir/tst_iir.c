// RUN: hlstool --tb_file %s dynamic

#include "iir.h"
#include <stdlib.h>

#ifndef AMOUNT_OF_TEST
#define AMOUNT_OF_TEST 1
#endif

int main(void) {
  int y[AMOUNT_OF_TEST][1000];
  int x[AMOUNT_OF_TEST][1000];
  int b[AMOUNT_OF_TEST];
  int a[AMOUNT_OF_TEST];
  srand(13);
  for (int i = 0; i < AMOUNT_OF_TEST; ++i) {
    a[i] = rand();
    b[i] = rand();
    for (int j = 0; j < 1000; ++j) {
      y[i][j] = rand() % 1000;
      x[i][j] = rand() % 1000;
    }
  }
  for (int i = 0; i < AMOUNT_OF_TEST; ++i) {
    iir(y[i], x[i], a[i], b[i]);
  }
}
