#include "mystring.h"
#include "mystring_tests.h"

void replaceDigitsBySpaces(char* str) {
  char* read_ptr = str;
  char* write_ptr = _string_buffer;
  while (*read_ptr != '\0') {
    if (isdigit(*read_ptr)) {
      int digit = *read_ptr - '0';
      for (int i = 0; i < digit; i++) {
        *write_ptr = ' ';
        write_ptr++;
      }
    } else {
      *write_ptr = *read_ptr;
      write_ptr++;
    }
    read_ptr++;
  }
  *copy(_string_buffer, write_ptr, str) = '\0';
}

void test_replaceDigitsBySpaces_empty() {
  char str[] = "";
  replaceDigitsBySpaces(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replaceDigitsBySpaces_onlyDigits() {
  char str[] = "123";
  replaceDigitsBySpaces(str);
  char expected[] = "      ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replaceDigitsBySpaces_noneDigits() {
  char str[] = "a n s adqdas d    f ";
  replaceDigitsBySpaces(str);
  char expected[] = "a n s adqdas d    f ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replaceDigitsBySpaces_digitsAndLetters() {
  char str[] = "a2b4k1l 2 g";
  replaceDigitsBySpaces(str);
  char expected[] = "a  b    k l    g";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr() {
  fprintf(stderr, "-------------------\n");
  test_replaceDigitsBySpaces_empty();
  test_replaceDigitsBySpaces_onlyDigits();
  test_replaceDigitsBySpaces_noneDigits();
  test_replaceDigitsBySpaces_digitsAndLetters();
  fprintf(stderr, "\n");
}

int main() {
  test_digitToStartReverseStr();

  return 0;
}