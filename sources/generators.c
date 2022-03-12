#include "generators.h"

void generateRandomArray(GenBase* arr,
                         const size_t n) {
  for (size_t i = 0; i < n; i++) {
    arr[i] = (GenBase) xorshift() + INT32_MIN;
  }
}

void generateOrderedArray(GenBase* arr,
                          const size_t n) {
  const GenBase middle = (GenBase) n / 2;
  for (size_t i = 0; i < n; i++) {
    arr[i] = (GenBase) i - middle;
  }
}

void generateOrderedBackwardsArray(GenBase* arr,
                                   const size_t n) {
  const GenBase middle = (GenBase) n / 2;
  for (size_t i = 0; i < n; i++) {
    arr[i] = middle - (GenBase) i;
  }
}