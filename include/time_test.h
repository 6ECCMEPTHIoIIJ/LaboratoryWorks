#ifndef FUNCTION_TESTING_LIB_TIME_TEST_H
#define FUNCTION_TESTING_LIB_TIME_TEST_H

#include "generators.h"
#include "sort_funcs.h"

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


void checkTime(SortFunc sort_func,
               GeneratingFunc generating_func,
               size_t size);

void checkNComp(SortFunc sort_func,
                GeneratingFunc generating_func,
                size_t size);

#endif // FUNCTION_TESTING_LIB_TIME_TEST_H
