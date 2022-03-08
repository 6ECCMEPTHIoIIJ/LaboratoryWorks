#include "../include/mystring.h"
#include "../tests/mystring_tests.h"

/*
 * Обращает символы в слове word
 */
void reverseWord(WordDescriptor word) {
  char* end_string_buffer = copyReverse(word.begin - 1,
                                        word.end - 1,
                                        _string_buffer);
  copy(_string_buffer, end_string_buffer, word.begin);
}

void test_reverseWord_oneLetter() {
  char str[] = "a";
  WordDescriptor word;
  getWord(str, &word);
  reverseWord(word);
  char expected[] = "a";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_lettersToStartDigitsToEnd_manyLetters() {
  char str[] = "abacd";
  WordDescriptor word;
  getWord(str, &word);
  reverseWord(word);
  char expected[] = "dcaba";
  WordDescriptor expected_word;
  getWord(expected, &expected_word);
  ASSERT_WORD(expected_word, word);
  fprintf(stderr, "-------------------\n");
}

void test_reverseWord() {
  fprintf(stderr, "-------------------\n");
  test_reverseWord_oneLetter();
  test_lettersToStartDigitsToEnd_manyLetters();
  fprintf(stderr, "\n");
}

/*
 * Обращает символы каждого слова строки str
 */
void reverseLettersInWords(char* str) {
  char* begin_search = str;
  WordDescriptor word;
  while (getWord(begin_search, &word)) {
    reverseWord(word);
    begin_search = word.end;
  }
}

void test_reverseLettersInWords_empty() {
  char str[] = "";
  reverseLettersInWords(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseLettersInWords_oneWord() {
  char str[] = "asd123";
  reverseLettersInWords(str);
  char expected[] = "321dsa";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseLettersInWords_manyWords() {
  char str[] = "-%%\?";
  reverseLettersInWords(str);
  char expected[] = "\?%%-";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_reverseLettersInWords_noneLetters() {
  char str[] = "abcd    hda asv";
  reverseLettersInWords(str);
  char expected[] = "dcba    adh vsa";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}


void test_reverseLettersInWords() {
  fprintf(stderr, "-------------------\n");
  test_reverseLettersInWords_empty();
  test_reverseLettersInWords_oneWord();
  test_reverseLettersInWords_manyWords();
  test_reverseLettersInWords_noneLetters();
  fprintf(stderr, "\n");
}

int main() {
  test_reverseWord();
  test_reverseLettersInWords();

  return 0;
}