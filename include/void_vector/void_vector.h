#ifndef VOID_VECTOR
#define VOID_VECTOR

#include <limits.h>
#include <stdio.h>

typedef struct vectorVoid {
  void *data;          // Array of elements that vectorVoid object contains
  size_t size;         // Amount of elements that vectorVoid object contains at current moment
  size_t capacity;     // Memoty in bytes * baseTypeSize reserved for data field
  size_t baseTypeSize; // Memory in bytes that one element takes
} vectorVoid;

/**
 *@brief           			Create a vectorVoid object with capacity and baseTypeSize fields setted to given values
 *                  		and size field setted to zero value.
 *                  		Throw an exception "Allocation error" if system can`t allocate memory for vectorVoid object data field.
 * 											Throw an exception "Type error" if given value for baseTypeSize field is equal to zero
 *
 * @param capacity 			vectorVoid object capacity field value that is equal to amount of elements that vectorVoid object data field can contain
 * @param baseTypeSize 	Memory in bytes that one element of vectorVoid object data field takes
 * @return 							vectorVoid object
 */
vectorVoid createVectorV(size_t capacity, size_t baseTypeSize);

/**
 * @brief 							Reallocate memory area for vectorVoid object data field,
 *                      set vectorVoid object capacity field value to given value anyway and
 *                      set vectorVoid object size field value to given value
 *                      if given value is less than vectorVoid object size field value and
 *                      keep vectorVoid object size field value otherwise. If given newCapacity value is 
 * 											equal to zero, functions works as destroyVectorV(vectorVoid *v) function
 *                      Throw an exception "Allocation error" if system can`t allocate memory for vectorVoid object data
 *                      field
 *
 * @param v 						pointer to a vectorVoid object
 * @param newCapacity 	new vectorVoid object capacity field value
 */
void reserveVectorV(vectorVoid *v, size_t newCapacity);

/**
 * @brief 	Free all memory reserved for vectorVoid object data field and its value
 * 					to NULL, set values of all other vectorVoid object fields to zero
 * 
 * @param v pointer to a vectorVoid object
 */
void destroyVectorV(vectorVoid *v);

/**
 * @brief 	Delete all elements that vectorVoid object contains but don`t free memory reserved for vectorVoid object data field;
 *          set vectorVoid object size field value to zero value
 * 
 * @param v pointer to a vectorVoid object
 */
void clearVectorV(vectorVoid *v);

/**
 * @brief   Set vectorVoid object capacity field value to vectorVoid object size field value and
 *          reallocate memory area for vectorVoid object data field. If vectorVoid object capacity field value 
 * 					equal to zero, functions works as destroyVectorV(vectorVoid *v) function
 *          Throw an exception "Allocation error" if system can`t allocate memory for vectorVoid object data field
 *
 * @param v pointer to a vectorVoid object
 */
void shrinkVectorVToFit(vectorVoid *v);

#endif // !VOID_VECTOR
