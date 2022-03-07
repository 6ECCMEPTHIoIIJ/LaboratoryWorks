#include <memory.h>
#include "../include/mystring.h"

int getWord(char* begin_search,
            WordDescriptor* word) {
  word->begin = findNonSpace(begin_search);
  if (*word->begin == '\0') {
    return 0;
  }

  word->end = findSpace(word->begin);

  return 1;
}

int getWordReverse(char* r_end_search,
                   char* r_begin_search,
                   WordDescriptor* word) {
  word->end = findNonSpaceReverse(r_end_search, r_begin_search) + 1;
  if (word->end == r_end_search + 1) {
    return 0;
  }

  word->begin = findSpaceReverse(r_end_search, word->end - 1) + 1;

  return 1;
}

int wordcmp(WordDescriptor w_1,
            WordDescriptor w_2) {
  while (w_1.begin != w_1.end &&
         w_2.begin != w_2.end &&
         *w_1.begin == *w_2.begin) {
    w_1.begin++;
    w_2.begin++;
  }

  if (w_1.begin == w_1.end &&
      w_2.begin == w_2.end) {
    return 0;
  } else if (w_1.begin == w_1.end &&
             w_2.begin != w_2.end) {
    return -(*w_2.begin);
  } else if (w_1.begin != w_1.end &&
             w_2.begin == w_2.end) {
    return *w_1.begin;
  } else {
    return *w_1.begin - *w_2.begin;
  }
}

void outputWord(WordDescriptor word) {
  while (word.begin != word.end) {
    putchar(*word.begin);
    word.begin++;
  }
}

void getBagOfWords(char* begin_search,
                   BagOfWords* bag) {
  size_t word_i = 0;
  while (getWord(begin_search, bag->words + word_i)) {
    begin_search = bag->words[word_i].end;
    word_i++;
  }
  bag->size = word_i;
}

size_t mystrlen(char* begin) {
  char* end = begin;
  while (*end != '\0') {
    end++;
  }

  return end - begin;
}

char* find(char* begin,
           char* end,
           const int ch) {
  while (begin != end && *begin != ch) {
    begin++;
  }

  return begin;
}

char* findNonSpace(char* begin) {
  while (isspace(*begin)) {
    begin++;
  }

  return begin;
}

char* findSpace(char* begin) {
  while (*begin != '\0' && !isspace(*begin)) {
    begin++;
  }

  return begin;
}

char* findNonSpaceReverse(char* r_end,
                          char* r_begin) {
  char* cur = r_begin;
  while (cur != r_end && isspace(*cur)) {
    cur--;
  }

  return cur;
}

char* findSpaceReverse(char* r_end,
                       char* r_begin) {
  char* cur = r_begin;
  while (cur != r_end && !isspace(*cur)) {
    cur--;
  }

  return cur;
}

int mystrcmp(char* lhs,
             char* rhs) {
  while (*lhs != '\0' && *lhs == *rhs) {
    lhs++;
    rhs++;
  }

  return *lhs - *rhs;
}

char* copy(char* begin_src,
           char* end_src,
           char* begin_dst) {
  memcpy(begin_dst, begin_src, end_src - begin_src);

  return begin_dst + (end_src - begin_src);
}

char* copyIf(char* begin_src,
             char* end_src,
             char* begin_dst,
             int (* condition)(int)) {
  while (begin_src != end_src) {
    if (condition(*begin_src)) {
      *begin_dst = *begin_src;
      begin_dst++;
    }
    begin_src++;
  }

  return begin_dst;
}

char* copyIfReverse(char* r_end_src,
                    char* r_begin_src,
                    char* begin_dst,
                    int (* condition)(int)) {
  char* cur = r_begin_src;
  while (cur != r_end_src) {
    if (condition(*cur)) {
      *begin_dst = *cur;
      begin_dst++;
    }
    cur--;
  }

  return begin_dst;
}

void wordDescriptorToString(WordDescriptor word,
                            char* dst) {
  if (*word.begin == '\0') {
    *dst = '\0';
  } else {
    *copy(word.begin, word.end, dst) = '\0';
  }
}