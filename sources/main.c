#include "../include/matrix.h"
#include <assert.h>

//	#define TASK_1
// 	#define TASK_2
//	#define TASK_3
#define TASK_4

//	Тестирование основных функций библиотеки matrix.h
#ifdef TEST_MATRIX

#include "../include/matrix_tests.h"

int main() {
	test_matrix();

	return 0;
}

#endif // TEST_MATRIX

//	Дана квадратная матрица, все элементы которой различны. Поменять местами
//	строки, в которых находятся максимальный и минимальный элементы.
#ifdef TASK_1

/**
 * @brief Обмен строк матрицы, содержащих минимальный и максимальный элементы
 *
 * @param m матрица
 */
void SwapRowsWithMinMaxEls(Matrix m) {
	SwapRows(m, GetMinValuePos(m).row_i, GetMaxValuePos(m).row_i);
}

static void test_transposeMatrix_DiffRows() {
	printf("[--------] DiffRows\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 2, 3,
											 4, 5, 6,
											 7, 8, 9};
	int expected_arr[] = {7, 8, 9,
												4, 5, 6,
												1, 2, 3};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SwapRowsWithMinMaxEls(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_transposeMatrix_OneRow() {
	printf("[--------] OneRow\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 2, 3,
											 4, 5, 6,
											 -6, 8, 9};
	int expected_arr[] = {1, 2, 3,
												4, 5, 6,
												-6, 8, 9};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SwapRowsWithMinMaxEls(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SwapRowsWithMinMaxEls() {
	printf("[========] %s()\n", __FUNCTION__);
	test_transposeMatrix_DiffRows();
	test_transposeMatrix_OneRow();
}

int main() {
	test_SwapRowsWithMinMaxEls();

	return 0;
}

#endif // TASK_1

//	Упорядочить строки матрицы по неубыванию наибольших элементов строк:
#ifdef TASK_2

/**
 * @brief Поиск максимального значения элементов массива
 *
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return	максимальное значение элементов массива
 */
int GetMax(int* arr,
					 const size_t size) {
	int max = arr[0];
	for (size_t i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

/**
 * @brief Сортировка строк матрицы по неубыванию значений максимальных
 * 				элементов строк
 *
 * @param m матрица
 */
void sortRowsByMaxElement(Matrix m) {
	InsertionSortRowsMatrixByRowCriteria(m, GetMax);
}

static void test_sortRowsByMaxElement_Unsorted() {
	printf("[--------] Unsorted\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, -7, 9,
											 0, 128, 11,
											 -123, -1, -4};
	int expected_arr[] = {-123, -1, -4,
												1, -7, 9,
												0, 128, 11};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	sortRowsByMaxElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_sortRowsByMaxElement_Sorted() {
	printf("[--------] Sorted\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 2, 3,
											 4, 5, 6,
											 7, 8, 9};
	int expected_arr[] = {1, 2, 3,
												4, 5, 6,
												7, 8, 9};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	sortRowsByMaxElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_sortRowsByMaxElement() {
	printf("[========] %s()\n", __FUNCTION__);
	test_sortRowsByMaxElement_Unsorted();
	test_sortRowsByMaxElement_Sorted();
}

int main() {
	test_sortRowsByMaxElement();

	return 0;
}

#endif // TASK_2

//	Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
//	минимальных элементов столбцов:
#ifdef TASK_3

/**
 * @brief Поиск минимального значения элементов массива
 *
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return	минимальное значение элементов массива
 */
int GetMin(int* arr,
					 const size_t size) {
	int min = arr[0];
	for (size_t i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

/**
 * @brief Сортировка строк матрицы по неубыванию значений максимальных
 * 				элементов строк
 *
 * @param m матрица
 */
void sortColsByMinElement(Matrix m) {
	InsertionSortColsMatrixByColCriteria(m, GetMin);
}

static void test_sortColsByMinElement_Unsorted() {
	printf("[--------] Unsorted\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 6;
	int initial_arr[] = {3, 5, 2, 4, 3, 3,
											 2, 5, 1, 8, 2, 7,
											 6, 1, 4, 4, 8, 3};
	int expected_arr[] = {5, 2, 3, 3, 3, 4,
												5, 1, 2, 2, 7, 8,
												1, 4, 6, 8, 3, 4};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	sortColsByMinElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_sortColsByMinElement_Sorted() {
	printf("[--------] Sorted\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, -7, 9,
											 0, 128, 11,
											 -123, -1, -4};
	int expected_arr[] = {1, -7, 9,
												0, 128, 11,
												-123, -1, -4};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	sortColsByMinElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_sortRowsByMaxElement() {
	printf("[========] %s()\n", __FUNCTION__);
	test_sortColsByMinElement_Unsorted();
	test_sortColsByMinElement_Sorted();
}

int main() {
	test_sortRowsByMaxElement();

	return 0;
}

#endif // TASK_3

//	Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом (𝐴2)
#ifdef TASK_4

void getSquareOfMatrixIfSymmetric(Matrix* m) {
	if (IsSymmetricMatrix(*m)) {
		Matrix t = MulMatrices(*m, *m);
		FreeMemMatrix(m);
		*m = t;
	}
}

static void test_getSquareOfMatrixIfSymmetric_Square() {
	printf("[--------] Square\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 0, 0,
											 0, 2, 0,
											 0, 0, 13};
	int expected_arr[] = {1, 0, 0,
												0, 4, 0,
												0, 0, 169};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	getSquareOfMatrixIfSymmetric(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_getSquareOfMatrixIfSymmetric_NotSquare() {
	printf("[--------] NotSquare\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 0, 0,
											 0, 7, 0,
											 0, 0, 1,
											 9, 8, 7};
	int expected_arr[] = {1, 0, 0,
												0, 7, 0,
												0, 0, 1,
												9, 8, 7};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	getSquareOfMatrixIfSymmetric(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_transposeMatrix() {
	printf("[========] %s()\n", __FUNCTION__);
	test_getSquareOfMatrixIfSymmetric_Square();
	test_getSquareOfMatrixIfSymmetric_NotSquare();
}

int main() {
	test_transposeMatrix();

	return 0;
}

#endif // TASK_4
