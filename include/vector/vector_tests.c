#include "vector_tests.h"
#include "vector.h"

#include <assert.h>

#define EMPTY 0
#define SMALL 10
#define NORMAL 100
#define BIG 1000

static void test_createVector_destroyVector_null() {
    printf("\t\t [ null ] \t -> \t ");

    vector v = createVector(EMPTY);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVector(&v);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
}

static void test_createVector_destroyVector_notNull() {
    printf("\t\t [ not null ] \t -> \t ");

    vector v = createVector(NORMAL);
    assert(v.capacity == NORMAL);
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVector(&v);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
}

static void test_createVector_destroyVector() {
    printf("\t [ createVector() / destroyVector() ]\n");

    test_createVector_destroyVector_null();
    test_createVector_destroyVector_notNull();
}

static void test_reserveVector_null() {
    printf("\t\t [ null ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;

    reserveVector(&v, EMPTY);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_reserveVector_smaller() {
    printf("\t\t [ smaller ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;

    reserveVector(&v, SMALL);
    assert(v.capacity == SMALL);
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_reserveVector_bigger() {
    printf("\t\t [ bigger ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;

    reserveVector(&v, BIG);
    assert(v.capacity == BIG);
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_reserveVector_equal() {
    printf("\t\t [ equal ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;

    reserveVector(&v, NORMAL);
    assert(v.capacity == NORMAL);
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_reserveVector_empty() {
    printf("\t\t [ empty ] \t -> \t ");

    vector v = createVector(NORMAL);

    reserveVector(&v, SMALL);
    assert(v.capacity == SMALL);
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_reserveVector() {
    printf("\t [ reserveVector() ]\n");

    test_reserveVector_null();
    test_reserveVector_smaller();
    test_reserveVector_bigger();
    test_reserveVector_equal();
    test_reserveVector_empty();
}

static void test_clearVector_empty() {
    printf("\t\t [ empty ] \t -> \t ");

    vector v = createVector(NORMAL);

    clearVector(&v);
    assert(v.capacity == NORMAL);
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_clearVector_notEmpty() {
    printf("\t\t [ not empty ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = SMALL;
    clearVector(&v);
    assert(v.capacity == NORMAL);
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_clearVector_full() {
    printf("\t\t [ full ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;
    clearVector(&v);
    assert(v.capacity == NORMAL);
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_clearVector_null() {
    printf("\t\t [ null ] \t -> \t ");

    vector v = createVector(EMPTY);

    clearVector(&v);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_clearVector() {
    printf("\t [ clearVector() ]\n");

    test_clearVector_empty();
    test_clearVector_notEmpty();
    test_clearVector_full();
    test_clearVector_null();
}

static void test_shrinkVectorToFit_empty() {
    printf("\t\t [ empty ] \t -> \t ");

    vector v = createVector(NORMAL);

    shrinkVectorToFit(&v);
    assert(v.capacity == EMPTY);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_shrinkVectorToFit_notEmpty() {
    printf("\t\t [ not empty ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = SMALL;
    shrinkVectorToFit(&v);
    assert(v.capacity == SMALL);
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_shrinkVectorToFit_full() {
    printf("\t\t [ full ] \t -> \t ");

    vector v = createVector(NORMAL);
    v.size = v.capacity;
    shrinkVectorToFit(&v);
    assert(v.capacity == NORMAL);
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVector(&v);

    printf("{ PASSED }\n");
}

static void test_shrinkVectorToFit() {
    printf("\t [ shrinkVectorToFit() ]\n");

    test_shrinkVectorToFit_empty();
    test_shrinkVectorToFit_notEmpty();
    test_shrinkVectorToFit_full();
}

void test_vector() {
    printf("[ vector ]\n");

    test_createVector_destroyVector();
    test_reserveVector();
    test_clearVector();
    test_shrinkVectorToFit();
}