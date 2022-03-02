#ifndef INC_5E_TESTS_H
#define INC_5E_TESTS_H

#include <stdio.h>

#include "../include/mystring.h"

#define ASSERT_STRING(EXPECTED, GOT) \
assertString(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertString(char* expected,
                  char* got,
                  const char* fileName,
                  const char* funcName,
                  const size_t line) {
  if (mystrcmp(expected, got) != 0) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: \"%s\"\n", expected);
    fprintf(stderr, "Got: \"%s\"\n", got);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_INT(EXPECTED, GOT) \
assertInt(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertInt(const int expected,
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

#define ASSERT_SIZE(EXPECTED, GOT) \
assertSize(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertSize(const size_t expected,
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

#define ASSERT_PTR(EXPECTED, GOT) \
assertPtr(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertPtr(const void* expected,
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

#endif // !INC_5E_TESTS_H
