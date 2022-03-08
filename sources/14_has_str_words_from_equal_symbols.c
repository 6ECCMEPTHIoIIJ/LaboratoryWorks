#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>
#include <stdlib.h>

/*
 * Компаратор для сравнения двух слов arg_1 и arg_2
 */
static int wordcmp_(const void* arg_1, const void* arg_2) {
  return wordcmp(*(WordDescriptor*) arg_1, *(WordDescriptor*) arg_2);
}

/*
 * Компаратор для сравнения двух символов arg_1 и arg_2
 */
static int chcmp_(const void* arg_1, const void* arg_2) {
  return *(char*) arg_1 - *(char*) arg_2;
}

/*
 * Сокращает число идущих подряд символов слова word до одного
 */
void removeAdjacentEqualLettersInWord(WordDescriptor* word) {
  char* begin_dst = word->begin;
  char* begin_src = word->begin;
  while (begin_src != word->end) {
    if (*begin_src != *(begin_src + 1)) {
      *begin_dst = *begin_src;
      begin_dst++;
    }
    begin_src++;
  }
  word->end = begin_dst;
}

void test_removeAdjacentEqualLettersInWord_allAreEqual() {
  char str[] = "aaaaaaaaa";
  WordDescriptor word;
  getWord(str, &word);
  removeAdjacentEqualLettersInWord(&word);
  char expected[] = "a";
  char str_from_word[sizeof(expected)];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}

void test_removeAdjacentEqualLettersInWord_notAllAreDuplicates() {
  char str[] = "aabccdcdcd";
  WordDescriptor word;
  getWord(str, &word);
  removeAdjacentEqualLettersInWord(&word);
  char expected[] = "abcdcdcd";
  char str_from_word[sizeof(expected)];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}

void test_removeAdjacentEqualLettersInWord_allAreDuplicates() {
  char str[] = "aabbccddccdd";
  WordDescriptor word;
  getWord(str, &word);
  removeAdjacentEqualLettersInWord(&word);
  char expected[] = "abcdcd";
  char str_from_word[sizeof(expected)];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}

void test_removeAdjacentEqualLettersInWord() {
  fprintf(stderr, "-------------------\n");
  test_removeAdjacentEqualLettersInWord_allAreEqual();
  test_removeAdjacentEqualLettersInWord_notAllAreDuplicates();
  test_removeAdjacentEqualLettersInWord_allAreDuplicates();
  fprintf(stderr, "\n");
}

bool hasStrWordsFromEqualSymbols(char* str) {
  *copy(str, str + mystrlen(str), _string_buffer) = '\0';
  getBagOfWords(_string_buffer, &_bag_1);
  for (size_t i = 0; i < _bag_1.size; i++) {
    qsort(_bag_1.words[i].begin, _bag_1.words[i].end - _bag_1.words[i].begin, sizeof(char), chcmp_);
    removeAdjacentEqualLettersInWord(&_bag_1.words[i]);
  }
  qsort(_bag_1.words, _bag_1.size, sizeof(*_bag_1.words), wordcmp_);
  for (size_t i = 1; i < _bag_1.size; i++) {
    if (wordcmp(_bag_1.words[i], _bag_1.words[i - 1]) == 0) {
      return true;
    }
  }

  return false;
}

void test_hasStrWordsFromEqualSymbols_empty() {
  char str[] = "";
  char expected[] = "";
  ASSERT_INT(false, hasStrWordsFromEqualSymbols(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStrWordsFromEqualSymbols_oneWord() {
  char str[] = "afasf";
  char expected[] = "afasf";
  ASSERT_INT(false, hasStrWordsFromEqualSymbols(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStrWordsFromEqualSymbols_false() {
  char str[] = "aaaaa b sad said kill cool ";
  char expected[] = "aaaaa b sad said kill cool ";
  ASSERT_INT(false, hasStrWordsFromEqualSymbols(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStrWordsFromEqualSymbols_true() {
  char str[] = "aaaaa b sad said kill a ";
  char expected[] = "aaaaa b sad said kill a ";
  ASSERT_INT(true, hasStrWordsFromEqualSymbols(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStrWordsFromEqualSymbols_trueManyTimes() {
  char str[] = "aaaaa iassadsdasasdiiidaads b sad said kill aasadsadasdasda ";
  char expected[] = "aaaaa iassadsdasasdiiidaads b sad said kill aasadsadasdasda ";
  ASSERT_INT(true, hasStrWordsFromEqualSymbols(str));
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_hasStringEqualWords() {
  fprintf(stderr, "-------------------\n");
  test_hasStrWordsFromEqualSymbols_empty();
  test_hasStrWordsFromEqualSymbols_oneWord();
  test_hasStrWordsFromEqualSymbols_false();
  test_hasStrWordsFromEqualSymbols_true();
  test_hasStrWordsFromEqualSymbols_trueManyTimes();
  fprintf(stderr, "\n");
}

int main() {
  test_removeAdjacentEqualLettersInWord();
  test_hasStringEqualWords();

  return 0;
}