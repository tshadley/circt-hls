// RUN: hlstool --no_trace --rebuild --tb_file %s dynamic --run_sim

#include "test_memory_10.h"
#include <stdlib.h>

#ifndef N_KERNEL_CALLS
#define N_KERNEL_CALLS 1
#endif

int main(void) {
  int a[N_KERNEL_CALLS][4];
  int n[N_KERNEL_CALLS];
  srand(13);
  for (int i = 0; i < N_KERNEL_CALLS; ++i) {
    n[i] = 3;
    for (int j = 0; j < 4; ++j) {
      a[i][j] = (rand() % 100) - 50;
    }
  }
  for (int i = 0; i < N_KERNEL_CALLS; ++i) {
    test_memory_10(a[i], n[i]);
  }
  return 0;
}
