#include <stdio.h>

#include "time_test.h"

void testTime() {
  const size_t kMinSize = 10000;
  const size_t kMaxSize = 1000000;
  const size_t kStepSize = 5000;
  GeneratingFunc generating_funcs[] = {
//      {generateRandomArray,           "random"},
      {generateOrderedArray,          "ordered"},
//      {generateOrderedBackwardsArray, "orderedBackwards"}
  };
  SortFunc sort_funcs[] = {
      {insertionSort, getInsertionSortNComp, part, 1, "insertionSort"},
//      {selectionSort, getSelectionSortNComp, none, 1, "selectionSort"},
//      {bubbleSort, getBubbleSortNComp, none, 1, "bubbleSort"},
//      {stdQsort, NULL, full, 3, "stdQsort"},
//      {combSort, getСombSortNComp, part, 3, "combSort"},
//      {radixSort, getRadixSortNComp, none, 1, "radixSort"},
//      {countSort, getСountSortNComp, none, 1,  "countSort"},
//      {mergeSort, getMergeSortNComp, none, 1,  "mergeSort"},
//      {timSort, getTimSortNComp, none, 1,  "timSort"},
//      {shellSort, getShellSortNComp, none, 1, "shellSort"},
  };
  for (size_t size = kMinSize; size <= kMaxSize; size += kStepSize) {
    printf("SIZE = %zu\n-----------------------\n", size);
    for (size_t generating_func_i = 0;
         generating_func_i < ARRAY_SIZE(generating_funcs);
         generating_func_i++) {
      for (size_t sort_func_i = 0;
           sort_func_i < ARRAY_SIZE(sort_funcs); sort_func_i++) {
        checkTime(sort_funcs[sort_func_i],
                  generating_funcs[generating_func_i],
                  size);
      }
    }
    printf("\n-----------------------\n");
  }

  for (size_t size = kMinSize; size <= kMaxSize; size += kStepSize) {
    printf("SIZE = %zu\n-----------------------\n", size);
    for (size_t generating_func_i = 0;
         generating_func_i < ARRAY_SIZE(generating_funcs);
         generating_func_i++) {
      for (size_t sort_func_i = 0;
           sort_func_i < ARRAY_SIZE(sort_funcs); sort_func_i++) {
        checkNComp(sort_funcs[sort_func_i],
                   generating_funcs[generating_func_i],
                   size);
      }
    }
    printf("\n-----------------------\n");
  }
}

int main() {
  testTime();

  return 0;
}
