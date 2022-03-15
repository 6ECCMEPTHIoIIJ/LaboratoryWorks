#include "generators.h"

#define INTERVAL 1000000
#define MIDDLE (INTERVAL / 2)

void generateRandomArray(GenBase* arr,
                         const size_t n) {
  const GenBase interval = INTERVAL;
  const GenBase middle = MIDDLE;
  for (size_t i = 0; i < n; i++) {
    arr[i] = (GenBase) xorshift() % interval - middle;
  }
}

void generateOrderedArray(GenBase* arr,
                          const size_t n) {
  const GenBase interval = INTERVAL;
  const GenBase middle = MIDDLE;
  for (size_t i = 0; i < n; i++) {
    arr[i] = (GenBase) i % interval - middle;
  }
}

void generateOrderedBackwardsArray(GenBase* arr,
                                   const size_t n) {
  const GenBase interval = INTERVAL;
  const GenBase middle = MIDDLE;
  for (size_t i = 0; i < n; i++) {
    arr[i] = middle - (GenBase) i % interval;
  }
}