#include "../include/mystring.h"
#include "../tests/mystring_tests.h"

int areWordsSorted(char* str) {
  WordDescriptor pre_word;
  if (getWord(str, &pre_word)) {
    WordDescriptor cur_word;
    while (getWord(pre_word.end, &cur_word)) {
      if (wordcmp(pre_word, cur_word) > 0) {
        return 0;
      }

      pre_word = cur_word;
    }

    return  1;
  }

  return 1;
}

void test_areWordsSorted_empty() {
  char str[] = "";
  ASSERT_INT(1, areWordsSorted(str));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_oneWord() {
  char str[] = "    dsaa   ";
  ASSERT_INT(1, areWordsSorted(str));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_sorted() {
  char str_1[] = " abc  abc  abca bcac bcac";
  ASSERT_INT(1, areWordsSorted(str_1));
  char str_2[] = "a b c ca cb da daa daaa  daab";
  ASSERT_INT(1, areWordsSorted(str_2));
  char str_3[] = "aaaaaaaaa b caaaa cab";
  ASSERT_INT(1, areWordsSorted(str_3));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_notSorted() {
  char str_1[] = " abca   abc abc abc bcac";
  ASSERT_INT(0, areWordsSorted(str_1));
  char str_2[] = "daab ka an dsa ";
  ASSERT_INT(0, areWordsSorted(str_2));
  char str_3[] = "ab aaaaaaaaa";
  ASSERT_INT(0, areWordsSorted(str_3));
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