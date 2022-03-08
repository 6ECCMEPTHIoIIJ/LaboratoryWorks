#include "mystring.h"
#include "mystring_tests.h"

/*
 * Переносит цифры в конец слова word, инвертируя их порядок, а буквы - в
 * конец, сохраняя их порядок
 */
void digitsToEndReverse(WordDescriptor word) {
  char* end_string_buffer = copy(word.begin, word.end, _string_buffer);
  char* rec_position = copyIf(_string_buffer, end_string_buffer, word.begin,
                              isalpha);
  copyIfReverse(_string_buffer - 1, end_string_buffer - 1,
                rec_position, isdigit);
}

void test_digitsToEndReverse_lettersAndDigits() {
  char str[] = "a1s23d";
  WordDescriptor word;
  getWord(str, &word);
  digitsToEndReverse(word);
  char expected[] = "asd321";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverse_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  WordDescriptor word;
  getWord(str, &word);
  digitsToEndReverse(word);
  char expected[] = "-%%\?";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverse_noneLetters() {
  char str[] = "123";
  WordDescriptor word;
  getWord(str, &word);
  digitsToEndReverse(word);
  char expected[] = "321";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverse_noneDigits() {
  char str[] = "asd";
  WordDescriptor word;
  getWord(str, &word);
  digitsToEndReverse(word);
  char expected[] = "asd";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverse() {
  fprintf(stderr, "-------------------\n");
  test_digitsToEndReverse_lettersAndDigits();
  test_digitsToEndReverse_nonLettersNoneDigits();
  test_digitsToEndReverse_noneLetters();
  test_digitsToEndReverse_noneDigits();
  fprintf(stderr, "\n");
}

/*
 * Преобразовывает строку таким образом, чтобы цифры каждого слова были
 * перенесены в конец слова с обращением их порядка, а буквы - в начало, с
 * сохранением их порядка
 */
void  digitsToEndReverseStr(char* str) {
  char* begin_search = str;
  WordDescriptor word;
  while (getWord(begin_search, &word)) {
    digitsToEndReverse(word);
    begin_search = word.end;
  }
}

void test_digitsToEndReverseStr_empty() {
  char str[] = "";
  digitsToEndReverseStr(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr_oneWord() {
  char str[] = "asd123";
  digitsToEndReverseStr(str);
  char expected[] = "asd321";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr_nonLettersNoneDigits() {
  char str[] = "-%%\?";
  digitsToEndReverseStr(str);
  char expected[] = "-%%\?";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr_noneLetters() {
  char str[] = "123 456 312";
  digitsToEndReverseStr(str);
  char expected[] = "321 654 213";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr_noneDigits() {
  char str[] = "abc dfg ker";
  digitsToEndReverseStr(str);
  char expected[] = "abc dfg ker";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr_someWords() {
  char str[] = "1ab3 78na mf91";
  digitsToEndReverseStr(str);
  char expected[] = "ab31 na87 mf19";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_digitsToEndReverseStr() {
  fprintf(stderr, "-------------------\n");
  test_digitsToEndReverseStr_empty();
  test_digitsToEndReverseStr_oneWord();
  test_digitsToEndReverseStr_nonLettersNoneDigits();
  test_digitsToEndReverseStr_noneLetters();
  test_digitsToEndReverseStr_noneDigits();
  test_digitsToEndReverseStr_someWords();
  fprintf(stderr, "\n");
}


int main() {
  test_digitsToEndReverse();
  test_digitsToEndReverseStr();

  return 0;
}