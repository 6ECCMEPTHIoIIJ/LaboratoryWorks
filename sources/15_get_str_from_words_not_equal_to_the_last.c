#include "mystring.h"
#include "mystring_tests.h"

/*
 * Преобразует строку str, оставляя в ней только слова, отличные от ее
 * последнего слова, не сохраняет пробельные символы исходной строки. В
 * качестве разделителя использует символ пробела
 */
void getStrFromWordsNotEqualToTheLast(char* str) {
  char* r_end = str - 1;
  char* r_begin = str + mystrlen(str) - 1;
  WordDescriptor last_word;
  getWordReverse(r_end, r_begin, &last_word);
  char* begin_src = str;
  char* begin_dst = str;
  WordDescriptor cur_word;
  while (getWord(begin_src, &cur_word)) {
    if (wordcmp(cur_word, last_word) != 0) {
      begin_dst = copy(cur_word.begin, cur_word.end, begin_dst);
      *begin_dst++ = ' ';
    }
    begin_src = cur_word.end;
  }

  *(begin_dst - (begin_dst != str)) = '\0';
}

void test_getStrFromWordsNotEqualToTheLast_empty() {
  char str[] = "";
  getStrFromWordsNotEqualToTheLast(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast_oneWord() {
  char str[] = "  asfasg    ";
  getStrFromWordsNotEqualToTheLast(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast_noneWordsEqualToLast() {
  char str[] = "it  seems   you talk   too  much";
  getStrFromWordsNotEqualToTheLast(str);
  char expected[] = "it seems you talk too";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast_allWordsAreEqualToLast() {
  char str[] = "kill    kill kill    kill kill";
  getStrFromWordsNotEqualToTheLast(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast_notAllWordsAreEqualToLast() {
  char str[] = "kill   them all ,   kill   them all";
  getStrFromWordsNotEqualToTheLast(str);
  char expected[] = "kill them , kill them";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast() {
  fprintf(stderr, "-------------------\n");
  test_getStrFromWordsNotEqualToTheLast_empty();
  test_getStrFromWordsNotEqualToTheLast_oneWord();
  test_getStrFromWordsNotEqualToTheLast_noneWordsEqualToLast();
  test_getStrFromWordsNotEqualToTheLast_allWordsAreEqualToLast();
  test_getStrFromWordsNotEqualToTheLast_notAllWordsAreEqualToLast();
  fprintf(stderr, "\n");
}

int main() {
  test_getStrFromWordsNotEqualToTheLast();
  return 0;
}