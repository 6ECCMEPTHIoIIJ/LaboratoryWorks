#include "mystring.h"
#include "mystring_tests.h"

/*
 * Возвращает true, если слово word - палиндром, и false в противном случае
 */
static int isPalindrome(WordDescriptor word) {
  word.end--;
  while (word.begin < word.end) {
    if (*word.begin != *word.end) {
      return 0;
    }
    word.begin++;
    word.end--;
  }

  return 1;
}

/*--------------------------------------------------------
 * TESTING: this function was tested in task 8 (watch file
 * 8_count_palindromes.c)
 -------------------------------------------------------*/

/*
 * Удаляет из строки str все слова-палиндромы. Сохраняет все пробельные символы
 * исходной строки
 */
void removePalindromes(char* str) {
  char* begin_src = str;
  char* begin_dst = str;
  WordDescriptor cur_word;
  while (getWord(begin_src, &cur_word)) {
    begin_dst = copy(begin_src, cur_word.begin, begin_dst);
    if (!isPalindrome(cur_word)) {
      begin_dst = copy(cur_word.begin, cur_word.end, begin_dst);
    }
    begin_src = cur_word.end;
  }

  *copy(begin_src, str + mystrlen(str), begin_dst) = '\0';
}

void test_removePalindromes_empty() {
  char str[] = "";
  removePalindromes(str);
  char expected[] = "";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removePalindromes_oneWordAndNotPalindrome() {
  char str[] = "  asfasg    ";
  removePalindromes(str);
  char expected[] = "  asfasg    ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removePalindromes_oneWordAndPalindrome() {
  char str_1[] = "  abaccaba    ";
  removePalindromes(str_1);
  char expected_1[] = "      ";
  ASSERT_STRING(expected_1, str_1);
  char str_2[] = "  a    ";
  removePalindromes(str_2);
  char expected_2[] = "      ";
  ASSERT_STRING(expected_2, str_2);
  fprintf(stderr, "-------------------\n");
}

void test_removePalindromes_allArePalindromes() {
  char str[] = "  aba bb cabac    helloolleh    ";
  removePalindromes(str);
  char expected[] = "            ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removePalindromes_notAllArePalindromes() {
  char str[] = "  aba bb cabc  a  helloleh    ";
  removePalindromes(str);
  char expected[] = "    cabc    helloleh    ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}

void test_removePalindromes_notAnyPalindromes() {
  char str[] = "  abc xb cabc    helloleh    ";
  removePalindromes(str);
  char expected[] = "  abc xb cabc    helloleh    ";
  ASSERT_STRING(expected, str);
  fprintf(stderr, "-------------------\n");
}


void test_getStrFromWordsNotEqualToTheLast() {
  fprintf(stderr, "-------------------\n");
  test_removePalindromes_empty();
  test_removePalindromes_oneWordAndNotPalindrome();
  test_removePalindromes_oneWordAndPalindrome();
  test_removePalindromes_allArePalindromes();
  test_removePalindromes_notAllArePalindromes();
  test_removePalindromes_notAnyPalindromes();
  fprintf(stderr, "\n");
}

int main() {
  test_getStrFromWordsNotEqualToTheLast();

  return 0;
}