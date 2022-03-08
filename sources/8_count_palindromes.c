#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>

/*
 * Возвращает true, если слово word - палиндром, и false в противном случае
 */
static bool isPalindrome(WordDescriptor word) {
  word.end--;
  while (word.begin < word.end) {
    if (*word.begin != *word.end) {
      return false;
    }
    word.begin++;
    word.end--;
  }

  return true;
}

void test_isPalindrome_true() {
  char str_1[] = "abacaba";
  char str_2[] = "abacddcaba";
  char str_3[] = "a";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(true, isPalindrome(word));
  getWord(str_2, &word);
  ASSERT_INT(true, isPalindrome(word));
  getWord(str_3, &word);
  ASSERT_INT(true, isPalindrome(word));
  fprintf(stderr, "-------------------\n");
}

void test_isPalindrome_false() {
  char str_1[] = "abdcaba";
  char str_2[] = "abacddaba";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(false, isPalindrome(word));
  getWord(str_2, &word);
  ASSERT_INT(false, isPalindrome(word));
  fprintf(stderr, "-------------------\n");
}

void test_isPalindrome() {
  fprintf(stderr, "-------------------\n");
  test_isPalindrome_true();
  test_isPalindrome_false();
  fprintf(stderr, "\n");
}

/*
 * Возвращает кол-во палиндромов, содержащихся в строке str и разделенных
 * символом separator
 */
size_t countPalindromes(char* str, char separator) {
  size_t count_isPalindromes = 0;
  char* begin = str;
  char* end;
  size_t str_len = mystrlen(str);
  WordDescriptor word;
  while (*(end = find(begin, str + str_len, separator)) != '\0') {
    getWordReverse(begin - 1, end - 1, &word);
    count_isPalindromes += isPalindrome(word);
    begin = end + 1;
  }

  getWordReverse(begin - 1, end - 1, &word);
  count_isPalindromes += isPalindrome(word);

  return count_isPalindromes;
}

void test_countPalindromes_allArePalindromes() {
  char str[] = "aba,abaccaba ,a";
  ASSERT_INT(3, countPalindromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPalindromes_notAllArePalindromes() {
  char str[] = "ab, caba  , aba,io, i";
  ASSERT_INT(2, countPalindromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPalindromes_allAreNotPalindromes() {
  char str[] = "ab, caba, ba, io, ik";
  ASSERT_INT(0, countPalindromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPalindromes_oneWord() {
  char str[] = "abcaba";
  ASSERT_INT(0, countPalindromes(str, ','));
  fprintf(stderr, "-------------------\n");
}


void test_countPalindromes_oneWordAndPalindrome() {
  char str[] = "abacaba";
  ASSERT_INT(1, countPalindromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPalindromes() {
  fprintf(stderr, "-------------------\n");
  test_countPalindromes_allArePalindromes();
  test_countPalindromes_notAllArePalindromes();
  test_countPalindromes_allAreNotPalindromes();
  test_countPalindromes_oneWord();
  test_countPalindromes_oneWordAndPalindrome();
  fprintf(stderr, "\n");
}

int main() {
  test_isPalindrome();
  test_countPalindromes();

  return 0;
}