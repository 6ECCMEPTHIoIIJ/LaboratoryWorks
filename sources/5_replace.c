#include "mystring.h"
#include "mystring_tests.h"

void replace(char* str,
             char* w_1,
             char* w_2) {
  size_t w_1_size = mystrlen(w_1);
  size_t w_2_size = mystrlen(w_2);
  WordDescriptor word_1 = {w_1, w_1 + w_1_size};
  WordDescriptor word_2 = {w_2, w_2 + w_2_size};

  char* read_ptr;
  char* write_ptr;
  if (w_1_size > w_2_size) {
    read_ptr = str;
  } else {
    *copy(str, str + mystrlen(str), _string_buffer) = '\0';
    read_ptr = _string_buffer;
  }
  write_ptr = str;

  WordDescriptor cur_word;
  while (getWord(read_ptr, &cur_word)) {
    write_ptr = copy(read_ptr, cur_word.begin, write_ptr);
    if (wordcmp(cur_word, word_1) == 0) {
      write_ptr = copy(word_2.begin, word_2.end, write_ptr);
    } else {
      write_ptr = copy(cur_word.begin,
                       cur_word.end,
                       write_ptr);
    }
    read_ptr = cur_word.end;
  }

  *write_ptr = '\0';
}

void test_replace_empty() {
  char str[] = "";
  char w_1[] = "aba";
  char w_2[] = "caba";
  replace(str, w_1, w_2);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_manySoughtWords() {
  char str[15] = "aba, aba aba";
  char w_1[] = "aba";
  char w_2[] = "caba";
  replace(str, w_1, w_2);
  char expected[] = "aba, caba caba";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_noOneSoughtWord() {
  char str[] = "abaababa";
  char w_1[] = "aba";
  char w_2[] = "caba";
  replace(str, w_1, w_2);
  char expected[] = "abaababa";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_oneSoughtWordW1LenBiggerW2Len() {
  char str[5] = "aba";
  char w_1[] = "aba";
  char w_2[] = "caba";
  replace(str, w_1, w_2);
  char expected[] = "caba";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_manySoughtWordsW1LenBiggerW2Len() {
  char str[] = "caba, caba caba";
  char w_1[] = "caba";
  char w_2[] = "aba";
  replace(str, w_1, w_2);
  char expected[] = "caba, aba aba";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_notAllWordsAreSought() {
  char str[] = "caba, hell caba death pain hell spirit hello";
  char w_1[] = "hell";
  char w_2[] = "aba";
  replace(str, w_1, w_2);
  char expected[] = "caba, aba caba death pain aba spirit hello";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace_notAllWordsAreSoughtW1LenBiggerW2Len() {
  char str[63] = "caba, hell caba death pain hell spirit hello";
  char w_1[] = "hell";
  char w_2[] = "creepingDeath";
  replace(str, w_1, w_2);
  char expected[] = "caba, creepingDeath caba death pain creepingDeath spirit hello";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_replace() {
  fprintf(stderr, "-------------------\n");
  test_replace_empty();
  test_replace_manySoughtWords();
  test_replace_noOneSoughtWord();
  test_replace_oneSoughtWordW1LenBiggerW2Len();
  test_replace_manySoughtWordsW1LenBiggerW2Len();
  test_replace_notAllWordsAreSought();
  test_replace_notAllWordsAreSoughtW1LenBiggerW2Len();
  fprintf(stderr, "\n");
}

int main() {
  test_replace();

  return 0;
}