#include "sort_funcs.h"

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

size_t getBubbleSortNComp(GenBase* arr,
                          const size_t size) {
  size_t cmp_count = 0;
  for (size_t i = 0; cmp_count++, i < size - 1; i++) {
    for (size_t j = size - 1; cmp_count++, j > i; j--) {
      if (cmp_count++, arr[j - 1] > arr[j]) {
        swap(arr + j - 1, arr + j, sizeof(*arr));
      }
    }
  }

  return cmp_count;
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

size_t getSelectionSortNComp(GenBase* arr,
                             const size_t size) {
  size_t cmp_count = 0;
  for (size_t i = 0; cmp_count++, i < size - 1; i++) {
    size_t min_i = i;
    for (size_t j = i + 1; cmp_count++, j < size; j++) {
      if (cmp_count++, arr[j] < arr[min_i]) {
        min_i = j;
      }
    }

    if (cmp_count++, arr[min_i] < arr[i]) {
      swap(arr + i, arr + min_i, sizeof(*arr));
    }
  }

  return cmp_count;
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

size_t getInsertionSortNComp(GenBase* arr,
                             const size_t size) {
  size_t cmp_count = 0;
  for (size_t i = 1; cmp_count++, i < size; i++) {
    GenBase tmp = arr[i];
    size_t j = i;
    while (cmp_count += 2, j > 0 && arr[j - 1] > tmp) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }

  return cmp_count;
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

size_t getСombSortNComp(GenBase* arr,
                        const size_t size) {
  size_t cmp_count = 0;
  size_t step = size;
  bool swapped = true;
  while (cmp_count++, step > 1 || swapped) {
    if (step > 1) {
      step /= GOLDEN_RATIO;
    }
    swapped = false;
    for (size_t i = 0, j = i + step; cmp_count++, j < size; i++, j++) {
      if (cmp_count++, arr[i] > arr[j]) {
        swap(arr + i, arr + j, sizeof(*arr));
        swapped = true;
      }
    }
  }

  return cmp_count;
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

size_t getСountSortNComp(GenBase* arr,
                         const size_t size) {
  size_t cmp_count = 0;
  GenBase min, max;
  getMinMax(arr, size, &min, &max);
  GenBase interval = max - min + 1;

  GenBase* b = (GenBase*) calloc(interval, sizeof(GenBase));
  for (int i = 0; cmp_count++, i < size; i++) {
    b[arr[i] - min]++;
  }

  int pos = 0;
  for (int i = 0; cmp_count++, i < interval; i++) {
    int x = b[i];
    for (int j = 0; cmp_count++, j < x; j++) {
      arr[pos++] = min + i;
    }
  }

  free(b);

  return cmp_count;
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

size_t getRadixSortNComp(GenBase* arr,
                         const size_t size) {
  size_t cmp_count = 0;
  const unsigned char mask = UCHAR_MAX;
  const size_t step = sizeof(char) * 8;
  GenBase* buffer = (GenBase*) malloc(size * sizeof(GenBase));

  for (size_t byte_i = 0; cmp_count++, byte_i < sizeof(GenBase); byte_i++) {
    size_t positions[UCHAR_MAX + 1] = {0};
    for (int i = 0; cmp_count++, i < size; i++) {
      unsigned char cur_byte = ((arr[i] >> (byte_i * step)) ^
                                ((byte_i + 1 == sizeof(GenBase)) ?
                                 (1 << (step - 1)) : 0)) & mask;
      positions[cur_byte + 1]++;
    }

    for (size_t i = 1; cmp_count++, i < ARRAY_SIZE(positions); i++) {
      positions[i] += positions[i - 1];
    }

    for (size_t i = 0; cmp_count++, i < size; i++) {
      unsigned char cur_byte = ((arr[i] >> (byte_i * step)) ^
                                ((byte_i + 1 == sizeof(GenBase)) ?
                                 (1 << (step - 1)) : 0)) & mask;
      buffer[positions[cur_byte]++] = arr[i];
    }

    memcpy(arr, buffer, size * sizeof(GenBase));
  }

  free(buffer);

  return cmp_count;
}

void merge(GenBase* arr_1,
           const size_t size_1,
           GenBase* arr_2,
           const size_t size_2,
           GenBase* out_arr) {
  size_t i_1 = 0, i_2 = 0;
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

size_t getMergeNComp(GenBase* arr_1,
                     const size_t size_1,
                     GenBase* arr_2,
                     const size_t size_2,
                     GenBase* out_arr) {
  size_t cmp_count = 0;
  size_t i_1 = 0, i_2 = 0;
  while (cmp_count += 2, i_1 < size_1 || i_2 < size_2) {
    if (cmp_count += 3, i_2 == size_2 ||
                        i_1 < size_1 && arr_1[i_1] < arr_2[i_2]) {
      out_arr[i_1 + i_2] = arr_1[i_1];
      i_1++;
    } else {
      out_arr[i_1 + i_2] = arr_2[i_2];
      i_2++;
    }
  }

  return cmp_count;
}

size_t getMergeSort_NComp(GenBase* source,
                          const size_t l,
                          const size_t r,
                          GenBase* buffer) {
  size_t cmp_count = 0;
  const size_t n = r - l;
  if (n <= 1) {
    return cmp_count;
  }
  const size_t m = l + (r - l) / 2;
  cmp_count += getMergeSort_NComp(source, l, m, buffer);
  cmp_count += getMergeSort_NComp(source, m, r, buffer);
  cmp_count += getMergeNComp(source + l, m - l, source + m, r - m, buffer);
  memcpy(source + l, buffer, sizeof(int) * n);

  return cmp_count;
}

size_t getMergeSortNComp(GenBase* arr,
                         const size_t size) {
  size_t cmp_count;
  GenBase* buffer = (GenBase*) malloc(sizeof(GenBase) * size);
  cmp_count = getMergeSort_NComp(arr, 0, size, buffer);
  free(buffer);

  return cmp_count;
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
    timSort_(source, l, m, buffer);
    timSort_(source, m, r, buffer);
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

size_t getTimSort_NComp(GenBase* source,
                const size_t l,
                const size_t r,
                GenBase* buffer) {
  size_t cmp_count = 0;
  const size_t n = r - l;
  if (n <= 1) {
    return cmp_count;
  }
  const size_t m = l + (r - l) / 2;
  if (n > 40) {
    cmp_count += getTimSort_NComp(source, l, m, buffer);
    cmp_count += getTimSort_NComp(source, m, r, buffer);
    cmp_count += getMergeNComp(source + l, m - l, source + m, r - m, buffer);
    memcpy(source + l, buffer, sizeof(int) * n);
  } else {
    cmp_count += getInsertionSortNComp(source + l, n);
  }

  return  cmp_count;
}

size_t getTimSortNComp(GenBase* arr,
                       const size_t size) {
  size_t cmp_count;
  GenBase* buffer = (GenBase*) malloc(sizeof(GenBase) * size);
  cmp_count = getTimSort_NComp(arr, 0, size, buffer);
  free(buffer);

  return cmp_count;
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

size_t getShellSortNComp(GenBase* arr,
                         const size_t size) {
  size_t cmp_count = 0;
  for (size_t step = size / 2; cmp_count++, step > 0; step /= 2) {
    for (size_t i = step; cmp_count++, i < size; i++) {
      const GenBase tmp = arr[i];
      size_t j = i;
      while (cmp_count += 2, j >= step && tmp < arr[j - step]) {
        arr[j] = arr[j - step];
        j -= step;
      }
      arr[j] = tmp;
    }
  }

  return cmp_count;
}