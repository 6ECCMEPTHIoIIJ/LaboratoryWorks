#include "mystring.h"
#include "mystring_tests.h"
#include <stdlib.h>

#include <stdbool.h>

/*
 * Компаратор для сравнения двух слов arg_1 и arg_2
 */
static int wordcmp_(const void* arg_1, const void* arg_2) {
  return wordcmp(*(WordDescriptor*) arg_1, *(WordDescriptor*) arg_2);
}

/*
 * Возвращает true, если в строке str содержатся одинаковые слова, и false в
 * противном случае
 */
bool hasStringEqualWords(char* str) {
  getBagOfWords(str, &_bag_1);
  qsort(_bag_1.words, _bag_1.size, sizeof(*_bag_1.words), wordcmp_);
  for (size_t i = 1; i < _bag_1.size; i++) {
    if (wordcmp(_bag_1.words[i], _bag_1.words[i - 1]) == 0) {
      return true;
    }
  }

  return false;
}

void test_hasStringEqualWords_empty() {
  char str[] = "";
  char expected[] = "";
  ASSERT_INT(false, hasStringEqualWords(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_oneWord() {
  char str[] = "qwd";
  char expected[] = "qwd";
  ASSERT_INT(false, hasStringEqualWords(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_false() {
  char str[] = "qwd asd cqcw cjoa cqc";
  char expected[] = "qwd asd cqcw cjoa cqc";
  ASSERT_INT(false, hasStringEqualWords(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords_true() {
  char str[] = "qwd asd cqcw dais aosna asd kbw qwej cqw";
  char expected[] = "qwd asd cqcw dais aosna asd kbw qwej cqw";
  ASSERT_INT(true, hasStringEqualWords(str));
  ASSERT_STRING(expected, str);
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