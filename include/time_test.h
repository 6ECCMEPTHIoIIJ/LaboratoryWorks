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

void checkTime(void (* sortFunc )(int*,
                                  size_t),
               bool is_random_dependent_func,
               void (* generateFunc )(int*,
                                      size_t),
               size_t size,
               char* experiment_name,
               char* file_path);

#endif // FUNCTION_TESTING_LIB_TIME_TEST_H
