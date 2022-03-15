#include <stdio.h>

#include "time_test.h"
#include <stdlib.h>
#include <memory.h>

#define GOLDEN_RATIO 1.247330950103979

static int intcmp(const void* p_1,
                  const void* p_2) {
  int arg_1 = *(int*) p_1;
  int arg_2 = *(int*) p_2;

  if (arg_1 < arg_2) { return -1; }
  if (arg_1 > arg_2) { return 1; }
  return 0;
}

void stdQsort(GenBase* arr,
              const size_t size) {
  qsort(arr, size, sizeof(GenBase), intcmp);
}

void swapBytes(char* p_1,
               char* p_2) {
  const char t = *p_1;
  *p_1 = *p_2;
  *p_2 = t;
}

void swap(void* p_1,
          void* p_2,
          const size_t memsize) {
  for (size_t i = 0; i < memsize; i++) {
    swapBytes(p_1 + i, p_2 + i);
  }
}

void bubbleSort(GenBase* arr,
                const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = size - 1; j > i; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(arr + j - 1, arr + j, sizeof(*arr));
      }
    }
  }
}

void selectionSort(GenBase* arr,
                   const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t min_i = i;
    for (size_t j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_i]) {
        min_i = j;
      }
    }

    if (arr[min_i] < arr[i]) {
      swap(arr + i, arr + min_i, sizeof(*arr));
    }
  }
}

void insertionSort(GenBase* arr,
                   const size_t size) {
  for (size_t i = 1; i < size; i++) {
    GenBase tmp = arr[i];
    size_t j = i;
    while (j > 0 && arr[j - 1] > tmp) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

void combSort(int* arr,
              size_t size) {
  size_t step = size;
  bool swapped = true;
  while (step > 1 || swapped) {
    if (step > 1) {
      step /= GOLDEN_RATIO;
    }
    swapped = false;
    for (size_t i = 0, j = i + step; j < size; i++, j++) {
      if (arr[i] > arr[j]) {
        swap(arr + i, arr + j, sizeof(*arr));
        swapped = true;
      }
    }
  }
}

void getMinMax(GenBase* arr,
               const size_t size,
               GenBase* min,
               GenBase* max) {
  *min = arr[0];
  *max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < *min) {
      *min = arr[i];
    } else if (arr[i] > *max) {
      *max = arr[i];
    }
  }
}

void countSort(GenBase* arr,
               const size_t size) {
  GenBase min, max;
  getMinMax(arr, size, &min, &max);
  GenBase interval = max - min + 1;

  GenBase* b = (GenBase*) calloc(interval, sizeof(GenBase));
  for (int i = 0; i < size; i++) {
    b[arr[i] - min]++;
  }

  int pos = 0;
  for (int i = 0; i < interval; i++) {
    int x = b[i];
    for (int j = 0; j < x; j++) {
      arr[pos++] = min + i;
    }
  }

  free(b);
}

void radixSort(GenBase* arr,
               const size_t size) {
  const unsigned char mask = UCHAR_MAX;
  const size_t step = sizeof(char) * 8;
  GenBase* buffer = (GenBase*) malloc(size * sizeof(GenBase));

  for (size_t byte_i = 0; byte_i < sizeof(GenBase); byte_i++) {
    size_t positions[UCHAR_MAX + 1] = {0};
    for (int i = 0; i < size; i++) {
      unsigned char cur_byte = ((arr[i] >> (byte_i * step)) ^
                                ((byte_i + 1 == sizeof(GenBase)) ?
                                 (1 << (step - 1)) : 0)) & mask;
      positions[cur_byte + 1]++;
    }

    for (size_t i = 1; i < ARRAY_SIZE(positions); i++) {
      positions[i] += positions[i - 1];
    }

    for (size_t i = 0; i < size; i++) {
      unsigned char cur_byte = ((arr[i] >> (byte_i * step)) ^
                                ((byte_i + 1 == sizeof(GenBase)) ?
                                 (1 << (step - 1)) : 0)) & mask;
      buffer[positions[cur_byte]++] = arr[i];
    }

    memcpy(arr, buffer, size * sizeof(GenBase));
  }

  free(buffer);
}

void merge(int* arr_1,
           const size_t size_1,
           int* arr_2,
           const size_t size_2,
           int* out_arr) {
  int i_1 = 0, i_2 = 0;
  while (i_1 < size_1 || i_2 < size_2) {
    if (i_2 == size_2 || i_1 < size_1 && arr_1[i_1] < arr_2[i_2]) {
      out_arr[i_1 + i_2] = arr_1[i_1];
      i_1++;
    } else {
      out_arr[i_1 + i_2] = arr_2[i_2];
      i_2++;
    }
  }
}

void mergeSort_(GenBase* source,
                const size_t l,
                const size_t r,
                GenBase* buffer) {
  const size_t n = r - l;
  if (n <= 1) {
    return;
  }
  const size_t m = l + (r - l) / 2;
  mergeSort_(source, l, m, buffer);
  mergeSort_(source, m, r, buffer);
  merge(source + l, m - l, source + m, r - m, buffer);
  memcpy(source + l, buffer, sizeof(int) * n);
}

void mergeSort(GenBase* arr,
               const size_t size) {
  GenBase* buffer = (GenBase*) malloc(sizeof(GenBase) * size);
  mergeSort_(arr, 0, size, buffer);
  free(buffer);
}

void timSort_(GenBase* source,
              const size_t l,
              const size_t r,
              GenBase* buffer) {
  const size_t n = r - l;
  if (n <= 1) {
    return;
  }
  const size_t m = l + (r - l) / 2;
  if (n > 40) {
    mergeSort_(source, l, m, buffer);
    mergeSort_(source, m, r, buffer);
    merge(source + l, m - l, source + m, r - m, buffer);
    memcpy(source + l, buffer, sizeof(int) * n);
  } else {
    insertionSort(source + l, n);
  }
}

void timSort(GenBase* arr,
             const size_t size) {
  GenBase* buffer = (GenBase*) malloc(sizeof(GenBase) * size);
  timSort_(arr, 0, size, buffer);
  free(buffer);
}

void shellSort(GenBase* arr,
               const size_t size) {
  for (size_t step = size / 2; step > 0; step /= 2) {
    for (size_t i = step; i < size; i++) {
      const GenBase tmp = arr[i];
      size_t j = i;
      while (j >= step && tmp < arr[j - step]) {
        arr[j] = arr[j - step];
        j -= step;
      }
      arr[j] = tmp;
    }
  }
}

void testTime() {
  const size_t kMinSize = 10000;
  const size_t kMaxSize = 1000000;
  const size_t kStepSize = 5000;
  GeneratingFunc generating_funcs[] = {
      {generateRandomArray,           "random"},
      {generateOrderedArray,          "ordered"},
      {generateOrderedBackwardsArray, "orderedBackwards"}
  };
  SortFunc sort_funcs[] = {
//      {insertionSort, part, 11, "insertionSort"},
//      {selectionSort, none, 3,  "selectionSort"},
//      {bubbleSort,    part, 3,  "bubbleSort"},
//      {stdQsort,  full, 11, "stdQsort"},
//      {combSort,      part, 11, "combSort"},
//      {radixSort, none, 1,  "radixSort"},
//      {countSort, none, 3,  "countSort"},
//      {mergeSort, part, 1,  "mergeSort"},
//      {timSort, part, 1,  "timSort"},
      {shellSort, part, 1, "shellSort"},
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
}

int main() {
  testTime();

  return 0;
}
