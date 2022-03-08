#include "../include/mystring.h"
#include "../tests/mystring_tests.h"

/*
 * Переносит цифры в начало слова word, а буквы - в конец, сохраняя их порядок
 */
void lettersToEndDigitsToStart(WordDescriptor word) {
  char* end_string_buffer = copy(word.begin, word.end, _string_buffer);
  char* rec_position = copyIf(_string_buffer,
                              end_string_buffer,
                              word.begin,
                              isalpha);
  copyIf(_string_buffer, end_string_buffer, rec_position, isdigit);
}

void test_lettersToStartDigitsToEnd_lettersAndDigits() {
  char str[] = "a1s23d";
  WordDescriptor word;
  getWord(str, &word);
  lettersToEndDigitsToStart(word);
  char expected[] = "asd123";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  WordDescriptor word;
  getWord(str, &word);
  lettersToEndDigitsToStart(word);
  char expected[] = "-%%\?";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd_noneLetters() {
  char str[] = "123";
  WordDescriptor word;
  getWord(str, &word);
  lettersToEndDigitsToStart(word);
  char expected[] = "123";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd_noneDigits() {
  char str[] = "asd";
  WordDescriptor word;
  getWord(str, &word);
  lettersToEndDigitsToStart(word);
  char expected[] = "asd";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd() {
  fprintf(stderr, "-------------------\n");
  test_lettersToStartDigitsToEnd_lettersAndDigits();
  test_lettersToStartDigitsToEnd_nonLettersNoneDigits();
  test_lettersToStartDigitsToEnd_noneLetters();
  test_lettersToStartDigitsToEnd_noneDigits();
  fprintf(stderr, "\n");
}

/*
 * Преобразовывает строку str таким образом, чтобы цифры каждого слова шли в
 * начале слова, а буквы - в конце, сохраняя порядок букв и цифр
 */
void lettersToStartDigitsToEndStr(char* str) {
  char* begin_search = str;
  WordDescriptor word;
  while (getWord(begin_search, &word)) {
    lettersToEndDigitsToStart(word);
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
  char str[] = "123asd";
  lettersToStartDigitsToEndStr(str);
  char expected[] = "asd123";
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
  char expected[] = "ab13 na78 mf91";
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
  test_lettersToStartDigitsToEnd();
  test_lettersToStartDigitsToEndStr();

  return 0;
}