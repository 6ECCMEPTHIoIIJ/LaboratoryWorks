#include "mystring.h"
#include "mystring_tests.h"

typedef enum WordBeforeFirstWordWithSymbolReturnCode {
  kFirstWordWithSymbol,
  kNotFoundWordWithSymbol,
  kWordFound,
  kEmpty
} WordBeforeFirstWordWithSymbolReturnCode;

int isSymbolInWord(WordDescriptor word,
                   const char symbol) {
  return find(word.begin, word.end, symbol) != word.end;
}

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
  test_isSubstringBySymbols();

  return 0;
}