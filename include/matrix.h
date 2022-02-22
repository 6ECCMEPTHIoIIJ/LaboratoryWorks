#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Matrix {
	int** data;
	size_t n_rows;
	size_t n_cols;
} Matrix;

typedef struct Position {
	size_t row_i;
	size_t col_i;
} Position;

/**
 * @brief Выделение памяти для размещения в ней элементов матрицы заданного
 * 				размера. Если одна из размерностей матрицы равна
 *				0	, поле data устанавливается в NULL.
 *			  Выбрасывает исключение: "Allocation error", если системе не удается
 * 			 	выделить память под элементы матрицы
 *
 * @param n_rows 	высота матрицы
 * @param n_cols 	ширина матрицы
 * @return пустую матрицу заданного размера
 */
Matrix GetMemMatrix(size_t n_rows,
										size_t n_cols);

/**
 * @brief Выделение памяти под массив матриц заданного размера.
 * 			  Выбрасывает исключение: "Allocation error", если системе не удается
 * 			 	выделить память под элементы матрицы
 *
 * @param n_matrices	количество матриц в массиве
 * @param n_rows 			высота каждой матрицы
 * @param n_cols 			ширина каждой матрицы
 * @return указатель на начало массива матриц
 */
Matrix* GetMemArrayOfMatrices(size_t n_matrices,
															size_t n_rows,
															size_t n_cols);

/**
 * @brief Освобождение памяти, выделенной под элементы матрицы.
 * 				Значения полей data, n_rows, n_cols
 * устанавливаются в NULL, 0, 0 соответственно
 *
 * @param m	указатель на матрицу
 */
void FreeMemMatrix(Matrix* m);

/**
 * @brief Освобождение памяти, выделенной под массив матриц.
 * 				Значения полей матриц data, n_rows, n_cols
 * устанавливаются в NULL, 0, 0 соответственно
 *
 * @param ms 					указатель на начало массива
 * @param n_matrices 	количество матриц в массиве
 */
void FreeMemMatrices(Matrix* ms,
										 size_t n_matrices);

/**
 * @brief Ввод элементов матрицы
 *
 * @param m матрица
 */
void InputMatrix(Matrix m);

/**
 * @brief Ввод массива матриц
 *
 * @param ms					указатель на начало массива
 * @param n_matrices	количество элементов в массиве
 */
void InputMatrices(Matrix* ms,
									 size_t n_matrices);

/**
 * @brief Вывод элементов матрицы в консоль
 *
 * @param m	матрица
 */
void OutputMatrix(Matrix m);

/**
 * @brief Вывод массива матриц в консоль
 *
 * @param ms 					указатель на начало массива
 * @param n_matrices 	количество матриц в массиве
 */
void OutputMatrices(Matrix* ms,
										size_t n_matrices);

/**
 * @brief Обмен значений двух строк матрицы
 *
 * @param m 	матрица
 * @param i_1 	индекс первой строки
 * @param i_2 	индекс второй строки
 */
void SwapRows(Matrix m,
							size_t i_1,
							size_t i_2);

/**
 * @brief Обмен значений двух столбцов матрицы
 *
 * @param m 	матрица
 * @param i_1 	индекс первого столбца
 * @param i_2 	индекс второго столбца
 */
void SwapCols(Matrix m,
							size_t i_1,
							size_t i_2);

/**
 * @brief Сортировка вставками строк матрицы по критерию
 *
 * @param m					матрица
 * @param criteria	критерий сортировки
 */
void InsertionSortRowsMatrixByRowCriteria(Matrix m,
																					int (* criteria)(int*,
																													 size_t));

/**
 * @brief Сортировка вставками столбцов матрицы по критерию
 *
 * @param m 				матрица
 * @param criteria 	критерий сортировки
 */
void InsertionSortColsMatrixByColCriteria(Matrix m,
																					int (* criteria)(int*,
																													 size_t));

/**
 * @brief Проверка, является ли данная матрица квадратной
 *
 * @param m матрица
 * @return 	'true', если матрица квадратная,
 * 					'false' в противном случае
 */
bool IsSquareMatrix(Matrix m);

/**
 * @brief Проверка на равенство двух матриц
 *
 * @param m_1	первая матрица
 * @param m_2	вторая матрица
 * @return 	'true', если матрицы равны,
 * 					'false' в противном случае
 */
bool AreTwoMatricesEqual(Matrix m_1,
												 Matrix m_2);

/**
 * @brief Проверка, является ли данная матрица единичной
 *
 * @param m матрица
 * @return 	'true', если матрица единичная,
 * 					'false' в противном случае
 */
bool IsEMatrix(Matrix m);


/**
 * @brief Проверка, является ли данная матрица симметричной
 *
 * @param m матрица
 * @return 	'true', если матрица симметричная,
 * 					'false' в противном случае
 */
bool IsSymmetricMatrix(Matrix m);

/**
 * @brief Транспонирование матрицы
 *
 * @param m указатель на мтарицу
 */
void TransposeMatrix(Matrix* m);

/**
 * @brief Получение позиции минимального значения матрицы
 *
 * @param m матрица
 * @return 	позицию первого минимального значения матрицы
 */
Position GetMinValuePos(Matrix m);

/**
 * @brief Получение позиции максимального значения матрицы
 *
 * @param m матрица
 * @return 	позицию первого максимального значения матрицы
 */
Position GetMaxValuePos(Matrix m);

/**
 * @brief Выделение памяти под массив матриц заданного размера и заполнение ее
 *			 	значениями элементов данного массива.
 *				Выбрасывает исключение: "Allocation error", если системе не удается
 * 				выделить память под элементы матрицы
 *
 * @param arr			указатель на начало массива значений
 * @param n_rows	высота матрицы
 * @param n_cols	ширина матрицы
 * @return 	матрицу заданного размера с заполненными элементами
 */
Matrix CreateMatrixFromArray(int* arr,
														 size_t n_rows,
														 size_t n_cols);

/**
 * @brief Выделение памяти под массив матриц заданного размера и заполнение их
 * 				значениями элементов данного массива.
 *  			Выбрасывает исключение: "Allocation error", если системе не удается
 * 				выделить память под элементы матрицы
 *
 * @param arr					указатель на начало массива
 *значений
 * @param n_matrices	количество матриц в массиве матриц
 * @param n_rows			высота каждой матрицы
 * @param n_cols			ширина каждой матрицы
 * @return указатель на начало массива матриц
 */
Matrix* CreateArrayOfMatrixFromArray(int* arr,
																		 size_t n_matrices,
																		 size_t n_rows,
																		 size_t n_cols);

/**
 * @brief Вычисление произведения двух матриц
 * 				Выбрасывает исключение: "Matrix size error", если невозможно
 * 				вычислить произведение матриц из-за несоответствия
 * 				их размеров
 *
 * @param m_1 первая матрица
 * @param m_2 вторая матрица
 * @return результат произведения матриц
 */
Matrix MulMatrices(Matrix m_1,
									 Matrix m_2);

#endif  // MATRIX_H
