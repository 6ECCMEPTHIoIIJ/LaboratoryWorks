#include "void_vector.h"

#include <malloc.h>
#include <windows.h>
#include <stdint.h>
#include <memory.h>

#define TYPE_ERR_CODE 1
#define ALLOCTION_ERR_CODE 1
#define DATA_ACCESS_ERR_CODE 2

#define throwException(EXIT_CODE, ...) \
  fprintf(stderr, __VA_ARGS__);        \
  exit(EXIT_CODE)

vectorVoid createVectorV(size_t capacity, const size_t baseTypeSize) {
	void *data;
	if (baseTypeSize == 0) {
		throwException(TYPE_ERR_CODE, 
									 "Type error: type size must be positive integer\n");
	}
	if (capacity != 0) {
		data = malloc(capacity * baseTypeSize);
		if (data == NULL) {
			if (capacity <= SIZE_MAX / baseTypeSize) {
        throwException(ALLOCTION_ERR_CODE,
                       "Allocation error: system can`t allocate %zu bytes of memory\n",
                       capacity * baseTypeSize);
      } else {
        throwException(ALLOCTION_ERR_CODE,
                       "Allocation error: system can`t allocate %zu * %zu bytes of memory\n",
                       capacity, baseTypeSize);
      }
		}
	} else {
		data = NULL;
	}

	return (vectorVoid) {data, 0, capacity, baseTypeSize};
}

void destroyVectorV(vectorVoid *v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
	v->baseTypeSize = 0;
}

void reserveVectorV(vectorVoid *v, const size_t newCapacity) {
	if (newCapacity != 0) {
		v->data = realloc(v->data, newCapacity * v->baseTypeSize);
		if (v->data == NULL) {
      if (newCapacity <= SIZE_MAX / v->baseTypeSize) {
        throwException(ALLOCTION_ERR_CODE,
                       "Allocation error: system can`t allocate %zu bytes of memory\n",
                       newCapacity * v->baseTypeSize);
      } else {
        throwException(ALLOCTION_ERR_CODE,
                       "Allocation error: system can`t allocate %zu * %zu bytes of memory\n",
                       newCapacity, v->baseTypeSize);
      }
    }
		v->capacity = newCapacity;
    if (v->size > newCapacity) {
      v->size = newCapacity;
    }
	} else {
		destroyVectorV(v);
	}
}

void clearVectorV(vectorVoid *v) {
	v->size = 0;
}

void shrinkVectorVToFit(vectorVoid *v) {
	reserveVectorV(v, v->size);
}

bool isVectorVEmpty(const vectorVoid *v) {
	return v->size == 0;
}

bool isVectorVFull(const vectorVoid *v) {
	return v->size == v->capacity;
}

void getVectorVValue(const vectorVoid *v, const size_t i, void *dst) {
	const void *src = v->data + i * v->baseTypeSize;
	memcpy(dst, src, v->baseTypeSize);
}

void setVectorVValue(vectorVoid *v, const size_t i, const void *src) {
	void *dst = v->data + i * v->baseTypeSize;
	memcpy(dst, src, v->baseTypeSize);
}

void vectorVPopBack(vectorVoid *v) {
	if (isVectorVEmpty(v)) {
    throwException(DATA_ACCESS_ERR_CODE,
                   "Data access error: impossible to remove element from already empty vectorVoid\n");
  }
	v->size--;
}

void vectorVPushBack(vectorVoid *v, const void *src) {
	if (isVectorVFull(v)) {
    reserveVectorV(v, v->capacity ? v->capacity * 2 : 1);
  }
	void *dst = v->data + v->size * v->baseTypeSize;
  memcpy(dst, src, v->baseTypeSize);
  v->size++;
}