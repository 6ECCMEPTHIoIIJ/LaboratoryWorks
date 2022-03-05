#include "../include/mystring.h"
#include "../tests/tests.h"

void digitToStartReverse(WordDescriptor word) {
  char* end_string_buffer = copy(word.begin, word.end, _string_buffer);
  char* rec_position = copyIfReverse(_string_buffer - 1, end_string_buffer - 1,
                                     word.begin, isdigit);
  copyIf(_string_buffer , end_string_buffer, rec_position, isalpha);
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
  test_digitToStartReverseStr();

  return 0;
}