#include "../include/mystring.h"
#include "../tests/mystring_tests.h"

void outputWordsInReverseOrder(char* str) {
  getBagOfWords(str, &_bag_1);

  for (size_t i = _bag_1.size - 1; i != -1; i--) {
    outputWord(_bag_1.words[i]);
    putchar('\n');
  }
}

int main() {
  outputWordsInReverseOrder("");
  printf("-----\n");
  outputWordsInReverseOrder("darling my die Die,");
  printf("-----\n");
  outputWordsInReverseOrder("Unforgiven");
  printf("-----\n");
  return 0;
}

