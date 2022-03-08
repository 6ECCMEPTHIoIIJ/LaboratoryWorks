#include "mystring_tests.h"
#include "mystring.h"

#include <stdbool.h>

static bool isWordFound(char* str,
                WordDescriptor word) {
  WordDescriptor cur_word;
  char *begin = str;
  while (getWord(begin, &cur_word)) {
    if (wordcmp(word, cur_word) == 0) {
      return true;
    }
    begin = cur_word.end;
  }

  return false;
}

void test_isWordFound_empty() {
  char str[] = "";
  WordDescriptor word;
  char word_in_char[] = "find_me";
  getWord(word_in_char, &word);
  ASSERT_INT(false, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound_notFound() {
  char str[] = "hi, i`m here, find me";
  WordDescriptor word;
  char word_in_char[] = "find_me";
  getWord(word_in_char, &word);
  ASSERT_INT(false, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound_foundNotFirst() {
  char str[] = "I will destroy everything";
  WordDescriptor word;
  char word_in_char[] = "destroy";
  getWord(word_in_char, &word);
  ASSERT_INT(true, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound_foundFirst() {
  char str[] = "I will destroy everything";
  WordDescriptor word;
  char word_in_char[] = "I";
  getWord(word_in_char, &word);
  ASSERT_INT(true, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound_foundLast() {
  char str[] = "I will destroy everything";
  WordDescriptor word;
  char word_in_char[] = "everything";
  getWord(word_in_char, &word);
  ASSERT_INT(true, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound_foundOneWord() {
  char str[] = "haha";
  WordDescriptor word;
  char word_in_char[] = "haha";
  getWord(word_in_char, &word);
  ASSERT_INT(true, isWordFound(str, word));
  fprintf(stderr, "-------------------\n");
}

void test_isWordFound() {
  fprintf(stderr, "-------------------\n");
  test_isWordFound_empty();
  test_isWordFound_notFound();
  test_isWordFound_foundNotFirst();
  test_isWordFound_foundFirst();
  test_isWordFound_foundLast();
  test_isWordFound_foundOneWord();
  fprintf(stderr, "\n");
}

/*
 * Возвращает true, если строки str_1 и str_2 содержат одинаковые слова,
 * сохраняет последнее слово строки str_1, содержащееся и в str_2 в
 * last_word, в противном случае возвращает false и оставляет значение
 * last_word оставляет без изменения
 */
static bool findLastEqualWordInBothStr(char* str_1,
                                char* str_2,
                                WordDescriptor* last_word) {
  char* r_end_1 = str_1 - 1;
  char* r_begin_1 = str_1 + mystrlen(str_1) - 1;
  WordDescriptor cur_word;
  while (getWordReverse(r_end_1, r_begin_1, &cur_word)) {
    if (isWordFound(str_2, cur_word)) {
      *last_word = cur_word;
      return true;
    }
    r_begin_1 = cur_word.begin - 1;
  }

  return false;
}

void test_findLastEqualWordInBothStr_notLast() {
  char str_1[] = "meet in hell my dear";
  char str_2[] = "in hell , I said";
  WordDescriptor word;
  ASSERT_INT(true, findLastEqualWordInBothStr(str_1, str_2, &word));
  char expected[] = "hell";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_lastForFirstStr() {
  char str_1[] = "meet in hell";
  char str_2[] = "in hell , I said";
  WordDescriptor word;
  ASSERT_INT(1, findLastEqualWordInBothStr(str_1, str_2, &word));
  char expected[] = "hell";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_lastForSecondStr() {
  char str_1[] = "meet in hell my dear";
  char str_2[] = "in hell";
  WordDescriptor word;
  ASSERT_INT(true, findLastEqualWordInBothStr(str_1, str_2, &word));
  char expected[] = "hell";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_emptyBoth() {
  char str_1[] = "";
  char str_2[] = "";
  WordDescriptor word;
  ASSERT_INT(false, findLastEqualWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_emptyFirst() {
  char str_1[] = "";
  char str_2[] = "one by one";
  WordDescriptor word;
  ASSERT_INT(false, findLastEqualWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_emptySecond() {
  char str_1[] = "my friend of misery";
  char str_2[] = "";
  WordDescriptor word;
  ASSERT_INT(false, findLastEqualWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_notFound() {
  char str_1[] = "my friend of misery";
  char str_2[] = "meet in hell";
  WordDescriptor word;
  ASSERT_INT(false, findLastEqualWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr_oneWord() {
  char str_1[] = "armageddon";
  char str_2[] = "armageddon";
  WordDescriptor word;
  ASSERT_INT(true, findLastEqualWordInBothStr(str_1, str_2, &word));
  char expected[] = "armageddon";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_findLastEqualWordInBothStr() {
  fprintf(stderr, "-------------------\n");
  test_findLastEqualWordInBothStr_notLast();
  test_findLastEqualWordInBothStr_lastForFirstStr();
  test_findLastEqualWordInBothStr_lastForSecondStr();
  test_findLastEqualWordInBothStr_emptyBoth();
  test_findLastEqualWordInBothStr_emptyFirst();
  test_findLastEqualWordInBothStr_emptySecond();
  test_findLastEqualWordInBothStr_notFound();
  test_findLastEqualWordInBothStr_oneWord();
  fprintf(stderr, "\n");
}


int main() {
  test_isWordFound();
  test_findLastEqualWordInBothStr();

  return 0;
}