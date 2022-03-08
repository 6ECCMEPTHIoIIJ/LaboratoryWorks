#include "mystring.h"
#include "mystring_tests.h"

#include <stdbool.h>

/*
 * Перечисление возвращаемых кодов функции getWordBeforeFirstWordWithSymbol:
 * kFirstWordWithSymbol = 0 - первое слово содержит искомый символ
 * kNotFoundWordWithSymbol = 1 - слово с искомым символом отсутствует
 * kWordFound = 2 - слово, стоящее перед словом с искомым символом найдено и
 *                  успешно сохранено в соответствующую переменную
 * kEmpty = 3 - в строке нет ни одного слова
 */
typedef enum WordBeforeFirstWordWithSymbolReturnCode {
  kFirstWordWithSymbol,
  kNotFoundWordWithSymbol,
  kWordFound,
  kEmpty
} WordBeforeFirstWordWithSymbolReturnCode;

/*
 * Возвращает true, если символ symbol найден в слове word, и false в
 * противном случае
 */
bool isSymbolInWord(WordDescriptor word,
                   const char symbol) {
  return find(word.begin, word.end, symbol) != word.end;
}

void test_getWordBeforeFirstWordWithSymbol_false() {
  char str[] = "hell";
  WordDescriptor word;
  getWord(str, &word);
  ASSERT_INT(false, isSymbolInWord(word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_oneLetterTrue() {
  char str[] = "a";
  WordDescriptor word;
  getWord(str, &word);
  ASSERT_INT(true, isSymbolInWord(word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_oneLetterFalse() {
  char str[] = "b";
  WordDescriptor word;
  getWord(str, &word);
  ASSERT_INT(false, isSymbolInWord(word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_true() {
  char str[] = "tank";
  WordDescriptor word;
  getWord(str, &word);
  ASSERT_INT(true, isSymbolInWord(word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol() {
  fprintf(stderr, "-------------------\n");
  test_getWordBeforeFirstWordWithSymbol_false();
  test_getWordBeforeFirstWordWithSymbol_oneLetterTrue();
  test_getWordBeforeFirstWordWithSymbol_oneLetterFalse();
  test_getWordBeforeFirstWordWithSymbol_true();
  fprintf(stderr, "\n");
}

/*
 * Возвращает kFirstWordWithSymbol, если первое слово строки str содержит
 * искомый символ symbol, kNotFoundWordWithSymbol, если слово с искомым
 * символом отсутствует, kWordFound, если слово с искомым символом найдено и
 * стоит не на первой позиции, также в этом случае сохраняет слово,
 * предшествующее ему слово в переменную word, возвращает kEmpty, если строка
 * не содержит ни одного слова
 */
WordBeforeFirstWordWithSymbolReturnCode
getWordBeforeFirstWordWithSymbol(char* str,
                                 WordDescriptor* word,
                                 const char symbol) {
  char* begin = str;
  WordDescriptor pre_word;
  if (getWord(begin, &pre_word)) {
    if (!isSymbolInWord(pre_word, symbol)) {
      begin = pre_word.end;
      WordDescriptor next_word;
      while (getWord(begin, &next_word)) {
        if (isSymbolInWord(next_word, symbol)) {
          *word = pre_word;
          return kWordFound;
        }

        pre_word = next_word;
        begin = pre_word.end;
      }

      return kNotFoundWordWithSymbol;

    } else {
      return kFirstWordWithSymbol;
    }
  } else {
    return kEmpty;
  }
}

void test_getWordBeforeFirstWordWithSymbol_empty() {
  char str[] = "";
  WordDescriptor word;
  ASSERT_INT(kEmpty, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_firstWordWithSymbol() {
  char str[] = "death is near";
  WordDescriptor word;
  ASSERT_INT(kFirstWordWithSymbol, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_notFoundWordWithSymbolOneWord() {
  char str[] = "throne";
  WordDescriptor word;
  ASSERT_INT(kNotFoundWordWithSymbol, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_notFoundWordWithSymbolManyWords() {
  char str[] = "this throne is mine";
  WordDescriptor word;
  ASSERT_INT(kNotFoundWordWithSymbol, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_notLast() {
  char str[] = "meet in hell my dear";
  WordDescriptor word;
  ASSERT_INT(kWordFound, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  char expected[] = "my";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_getWordBeforeFirstWordWithSymbol_wordFoundTwoWords() {
  char str[] = "my dear";
  WordDescriptor word;
  ASSERT_INT(kWordFound, getWordBeforeFirstWordWithSymbol(str, &word, 'a'));
  char expected[] = "my";
  char got[sizeof(expected)];
  wordDescriptorToString(word, got);
  ASSERT_STRING(expected, got);
  fprintf(stderr, "-------------------\n");
}

void test_isSubstringBySymbols() {
  fprintf(stderr, "-------------------\n");
  test_getWordBeforeFirstWordWithSymbol_empty();
  test_getWordBeforeFirstWordWithSymbol_firstWordWithSymbol();
  test_getWordBeforeFirstWordWithSymbol_notFoundWordWithSymbolOneWord();
  test_getWordBeforeFirstWordWithSymbol_notFoundWordWithSymbolManyWords();
  test_getWordBeforeFirstWordWithSymbol_notLast();
  test_getWordBeforeFirstWordWithSymbol_wordFoundTwoWords();
  fprintf(stderr, "\n");
}

int main() {
  test_getWordBeforeFirstWordWithSymbol();
  test_isSubstringBySymbols();

  return 0;
}