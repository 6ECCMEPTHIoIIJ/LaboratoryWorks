#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>

/*
 *
 */
bool areWordsSorted(char* str) {
  WordDescriptor pre_word;
  if (getWord(str, &pre_word)) {
    WordDescriptor cur_word;
    while (getWord(pre_word.end, &cur_word)) {
      if (wordcmp(pre_word, cur_word) > 0) {
        return false;
      }
      pre_word = cur_word;
    }
  }

  return true;
}

void test_areWordsSorted_empty() {
  char str[] = "";
  ASSERT_INT(true, areWordsSorted(str));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_oneWord() {
  char str[] = "    dsaa   ";
  ASSERT_INT(true, areWordsSorted(str));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_sorted() {
  char str_1[] = " abc  abc  abca bcac bcac";
  ASSERT_INT(true, areWordsSorted(str_1));
  char str_2[] = "a b c ca cb da daa daaa  daab";
  ASSERT_INT(true, areWordsSorted(str_2));
  char str_3[] = "aaaaaaaaa b caaaa cab";
  ASSERT_INT(true, areWordsSorted(str_3));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_notSorted() {
  char str_1[] = " abca   abc abc abc bcac";
  ASSERT_INT(false, areWordsSorted(str_1));
  char str_2[] = "daab ka an dsa ";
  ASSERT_INT(false, areWordsSorted(str_2));
  char str_3[] = "ab aaaaaaaaa";
  ASSERT_INT(false, areWordsSorted(str_3));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted() {
  fprintf(stderr, "-------------------\n");
  test_areWordsSorted_empty();
  test_areWordsSorted_oneWord();
  test_areWordsSorted_sorted();
  test_areWordsSorted_notSorted();
  fprintf(stderr, "\n");
}

int main() {
  test_areWordsSorted();

  return 0;
}