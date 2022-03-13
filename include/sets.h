#ifndef INC_LR_1_1_SETS_H
#define INC_LR_1_1_SETS_H

#include <stdio.h>
#include <stdbool.h>

// Максимальный размер множества
#define MAX_SET_SIZE 10
// Вычисляет кол-во элементов массива ARR
#define ARRAY_SIZE(ARR) (sizeof(ARR) / sizeof(*ARR))
/* Создает множество типа Set из элементов массива ARR,
 * не производит копирования элементов массива, последующее изменение поля
 * data структуры Set приведет к изменению исходного массива ARR
 */
#define SET(ARR) ((Set) {(ARR), ARRAY_SIZE(ARR)})
/* Создает множество типа Bitset из элементов массива ARR,
 * не производит копирования элементов массива, последующее изменение поля
 * data структуры Bitset приведет к изменению исходного массива ARR
 */
#define BITSET(ARR) ((Bitset) {(ARR), ARRAY_SIZE(ARR)})

/*
 * Множество на упорядоченном или не упорядоченном массиве
 * data - указатель на нулевой элемент массива множества
 * size - кол-во элементов в множестве
 */
typedef struct Set {
  int* data;
  size_t size;
} Set;

/*
 * Множество на массиве типа bool
 * data - указатель на нулевой элемент массива множества. Значение 1 в i-й
 * ячейке массива соответствует наличию элемента i+1 в множестве, 0 - его
 * отсутствию
 * size - максимальный элемент, содержащийся в множестве
 */
typedef struct Bitset {
  bool* data;
  size_t size;
} Bitset;

/*
 * Выводит элементы множества set в поток out
 */
void fprintset(FILE* out,
               Set set);

/*
 * Выводит элементы множества set в поток out
 */
void fprintbitset(FILE* out,
                  Bitset set);

/*
 * Сохраняет результат объединения множеств на не упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void unionU(Set set_1,
            Set set_2,
            Set* out_set);

/*
 * Сохраняет результат объединения множеств на упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void unionO(Set set_1,
            Set set_2,
            Set* out_set);

/*
 * Сохраняет результат объединения множеств на массивах типа bool
 * set_1 и set_2 в множестве out_set
 */
void unionBitset(Bitset set_1,
                 Bitset set_2,
                 Bitset* out_set);

/*
 * Сохраняет результат пересечения множеств на не упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void intersectionU(Set set_1,
                   Set set_2,
                   Set* out_set);

/*
 * Сохраняет результат пересечения множеств на упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void intersectionO(Set set_1,
                   Set set_2,
                   Set* out_set);

/*
 * Сохраняет результат пересечения множеств на массивах типа bool
 * set_1 и set_2 в множестве out_set
 */
void intersectionBitset(Bitset set_1,
                        Bitset set_2,
                        Bitset* out_set);

/*
 * Сохраняет результат разности множеств на не упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void differenceU(Set set_1,
                 Set set_2,
                 Set* out_set);

/*
 * Сохраняет результат разности множеств на упорядоченных массивах
 * set_1 и set_2 в множестве out_set
 */
void differenceO(Set set_1,
                 Set set_2,
                 Set* out_set);

/*
 * Сохраняет результат разности множеств на массивах типа bool
 * set_1 и set_2 в множестве out_set
 */
void differenceBitset(Bitset set_1,
                      Bitset set_2,
                      Bitset* out_set);

/*
 * Сохраняет результат симметрической разности множеств на не упорядоченных
 * массивах set_1 и set_2 в множестве out_set
 */
void xorU(Set set_1,
          Set set_2,
          Set* out_set);

/*
 * Сохраняет результат симметрической разности множеств на упорядоченных
 * массивах set_1 и set_2 в множестве out_set
 */
void xorO(Set set_1,
          Set set_2,
          Set* out_set);

/*
 * Сохраняет результат симметрической разности множеств на массивах типа bool
 * set_1 и set_2 в множестве out_set
 */
void xorBitset(Bitset set_1,
               Bitset set_2,
               Bitset* out_set);

/*
 * Возвращает true, если set_1 является подмножеством set_2, и false в
 * противном случе
 */
bool isSubU(Set set_1,
            Set set_2);

/*
 * Возвращает true, если set_1 является подмножеством set_2, и false в
 * противном случе
 */
bool isSubO(Set set_1,
            Set set_2);

/*
 * Возвращает true, если set_1 является подмножеством set_2, и false в
 * противном случе
 */
bool isSubBitset(Bitset set_1,
                 Bitset set_2);

/*
 * Возвращает true, если множества set_1 и set_2 равны, и false в
 * противном случе
 */
bool areEqualU(Set set_1,
               Set set_2);

/*
 * Возвращает true, если множества set_1 и set_2 равны, и false в
 * противном случе
 */
bool areEqualO(Set set_1,
               Set set_2);

/*
 * Возвращает true, если множества set_1 и set_2 равны, и false в
 * противном случе
 */
bool areEqualBitset(Bitset set_1,
                    Bitset set_2);

/*
 * Сохраняет результат дополнения множества на не упорядоченном массиве
 * set до универсума universe в множестве out_set
 */
void addToUniverseU(Set universe,
                    Set set,
                    Set* out_set);

/*
 * Сохраняет результат дополнения множества на упорядоченном массиве
 * set до универсума universe в множестве out_set
 */
void addToUniverseO(Set universe,
                    Set set,
                    Set* out_set);

/*
 * Сохраняет результат дополнения множества на массиве типа bool
 * set до универсума universe в множестве out_set
 */
void addToUniverseBitset(Bitset universe,
                         Bitset set,
                         Bitset* out_set);

#endif // INC_LR_1_1_SETS_H
