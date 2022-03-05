#include "../include/mystring.h"
#include "../tests/tests.h"

#include <stdbool.h>

#define ASCII_SYMBOLS_AMOUNT 256

void getLettersInString(char* str,
                        bool letters[ASCII_SYMBOLS_AMOUNT]) {
  while (*str != '\0') {
    letters[*str] = true;
    str++;
  }
}

bool isSubstringBySymbols(char* str_1,
                          char* str_2) {
  bool letters[ASCII_SYMBOLS_AMOUNT] = {0};
  getLettersInString(str_2, letters);

  while (*str_1 != '\0') {
    if (!letters[*str_1]) {
      return false;
    }
    
    str_1++;
  }

  return true;
}

void test_isSubstringBySymbols_bothEmpty() {
  char str_1[] = "";
  char str_2[] = "";
  ASSERT_INT(1, isSubstringBySymbols(str_1, str_2));
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols_firstEmpty() {
  char str_1[] = "";
  char str_2[] = " asf adf";
  ASSERT_INT(1, isSubstringBySymbols(str_1, str_2));
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols_secondEmpty() {
  char str_1[] = " avdfdbs d ";
  char str_2[] = "";
  ASSERT_INT(0, isSubstringBySymbols(str_1, str_2));
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols_diffAmountOfLetters() {
  char str_1[] = "hell";
  char str_2[] = "oleh";
  ASSERT_INT(1, isSubstringBySymbols(str_1, str_2));
  char str_3[] = "d        ea    th";
  char str_4[] = " death";
  ASSERT_INT(1, isSubstringBySymbols(str_3, str_4));
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols_false() {
  char str_1[] = "hell";
  char str_2[] = "  oeh  ";
  ASSERT_INT(0, isSubstringBySymbols(str_1, str_2));
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols() {
  fprintf(stderr, "-------------------\n");
  test_isSubstringBySymbols_bothEmpty();
  test_isSubstringBySymbols_firstEmpty();
  test_isSubstringBySymbols_secondEmpty();
  test_isSubstringBySymbols_diffAmountOfLetters();
  test_isSubstringBySymbols_false();
  fprintf(stderr, "\n");
}

int main() {
  test_isSubstringBySymbols();

  return 0;
}