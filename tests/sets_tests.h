#ifndef INC_LR_1_1_SETS_TESTS_H
#define INC_LR_1_1_SETS_TESTS_H

#include "tests.h"
#include "sets.h"

#define ASSERT_SET_EQ(EXPECTED, GOT) \
assertSetEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertSetEq(const Set expected,
                 const Set got,
                 const char* fileName,
                 const char* funcName,
                 const size_t line) {
  if (!areEqualU(expected, got)) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: data = ");
    fprintset(stderr, expected);
    fprintf(stderr, " size = %zu\n", expected.size);
    fprintf(stderr, "Got: data = ");
    fprintset(stderr, got);
    fprintf(stderr, "; size = %zu\n", got.size);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

#define ASSERT_BITSET_EQ(EXPECTED, GOT) \
assertBitsetEq(EXPECTED, GOT, __FILE__, __FUNCTION__, __LINE__)

void assertBitsetEq(const Bitset expected,
                    const Bitset got,
                    const char* fileName,
                    const char* funcName,
                    const size_t line) {
  if (!areEqualBitset(expected, got)) {
    fprintf(stderr, "File %s\n", fileName);
    fprintf(stderr, "%s - failed on line %zu\n", funcName, line);
    fprintf(stderr, "Expected: data = ");
    fprintbitset(stderr, expected);
    fprintf(stderr, " size = %zu\n", expected.size);
    fprintf(stderr, "Got: data = ");
    fprintbitset(stderr, got);
    fprintf(stderr, "; size = %zu\n", got.size);
  } else {
    fprintf(stderr, "%s - OK\n", funcName);
  }
}

void test_unionU() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  unionU(SET(((int[]) {1, 2})),
         SET(((int[]) {4, 3})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  unionU(SET(((int[]) {1, 2})),
         SET(((int[]) {3, 4})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  unionU(SET(((int[]) {})),
         SET(((int[]) {3, 4})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {3, 4})), got);

  unionU(SET(((int[]) {1, 2})),
         SET(((int[]) {})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  unionU(SET(((int[]) {})),
         SET(((int[]) {})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  unionU(SET(((int[]) {1, 2, 4, 3})),
         SET(((int[]) {2, 4, 1, 3})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  unionU(SET(((int[]) {1, 8, 9, 3})),
         SET(((int[]) {2, 6, 1, 7})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 6, 7, 8, 9})), got);
  fprintf(stderr, "---------------------\n");
}

void test_unionO() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  unionO(SET(((int[]) {1, 2})),
         SET(((int[]) {3, 4})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  unionO(SET(((int[]) {})),
         SET(((int[]) {3, 4})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {3, 4})), got);

  unionO(SET(((int[]) {1, 2})),
         SET(((int[]) {})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  unionO(SET(((int[]) {})),
         SET(((int[]) {})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  unionO(SET(((int[]) {1, 2, 3, 4})),
         SET(((int[]) {1, 2, 3, 4})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  unionO(SET(((int[]) {1, 3, 8, 9})),
         SET(((int[]) {1, 2, 6, 7})),
         &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 6, 7, 8, 9})), got);
  fprintf(stderr, "---------------------\n");
}

void test_unionBitset() {
  bool data[MAX_SET_SIZE];
  Bitset got = {data, 0};
  unionBitset(BITSET(((bool[]) {1, 1})),
              BITSET(((bool[]) {0, 0, 1, 1})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 1, 1})), got);

  unionBitset(BITSET(((bool[]) {})),
              BITSET(((bool[]) {0, 0, 1, 1})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {0, 0, 1, 1})), got);

  unionBitset(BITSET(((bool[]) {1, 1})),
              BITSET(((bool[]) {})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1})), got);

  unionBitset(BITSET(((bool[]) {})),
              BITSET(((bool[]) {})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  unionBitset(BITSET(((bool[]) {1, 1, 1, 1})),
              BITSET(((bool[]) {1, 1, 1, 1})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 1, 1})), got);

  unionBitset(BITSET(((bool[]) {1, 0, 1, 0, 0, 0, 0, 1, 1})),
              BITSET(((bool[]) {1, 1, 0, 0, 0, 1, 1})),
              &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 1, 0, 0, 1, 1, 1, 1})), got);
  fprintf(stderr, "---------------------\n");
}

void test_intersectionU() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  intersectionU(SET(((int[]) {1, 2})),
                SET(((int[]) {4, 3})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionU(SET(((int[]) {})),
                SET(((int[]) {3, 4})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionU(SET(((int[]) {1, 2})),
                SET(((int[]) {})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionU(SET(((int[]) {})),
                SET(((int[]) {})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionU(SET(((int[]) {1, 2, 4, 3})),
                SET(((int[]) {2, 4, 1, 3})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  intersectionU(SET(((int[]) {1, 8, 6, 3})),
                SET(((int[]) {2, 6, 1, 7})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 6})), got);
  fprintf(stderr, "---------------------\n");
}

void test_intersectionO() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  intersectionO(SET(((int[]) {1, 2})),
                SET(((int[]) {3, 4})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionO(SET(((int[]) {})),
                SET(((int[]) {3, 4})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionO(SET(((int[]) {1, 2})),
                SET(((int[]) {})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionO(SET(((int[]) {})),
                SET(((int[]) {})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  intersectionO(SET(((int[]) {1, 2, 3, 4})),
                SET(((int[]) {1, 2, 3, 4})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  intersectionO(SET(((int[]) {1, 2, 3, 4})),
                SET(((int[]) {2, 4, 6, 7})),
                &got);
  ASSERT_SET_EQ(SET(((int[]) {2, 4})), got);
  fprintf(stderr, "---------------------\n");
}

void test_intersectionBitset() {
  bool data[MAX_SET_SIZE];
  Bitset got = {data, 0};
  intersectionBitset(BITSET(((bool[]) {1, 1})),
                     BITSET(((bool[]) {0, 0, 1, 1})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  intersectionBitset(BITSET(((bool[]) {})),
                     BITSET(((bool[]) {0, 0, 1, 1})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  intersectionBitset(BITSET(((bool[]) {1, 1})),
                     BITSET(((bool[]) {})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  intersectionBitset(BITSET(((bool[]) {})),
                     BITSET(((bool[]) {})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  intersectionBitset(BITSET(((bool[]) {1, 1, 1, 1})),
                     BITSET(((bool[]) {1, 1, 1, 1})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 1, 1})), got);

  intersectionBitset(BITSET(((bool[]) {1, 0, 1, 0, 0, 0, 0, 1, 1})),
                     BITSET(((bool[]) {1, 1, 0, 0, 0, 1, 1})),
                     &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1})), got);
  fprintf(stderr, "---------------------\n");
}

void test_differenceU() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  differenceU(SET(((int[]) {1, 2})),
              SET(((int[]) {4, 3})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  differenceU(SET(((int[]) {})),
              SET(((int[]) {3, 4})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceU(SET(((int[]) {1, 2})),
              SET(((int[]) {})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  differenceU(SET(((int[]) {})),
              SET(((int[]) {})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceU(SET(((int[]) {1, 2, 4, 3})),
              SET(((int[]) {2, 4, 1, 3})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceU(SET(((int[]) {1, 8, 6, 3})),
              SET(((int[]) {2, 6, 1, 7})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {8, 3})), got);
  fprintf(stderr, "---------------------\n");
}

void test_differenceO() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  differenceO(SET(((int[]) {1, 2})),
              SET(((int[]) {3, 4})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  differenceO(SET(((int[]) {})),
              SET(((int[]) {3, 4})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceO(SET(((int[]) {1, 2})),
              SET(((int[]) {})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  differenceO(SET(((int[]) {})),
              SET(((int[]) {})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceO(SET(((int[]) {1, 2, 3, 4})),
              SET(((int[]) {1, 2, 3, 4})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  differenceO(SET(((int[]) {1, 2, 3, 4})),
              SET(((int[]) {2, 4, 7, 8})),
              &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 3})), got);
  fprintf(stderr, "---------------------\n");
}

void test_differenceBitset() {
  bool data[MAX_SET_SIZE];
  Bitset got = {data, 0};
  differenceBitset(BITSET(((bool[]) {1, 1})),
                   BITSET(((bool[]) {0, 0, 1, 1})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1})), got);

  differenceBitset(BITSET(((bool[]) {})),
                   BITSET(((bool[]) {0, 0, 1, 1})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  differenceBitset(BITSET(((bool[]) {1, 1})),
                   BITSET(((bool[]) {})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1})), got);

  differenceBitset(BITSET(((bool[]) {})),
                   BITSET(((bool[]) {})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  differenceBitset(BITSET(((bool[]) {1, 1, 1, 1})),
                   BITSET(((bool[]) {1, 1, 1, 1})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  differenceBitset(BITSET(((bool[]) {1, 0, 1, 0, 0, 0, 0, 1, 1})),
                   BITSET(((bool[]) {1, 1, 0, 0, 0, 1, 1})),
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {0, 0, 1, 0, 0, 0, 0, 1, 1})), got);
  fprintf(stderr, "---------------------\n");
}

void test_xorU() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  xorU(SET(((int[]) {2, 1})),
       SET(((int[]) {4, 3})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  xorU(SET(((int[]) {})),
       SET(((int[]) {3, 4})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {3, 4})), got);

  xorU(SET(((int[]) {1, 2})),
       SET(((int[]) {})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  xorU(SET(((int[]) {})),
       SET(((int[]) {})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  xorU(SET(((int[]) {1, 4, 3, 2})),
       SET(((int[]) {1, 2, 3, 4})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  xorU(SET(((int[]) {1, 3, 2, 4})),
       SET(((int[]) {2, 4, 7, 8})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 3, 7, 8})), got);
  fprintf(stderr, "---------------------\n");
}

void test_xorO() {
  int data[MAX_SET_SIZE];
  Set got = {data, 0};
  xorO(SET(((int[]) {1, 2})),
       SET(((int[]) {3, 4})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4})), got);

  xorO(SET(((int[]) {})),
       SET(((int[]) {3, 4})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {3, 4})), got);

  xorO(SET(((int[]) {1, 2})),
       SET(((int[]) {})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2})), got);

  xorO(SET(((int[]) {})),
       SET(((int[]) {})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  xorO(SET(((int[]) {1, 2, 3, 4})),
       SET(((int[]) {1, 2, 3, 4})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);

  xorO(SET(((int[]) {1, 2, 3, 4})),
       SET(((int[]) {2, 4, 7, 8})),
       &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 3, 7, 8})), got);
  fprintf(stderr, "---------------------\n");
}

void test_xorBitset() {
  bool data[MAX_SET_SIZE];
  Bitset got = {data, 0};
  xorBitset(BITSET(((bool[]) {1, 1})),
            BITSET(((bool[]) {0, 0, 1, 1})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 1, 1})), got);

  xorBitset(BITSET(((bool[]) {})),
            BITSET(((bool[]) {0, 0, 1, 1})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {0, 0, 1, 1})), got);

  xorBitset(BITSET(((bool[]) {1, 1})),
            BITSET(((bool[]) {})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1})), got);

  xorBitset(BITSET(((bool[]) {})),
            BITSET(((bool[]) {})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  xorBitset(BITSET(((bool[]) {1, 1, 1, 1})),
            BITSET(((bool[]) {1, 1, 1, 1})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  xorBitset(BITSET(((bool[]) {1, 0, 1, 0, 0, 0, 0, 1, 1})),
            BITSET(((bool[]) {1, 1, 0, 0, 0, 1, 1})),
            &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {0, 1, 1, 0, 0, 1, 1, 1, 1})), got);
  fprintf(stderr, "---------------------\n");
}

void test_isSubU() {
  ASSERT_INT_EQ(0, isSubU(SET(((int[]) {2, 1})),
                          SET(((int[]) {4, 3}))));

  ASSERT_INT_EQ(1, isSubU(SET(((int[]) {3})),
                          SET(((int[]) {4, 3}))));

  ASSERT_INT_EQ(1, isSubU(SET(((int[]) {3, 1})),
                          SET(((int[]) {1, 2, 4, 3}))));

  ASSERT_INT_EQ(1, isSubU(SET(((int[]) {})),
                          SET(((int[]) {1, 2, 4, 3}))));

  ASSERT_INT_EQ(0, isSubU(SET(((int[]) {2, 1})),
                          SET(((int[]) {}))));

  ASSERT_INT_EQ(1, isSubU(SET(((int[]) {})),
                          SET(((int[]) {}))));

  ASSERT_INT_EQ(1, isSubU(SET(((int[]) {1, 3, 2, 4})),
                          SET(((int[]) {1, 2, 4, 3}))));
  fprintf(stderr, "---------------------\n");
}

void test_isSubO() {
  ASSERT_INT_EQ(0, isSubO(SET(((int[]) {1, 2})),
                          SET(((int[]) {3, 4}))));

  ASSERT_INT_EQ(1, isSubO(SET(((int[]) {3})),
                          SET(((int[]) {3, 4}))));

  ASSERT_INT_EQ(1, isSubO(SET(((int[]) {1, 3})),
                          SET(((int[]) {1, 2, 3, 4}))));

  ASSERT_INT_EQ(1, isSubO(SET(((int[]) {})),
                          SET(((int[]) {1, 2, 3, 4}))));

  ASSERT_INT_EQ(0, isSubO(SET(((int[]) {1, 2})),
                          SET(((int[]) {}))));

  ASSERT_INT_EQ(1, isSubO(SET(((int[]) {})),
                          SET(((int[]) {}))));

  ASSERT_INT_EQ(1, isSubO(SET(((int[]) {1, 2, 3, 4})),
                          SET(((int[]) {1, 2, 3, 4}))));
  fprintf(stderr, "---------------------\n");
}

void test_isSubBitset() {
  ASSERT_INT_EQ(0, isSubBitset(BITSET(((bool[]) {1, 1})),
                               BITSET(((bool[]) {0, 0, 1, 1}))));

  ASSERT_INT_EQ(1, isSubBitset(BITSET(((bool[]) {0, 0, 1})),
                               BITSET(((bool[]) {0, 0, 1, 1}))));

  ASSERT_INT_EQ(1, isSubBitset(BITSET(((bool[]) {1, 0, 1})),
                               BITSET(((bool[]) {1, 0, 1, 1}))));

  ASSERT_INT_EQ(1, isSubBitset(BITSET(((bool[]) {})),
                               BITSET(((bool[]) {1, 0, 1, 1}))));

  ASSERT_INT_EQ(0, isSubBitset(BITSET(((bool[]) {1, 1})),
                               BITSET(((bool[]) {}))));

  ASSERT_INT_EQ(1, isSubBitset(BITSET(((bool[]) {})),
                               BITSET(((bool[]) {}))));

  ASSERT_INT_EQ(1, isSubBitset(BITSET(((bool[]) {1, 1, 1, 1})),
                               BITSET(((bool[]) {1, 1, 1, 1}))));
  fprintf(stderr, "---------------------\n");
}

void test_areEqualU() {
  ASSERT_INT_EQ(0, areEqualU(SET(((int[]) {2, 1})),
                             SET(((int[]) {4, 3}))));

  ASSERT_INT_EQ(0, areEqualU(SET(((int[]) {3})),
                             SET(((int[]) {4, 3}))));

  ASSERT_INT_EQ(0, areEqualU(SET(((int[]) {3, 1})),
                             SET(((int[]) {1, 2, 4, 3}))));

  ASSERT_INT_EQ(0, areEqualU(SET(((int[]) {})),
                             SET(((int[]) {1, 2, 4, 3}))));

  ASSERT_INT_EQ(0, areEqualU(SET(((int[]) {2, 1})),
                             SET(((int[]) {}))));

  ASSERT_INT_EQ(1, areEqualU(SET(((int[]) {})),
                             SET(((int[]) {}))));

  ASSERT_INT_EQ(1, areEqualU(SET(((int[]) {1, 3, 2, 4})),
                             SET(((int[]) {1, 2, 4, 3}))));
  fprintf(stderr, "---------------------\n");
}

void test_areEqualO() {
  ASSERT_INT_EQ(0, areEqualO(SET(((int[]) {1, 2})),
                             SET(((int[]) {3, 4}))));

  ASSERT_INT_EQ(0, areEqualO(SET(((int[]) {3})),
                             SET(((int[]) {3, 4}))));

  ASSERT_INT_EQ(0, areEqualO(SET(((int[]) {1, 3})),
                             SET(((int[]) {1, 2, 3, 4}))));

  ASSERT_INT_EQ(0, areEqualO(SET(((int[]) {})),
                             SET(((int[]) {1, 2, 3, 4}))));

  ASSERT_INT_EQ(0, areEqualO(SET(((int[]) {1, 2})),
                             SET(((int[]) {}))));

  ASSERT_INT_EQ(1, areEqualO(SET(((int[]) {})),
                             SET(((int[]) {}))));

  ASSERT_INT_EQ(1, areEqualO(SET(((int[]) {1, 2, 3, 4})),
                             SET(((int[]) {1, 2, 3, 4}))));
  fprintf(stderr, "---------------------\n");
}

void test_areEqualBitset() {
  ASSERT_INT_EQ(0, areEqualBitset(BITSET(((bool[]) {1, 1})),
                                  BITSET(((bool[]) {0, 0, 1, 1}))));

  ASSERT_INT_EQ(0, areEqualBitset(BITSET(((bool[]) {0, 0, 1})),
                                  BITSET(((bool[]) {0, 0, 1, 1}))));

  ASSERT_INT_EQ(0, areEqualBitset(BITSET(((bool[]) {1, 0, 1})),
                                  BITSET(((bool[]) {1, 0, 1, 1}))));

  ASSERT_INT_EQ(0, areEqualBitset(BITSET(((bool[]) {})),
                                  BITSET(((bool[]) {1, 0, 1, 1}))));

  ASSERT_INT_EQ(0, areEqualBitset(BITSET(((bool[]) {1, 1})),
                                  BITSET(((bool[]) {}))));

  ASSERT_INT_EQ(1, areEqualBitset(BITSET(((bool[]) {})),
                                  BITSET(((bool[]) {}))));

  ASSERT_INT_EQ(1, areEqualBitset(BITSET(((bool[]) {1, 1, 1, 1})),
                                  BITSET(((bool[]) {1, 1, 1, 1}))));
  fprintf(stderr, "---------------------\n");
}

void test_addToUniverseU() {
  int data[MAX_SET_SIZE];
  const Set kUniverse = SET(((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
  Set got = {data, 0};
  addToUniverseU(kUniverse,
                 SET(((int[]) {3, 4, 9, 1})),
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {2, 5, 6, 7, 8, 10})), got);

  addToUniverseU(kUniverse,
                 SET(((int[]) {})),
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})), got);

  addToUniverseU(kUniverse,
                 kUniverse,
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);
  fprintf(stderr, "---------------------\n");
}

void test_addToUniverseO() {
  int data[MAX_SET_SIZE];
  const Set kUniverse = SET(((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
  Set got = {data, 0};
  addToUniverseO(kUniverse,
                 SET(((int[]) {1, 3, 4, 9})),
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {2, 5, 6, 7, 8, 10})), got);

  addToUniverseO(kUniverse,
                 SET(((int[]) {})),
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})), got);

  addToUniverseO(kUniverse,
                 kUniverse,
                 &got);
  ASSERT_SET_EQ(SET(((int[]) {})), got);
  fprintf(stderr, "---------------------\n");
}

void test_addToUniverseBitset() {
  bool data[MAX_SET_SIZE];
  const Bitset kUniverse = BITSET(((bool[]) {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  Bitset got = {data, 0};
  addToUniverseBitset(kUniverse,
                      BITSET(((bool[]) {0, 0, 1, 1})),
                      &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {1, 1, 0, 0, 1, 1, 1, 1, 1, 1})), got);

  differenceBitset(kUniverse,
                   kUniverse,
                   &got);
  ASSERT_BITSET_EQ(BITSET(((bool[]) {})), got);

  differenceBitset(kUniverse,
                   BITSET(((bool[]) {})),
                   &got);
  ASSERT_BITSET_EQ(kUniverse, got);
  fprintf(stderr, "---------------------\n");
}

void test_set() {
  fprintf(stderr, "---------------------\n");
  test_unionU();
  test_unionO();
  test_unionBitset();
  test_intersectionU();
  test_intersectionO();
  test_intersectionBitset();
  test_differenceU();
  test_differenceO();
  test_differenceBitset();
  test_xorU();
  test_xorO();
  test_xorBitset();
  test_isSubU();
  test_isSubO();
  test_isSubBitset();
  test_areEqualU();
  test_areEqualO();
  test_areEqualBitset();
  test_addToUniverseU();
  test_addToUniverseO();
  test_addToUniverseBitset();
}

#endif // INC_LR_1_1_SETS_TESTS_H