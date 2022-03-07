#include "mystring.h"
#include "mystring_tests.h"

/**
 * @brief   Удаление лишних пробелов в начале и конце строки, сокращение числа
 *          пробелов между словами до 1
 * @param str указатель на начало строки
 */
void removeExtraSpaces(char* str) {
  char* begin_dst = str;
  str = findNonSpace(str);
  while (*str != '\0') {
    if (*str != ' ' || (*(str + 1) != ' ' && *(str + 1) != '\0')) {
      *begin_dst = *str;
      begin_dst++;
    }
    str++;
  }
  *begin_dst = '\0';
}

void test_removeExtraSpaces_empty() {
  char str[] = "";
  removeExtraSpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_oneWord() {
  char str[] = "             ";
  removeExtraSpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_nonLettersNoneDigits() {
  char str[] = "aabbccdd";
  removeExtraSpaces(str);
  char expected[] = "aabbccdd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_noneLetters() {
  char str[] = "asd s    ff a";
  removeExtraSpaces(str);
  char expected[] = "asd s ff a";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_someWords() {
  char str[] = "    asd   asd     ";
  removeExtraSpaces(str);
  char expected[] = "asd asd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces() {
  fprintf(stderr, "-------------------\n");
  test_removeExtraSpaces_empty();
  test_removeExtraSpaces_oneWord();
  test_removeExtraSpaces_nonLettersNoneDigits();
  test_removeExtraSpaces_noneLetters();
  test_removeExtraSpaces_someWords();
  fprintf(stderr, "\n");
}


int main() {
  test_removeExtraSpaces();
  return 0;
}