#include "mystring.h"
#include "mystring_tests.h"

/*
 * Если строки str_1 и str_2 содержат различное кол-во слов, добавляет
 * недостающие слова в строку с меньшим числом слов, в противном случае
 * оставляет строки без изменений. При дополнении сохраняет пробельные символы
 * исходной строки, содержащей меньшее кол-во слов, между добавленными
 * словами в качестве разделителя используется символ пробела, строка с
 * большим числом остается без изменений
 */
void addWordsToShorterStr(char* str_1,
                          char* str_2) {
  getBagOfWords(str_1, &_bag_1);
  getBagOfWords(str_2, &_bag_2);

  char* begin_1 = findNonSpaceReverse(str_1 - 1,
                                      str_1 + mystrlen(str_1) - 1) + 1;
  for (size_t i = _bag_1.size; i < _bag_2.size; i++) {
    *begin_1++ = ' ';
    begin_1 = copy(_bag_2.words[i].begin, _bag_2.words[i].end, begin_1);
  }
  char* begin_2 = findNonSpaceReverse(str_2 - 1,
                                      str_2 + mystrlen(str_2) - 1) + 1;
  for (size_t i = _bag_2.size; i < _bag_1.size; i++) {
    *begin_2++ = ' ';
    begin_2 = copy(_bag_1.words[i].begin, _bag_1.words[i].end, begin_2);
  }

  *begin_1 = '\0';
  *begin_2 = '\0';
}

void test_addWordsToShorterStr_empty() {
  char str_1[] = "";
  char str_2[] = "";
  addWordsToShorterStr(str_1, str_2);
  char expected_1[] = "";
  char expected_2[] = "";
  ASSERT_STRING(expected_1, str_1);
  ASSERT_STRING(expected_2, str_2);
  fprintf(stderr, "-------------------\n");
}

void test_addWordsToShorterStr_firstLonger() {
  char str_1[] = "finish   him";
  char str_2[9] = "heal";
  addWordsToShorterStr(str_1, str_2);
  char expected_1[] = "finish   him";
  char expected_2[] = "heal him";
  ASSERT_STRING(expected_1, str_1);
  ASSERT_STRING(expected_2, str_2);
  fprintf(stderr, "-------------------\n");
}

void test_addWordsToShorterStr_secondLonger() {
  char str_1[34] = "finish   him   quickly";
  char str_2[] = "it isn`t good to\tdo\nthis";
  addWordsToShorterStr(str_1, str_2);
  char expected_1[] = "finish   him   quickly to do this";
  char expected_2[] = "it isn`t good to\tdo\nthis";
  ASSERT_STRING(expected_1, str_1);
  ASSERT_STRING(expected_2, str_2);
  fprintf(stderr, "-------------------\n");
}

void test_addWordsToShorterStr_equalLength() {
  char str_1[] = "it is funny";
  char str_2[] = "it isn`t good";
  addWordsToShorterStr(str_1, str_2);
  char expected_1[] = "it is funny";
  char expected_2[] = "it isn`t good";
  ASSERT_STRING(expected_1, str_1);
  ASSERT_STRING(expected_2, str_2);
  fprintf(stderr, "-------------------\n");
}

void test_addWordsToShorterStr() {
  fprintf(stderr, "-------------------\n");
  test_addWordsToShorterStr_empty();
  test_addWordsToShorterStr_firstLonger();
  test_addWordsToShorterStr_secondLonger();
  test_addWordsToShorterStr_equalLength();
  fprintf(stderr, "\n");
}

int main() {
  test_addWordsToShorterStr();
  return 0;
}