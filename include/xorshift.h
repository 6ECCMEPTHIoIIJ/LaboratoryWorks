#ifndef FUNCTION_TESTING_LIB_XORSHIFT_H
#define FUNCTION_TESTING_LIB_XORSHIFT_H

#include <stdint.h>

typedef uint32_t XorshiftBase; // тип генерируемых чисел

/*
 * Текущее состояние ГПСЧ
 */
typedef struct XorshiftState {
  XorshiftBase _0, _1, _2, _3;
} XorshiftState;

/*
 * Возвращает сгенерированное псевдослучайное число в диапазоне [0 ...
 * UINT32_MAX]
 */
XorshiftBase xorshift();

/*
 * Устанавливает зерно ГПСЧ в значение seed
 */
void setXorshiftSeed(XorshiftState seed);

#endif // FUNCTION_TESTING_LIB_XORSHIFT_H

