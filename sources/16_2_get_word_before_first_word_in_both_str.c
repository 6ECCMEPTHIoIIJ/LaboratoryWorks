#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>

/*
 * Перечисление возвращаемых кодов функции getWordBeforeFirstWordInBothStr:
 * kFirstWordIsCommonToBothStr = 0 - первое слово содержится в обеих строках
 * kNotFoundWordCommonToBothStr = 1 - слово, общее для обеих строк отсутствует
 * kWordFound = 2 - слово, стоящее перед словом, содержащимся в обеих строках,
 *                  найдено и успешно сохранено в соответствующую переменную
 * kEmpty = 3 - в строке нет ни одного слова
 */
typedef enum WordBeforeFirstWordInBothStrReturnCode {
  kFirstWordIsCommonToBothStr,
  kNotFoundWordCommonToBothStr,
  kWordFound,
  kEmpty
} WordBeforeFirstWordInBothStrReturnCode;

/*
 * Возвращает true, если слово word найдено в строке str, и false в противном
 * случае
 */
static bool isWordFound(char* str,
                        WordDescriptor word) {
  WordDescriptor cur_word;
  char* begin = str;
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
 * Возвращает kFirstWordIsCommonToBothStr, если первое слово строки str_1
 * содержится в строке str_2, kNotFoundWordCommonToBothStr, если слово, общее
 * для обеих строк отсутствует, kWordFound, если общее слово найдено и
 * стоит не на первой позиции, также в этом случае сохраняет слово,
 * предшествующее ему в переменную word, возвращает kEmpty, если строка
 * не содержит ни одного слова
 */
WordBeforeFirstWordInBothStrReturnCode
getWordBeforeFirstWordInBothStr(char* str_1,
                                char* str_2,
                                WordDescriptor* word) {
  char* begin = str_1;
  WordDescriptor pre_word;
  if (getWord(begin, &pre_word)) {
    if (!isWordFound(str_2, pre_word)) {
      begin = pre_word.end;
      WordDescriptor next_word;
      while (getWord(begin, &next_word)) {
        if (isWordFound(str_2, next_word)) {
          *word = pre_word;
          return kWordFound;
        }

        pre_word = next_word;
        begin = pre_word.end;
      }

      return kNotFoundWordCommonToBothStr;
    } else {
      return kFirstWordIsCommonToBothStr;
    }
  } else {
    return kEmpty;
  }
}

void test_getWordBeforeFirstWordInBothStr_empty() {
  char str_1[] = "";
  char str_2[] = "";
  WordDescriptor word;
  ASSERT_INT(kEmpty, getWordBeforeFirstWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordInBothStr_firstWord() {
  char str_1[] = "word death pain";
  char str_2[] = "here is this word you trying to find";
  WordDescriptor word;
  ASSERT_INT(kFirstWordIsCommonToBothStr,
             getWordBeforeFirstWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordInBothStr_notFound() {
  char str_1[] = "nothing world room";
  char str_2[] = "here is this word you trying to find";
  WordDescriptor word;
  ASSERT_INT(kNotFoundWordCommonToBothStr,
             getWordBeforeFirstWordInBothStr(str_1, str_2, &word));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordInBothStr_found() {
  char str_1[] = "do this here and now . this is war";
  char str_2[] = "here is this word you trying to find";
  WordDescriptor word;
  ASSERT_INT(kWordFound, getWordBeforeFirstWordInBothStr(str_1, str_2, &word));
  char expected[] = "do";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordInBothStr() {
  fprintf(stderr, "-------------------\n");
  test_getWordBeforeFirstWordInBothStr_empty();
  test_getWordBeforeFirstWordInBothStr_firstWord();
  test_getWordBeforeFirstWordInBothStr_notFound();
  test_getWordBeforeFirstWordInBothStr_found();
  fprintf(stderr, "\n");
}

int main() {
  test_getWordBeforeFirstWordInBothStr();
  return 0;
}