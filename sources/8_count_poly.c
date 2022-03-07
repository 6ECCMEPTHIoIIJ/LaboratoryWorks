#include "mystring.h"
#include "mystring_tests.h"

int isPoly(WordDescriptor word) {
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

void test_isPoly_true() {
  char str_1[] = "abacaba";
  char str_2[] = "abacddcaba";
  char str_3[] = "a";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(1, isPoly(word));
  getWord(str_2, &word);
  ASSERT_INT(1, isPoly(word));
  getWord(str_3, &word);
  ASSERT_INT(1, isPoly(word));
  fprintf(stderr, "-------------------\n");
}

void test_isPoly_false() {
  char str_1[] = "abdcaba";
  char str_2[] = "abacddaba";
  WordDescriptor word;
  getWord(str_1, &word);
  ASSERT_INT(0, isPoly(word));
  getWord(str_2, &word);
  ASSERT_INT(0, isPoly(word));
  fprintf(stderr, "-------------------\n");
}

void test_isPoly() {
  fprintf(stderr, "-------------------\n");
  test_isPoly_true();
  test_isPoly_false();
  fprintf(stderr, "\n");
}

size_t countPoly(char* str, char separator) {
  size_t count_poly = 0;
  char* begin = str;
  char* end;
  size_t str_len = mystrlen(str);
  WordDescriptor word;
  while (*(end = find(begin, str + str_len, separator)) != '\0') {
    getWordReverse(begin - 1, end - 1, &word);
    count_poly += isPoly(word);
    begin = end + 1;
  }

  getWordReverse(begin - 1, end - 1, &word);
  count_poly += isPoly(word);

  return count_poly;
}

void test_countPoly_allArePoly() {
  char str[] = "aba, abaccaba ,a";
  ASSERT_INT(3, countPoly(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPoly_notAllArePoly() {
  char str[] = "ab, caba, aba, io, i";
  ASSERT_INT(2, countPoly(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPoly_allAreNotPoly() {
  char str[] = "ab, caba, ba, io, ik";
  ASSERT_INT(0, countPoly(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPoly_oneWord() {
  char str[] = "abcaba";
  ASSERT_INT(0, countPoly(str, ','));
  fprintf(stderr, "-------------------\n");
}


void test_countPoly_oneWordAndIsPoly() {
  char str[] = "abacaba";
  ASSERT_INT(1, countPoly(str, ','));
  fprintf(stderr, "-------------------\n");
}

void test_countPoly() {
  fprintf(stderr, "-------------------\n");
  test_countPoly_allArePoly();
  test_countPoly_notAllArePoly();
  test_countPoly_allAreNotPoly();
  test_countPoly_oneWord();
  test_countPoly_oneWordAndIsPoly();
  fprintf(stderr, "\n");
}

int main() {
  test_isPoly();
  test_countPoly();

  return 0;
}