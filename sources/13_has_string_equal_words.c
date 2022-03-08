#include "mystring.h"
#include "mystring_tests.h"
#include <stdlib.h>

int hasStringEqualWords(char* str) {
  getBagOfWords(str, &_bag_1);
  qsort(_bag_1.words, _bag_1.size, sizeof(*_bag_1.words), wordcmp);
  for (size_t i = 1; i < _bag_1.size; i++) {
    if (wordcmp(_bag_1.words[i], _bag_1.words[i - 1]) == 0) {
      return 1;
    }
  }

  return 0;
}

void test_hasStringEqualWords_empty() {
  char str[] = "";
  ASSERT_INT(0, hasStringEqualWords(str));
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_oneWord() {
  char str[] = "qwd";
  ASSERT_INT(0, hasStringEqualWords(str));
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_false() {
  char str[] = "qwd asd cqcw cjoa cqc";
  ASSERT_INT(0, hasStringEqualWords(str));
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_true() {
  char str[] = "qwd asd cqcw dais aosna asd kbw qwej cqw";
  ASSERT_INT(1, hasStringEqualWords(str));
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords() {
  fprintf(stderr, "-------------------\n");
  test_hasStringEqualWords_empty();
  test_hasStringEqualWords_oneWord();
  test_hasStringEqualWords_false();
  test_hasStringEqualWords_true();
  fprintf(stderr, "\n");
}

int main() {
  test_hasStringEqualWords();

  return 0;
}