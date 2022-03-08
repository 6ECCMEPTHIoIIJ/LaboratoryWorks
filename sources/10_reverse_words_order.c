#include "mystring.h"
#include "mystring_tests.h"

/*
 * Меняет порядок слов в строке str на обратный, не сохраняет пробельные
 * символы исходной строки. В качестве разделителя использует символ пробела
 */
void reverseWordsOrder(char* str) { // отсутствие сохранения исходных
  // пробельных символов обусловлено спецификой задания: не использовать
  // BagOfWords
  char* r_begin_src = str + mystrlen(str) - 1;
  char* r_end_src = str - 1;
  char* begin_dst = _string_buffer;
  WordDescriptor word;
  while (getWordReverse(r_end_src, r_begin_src, &word)) {
    begin_dst = copy(word.begin, word.end, begin_dst);
    *begin_dst++ = ' ';
    r_begin_src = word.begin - 1;
  }

  *copy(_string_buffer, begin_dst - (begin_dst != _string_buffer), str) = '\0';
}

void test_reverseWordsOrder_empty() {
  char str[] = "";
  reverseWordsOrder(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseWordsOrder_oneWord() {
  char str[] = "asd";
  reverseWordsOrder(str);
  char expected[] = "asd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseWordsOrder_someWords() {
  char str[] = "death   is  near";
  reverseWordsOrder(str);
  char expected[] = "near is death";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseWordsOrder() {
  fprintf(stderr, "-------------------\n");
  test_reverseWordsOrder_empty();
  test_reverseWordsOrder_oneWord();
  test_reverseWordsOrder_someWords();
  fprintf(stderr, "\n");
}

int main() {
  test_reverseWordsOrder();

  return 0;
}