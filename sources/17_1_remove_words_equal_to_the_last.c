#include "mystring.h"
#include "mystring_tests.h"

void removeWordsEqualToTheLast(char* str) {
  char* r_end = str - 1;
  char* r_begin = str + mystrlen(str) - 1;
  WordDescriptor last_word;
  getWordReverse(r_end, r_begin, &last_word);
  char* begin_src = str;
  char* begin_dst = str;
  WordDescriptor cur_word;
  while (getWord(begin_src, &cur_word)) {
    begin_dst = copy(begin_src, cur_word.begin, begin_dst);
    if (wordcmp(cur_word, last_word) != 0) {
      begin_dst = copy(cur_word.begin, cur_word.end, begin_dst);
    }
    begin_src = cur_word.end;
  }

  *copy(begin_src, str + mystrlen(str), begin_dst) = '\0';
}

void test_removeWordsEqualToTheLast_empty() {
  char str[] = "";
  removeWordsEqualToTheLast(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeWordsEqualToTheLast_oneWord() {
  char str[] = "  asfasg    ";
  removeWordsEqualToTheLast(str);
  char expected[] = "      ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeWordsEqualToTheLast_noneWordsEqualToLast() {
  char str[] = "it  seems   you talk   too  much ";
  removeWordsEqualToTheLast(str);
  char expected[] = "it  seems   you talk   too   ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeWordsEqualToTheLast_allWordsAreEqualToLast() {
  char str[] = "kill    kill kill    kill kill";
  removeWordsEqualToTheLast(str);
  char expected[] = "          ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removeWordsEqualToTheLast_notAllWordsAreEqualToLast() {
  char str[] = "kill   them all ,   kill   them all";
  removeWordsEqualToTheLast(str);
  char expected[] = "kill   them  ,   kill   them ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_getStrFromWordsNotEqualToTheLast() {
  fprintf(stderr, "-------------------\n");
  test_removeWordsEqualToTheLast_empty();
  test_removeWordsEqualToTheLast_oneWord();
  test_removeWordsEqualToTheLast_noneWordsEqualToLast();
  test_removeWordsEqualToTheLast_allWordsAreEqualToLast();
  test_removeWordsEqualToTheLast_notAllWordsAreEqualToLast();
  fprintf(stderr, "\n");
}

int main() {
  test_getStrFromWordsNotEqualToTheLast();
  return 0;
}