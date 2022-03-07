#include "mystring.h"
#include "mystring_tests.h"

void digitToStartReverse(WordDescriptor word) {
  char* end_string_buffer = copy(word.begin, word.end, _string_buffer);
  char* rec_position = copyIfReverse(_string_buffer - 1, end_string_buffer - 1,
                                     word.begin, isdigit);
  copyIf(_string_buffer , end_string_buffer, rec_position, isalpha);
}

void test_digitToStartReverse_lettersAndDigits() {
  char str[] = "a1s23d";
  WordDescriptor word;
  getWord(str, &word);
  digitToStartReverse(word);
  char expected[] = "321asd";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverse_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  WordDescriptor word;
  getWord(str, &word);
  digitToStartReverse(word);
  char expected[] = "-%%\?";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverse_noneLetters() {
  char str[] = "123";
  WordDescriptor word;
  getWord(str, &word);
  digitToStartReverse(word);
  char expected[] = "321";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverse_noneDigits() {
  char str[] = "asd";
  WordDescriptor word;
  getWord(str, &word);
  digitToStartReverse(word);
  char expected[] = "asd";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd() {
  fprintf(stderr, "-------------------\n");
  test_digitToStartReverse_lettersAndDigits();
  test_digitToStartReverse_nonLettersNoneDigits();
  test_digitToStartReverse_noneLetters();
  test_digitToStartReverse_noneDigits();
  fprintf(stderr, "\n");
}

/**
 * @brief   Преобразование строки таким образом. чтобы цифры каждого слова
 *          были перенесены в начало слова с изменением порядка не обратный, а буквы -
 *          в конец слова без изменения порядка
 * @param str указатель на начало строки
 */
void  digitToStartReverseStr(char* str) {
  char* begin_search = str;
  WordDescriptor word;
  while (getWord(begin_search, &word)) {
    digitToStartReverse(word);
    begin_search = word.end;
  }
}

void test_digitToStartReverseStr_empty() {
  char str[] = "";
  digitToStartReverseStr(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr_oneWord() {
  char str[] = "asd123";
  digitToStartReverseStr(str);
  char expected[] = "321asd";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  digitToStartReverseStr(str);
  char expected[] = "-%%\?";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr_noneLetters() {
  char str[] = "123 456 312";
  digitToStartReverseStr(str);
  char expected[] = "321 654 213";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr_noneDigits() {
  char str[] = "abc dfg ker";
  digitToStartReverseStr(str);
  char expected[] = "abc dfg ker";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr_someWords() {
  char str[] = "1ab3 78na mf91";
  digitToStartReverseStr(str);
  char expected[] = "31ab 87na 19mf";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitToStartReverseStr() {
  fprintf(stderr, "-------------------\n");
  test_digitToStartReverseStr_empty();
  test_digitToStartReverseStr_oneWord();
  test_digitToStartReverseStr_nonLettersNoneDigits();
  test_digitToStartReverseStr_noneLetters();
  test_digitToStartReverseStr_noneDigits();
  test_digitToStartReverseStr_someWords();
  fprintf(stderr, "\n");
}


int main() {
  test_lettersToStartDigitsToEnd();
  test_digitToStartReverseStr();

  return 0;
}