#include "../include/matrix.h"
#include <assert.h>

//	#define TASK_1
#define TASK_2

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
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNCols,
																						kInitialNRows);
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
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNCols,
																						kInitialNRows);
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
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNCols,
																						kInitialNRows);
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
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNCols,
																						kInitialNRows);
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
