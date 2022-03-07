#include "../include/mystring.h"
#include "../tests/mystring_tests.h"

static int wordcmp(WordDescriptor w_1,
            WordDescriptor w_2) {
  int w_1_size = w_1.end - w_1.begin;
  int w_2_size = w_2.end - w_2.begin;

  if (w_1_size != w_2_size) {
    return w_1_size - w_2_size;
  }

  while (w_1.begin != w_1.end - 1 &&
         *w_1.begin == *w_2.begin) {
    w_1.begin++;
    w_2.begin++;
  }

  return *w_1.begin - *w_2.begin;
}

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
  char str[] = " abc    bca cba";
  ASSERT_INT(1, areWordsSorted(str));
  fprintf(stderr, "-------------------\n");
}

void test_areWordsSorted_notSorted() {
  char str[] = " abc  acb  aca ";
  ASSERT_INT(0, areWordsSorted(str));
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