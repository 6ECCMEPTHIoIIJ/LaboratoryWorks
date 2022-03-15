#include "time_test.h"

#include <stdlib.h>
#include <math.h>
#include <direct.h>
#include <minmax.h>

#define INNER_BUF_SIZE 100000000
#define DATA_DIR "../../data"

static bool isOrderedInt(GenBase* arr,
                         const size_t size) {
  for (size_t i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }

  return true;
}

static bool isOrderedDouble(double* arr,
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

static int doublecmp(const void* a,
                     const void* b) {
  double arg_1 = *(double*) a;
  double arg_2 = *(double*) b;

  if (arg_1 < arg_2) { return -1; }
  if (arg_1 > arg_2) { return 1; }
  return 0;
}

static double getMeanForRandomDependentFuncs(SortFunc sort_func,
                                             GeneratingFunc generating_func,
                                             const size_t size,
                                             GenBase* inner_buf) {
  double time_arr[sort_func.amount_of_repeats];
  for (size_t i = 0; i < ARRAY_SIZE(time_arr); i++) {
    generating_func.generate(inner_buf, size);
    TIME_TEST((sort_func).sort(inner_buf, size), time_arr[i]);
  }
  qsort(time_arr, ARRAY_SIZE(time_arr), sizeof(*time_arr), doublecmp);
  if (isOrderedDouble(time_arr, ARRAY_SIZE(time_arr))) {
    return time_arr[ARRAY_SIZE(time_arr) / 2];
  } else {
    return -1;
  }
}

static double getMeanForNotRandomDependentFuncs(SortFunc sort_func,
                                             GeneratingFunc generating_func,
                                             const size_t size,
                                             GenBase* inner_buf) {
  double time_arr[min(sort_func.amount_of_repeats, 3)];
  for (size_t i = 0; i < ARRAY_SIZE(time_arr); i++) {
    generating_func.generate(inner_buf, size);
    TIME_TEST((sort_func).sort(inner_buf, size), time_arr[i]);
  }
  qsort(time_arr, ARRAY_SIZE(time_arr), sizeof(*time_arr), doublecmp);
  if (isOrderedDouble(time_arr, ARRAY_SIZE(time_arr))) {
    return time_arr[ARRAY_SIZE(time_arr) / 2];
  } else {
    return -1;
  }
}

void createFile(char* file_name,
                const SortFunc sort_func,
                const char* experiment_name) {
  char file_dir[MAX_STR_LEN + 1];
  mkdir(DATA_DIR);
  sprintf(file_dir, "%s/%s/", DATA_DIR, sort_func.name);
  mkdir(file_dir);
  sprintf(file_name, "%s/%s_time.csv", file_dir, experiment_name);
}

void checkTime(SortFunc sort_func,
               GeneratingFunc generating_func,
               size_t size) {
  static size_t run_count = 1;
  static GenBase inner_buf[INNER_BUF_SIZE];
  generating_func.generate(inner_buf, size);
  printf("Run #%zu| ", run_count++);
  char experiment_name[sizeof(sort_func.name) +
                       sizeof(generating_func.name) - 1];
  sprintf(experiment_name, "%s_%s", sort_func.name, generating_func.name);
  printf("Name: %s_%s\n", sort_func.name, generating_func.name);

  double time;
  if (sort_func.random_dependence == full ||
      sort_func.random_dependence == part &&
      generating_func.generate == generateRandomArray) {
    time = getMeanForRandomDependentFuncs(sort_func, generating_func, size,
                                          inner_buf);
  } else {
    time = getMeanForNotRandomDependentFuncs(sort_func, generating_func, size,
                                          inner_buf);
  }

  printf("Status: ");
  if (isOrderedInt(inner_buf, size)) {
    printf("OK! Time: %.3f s.\n", time);

    char file_name[MAX_STR_LEN + 1];
    createFile(file_name, sort_func, experiment_name);
    FILE* f = fopen(file_name, "a");
    if (f == NULL) {
      fprintf(stderr, "FILE_OPEN_ERROR %s\n", file_name);
      exit(1);
    }
    fprintf(f, "%zu; %.3f\n", size, time);
    fclose(f);
  } else {
    printf("Wrong!\n{");
    fprintarr(stdout, inner_buf, size);
    printf("}\n");
  }
}

