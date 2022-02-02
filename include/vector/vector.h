#ifndef VECTOR
#define VECTOR

#include <stdio.h>
#include <stdbool.h>

typedef int vector_base_t;  // Base type of vector object data field

// Dynamic array
typedef struct vector {
    vector_base_t *data;    // Array of elements that vector object contains
    size_t size;            // Amount of elements that vector object contains at current moment
    size_t capacity;        // Memoty in bytes * sizeof(vector_base_t) reserved for data field
} vector;

/**
 * @brief           Create a vector object with vector object capacity field setted to given value
 *                  and vector object size field setted to zero value.
 *                  Throw an exception "Allocation error" if system can`t allocate memory for vector object data field
 *
 * @param capacity  vector object capacity field value that is equal to amount of elements that vector object data field can contain
 * @return          vector
 */
vector createVector(size_t capacity);

/**
 * @brief               Reallocate memory area for vector object data field,
 *                      set vector object capacity field value to given value anyway and
 *                      set vector object size field value to given value
 *                      if given value is less than vector object size field value and
 *                      keep vector object size field value
 *                      if given value is more than vector object size field value or equal to it.
 *                      Throw an exception "Allocation error" if system can`t allocate memory for vector object data field
 *
 *
 * @param v             pointer to a vector object
 * @param newCapacity   new vector object capacity field value
 */
void reserveVector(vector *v, size_t newCapacity);

/**
 * @brief   Free all memory reserved for vector object data field and
 *          set object capacity field value and vector object size field value to zero value
 *
 * @param v pointer to a vector object
 */
void destroyVector(vector *v);

/**
 * @brief   Delete all elements that vector object contains but don`t free memory reserved for vector object data field;
 *          set vector object size field value to zero value
 *
 * @param v pointer to a vector object
 */
void clearVector(vector *v);

/**
 * @brief   Set vector object capacity field value to vector object size field value and
 *          reallocate memory area for vector object data field.
 *          Throw an exception "Allocation error" if system can`t allocate memory for vector object data field
 *
 * @param v pointer to a vector object
 */
void shrinkVectorToFit(vector *v);

#endif // !VECTOR