#include "mystring.h"
#include "mystring_tests.h"

static int isPalindrome(WordDescriptor word) {
  word.end--;
  while (word.begin < word.end) {
    if (*word.begin != *word.end) {
      return 0;
    }
    word.begin++;
    word.end--;
  }

  return 1;
}

void test_Panidrome_true() {
  char str_1[] = "abacaba";
  char str_2[] = "abacddcaba";
  char str_3[] = "a";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(1, isPalindrome(word));
  getWord(str_2, &word);
  ASSERT_INT(1, isPalindrome(word));
  getWord(str_3, &word);
  ASSERT_INT(1, isPalindrome(word));
  fprintf(stderr, "-------------------\n");
}

void test_Panidrome_false() {
  char str_1[] = "abdcaba";
  char str_2[] = "abacddaba";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(0, isPalindrome(word));
  getWord(str_2, &word);
  ASSERT_INT(0, isPalindrome(word));
  fprintf(stderr, "-------------------\n");
}

void test_Panidrome() {
  fprintf(stderr, "-------------------\n");
  test_Panidrome_true();
  test_Panidrome_false();
  fprintf(stderr, "\n");
}

size_t countPanidromes(char* str, char separator) {
  size_t count_Panidromes = 0;
  char* begin = str;
  char* end;
  size_t str_len = mystrlen(str);
  WordDescriptor word;
  while (*(end = find(begin, str + str_len, separator)) != '\0') {
    getWordReverse(begin - 1, end - 1, &word);
    count_Panidromes += isPalindrome(word);
    begin = end + 1;
  }

  getWordReverse(begin - 1, end - 1, &word);
  count_Panidromes += isPalindrome(word);

  return count_Panidromes;
}

void test_countPanidromes_allArePanidromes() {
  char str[] = "aba,abaccaba ,a";
  ASSERT_INT(3, countPanidromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPanidromes_notAllArePanidromes() {
  char str[] = "ab, caba  , aba,io, i";
  ASSERT_INT(2, countPanidromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPanidromes_allAreNotPanidromes() {
  char str[] = "ab, caba, ba, io, ik";
  ASSERT_INT(0, countPanidromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPanidromes_oneWord() {
  char str[] = "abcaba";
  ASSERT_INT(0, countPanidromes(str, ','));
  fprintf(stderr, "-------------------\n");
}


void test_countPanidromes_oneWordAndPanidrome() {
  char str[] = "abacaba";
  ASSERT_INT(1, countPanidromes(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPanidromes() {
  fprintf(stderr, "-------------------\n");
  test_countPanidromes_allArePanidromes();
  test_countPanidromes_notAllArePanidromes();
  test_countPanidromes_allAreNotPanidromes();
  test_countPanidromes_oneWord();
  test_countPanidromes_oneWordAndPanidrome();
  fprintf(stderr, "\n");
}

int main() {
  test_Panidrome();
  test_countPanidromes();

  return 0;
}