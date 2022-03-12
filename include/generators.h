#ifndef FUNCTION_TESTING_LIB_GENERATORS_H
#define FUNCTION_TESTING_LIB_GENERATORS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include "xorshift.h"

#define MAX_STR_LEN 255 // максимальное кол-во символов в строке

typedef int32_t GenBase; // базовый тип генерируемой последовательности

/*
 * Функция генерации последовательности
 * generate - указатель на функцию-генератор
 * name - имя генератора, используемое при выводе
 */
typedef struct GeneratingFunc {
  void (* generate)(GenBase* arr,  // указатель на ф-цию генерации
                    size_t n);        // последовательности
  char name[MAX_STR_LEN + 1];         // имя генератора
} GeneratingFunc;

/*
 * Генерирует массива arr заданной длины n, элементы которого
 * представляют собой неупорядоченную псевдослучайную последовательность
 */
void generateRandomArray(GenBase* arr,
                         size_t n);

/*
 * Функция генерации неупорядоченной псевдослучайной последовательности
 */
static GeneratingFunc _generateRandomArray = {generateRandomArray, "random"};

/*
 * Генерирует массива arr заданной длины n, элементы которого
 * представляют собой упорядоченную последовательность
 */
void generateOrderedArray(GenBase* arr,
                          size_t n);

/*
 * Функция генерации упорядоченной последовательности
 */
static GeneratingFunc _generateOrderedArray = {generateOrderedArray, "ordered"};

/*
 * Генерирует массива arr заданной длины n, элементы которого
 * представляют собой упорядоченную в обратном порядке последовательность
 */
void generateOrderedBackwardsArray(GenBase* arr,
                                   size_t n);

/*
 * Функция генерации упорядоченной в обратном порядке последовательности
 */
static GeneratingFunc _generateOrderedBackwardsArray =
    {generateOrderedBackwardsArray,
     "ordered backwards"};

#endif // FUNCTION_TESTING_LIB_GENERATORS_H
