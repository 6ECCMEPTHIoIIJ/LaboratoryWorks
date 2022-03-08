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

/*--------------------------------------------------------
 * TESTING: эта функция была протестирована в задании 12 (см. файл
 * 12_find_last_equal_word_in_both_str.c)
 -------------------------------------------------------*/

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

/*--------------------------------------------------------
 * TESTING: эта функция была протестирована в задании 12 (см. файл
 * 12_find_last_equal_word_in_both_str.c)
 -------------------------------------------------------*/

int main() {

  return 0;
}