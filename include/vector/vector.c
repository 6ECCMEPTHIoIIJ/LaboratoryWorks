#include "vector.h"

#include <malloc.h>
#include <windows.h>
#include <stdint.h>

#define throwException(...) fprintf(stderr, __VA_ARGS__); exit(1)

vector createVector(const size_t capacity) {
    vector_base_t *data;
    if (capacity != 0) {
        data = (vector_base_t *) malloc(capacity * sizeof(vector_base_t));
        if (data == NULL) {
            if (capacity <= SIZE_MAX / sizeof(vector_base_t)) {
                throwException("Allocation error: system can`t allocate %zu bytes of memory\n", capacity * sizeof(vector_base_t));
            } else {
                throwException("Allocation error: system can`t allocate %zu * %zu bytes of memory\n", capacity, sizeof(vector_base_t));
            }
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
        v->data = (vector_base_t *) realloc(v->data, newCapacity * sizeof(vector_base_t));
        if (v->data == NULL) {
            if (newCapacity <= SIZE_MAX / sizeof(vector_base_t)) {
                throwException("Allocation error: system can`t allocate %zu bytes of memory\n", newCapacity * sizeof(vector_base_t));
            } else {
                throwException("Allocation error: system can`t allocate %zu * %zu bytes of memory\n", newCapacity, sizeof(vector_base_t));
            }
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

bool isVectorEmpty(const vector *v) {
    return v->size == 0;
}

bool isVectorFull(const vector *v) {
    return v->size == v->capacity;
}

void vectorPushBack(vector *v, const vector_base_t el) {
    if (isVectorFull(v)) {
        reserveVector(v, v->capacity ? v->capacity * 2 : 1);
    }
    v->data[v->size] = el;
    v->size++;
}

void vectorPopBack(vector *v) {
    if (isVectorEmpty(v)) {
        throwException("Data access error: impossible to remove element from already empty vector\n");
    }
    v->size--;
}