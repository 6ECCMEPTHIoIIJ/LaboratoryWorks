#include <stdio.h>

#include "time_test.h"
#include <stdlib.h>

static int intcmp(const void* a,
                  const void* b) {
  int arg_1 = *(int*) a;
  int arg_2 = *(int*) b;

  if (arg_1 < arg_2) { return -1; }
  if (arg_1 > arg_2) { return 1; }
  return 0;
}

void std_qsort(GenBase* arr,
               size_t size) {
  qsort(arr, size, sizeof(GenBase), intcmp);
}

int main() {
  const size_t kStepSize = 10000;
  const size_t kMaxSize = 500000;
  const size_t kMinSize = 10000;
  for (size_t i = kMinSize; i <= kMaxSize; i += kStepSize) {
    checkTime(std_qsort,
              true,
              generateRandomArray,
              i,
              "std_qsort_random", "../../data/std_qsort");
  }
  for (size_t i = kMinSize; i <= kMaxSize; i += kStepSize) {
    checkTime(std_qsort,
              true,
              generateOrderedArray,
              i,
              "std_qsort_ordered", "../../data/std_qsort");
  }
  for (size_t i = kMinSize; i <= kMaxSize; i += kStepSize) {
    checkTime(std_qsort,
              true,
              generateOrderedBackwardsArray,
              i,
              "std_qsort_ordered_backwards", "../../data/std_qsort");
  }
  return 0;
}
