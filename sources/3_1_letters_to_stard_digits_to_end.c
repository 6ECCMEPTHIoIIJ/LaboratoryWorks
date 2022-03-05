#include "../include/mystring.h"
#include "../tests/tests.h"

void lettersToStartDigitsToEnd(WordDescriptor word) {
  char* end_string_buffer = copy(word.begin, word.end, _string_buffer);
  char* rec_position = copyIf(_string_buffer,
                              end_string_buffer,
                              word.begin,
                              isdigit);
  copyIf(_string_buffer, end_string_buffer, rec_position, isalpha);
}

/**
 * @brief   Преобразование строки таким образом, чтобы цифры каждого слова
 *          были перенесены в начало слова без изменения порядка не обратный, а
 *          буквы - в конец слова
 * @param str указатель на начало строки
 */
void lettersToStartDigitsToEndStr(char* str) {
  char* begin_search = str;
  WordDescriptor word;
  while (getWord(begin_search, &word)) {
    lettersToStartDigitsToEnd(word);
    begin_search = word.end;
  }
}

void test_lettersToStartDigitsToEndStr_empty() {
  char str[] = "";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr_oneWord() {
  char str[] = "asd123";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "123asd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "-%%\?";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr_noneLetters() {
  char str[] = "123 456 312";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "123 456 312";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr_noneDigits() {
  char str[] = "abc dfg ker";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "abc dfg ker";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr_someWords() {
  char str[] = "1ab3 78na mf91";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "13ab 78na 91mf";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEndStr() {
  fprintf(stderr, "-------------------\n");
  test_lettersToStartDigitsToEndStr_empty();
  test_lettersToStartDigitsToEndStr_oneWord();
  test_lettersToStartDigitsToEndStr_nonLettersNoneDigits();
  test_lettersToStartDigitsToEndStr_noneLetters();
  test_lettersToStartDigitsToEndStr_noneDigits();
  test_lettersToStartDigitsToEndStr_someWords();
  fprintf(stderr, "\n");
}

int main() {
  test_lettersToStartDigitsToEndStr();

  return 0;
}