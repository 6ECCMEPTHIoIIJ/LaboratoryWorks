#ifndef FUNCTION_TESTING_LIB_SORT_FUNCS_H
#define FUNCTION_TESTING_LIB_SORT_FUNCS_H

#include "generators.h"

typedef enum RandomDependence {
  none,
  part,
  full
} RandomDependence;

/*
 * Функция генерации последовательности
 * generate - указатель на функцию-генератор
 * name - имя генератора, используемое при выводе
 */
typedef struct SortFunc {
  void (* sort)(GenBase* arr,     // указатель на ф-цию генерации
                size_t n);        // последовательности
  size_t (* nComp)(GenBase* arr,
                   size_t n);

  RandomDependence random_dependence;       // является ли функция рандомо-зависимой
  size_t amount_of_repeats;       // только для random_dependence_ = true
  char name[MAX_STR_LEN + 1];     // имя генератора
} SortFunc;

void stdQsort(GenBase* arr,
              size_t size);

void swap(void* p_1,
          void* p_2,
          size_t memsize);

void bubbleSort(GenBase* arr,
                size_t size);

size_t getBubbleSortNComp(GenBase* arr,
                          size_t size);

void selectionSort(GenBase* arr,
                   size_t size);

size_t getSelectionSortNComp(GenBase* arr,
                             size_t size);

void insertionSort(GenBase* arr,
                   size_t size);

size_t getInsertionSortNComp(GenBase* arr,
                             size_t size);

void combSort(GenBase* arr,
              size_t size);

size_t getСombSortNComp(GenBase* arr,
                        size_t size);

void getMinMax(GenBase* arr,
               size_t size,
               GenBase* min,
               GenBase* max);

void countSort(GenBase* arr,
               size_t size);

size_t getСountSortNComp(GenBase* arr,
                         size_t size);

void radixSort(GenBase* arr,
               size_t size);

size_t getRadixSortNComp(GenBase* arr,
                         size_t size);

void mergeSort(GenBase* arr,
               size_t size);

size_t getMergeSortNComp(GenBase* arr,
                         size_t size);

void timSort(GenBase* arr,
             size_t size);

size_t getTimSortNComp(GenBase* arr,
                       size_t size);


void shellSort(GenBase* arr,
               size_t size);

size_t getShellSortNComp(GenBase* arr,
                         size_t size);

#endif // FUNCTION_TESTING_LIB_SORT_FUNCS_H
