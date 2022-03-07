#include "mystring.h"

void outputWordsInReverseOrder(char* str) {
  getBagOfWords(str, &_bag_1);

  for (size_t i = _bag_1.size - 1; i != -1; i--) {
    fprintw(stdout, _bag_1.words[i]);
    putchar('\n');
  }
}

int main() {
  outputWordsInReverseOrder("");
  printf("-----\n");
  outputWordsInReverseOrder("darling!     my die      Die,");
  printf("-----\n");
  outputWordsInReverseOrder("Unforgiven");
  printf("-----\n");
  return 0;
}

