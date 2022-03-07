#ifndef INC_5E_MYSTRING_TESTS_H
#define INC_5E_MYSTRING_TESTS_H

#include "../include/mystring.h"
#include "tests.h"

static void test_mystrlen_Normal() {
  ASSERT_INT(7, (int) mystrlen("abacaba"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen_Spaces() {
  ASSERT_INT(3, (int) mystrlen("   "));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen_Escapes() {
  ASSERT_INT(4, (int) mystrlen("\t2\n3"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen_ZeroInCenter() {
  ASSERT_INT(1, (int) mystrlen("a\0idsadasc"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen_Empty() {
  ASSERT_INT(0, (int) mystrlen(""));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen_ZeroFirst() {
  ASSERT_INT(0, (int) mystrlen("\0\0\0\0fsdsf34234"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrlen() {
  fprintf(stderr, "-------------------\n");
  test_mystrlen_Empty();
  test_mystrlen_Escapes();
  test_mystrlen_Normal();
  test_mystrlen_Spaces();
  test_mystrlen_ZeroFirst();
  test_mystrlen_ZeroInCenter();
  fprintf(stderr, "\n");
}

static void test_find_firstSymbol() {
  char str[] = "abacaba";
  const size_t index = 0;
  ASSERT_PTR(str + index,
             find(str, str + mystrlen(str), 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_lastSymbol() {
  char str[] = "abacab=d";
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index,
             find(str, str + mystrlen(str), 'd'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFirstNotLast() {
  char str[] = "abczbca";
  const size_t index = 3;
  ASSERT_PTR(str + index,
             find(str, str + mystrlen(str), 'z'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFound() {
  char str[] = "abacaba";
  const size_t index = mystrlen(str);
  ASSERT_PTR(str + index,
             find(str, str + mystrlen(str), 'z'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_NullDiapason() {
  char str[] = "abacaba";
  const size_t begin = 1;
  const size_t end = 1;
  const size_t index = end;
  ASSERT_PTR(str + index,
             find(str + begin,
                  str + end, 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFullWordNotFound() {
  char str[] = "abacaba";
  const size_t begin = 1;
  const size_t end = 2;
  const size_t index = end;
  ASSERT_PTR(str + index,
             find(str + begin,
                  str + end, 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFullWordFirst() {
  char str[] = "abacaba";
  const size_t begin = 2;
  const size_t end = 4;
  const size_t index = begin;
  ASSERT_PTR(str + index,
             find(str + begin,
                  str + end, 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFullWordLast() {
  char str[] = "abacaba";
  const size_t begin = 3;
  const size_t end = 5;
  const size_t index = end - 1;
  ASSERT_PTR(str + index,
             find(str + begin,
                  str + end, 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find_notFullWordNotFirstNotLast() {
  char str[] = "abbcaba";
  const size_t begin = 1;
  const size_t end = 6;
  const size_t index = 4;
  ASSERT_PTR(str + index,
             find(str + begin,
                  str + end, 'a'));
  fprintf(stderr, "-------------------\n");
}

static void test_find() {
  fprintf(stderr, "-------------------\n");
  test_find_firstSymbol();
  test_find_lastSymbol();
  test_find_notFirstNotLast();
  test_find_notFound();
  test_find_notFullWordFirst();
  test_find_notFullWordLast();
  test_find_notFullWordNotFirstNotLast();
  test_find_notFullWordNotFound();
  test_find_NullDiapason();
  fprintf(stderr, "\n");
}

static void test_findNonSpace_first() {
  char str[] = "a  asd";
  const size_t index = 0;
  ASSERT_PTR(str + index,
             findNonSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_last() {
  char str[] = "    a";
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index,
             findNonSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFound() {
  char str[] = "    ";
  const size_t index = mystrlen(str);
  ASSERT_PTR(str + index,
             findNonSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFirstNotLast() {
  char str[] = "  gff";
  const size_t index = 2;
  ASSERT_PTR(str + index,
             findNonSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFullWordNotFirstNotLast() {
  char str[] = "   gff";
  const size_t begin = 1;
  const size_t index = 3;
  ASSERT_PTR(str + index,
             findNonSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFullWordFirst() {
  char str[] = "   gff";
  const size_t begin = 3;
  const size_t index = begin;
  ASSERT_PTR(str + index,
             findNonSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFullWordLast() {
  char str[] = "ffg g";
  const size_t begin = 3;
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index,
             findNonSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace_notFullWordNotFound() {
  char str[] = "avds ";
  const size_t begin = 4;
  const size_t index = mystrlen(str);
  ASSERT_PTR(str + index,
             findNonSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpace() {
  fprintf(stderr, "-------------------\n");
  test_findNonSpace_first();
  test_findNonSpace_last();
  test_findNonSpace_notFound();
  test_findNonSpace_notFirstNotLast();
  test_findNonSpace_notFullWordNotFirstNotLast();
  test_findNonSpace_notFullWordFirst();
  test_findNonSpace_notFullWordLast();
  test_findNonSpace_notFullWordNotFound();
  fprintf(stderr, "\n");
}

static void test_findSpace_first() {
  char str[] = "  asd";
  const size_t index = 0;
  ASSERT_PTR(str + index,
             findSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_last() {
  char str[] = "aaaaaaa ";
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index,
             findSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFound() {
  char str[] = "gggggg";
  const size_t index = mystrlen(str);
  ASSERT_PTR(str + index,
             findSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFirstNotLast() {
  char str[] = "gf  f";
  const size_t index = 2;
  ASSERT_PTR(str + index,
             findSpace(str));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFullWordNotFirstNotLast() {
  char str[] = "gff    ";
  const size_t begin = 1;
  const size_t index = 3;
  ASSERT_PTR(str + index,
             findSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFullWordFirst() {
  char str[] = "aaa ff";
  const size_t begin = 3;
  const size_t index = begin;
  ASSERT_PTR(str + index,
             findSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFullWordLast() {
  char str[] = " aa ";
  const size_t begin = 3;
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index,
             findSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace_notFullWordNotFound() {
  char str[] = "    a";
  const size_t begin = 4;
  const size_t index = mystrlen(str);
  ASSERT_PTR(str + index,
             findSpace(str + begin));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpace() {
  fprintf(stderr, "-------------------\n");
  test_findSpace_first();
  test_findSpace_last();
  test_findSpace_notFound();
  test_findSpace_notFirstNotLast();
  test_findSpace_notFullWordNotFirstNotLast();
  test_findSpace_notFullWordFirst();
  test_findSpace_notFullWordLast();
  test_findSpace_notFullWordNotFound();
  fprintf(stderr, "\n");
}

static void test_findNonSpaceReverse_first() {
  char str[] = "a     ";
  const size_t index = 0;
  ASSERT_PTR(str + index, findNonSpaceReverse(str - 1,
                                              str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_last() {
  char str[] = "    a";
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index, findNonSpaceReverse(str - 1,
                                              str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFound() {
  char str[] = "    ";
  const size_t index = -1;
  ASSERT_PTR(str + index, findNonSpaceReverse(str - 1,
                                              str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFirstNotLast() {
  char str[] = "jhg   ";
  const size_t index = 2;
  ASSERT_PTR(str + index, findNonSpaceReverse(str - 1,
                                              str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFullWordNotFirstNotLast() {
  char str[] = "   g ff";
  const size_t begin = 1;
  const size_t end = 4;
  const size_t index = 3;
  ASSERT_PTR(str + index,
             findNonSpaceReverse(str + begin - 1,
                                 str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFullWordFirst() {
  char str[] = "  g  ";
  const size_t begin = 2;
  const size_t end = 4;
  const size_t index = begin;
  ASSERT_PTR(str + index,
             findNonSpaceReverse(str + begin - 1,
                                 str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFullWordLast() {
  char str[] = "ffg g";
  const size_t begin = 0;
  const size_t end = 3;
  const size_t index = end - 1;
  ASSERT_PTR(str + index,
             findNonSpaceReverse(str + begin - 1,
                                 str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_notFullWordNotFound() {
  char str[] = "avds   ";
  const size_t begin = 5;
  const size_t end = 6;
  const size_t index = begin - 1;
  ASSERT_PTR(str + index,
             findNonSpaceReverse(str + begin - 1,
                                 str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse_ZeroDiapason() {
  char str[] = "avds   ";
  const size_t begin = 5;
  const size_t end = 5;
  const size_t index = begin - 1;
  ASSERT_PTR(str + index,
             findNonSpaceReverse(str + begin - 1,
                                 str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findNonSpaceReverse() {
  fprintf(stderr, "-------------------\n");
  test_findNonSpaceReverse_first();
  test_findNonSpaceReverse_last();
  test_findNonSpaceReverse_notFound();
  test_findNonSpaceReverse_notFirstNotLast();
  test_findNonSpaceReverse_notFullWordNotFirstNotLast();
  test_findNonSpaceReverse_notFullWordFirst();
  test_findNonSpaceReverse_notFullWordLast();
  test_findNonSpaceReverse_notFullWordNotFound();
  test_findNonSpaceReverse_ZeroDiapason();
  fprintf(stderr, "\n");
}

static void test_findSpaceReverse_first() {
  char str[] = "\nasdnajsd";
  const size_t index = 0;
  ASSERT_PTR(str + index, findSpaceReverse(str - 1,
                                           str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_last() {
  char str[] = " sf s fs\t";
  const size_t index = mystrlen(str) - 1;
  ASSERT_PTR(str + index, findSpaceReverse(str - 1,
                                           str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFound() {
  char str[] = "asfdsdf";
  const size_t index = -1;
  ASSERT_PTR(str + index, findSpaceReverse(str - 1,
                                           str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFirstNotLast() {
  char str[] = "as\nfsdfsd";
  const size_t index = 2;
  ASSERT_PTR(str + index, findSpaceReverse(str - 1,
                                           str + mystrlen(str) - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFullWordNotFirstNotLast() {
  char str[] = "das ffddd";
  const size_t begin = 1;
  const size_t end = 4;
  const size_t index = 3;
  ASSERT_PTR(str + index,
             findSpaceReverse(str + begin - 1,
                              str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFullWordFirst() {
  char str[] = "   ff";
  const size_t begin = 2;
  const size_t end = 4;
  const size_t index = begin;
  ASSERT_PTR(str + index,
             findSpaceReverse(str + begin - 1,
                              str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFullWordLast() {
  char str[] = "aa     ";
  const size_t begin = 0;
  const size_t end = 3;
  const size_t index = end - 1;
  ASSERT_PTR(str + index,
             findSpaceReverse(str + begin - 1,
                              str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_notFullWordNotFound() {
  char str[] = "    asd";
  const size_t begin = 5;
  const size_t end = 6;
  const size_t index = begin - 1;
  ASSERT_PTR(str + index,
             findSpaceReverse(str + begin - 1,
                              str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse_ZeroDiapason() {
  char str[] = "avds   ";
  const size_t begin = 5;
  const size_t end = 5;
  const size_t index = begin - 1;
  ASSERT_PTR(str + index,
             findSpaceReverse(str + begin - 1,
                              str + end - 1));
  fprintf(stderr, "-------------------\n");
}

static void test_findSpaceReverse() {
  fprintf(stderr, "-------------------\n");
  test_findSpaceReverse_first();
  test_findSpaceReverse_last();
  test_findSpaceReverse_notFound();
  test_findSpaceReverse_notFirstNotLast();
  test_findSpaceReverse_notFullWordNotFirstNotLast();
  test_findSpaceReverse_notFullWordFirst();
  test_findSpaceReverse_notFullWordLast();
  test_findSpaceReverse_notFullWordNotFound();
  test_findSpaceReverse_ZeroDiapason();
  fprintf(stderr, "\n");
}

static void test_mystrcmp_equal() {
  ASSERT_INT(0, mystrcmp("abacaba", "abacaba"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrcmp_notEqual() {
  ASSERT_INT('z' - 'a', mystrcmp("abzcaba", "abacaba"));
  ASSERT_INT('b' - 'z', mystrcmp("abacaba", "abacaza"));
  ASSERT_INT('b' - 'a', mystrcmp("bacaza", "abacaba"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrcmp_diffLen() {
  ASSERT_INT('c', mystrcmp("abacaba", "aba"));
  ASSERT_INT(-'c', mystrcmp("aba", "abacaba"));
  fprintf(stderr, "-------------------\n");
}

static void test_mystrcmp() {
  fprintf(stderr, "-------------------\n");
  test_mystrcmp_equal();
  test_mystrcmp_notEqual();
  test_mystrcmp_diffLen();
  fprintf(stderr, "\n");
}

static void test_copy_emptyString() {
  char initial[] = "";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copy(initial, initial + mystrlen(initial), str);
  char expected[] = "";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copy_notEmptyString() {
  char initial[] = "abacaba";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copy(initial, initial + mystrlen(initial), str);
  char expected[] = "abacaba";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copy() {
  fprintf(stderr, "-------------------\n");
  test_copy_emptyString();
  test_copy_notEmptyString();
  fprintf(stderr, "\n");
}

static int testCondition(const int ch) {
  return ch >= 'a' && ch <= 'z';
}

static void test_copyIf_copyAll() {
  char initial[] = "abacaba";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIf(initial, initial + mystrlen(initial), str,
                         testCondition);
  char expected[] = "abacaba";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIf_copyPart() {
  char initial[] = "\ta23ba\nc-a b   a67";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIf(initial, initial + mystrlen(initial), str,
                         testCondition);
  char expected[] = "abacaba";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIf_nothing() {
  char initial[] = "\t23\n-    67";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIf(initial, initial + mystrlen(initial), str,
                         testCondition);
  char expected[] = "";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIf() {
  fprintf(stderr, "-------------------\n");
  test_copyIf_copyAll();
  test_copyIf_copyPart();
  test_copyIf_nothing();
  fprintf(stderr, "\n");
}

static void test_copyIfReverse_copyAll() {
  char initial[] = "abaddbz";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIfReverse(initial - 1, initial + mystrlen(initial) - 1,
                                str,
                                testCondition);
  char expected[] = "zbddaba";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIfReverse_copyPart() {
  char initial[] = "\ta23ba\nd-d b   z67";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIfReverse(initial - 1, initial + mystrlen(initial) - 1,
                                str,
                                testCondition);
  char expected[] = "zbddaba";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIfReverse_nothing() {
  char initial[] = "\t23\n-    67";
  char str[mystrlen(initial) + 1];
  char* dst_ptr = copyIfReverse(initial - 1, initial + mystrlen(initial) - 1,
                                str,
                                testCondition);
  char expected[] = "";
  *dst_ptr = '\0';
  ASSERT_STRING(expected, str);
  ASSERT_PTR(str + mystrlen(str), dst_ptr);
  fprintf(stderr, "-------------------\n");
}

static void test_copyIfReverse() {
  fprintf(stderr, "-------------------\n");
  test_copyIfReverse_copyAll();
  test_copyIfReverse_copyPart();
  test_copyIfReverse_nothing();
  fprintf(stderr, "\n");
}

static void test_getWord_empty() {
  char initial[] = "";
  WordDescriptor word;
  int has_word_found = getWord(initial, &word);
  ASSERT_INT(0, has_word_found);
  ASSERT_PTR(initial + mystrlen(initial), word.begin);
  fprintf(stderr, "-------------------\n");
}

static void test_getWord_noOneWord() {
  char initial[] = "         ";
  WordDescriptor word;
  int has_word_found = getWord(initial, &word);
  ASSERT_INT(0, has_word_found);
  ASSERT_PTR(initial + mystrlen(initial), word.begin);
  fprintf(stderr, "-------------------\n");
}

static void test_getWord_oneWordWithSpaces() {
  char initial[] = "  asd   ";
  WordDescriptor word;
  int has_word_found = getWord(initial, &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial + 2, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + 5, word.end);
  ASSERT_INT(' ', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWord_oneWordWithoutSpaces() {
  char initial[] = "asd";
  WordDescriptor word;
  int has_word_found = getWord(initial, &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + mystrlen(initial), word.end);
  ASSERT_INT('\0', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWord_manyWords() {
  char initial[] = "b  asd   ";
  WordDescriptor word;
  int has_word_found = getWord(initial, &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial, word.begin);
  ASSERT_INT('b', *word.begin);
  ASSERT_PTR(initial + 1, word.end);
  ASSERT_INT(' ', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWord() {
  fprintf(stderr, "-------------------\n");
  test_getWord_noOneWord();
  test_getWord_empty();
  test_getWord_oneWordWithSpaces();
  test_getWord_manyWords();
  test_getWord_oneWordWithoutSpaces();
  fprintf(stderr, "\n");
}

static void test_getWordReverse_empty() {
  char initial[] = "";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(0, has_word_found);
  ASSERT_PTR(initial, word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse_noOneWord() {
  char initial[] = "         ";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(0, has_word_found);
  ASSERT_PTR(initial, word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse_oneWordWithSpaces() {
  char initial[] = "  asd   ";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial + 2, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + 5, word.end);
  ASSERT_INT(' ', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse_oneWordOneLetter() {
  char initial[] = "a";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + 1, word.end);
  ASSERT_INT('\0', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse_oneWordWithoutSpaces() {
  char initial[] = "asd";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + mystrlen(initial), word.end);
  ASSERT_INT('\0', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse_manyWords() {
  char initial[] = "b  asd   ";
  WordDescriptor word;
  int has_word_found = getWordReverse(initial - 1,
                                      initial + mystrlen(initial) - 1,
                                      &word);
  ASSERT_INT(1, has_word_found);
  ASSERT_PTR(initial + 3, word.begin);
  ASSERT_INT('a', *word.begin);
  ASSERT_PTR(initial + 6, word.end);
  ASSERT_INT(' ', *word.end);
  fprintf(stderr, "-------------------\n");
}

static void test_getWordReverse() {
  fprintf(stderr, "-------------------\n");
  test_getWordReverse_noOneWord();
  test_getWordReverse_empty();
  test_getWordReverse_oneWordWithSpaces();
  test_getWordReverse_manyWords();
  test_getWordReverse_oneWordWithoutSpaces();
  test_getWordReverse_oneWordOneLetter();
  fprintf(stderr, "\n");
}

static void test_wordcmp_equal() {
  char str_1[] = "abac asd a";
  char str_2[] = "abac asgn D";
  WordDescriptor w_1;
  getWord(str_1, &w_1);
  WordDescriptor w_2;
  getWord(str_2, &w_2);
  ASSERT_INT(0, wordcmp(w_1, w_2));
  ASSERT_INT(0, wordcmp(w_1, w_2));
  fprintf(stderr, "-------------------\n");
}

static void test_wordcmp_notEqual() {
  char str_1[] = "a asd a";
  char str_2[] = "abac asgn D";
  WordDescriptor w_1;
  getWord(str_1, &w_1);
  WordDescriptor w_2;
  getWord(str_2, &w_2);
  ASSERT_INT(-'b', wordcmp(w_1, w_2));
  char str_3[] = "abc";
  char str_4[] = "abd";
  getWord(str_3, &w_1);
  getWord(str_4, &w_2);
  ASSERT_INT('c' - 'd', wordcmp(w_1, w_2));
  char str_5[] = "ab";
  char str_6[] = "aaaaaaaaab";
  getWord(str_5, &w_1);
  getWord(str_6, &w_2);
  ASSERT_INT('b' - 'a', wordcmp(w_1, w_2));
  char str_7[] = "   avad ";
  char str_8[] = "hell";
  getWord(str_7, &w_1);
  getWord(str_8, &w_2);
  ASSERT_INT('a' - 'h', wordcmp(w_1, w_2));
  fprintf(stderr, "-------------------\n");
}

static void test_wordcmp() {
  fprintf(stderr, "-------------------\n");
  test_wordcmp_equal();
  test_wordcmp_notEqual();
  fprintf(stderr, "\n");
}

static void test_wordDescriptorToString_empty() {
  char initial[] = "";
  WordDescriptor word;
  getWord(initial, &word);
  char expected[] = "";
  char str_from_word[1];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}

static void test_wordDescriptorToString_oneLetter() {
  char initial[] = "g";
  WordDescriptor word;
  getWord(initial, &word);
  char expected[] = "g";
  char str_from_word[word.end - word.begin + 1];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}

static void test_wordDescriptorToString_notEmpty() {
  char initial[] = "asfas";
  WordDescriptor word;
  getWord(initial, &word);
  char expected[] = "asfas";
  char str_from_word[word.end - word.begin + 1];
  wordDescriptorToString(word, str_from_word);
  ASSERT_STRING(expected, str_from_word);
  fprintf(stderr, "-------------------\n");
}


static void test_wordDescriptorToString() {
  fprintf(stderr, "-------------------\n");
  test_wordDescriptorToString_empty();
  test_wordDescriptorToString_oneLetter();
  test_wordDescriptorToString_notEmpty();
  fprintf(stderr, "\n");
}

static void test_getBagOfWords_empty() {
  char str[] = "";
  BagOfWords bag;
  getBagOfWords(str, &bag);
  ASSERT_INT(0, bag.size);
  char expected_0[] = "";
  char str_from_w_0[1];
  wordDescriptorToString(bag.words[0], str_from_w_0);
  ASSERT_STRING(expected_0, str_from_w_0);
  fprintf(stderr, "-------------------\n");
}

static void test_getBagOfWords_oneWord() {
  char str[] = " dasd";
  BagOfWords bag;
  getBagOfWords(str, &bag);
  ASSERT_INT(1, bag.size);
  char expected_0[] = "dasd";
  char str_from_w_0[bag.words[0].end - bag.words[0].begin + 1];
  wordDescriptorToString(bag.words[0], str_from_w_0);
  ASSERT_STRING(expected_0, str_from_w_0);
  fprintf(stderr, "-------------------\n");
}

static void test_getBagOfWords_manyWords() {
  char str[] = " asd dasd fds";
  BagOfWords bag;
  getBagOfWords(str, &bag);
  ASSERT_INT(3, bag.size);
  char expected_0[] = "asd";
  char str_from_w_0[bag.words[0].end - bag.words[0].begin + 1];
  wordDescriptorToString(bag.words[0], str_from_w_0);
  ASSERT_STRING(expected_0, str_from_w_0);
  char expected_1[] = "dasd";
  char str_from_w_1[bag.words[1].end - bag.words[1].begin + 1];
  wordDescriptorToString(bag.words[1], str_from_w_1);
  ASSERT_STRING(expected_1, str_from_w_1);
  char expected_2[] = "fds";
  char str_from_w_2[bag.words[2].end - bag.words[2].begin + 1];
  wordDescriptorToString(bag.words[2], str_from_w_2);
  ASSERT_STRING(expected_2, str_from_w_2);
  fprintf(stderr, "-------------------\n");
}

static void test_getBagOfWords() {
  fprintf(stderr, "-------------------\n");
  test_getBagOfWords_empty();
  test_getBagOfWords_oneWord();
  test_getBagOfWords_manyWords();
  fprintf(stderr, "\n");
}

void test_mystring() {
  test_mystrlen();
  test_find();
  test_findNonSpace();
  test_findSpace();
  test_findNonSpaceReverse();
  test_findSpaceReverse();
  test_mystrcmp();
  test_copy();
  test_copyIf();
  test_copyIfReverse();
  test_getWord();
  test_getWordReverse();
  test_wordcmp();
  test_wordDescriptorToString();
  test_getBagOfWords();
}

#endif // INC_5E_MYSTRING_TESTS_H
