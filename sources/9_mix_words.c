#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>

void mixWords(char* str_1,
              char* str_2,
              char* str_mixed) {
  WordDescriptor w_1, w_2;
  bool is_w_1_found, is_w_2_found;
  char* begin_search_1 = str_1;
  char* begin_search_2 = str_2;
  char* dst = str_mixed;
  while ((is_w_1_found = getWord(begin_search_1, &w_1)),
         (is_w_2_found = getWord(begin_search_2, &w_2)),
         is_w_1_found || is_w_2_found) {
    if (is_w_1_found) {
      dst = copy(w_1.begin, w_1.end, dst);
      *dst++ = ' ';
      begin_search_1 = w_1.end;
    }
    if (is_w_2_found) {
      dst = copy(w_2.begin, w_2.end, dst);
      *dst++ = ' ';
      begin_search_2 = w_2.end;
    }
  }
  *(dst - (dst != str_mixed)) = '\0';
}

void test_mixWords_empty() {
  char str_1[] = "";
  char str_2[] = "";
  char str[mystrlen(str_1) + mystrlen(str_2) + 1];
  mixWords(str_1, str_2, str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_mixWords_secondLonger() {
  char str_1[] = "meet";
  char str_2[] = "in    hell   my darling";
  char str[mystrlen(str_1) + mystrlen(str_2) + 1];
  mixWords(str_1, str_2, str);
  char expected[] = "meet in hell my darling";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_mixWords_firstLonger() {
  char str_1[] = "I kill in seven days";
  char str_2[] = "will you";
  char str[mystrlen(str_1) + mystrlen(str_2) + 1];
  mixWords(str_1, str_2, str);
  char expected[] = "I will kill you in seven days";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_mixWords_equalLength() {
  char str_1[] = "I`m wanderer, vagabond me you";
  char str_2[] = "rover, nomad, call what will";
  char str[mystrlen(str_1) + mystrlen(str_2) + 1];
  mixWords(str_1, str_2, str);
  char expected[] = "I`m rover, wanderer, nomad, vagabond call me what you "
                    "will";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_mixWords() {
  fprintf(stderr, "-------------------\n");
  test_mixWords_empty();
  test_mixWords_secondLonger();
  test_mixWords_firstLonger();
  test_mixWords_equalLength();
  fprintf(stderr, "\n");
}

int main() {
  test_mixWords();

  return 0;
}