// RUN: dyn_incrementally_lower %s

#include "test_memory_8.h"
void test_memory_8(int a[4], int n) {
  int x;
  for (int i = 2; i < n; i++) {
    x = a[i - 1] + a[i - 2] + 5;
    if (x > 0) {
      a[i - 1] = a[i];
      a[i] = 0;
    }
  }
}
