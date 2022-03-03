#include "../include/mystring.h"
#include "../tests/tests.h"

int isnonspace(const int ch) {
  return !isspace(ch);
}

void removeSpaces(char* begin) {
  char* end = begin + mystrlen(begin);
  *copyIf(begin, end, begin, isnonspace) = '\0';
}

void test_removeSpaces_empty() {
  char str[] = "";
  removeSpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeSpaces_allAreEqual() {
  char str[] = "       ";
  removeSpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeSpaces_AllAreDuplicates() {
  char str[] = "   dsa fa    ";
  removeSpaces(str);
  char expected[] = "dsafa";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeSpaces_notAnyAreDuplicates() {
  char str[] = "dsafa";
  removeSpaces(str);
  char expected[] = "dsafa";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeSpaces() {
  fprintf(stderr, "-------------------\n");
  test_removeSpaces_empty();
  test_removeSpaces_allAreEqual();
  test_removeSpaces_AllAreDuplicates();
  test_removeSpaces_notAnyAreDuplicates();
  fprintf(stderr, "\n");
}

int main() {
  test_removeSpaces();
  return 0;
}