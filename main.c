#include "include/vector/vector.h"
#include "include/vector/vector_tests.h"

#include <stdint.h>

int main() {
    test_vector();

    vector v = createVector(SIZE_MAX);

    return 0;
}