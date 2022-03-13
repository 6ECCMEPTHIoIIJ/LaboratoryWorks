#ifndef INC_LR_1_1_TESTS_H
#define INC_LR_1_1_TESTS_H

#include <stdio.h>
#include <string.h>

#define ASSERT_STRING_EQ(EXPECTED, GOT) \
assertStringEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertStringEq(const char* expected,
                  const char* got,
                  const char* fileName,
                  const char* funcName,
                  const size_t line) {
  if (strcmp(expected, got) != 0) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: \"%s\"\n", expected);
    fprintf(stderr, "Got: \"%s\"\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_INT_EQ(EXPECTED, GOT) \
assertIntEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertIntEq(const int expected,
               const int got,
               const char* fileName,
               const char* funcName,
               const size_t line) {
  if (expected != got) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: %d\n", expected);
    fprintf(stderr, "Got: %d\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_SIZE_EQ(EXPECTED, GOT) \
assertSizeEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertSizeEq(const size_t expected,
                const size_t got,
                const char* fileName,
                const char* funcName,
                const size_t line) {
  if (expected != got) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: %zu\n", expected);
    fprintf(stderr, "Got: %zu\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_PTR_EQ(EXPECTED, GOT) \
assertPtrEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertPtrEq(const void* expected,
                 const void* got,
                 const char* fileName,
                 const char* funcName,
                 const size_t line) {
  if (expected != got) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: %p\n", expected);
    fprintf(stderr, "Got: %p\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_PTR_NE(NOT_EXPECTED, GOT) \
assertPtrNe(NOT_EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertPtrNe(const void* not_expected,
                 const void* got,
                 const char* fileName,
                 const char* funcName,
                 const size_t line) {
  if (not_expected == got) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: %p\n", not_expected);
    fprintf(stderr, "Got: %p\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#endif // !INC_LR_1_1_TESTS_H
