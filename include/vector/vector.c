#include "vector.h"

#include <malloc.h>
#include <windows.h>

static void throwException(const char *message) {
    fprintf(stderr, message);
    exit(1);
}

vector createVector(const size_t capacity) {
    vector_base_t *data;
    if (capacity != 0) {
        data = malloc(capacity * sizeof(vector_base_t));
        if (data == NULL) {
            throwException("Allocation error\n");
        }
    } else {
        data = NULL;
    }

    return (vector) { data, 0, capacity };
}

void destroyVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void reserveVector(vector *v, const size_t newCapacity) {
    if (newCapacity != 0) {
        v->data = realloc(v->data, newCapacity * sizeof(vector_base_t));
        if (v->data == NULL) {
            throwException("Allocation error\n");
        }
    } else {
        v->data = NULL;
    }
    v->capacity = newCapacity;
    if (v->size > newCapacity) {
        v->size = newCapacity;
    }
}

void clearVector(vector *v) {
    v->size = 0;
}

void shrinkVectorToFit(vector *v) {
    reserveVector(v, v->size);
}