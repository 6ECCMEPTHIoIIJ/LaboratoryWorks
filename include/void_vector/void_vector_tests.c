#include "void_vector_tests.h"
#include "void_vector.h"

#include <assert.h>

#define EMPTY 0
#define SMALL 10
#define NORMAL 100
#define BIG 1000

static void test_createVectorV_destroyVectorV_null() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
}

static void test_createVectorV_destroyVectorV_notNull() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char not null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int not null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double not null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    printf("{ PASSED } \t -> \t ");

    destroyVectorV(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    printf("{ PASSED }\n");
  }
}

static void test_createVectorV_destroyVectorV() {
  printf("\t [ createVectorV() / destroyVectorV() ]\n");

  test_createVectorV_destroyVectorV_null();
  test_createVectorV_destroyVectorV_notNull();
}

static void test_reserveVectorV_null() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    reserveVectorV(&v, EMPTY);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    reserveVectorV(&v, EMPTY);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double null ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    reserveVectorV(&v, EMPTY);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_reserveVectorV_smaller() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char smaller ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, SMALL);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int smaller ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, SMALL);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double smaller ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, SMALL);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_reserveVectorV_equal() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char equal ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, NORMAL);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int equal ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, NORMAL);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double equal ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, NORMAL);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_reserveVectorV_bigger() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char bigger ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, BIG);
    assert(v.capacity == BIG);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int bigger ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, BIG);
    assert(v.capacity == BIG);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double bigger ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = NORMAL;
    reserveVectorV(&v, BIG);
    assert(v.capacity == BIG);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_reserveVectorV() {
  printf("\t [ reserveVectorV() ]\n");

  test_reserveVectorV_null();
  test_reserveVectorV_smaller();
  test_reserveVectorV_equal();
  test_reserveVectorV_bigger();
}

static void test_clearVectorV_empty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_clearVectorV_notEmpty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    clearVectorV(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == EMPTY);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_clearVectorV() {
  printf("\t [ clearVectorV() ]\n");

  test_clearVectorV_empty();
  test_clearVectorV_notEmpty();
}

static void test_shrinkVectorVToFit_empty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    shrinkVectorVToFit(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    shrinkVectorVToFit(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    shrinkVectorVToFit(&v);
    assert(v.capacity == EMPTY);
    assert(v.baseTypeSize == 0);
    assert(v.size == EMPTY);
    assert(v.data == NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_shrinkVectorVToFit_notEmpty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    shrinkVectorVToFit(&v);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    shrinkVectorVToFit(&v);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    shrinkVectorVToFit(&v);
    assert(v.capacity == SMALL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == SMALL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_shrinkVectorVToFit_full() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    shrinkVectorVToFit(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    shrinkVectorVToFit(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    shrinkVectorVToFit(&v);
    assert(v.capacity == NORMAL);
    assert(v.baseTypeSize == sizeof(vectorVoid_base_t));
    assert(v.size == NORMAL);
    assert(v.data != NULL);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_shrinkVectorVToFit() {
  printf("\t [ shrinkVectorVToFit() ]\n");

  test_shrinkVectorVToFit_empty();
  test_shrinkVectorVToFit_notEmpty();
  test_shrinkVectorVToFit_full();
}

static void test_isVectorVEmpty_isVectorVFull_null() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double null ] \t -> \t ");

    vectorVoid v = createVectorV(EMPTY, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_isVectorVEmpty_isVectorVFull_empty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    assert(isVectorVEmpty(&v) == true);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_isVectorVEmpty_isVectorVFull_notEmpty() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double not empty ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = SMALL;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == false);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_isVectorVEmpty_isVectorVFull_full() {
  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double full ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    v.size = v.capacity;
    assert(isVectorVEmpty(&v) == false);
    printf("{ PASSED } \t -> \t ");

    assert(isVectorVFull(&v) == true);

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_isVectorVEmpty_isVectorVFull() {
  printf("\t [ isVectorVEmpty() / isVectorVFull() ]\n");

  test_isVectorVEmpty_isVectorVFull_null();
  test_isVectorVEmpty_isVectorVFull_full();
  test_isVectorVEmpty_isVectorVFull_empty();
  test_isVectorVEmpty_isVectorVFull_notEmpty();
}

static void test_getVectorVValue_setVectorVValue() {
  printf("\t [ getVectorVValue() / setVectorVValue() ]\n");

  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 5);
      setVectorVValue(&v, v.size, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size, &dst);
      assert(src == dst);
      v.size++;
    }

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 139);
      setVectorVValue(&v, v.size, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size, &dst);
      assert(src == dst);
      v.size++;
    }

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 1328.14678);
      setVectorVValue(&v, v.size, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size, &dst);
      assert(src == dst);
      v.size++;
    }

    destroyVectorV(&v);

    printf("{ PASSED }\n");
  }
}

static void test_vectorVPushBack_test_vectorVPopBack() {
  printf("\t [ vectorVPushBack() / vectorVPopBack() ]\n");

  {
    typedef char vectorVoid_base_t;
    printf("\t\t [ char ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 5);
      vectorVPushBack(&v, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size - 1, &dst);
      assert(src == dst);
    }

    printf("{ PASSED } \t -> \t ");

    while (v.size > 0) {
      vectorVPopBack(&v);
    }

    destroyVectorV(&v);

    printf("{ PASSED } \n");
  }
  {
    typedef int vectorVoid_base_t;
    printf("\t\t [ int ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 139);
      vectorVPushBack(&v, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size - 1, &dst);
      assert(src == dst);
    }

    printf("{ PASSED } \t -> \t ");

    while (v.size > 0) {
      vectorVPopBack(&v);
    }

    destroyVectorV(&v);

    printf("{ PASSED } \n");
  }
  {
    typedef double vectorVoid_base_t;
    printf("\t\t [ double ] \t -> \t ");

    vectorVoid v = createVectorV(NORMAL, sizeof(vectorVoid_base_t));
    while (v.size < v.capacity) {
      const vectorVoid_base_t src = (vectorVoid_base_t)(v.size * 1328.14678);
      vectorVPushBack(&v, &src);
      vectorVoid_base_t dst;
      getVectorVValue(&v, v.size - 1, &dst);
      assert(src == dst);
    }

    printf("{ PASSED } \t -> \t ");

    while (v.size > 0) {
      vectorVPopBack(&v);
    }

    destroyVectorV(&v);

    printf("{ PASSED } \n");
  }
}

void test_vectorVoid() {
  printf("[ vectorVoid ]\n");

  test_createVectorV_destroyVectorV();
  test_reserveVectorV();
  test_clearVectorV();
  test_shrinkVectorVToFit();
  test_isVectorVEmpty_isVectorVFull();
  test_getVectorVValue_setVectorVValue();
  test_vectorVPushBack_test_vectorVPopBack();
}