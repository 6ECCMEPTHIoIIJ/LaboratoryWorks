#include "../include/mystring.h"
#include "../tests/tests.h"

void removeExtraSpaces(char* begin) {
  char* begin_dst = begin;
  begin = findNonSpace(begin);
  while (*begin != '\0') {
    if (*begin != ' ' || (*(begin + 1) != ' ' && *(begin + 1) != '\0')) {
      *begin_dst = *begin;
      begin_dst++;
    }
    begin++;
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

void test_removeExtraSpaces_allAreSpaces() {
  char str[] = "             ";
  removeExtraSpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_notAnySpaces() {
  char str[] = "aabbccdd";
  removeExtraSpaces(str);
  char expected[] = "aabbccdd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_someSpacesAreExtra() {
  char str[] = "asd s    ff a";
  removeExtraSpaces(str);
  char expected[] = "asd s ff a";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces_extraSpacesOnBounds() {
  char str[] = "    asd   asd     ";
  removeExtraSpaces(str);
  char expected[] = "asd asd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeExtraSpaces() {
  fprintf(stderr, "-------------------\n");
  test_removeExtraSpaces_empty();
  test_removeExtraSpaces_allAreSpaces();
  test_removeExtraSpaces_notAnySpaces();
  test_removeExtraSpaces_someSpacesAreExtra();
  test_removeExtraSpaces_extraSpacesOnBounds();
  fprintf(stderr, "\n");
}


int main() {
  test_removeExtraSpaces();
  return 0;
}