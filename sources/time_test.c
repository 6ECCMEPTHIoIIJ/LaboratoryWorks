#include "time_test.h"

#include <stdlib.h>
#include <math.h>

#define INNER_BUF_SIZE 100000000
#define N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS 61

static int doublecmp(const void* a,
                     const void* b) {
  double arg_1 = *(double*) a;
  double arg_2 = *(double*) b;

  if (arg_1 < arg_2) { return -1; }
  if (arg_1 > arg_2) { return 1; }
  return 0;
}

static bool isOrdered(GenBase* arr,
                      const size_t size) {
  for (size_t i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }

  return true;
}

static void fprintarr(FILE* out,
                      GenBase* arr,
                      const size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    fprintf(out, "%d, ", arr[i]);
  }
  fprintf(out, "%d", arr[size - 1]);
}

void checkTime(void (* sortFunc)(int*,
                                 size_t),
               bool is_random_dependent_func,
               void (* generateFunc)(int*,
                                     size_t),
               size_t size,
               char* experiment_name,
               char* file_path) {
  static size_t run_count = 1;
  static GenBase inner_buf[INNER_BUF_SIZE];
  generateFunc(inner_buf, size);
  printf("Run #%zu| ", run_count++);
  printf("Name: %s\n", experiment_name);

  double time;
  if (is_random_dependent_func) {
    double median_time;
    double average_time = 0;
    double geom_mean_time = 1;
    double root_mean_square = 0;
    double time_arr[N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS];
    for (size_t i = 0; i < ARRAY_SIZE(time_arr); i++) {
      TIME_TEST(sortFunc(inner_buf, size), time_arr[i]);
      average_time += time_arr[i];
      geom_mean_time *= time_arr[i];
      root_mean_square += time_arr[i] * time_arr[i];
    }
    qsort(time_arr, ARRAY_SIZE(time_arr), sizeof(*time_arr), doublecmp);
    median_time = time_arr[N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS / 2];
    average_time /= N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS;
    geom_mean_time = pow(geom_mean_time,
                         1.0 / N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS);
    root_mean_square = sqrt(root_mean_square /
                            N_REPEATS_FOR_RANDOM_DEPENDENT_FUNCS);
    time = (((average_time + root_mean_square) / 2 + geom_mean_time) / 2 +
           median_time) / 2;
  } else {
    TIME_TEST(sortFunc(inner_buf, size), time)
  }

  printf("Status: ");
  if (isOrdered(inner_buf, size)) {
    printf("OK! Time: %.5f s.\n", time);

    char file_name[MAX_STR_LEN + 1];
    sprintf(file_name, "%s/%s.csv", file_path, experiment_name);
    FILE* f = fopen(file_name, "a");
    if (f == NULL) {
      fprintf(stderr, "FILE_OPEN_ERROR %s", file_name);
      exit(1);
    }
    fprintf(f, "%zu; %.5f\n", size, time);
    fclose(f);
  } else {
    printf("Wrong!\n{ ");
    fprintarr(stdout, inner_buf, size);
    printf(" }\n");
  }
}