#ifndef FUNCTION_TESTING_LIB_TIME_TEST_H
#define FUNCTION_TESTING_LIB_TIME_TEST_H

#include "generators.h"

#include <time.h>

#define ARRAY_SIZE(ARR) (sizeof(ARR) / sizeof(*ARR))

#define TIME_TEST(TEST_CODE, TIME) { \
  clock_t start_time = clock();      \
  {                                  \
  TEST_CODE;                         \
  }                                  \
  clock_t end_time = clock();        \
  clock_t test_time = end_time - start_time; \
  TIME = (double) test_time / CLOCKS_PER_SEC;\
}

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
  RandomDependence random_dependence;       // является ли функция рандомо-зависимой
  size_t amount_of_repeats;       // только для random_dependence_ = true
  char name[MAX_STR_LEN + 1];     // имя генератора
} SortFunc;

void checkTime(SortFunc sort_func,
               GeneratingFunc generating_func,
               size_t size);

#endif // FUNCTION_TESTING_LIB_TIME_TEST_H
