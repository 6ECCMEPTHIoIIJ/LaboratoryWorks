#include "mystring.h"
#include "mystring_tests.h"

/*
 * Удаляет пробелы по краям строки str и сокращает число пробелов между словами
 * до одного
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

void test_removeExtraSpaces_allAreDuplicates() {
  char str[] = "aabbccdd";
  removeExtraSpaces(str);
  char expected[] = "aabbccdd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_noneDuplicates() {
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
  test_removeExtraSpaces_allAreDuplicates();
  test_removeExtraSpaces_noneDuplicates();
  test_removeExtraSpaces_someWords();
  fprintf(stderr, "\n");
}


int main() {
  test_removeExtraSpaces();
  return 0;
}