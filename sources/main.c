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

void sort(GenBase* arr,
          size_t size) {
  qsort(arr, size, sizeof(GenBase), intcmp);
}

int main() {
  for (size_t i = 10000; i <= 500000; i += 10000) {
    checkTime(sort, true, generateRandomArray, i, "std_qsort_random", "../."
                                                                   "./data");
  }
  for (size_t i = 10000; i <= 500000; i += 10000) {
    checkTime(sort, true, generateOrderedArray, i, "std_qsort_ordered", "../."
                                                                   "./data");
  }
  for (size_t i = 10000; i <= 500000; i += 10000) {
    checkTime(sort, true, generateOrderedBackwardsArray,
              i,
              "std_qsort_ordered_backwards", "../../data");
  }
  return 0;
}
