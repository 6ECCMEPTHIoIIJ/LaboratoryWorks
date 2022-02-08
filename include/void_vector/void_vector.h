#ifndef VOID_VECTOR
#define VOID_VECTOR

#include <limits.h>
#include <stdbool.h>
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

/**
 * @brief   Check if vectorVoid object data field doesn`t contain any element
 *
 * @param v pointer to vectorVoid object
 * @return 'true' if vectorVoid object size field value is equal to zero value and 'false' otherwise
 */
bool isVectorVEmpty(const vectorVoid *v);

/**
 * @brief   Check if vectorVoid object data field is full of elements
 *
 * @param v pointer to vectorVoid object
 * @return  'true' if vectorVoid object size field value is equal to vectorVoid object capacity field value and 'false'
 * otherwise
 */
bool isVectorVFull(const vectorVoid *v);

/**
 * @brief     Get value of vectorVoid object data field element staying on given position
 *            and save its value into given addres
 *
 * @param v   pointer to the vectorValue object
 * @param i   position of sought element
 * @param dst addres here to write sought element value
 */
void getVectorVValue(const vectorVoid *v, size_t i, void *dst);

/**
 * @brief     Set value of the vectorVoid object data field element staying on given position
 *            to the value located in given addres
 *
 * @param v   pointer to the vectorValue object
 * @param i   position of sought element
 * @param src addres where setted value is located
 */
void setVectorVValue(vectorVoid *v, size_t i, const void *src);

/**
 * @brief     Remove last element of vectorVoid object data field and
 *            decrease vectorVoid object size field by one;
 *            Throw an exception "Data access error" if vectorVoid object size field value is equal to zero value
 *
 * @param v   pointer to the vectorValue object
 */
void vectorVPopBack(vectorVoid *v);

/**
 * @brief     Append given value to the end of vectorVoid object data field,
 *            increase vectorVoid object size field value by one;
 *            if vectorVoid object size field value is equal to vectorVoid object capacity field value
 *            increase vectorVoid object capacity field value and reallocate memory area for vectorVoid object data field
 *            to make possible adding given element to vectorVoid object data field
 *
 * @param v   pointer to the vectorValue object
 * @param src addres where setted value is located
 */
void vectorVPushBack(vectorVoid *v, const void *src);

#endif // !VOID_VECTOR
