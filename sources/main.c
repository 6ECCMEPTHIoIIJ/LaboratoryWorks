#include "../include/matrix.h"
#include <assert.h>
#include <malloc.h>

//	#define TASK_1
// 	#define TASK_2
//	#define TASK_3
// 	#define TASK_4
#define TASK_5

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
void SortColsByMinElement(Matrix m) {
	InsertionSortColsMatrixByColCriteria(m, GetMin);
}

static void test_SortColsByMinElement_Unsorted() {
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
	SortColsByMinElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SortColsByMinElement_Sorted() {
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
	SortColsByMinElement(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SortRowsByMaxElement() {
	printf("[========] %s()\n", __FUNCTION__);
	test_SortColsByMinElement_Unsorted();
	test_SortColsByMinElement_Sorted();
}

int main() {
	test_SortRowsByMaxElement();

	return 0;
}

#endif // TASK_3

//	Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом (𝐴2)
#ifdef TASK_4

/**
 * @brief Возведение в квадрат симметричной матрицы. Если матрица
 * 				несимметрична, то ее значение не меняется
 * @param m	указатель на матрицу
 */
void GetSquareOfMatrixIfSymmetric(Matrix* m) {
	if (IsSymmetricMatrix(*m)) {
		Matrix t = MulMatrices(*m, *m);
		FreeMemMatrix(m);
		*m = t;
	}
}

static void test_GetSquareOfMatrixIfSymmetric_Square() {
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
	GetSquareOfMatrixIfSymmetric(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_GetSquareOfMatrixIfSymmetric_NotSquare() {
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
	GetSquareOfMatrixIfSymmetric(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_GetSquareOfMatrixIfSymmetric() {
	printf("[========] %s()\n", __FUNCTION__);
	test_GetSquareOfMatrixIfSymmetric_Square();
	test_GetSquareOfMatrixIfSymmetric_NotSquare();
}

int main() {
	test_GetSquareOfMatrixIfSymmetric();

	return 0;
}

#endif // TASK_4

// 	Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных,
// 	то транспонировать матрицу.
#ifdef TASK_5

/**
 * @brief Вычисление суммы элементов массива
 *
 * @param arr 	указатель на первый элемент массива
 * @param size 	кол-во элементов массива
 * @return сумму элементов массива
 */
long long GetSum(int* arr,
								 const size_t size) {
	long long sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

/**
 * @brief Поиск индекса минимального элемента массива
 * @param arr 	указатель на нулевой элемент массива
 * @param size 	кол-во элементов массива
 * @param el 		искомое значение
 * @return индекс минимального элемента массива
 */
size_t Find(long long* arr,
						const size_t size,
						const long long el) {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == el) {
			return i;
		}
	}

	return size;
}

/**
 * @brief Проверка элементов массива на уникальность
 * @param arr 	указатель на первый элемент массива
 * @param size 	кол-во элементов массива
 * @return		'true', если элементы массива уникальны,
 * 						'false' в противном случае
 */
bool IsUnique(long long* arr,
							const size_t size) {
	for (size_t i = 0; i < size; i++) {
		const size_t pos = Find(arr, size, arr[i]);
		if (pos != i && pos != size) {
			return false;
		}
	}

	return true;
}

/**
 * @brief Транспонирование матрицы, не имеющей строк с одинаковой суммой
 * 				элементов. Если строки с одинаковой суммой имеются, то значение
 * 				матрицы не меняется
 * @param m указатель на матрицу
 */
void TransposeIfMatrixHasNotEqualSunOfRows(Matrix* m) {
	long long* row_sums = (long long*) malloc(m->n_rows * sizeof(*row_sums));
	for (size_t row_i = 0; row_i < m->n_rows; row_i++) {
		row_sums[row_i] = GetSum(m->data[row_i], m->n_cols);
	}

	if (IsUnique(row_sums, m->n_rows)) {
		TransposeMatrix(m);
	}
}

static void test_TransposeIfMatrixHasNotEqualSunOfRows_NotEqual() {
	printf("[--------] NotEqual\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 0, 0,
											 0, 7, 0,
											 0, 0, 2,
											 9, 8, 7};
	int expected_arr[] = {1, 0, 0, 9,
												0, 7, 0, 8,
												0, 0, 2, 7};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNCols,
																						kInitialNRows);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	TransposeIfMatrixHasNotEqualSunOfRows(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_TransposeIfMatrixHasNotEqualSunOfRows_HasEqual() {
	printf("[--------] HasEqual\n");
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
	TransposeIfMatrixHasNotEqualSunOfRows(&m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_TransposeIfMatrixHasNotEqualSunOfRows() {
	printf("[========] %s()\n", __FUNCTION__);
	test_TransposeIfMatrixHasNotEqualSunOfRows_HasEqual();
	test_TransposeIfMatrixHasNotEqualSunOfRows_NotEqual();
}

int main() {
	test_TransposeIfMatrixHasNotEqualSunOfRows();

	return 0;
}

#endif // TASK_5
