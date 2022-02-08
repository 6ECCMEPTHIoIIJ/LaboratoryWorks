#include "include/vector/vector.h"
#include "include/vector/vector_tests.h"
#include "include/void_vector/void_vector.h"
#include "include/void_vector/void_vector_tests.h"

#include <stdint.h>

int main() {
  test_vector();
  test_vectorVoid();

  vector v = createVector(SIZE_MAX);

  return 0;
}