#include "tests.h"
#include "mystring_tests.h"

/*
 * Сокращает число идущих подряд символов строки str до одного
 */
void removeAdjacentEqualLetters(char* str) {
  char* begin_dst = str;
  while (*str != '\0') {
    if (*str != *(str + 1)) {
      *begin_dst = *str;
      begin_dst++;
    }
    str++;
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

void test_removeExtraSpaces_allAreDuplicates() {
  char str[] = "aabbccdd";
  removeAdjacentEqualLetters(str);
  char expected[] = "abcd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_noneDuplicates() {
  char str[] = "abcdabcd";
  removeAdjacentEqualLetters(str);
  char expected[] = "abcdabcd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_someWords() {
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
  test_removeExtraSpaces_allAreDuplicates();
  test_removeExtraSpaces_noneDuplicates();
  test_removeExtraSpaces_someWords();
  fprintf(stderr, "\n");
}


int main() {
  test_removeAdjacentEqualLetters();
  return 0;
}