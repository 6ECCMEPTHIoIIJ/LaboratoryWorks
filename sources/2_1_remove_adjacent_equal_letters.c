#include "../tests/tests.h"

void removeAdjacentEqualLetters(char* begin) {
  char* begin_dst = begin;
  while (*begin != '\0') {
    if (*begin != *(begin + 1)) {
      *begin_dst = *begin;
      begin_dst++;
    }
    begin++;
  }
  *begin_dst = '\0';
}

void test_removeAdjacentEqualLetters_empty() {
  char str[] = "";
  removeAdjacentEqualLetters(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeAdjacentEqualLetters_allAreEqual() {
  char str[] = "             ";
  removeAdjacentEqualLetters(str);
  char expected[] = " ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_notAnySpaces() {
  char str[] = "aabbccdd";
  removeAdjacentEqualLetters(str);
  char expected[] = "abcd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_someSpacesAreExtra() {
  char str[] = "abcdabcd";
  removeAdjacentEqualLetters(str);
  char expected[] = "abcdabcd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_extraSpacesOnBounds() {
  char str[] = "aaabccc d d eee";
  removeAdjacentEqualLetters(str);
  char expected[] = "abc d d e";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeAdjacentEqualLetters() {
  fprintf(stderr, "-------------------\n");
  test_removeAdjacentEqualLetters_empty();
  test_removeAdjacentEqualLetters_allAreEqual();
  test_removeExtraSpaces_notAnySpaces();
  test_removeExtraSpaces_someSpacesAreExtra();
  test_removeExtraSpaces_extraSpacesOnBounds();
  fprintf(stderr, "\n");
}


int main() {
  test_removeAdjacentEqualLetters();
  return 0;
}