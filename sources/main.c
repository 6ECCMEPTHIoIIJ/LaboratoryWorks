#include "../include/matrix.h"
#include <assert.h>
#include <malloc.h>
#include <minmax.h>

//	#define TEST_MATRIX
//	#define TASK_1
// 	#define TASK_2
//	#define TASK_3
// 	#define TASK_4
//	#define TASK_5
//	#define TASK_6
//	#define TASK_7
//  #define TASK_8
//	#define TASK_9
//	#define TASK_10
//	#define TASK_11
#define TASK_12

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

static void test_SwapRowsWithMinMaxEls_DiffRows() {
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

static void test_SwapRowsWithMinMaxEls_OneRow() {
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
	test_SwapRowsWithMinMaxEls_DiffRows();
	test_SwapRowsWithMinMaxEls_OneRow();
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

//	Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно
//	обратными
#ifdef TASK_6

/**
 * @brief Проверка, являются ли матрицы взаимообратными
 * @param m_1	первая матрица
 * @param m_2	вторая матрица
 * @return	'true', если матрицы взаимообратные,
 * 					'false' в противном случае
 */
bool IsMutuallyInverseMatrices(const Matrix m_1,
															 const Matrix m_2) {
	if (!(IsSquareMatrix(m_1) &&
				(m_1.n_rows == m_2.n_rows &&
				 m_1.n_cols == m_2.n_cols))) {
		return false;
	}

	Matrix e = MulMatrices(m_1, m_2);

	if (IsEMatrix(e)) {
		FreeMemMatrix(&e);
		return true;
	} else {
		return false;
	}
}

static void test_IsMutuallyInverseMatrices_True() {
	printf("[--------] True\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr_1[] = {1, 0, 0,
												 0, 1, 0,
												 0, 0, 1};
	int initial_arr_2[] = {1, 0, 0,
												 0, 1, 0,
												 0, 0, 1};
	Matrix m_1 = CreateMatrixFromArray(initial_arr_1, kInitialNRows,
																		 kInitialNCols);
	Matrix m_2 = CreateMatrixFromArray(initial_arr_2, kInitialNRows,
																		 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(IsMutuallyInverseMatrices(m_1, m_2));

	FreeMemMatrix(&m_1);
	FreeMemMatrix(&m_2);
	printf("[      OK]\n");
}

static void test_IsMutuallyInverseMatrices_False() {
	printf("[--------] False\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr_1[] = {1, 0, 0,
												 0, 1, 0,
												 0, 0, 1};
	int initial_arr_2[] = {2, 0, 0,
												 0, 2, 0,
												 0, 0, 2};
	Matrix m_1 = CreateMatrixFromArray(initial_arr_1, kInitialNRows,
																		 kInitialNCols);
	Matrix m_2 = CreateMatrixFromArray(initial_arr_2, kInitialNRows,
																		 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsMutuallyInverseMatrices(m_1, m_2));

	FreeMemMatrix(&m_1);
	FreeMemMatrix(&m_2);
	printf("[      OK]\n");
}

static void test_IsMutuallyInverseMatrices_DiffSizes() {
	printf("[--------] DiffSizes\n");
	const size_t kInitialNRows1 = 3;
	const size_t kInitialNCols1 = 3;
	const size_t kInitialNRows2 = 4;
	const size_t kInitialNCols2 = 3;
	int initial_arr_1[] = {1, 0, 0,
												 0, 1, 0,
												 0, 0, 1};
	int initial_arr_2[] = {2, 0, 0,
												 0, 2, 0,
												 0, 0, 2,
												 0, 0, 0};
	Matrix m_1 = CreateMatrixFromArray(initial_arr_1, kInitialNRows1,
																		 kInitialNCols1);
	Matrix m_2 = CreateMatrixFromArray(initial_arr_2, kInitialNRows2,
																		 kInitialNCols2);
	printf("[--------] n_rows_1 = %zu, n_cols_1 = %zu,"
				 "n_rows_2 = %zu, n_cols_2 = %zu\n",
				 kInitialNRows1,
				 kInitialNCols1,
				 kInitialNRows2,
				 kInitialNCols2);
	printf("[RUN     ]\n");
	assert(!IsMutuallyInverseMatrices(m_1, m_2));

	FreeMemMatrix(&m_1);
	FreeMemMatrix(&m_2);
	printf("[      OK]\n");
}

static void test_IsMutuallyInverseMatrices() {
	printf("[========] %s()\n", __FUNCTION__);
	test_IsMutuallyInverseMatrices_DiffSizes();
	test_IsMutuallyInverseMatrices_False();
	test_IsMutuallyInverseMatrices_True();
}

int main() {
	test_IsMutuallyInverseMatrices();

	return 0;
}

#endif // TASK_6

//	Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов
//	этой матрицы, лежащих на прямой, параллельной прямой, содержащей элементы
//	𝑎[𝑖,𝑖]. Найти сумму максимальных элементов всех псевдодиагоналей данной
//	матрицы. На рисунке ниже все псевдодиагонали выделены различными
//	цветами:
#ifdef TASK_7

/**
 * @brief Поиск максимального элемента диагонали матрицы
 * @param m 		матрица
 * @param row_i индекс строки начального элемента диагонали
 * @param col_i индекс столбца начального элемента диагонали
 * @return значение максимального элемента диагонали
 */
int FindMaxOnDiagonal(const Matrix m,
											size_t row_i,
											size_t col_i) {
	int max = m.data[row_i][col_i];
	while (col_i < m.n_cols && row_i < m.n_rows) {
		if (m.data[row_i][col_i] > max) {
			max = m.data[row_i][col_i];
		}
		row_i++;
		col_i++;
	}

	return max;
}

/**
 * @brief Вычисление суммы максимальных элементов всех псевдо-диагоналей матрицы
 * @param m матрица
 * @return сумма максимальных элементов всех псевдо-диагоналей матрицы
 */
long long FindSumOfMaxesOfPseudoDiagonal(const Matrix m) {
	long long sum = 0;
	for (size_t row_shift = m.n_rows - 1; row_shift > 0; row_shift--) {
		sum += FindMaxOnDiagonal(m, row_shift, 0);
	}

	for (size_t col_shift = 1; col_shift < m.n_cols; col_shift++) {
		sum += FindMaxOnDiagonal(m, 0, col_shift);
	}

	return sum;
}

static void test_FindSumOfMaxesOfPseudoDiagonal_Square() {
	printf("[--------] Square\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {1, 2, 3,
											 4, 5, 6,
											 7, 8, 9};
	const int kExpected = 24;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(FindSumOfMaxesOfPseudoDiagonal(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_FindSumOfMaxesOfPseudoDiagonal_Wide() {
	printf("[--------] Wide\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {3, 2, 5, 4,
											 1, 3, 6, 3,
											 3, 2, 1, 2};
	const int kExpected = 20;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(FindSumOfMaxesOfPseudoDiagonal(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_FindSumOfMaxesOfPseudoDiagonal_Toll() {
	printf("[--------] Toll\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 3;
	int initial_arr[] = {3, 2, 5,
											 4, 1, 3,
											 6, 3, 3,
											 2, 1, 2};
	const int kExpected = 20;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(FindSumOfMaxesOfPseudoDiagonal(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_sortRowsByMaxElement() {
	printf("[========] %s()\n", __FUNCTION__);
	test_FindSumOfMaxesOfPseudoDiagonal_Square();
	test_FindSumOfMaxesOfPseudoDiagonal_Wide();
	test_FindSumOfMaxesOfPseudoDiagonal_Toll();
}

int main() {
	test_sortRowsByMaxElement();

	return 0;
}

#endif // TASK_7

//	Дана прямоугольная матрица, все элементы которой различны. Найти минимальный
//	элемент матрицы в выделенной области:
#ifdef TASK_8

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
 * @brief Поиск минимального элемента, лежащего в треугольной области над
 * 				максимальным элементом
 * @param m матрица
 * @return 	значение минимального элемента, лежащего в треугольной области над
 * 					максимальным элементом
 */
int GetMinInMaxArea(const Matrix m) {
	Position max_p = GetMaxValuePos(m);
	int min = m.data[max_p.row_i][max_p.col_i];
	for (size_t row_i = max_p.row_i; row_i != -1; row_i--) {
		const size_t col_shift = max_p.row_i - row_i;
		const size_t begin_col_i = max(0, max_p.col_i - col_shift);
		const size_t end_col_i = min(m.n_cols - 1, max_p.col_i + col_shift);
		min = GetMin(m.data[row_i] + begin_col_i, end_col_i - begin_col_i + 1);
	}

	return min;
}

static void test_GetMinInMaxArea_FullArea() {
	printf("[--------] FullArea\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {10, 7, 5, 6,
											 3, 11, 8, 9,
											 4, 1, 12, 2};
	const int kExpected = 5;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);

	printf("[--------] n_rows_1 = %zu, n_cols_1 = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(GetMinInMaxArea(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_GetMinInMaxArea_NotFullArea() {
	printf("[--------] NotFullArea\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {6, 8, 9, 2,
											 7, 12, 3, 4,
											 10, 11, 5, 1};
	const int kExpected = 6;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);

	printf("[--------] n_rows_1 = %zu, n_cols_1 = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(GetMinInMaxArea(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_GetMinInMaxArea_OneEl() {
	printf("[--------] NotFullArea\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {6, 69, 9, 2,
											 7, 12, 3, 4,
											 10, 11, 5, 1};
	const int kExpected = 69;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);

	printf("[--------] n_rows_1 = %zu, n_cols_1 = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(GetMinInMaxArea(m) == kExpected);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_GetMinInMaxArea() {
	printf("[========] %s()\n", __FUNCTION__);
	test_GetMinInMaxArea_NotFullArea();
	test_GetMinInMaxArea_OneEl();
	test_GetMinInMaxArea_OneEl();
}

int main() {
	test_GetMinInMaxArea();

	return 0;
}

#endif // TASK_8

//	Дано 𝑛 точек в 𝑚-мерном пространстве. Упорядочить точки по неубыванию их
//	расстояний до начала координат.
#ifdef TASK_9

#include <math.h>

/**
 * @brief Вычисление суммы квадратов элементов массива
 * @param arr 	указатель на нулевой элемент массива
 * @param size 	кол-во элементов массива
 * @return сумму квадратов элементов массива
 */
long long GetSumOfSquares(int* arr,
													const size_t size) {
	long long sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += arr[i] * arr[i];
	}

	return sum;
}

/**
 * @brief Вычисление расстояния от точки, заданной в n-мерном пространстве,
 * 				до начала координат
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return 	расстояние от точки, заданной в n-мерном пространстве,
 * 					до начала координат
 */
double GetDistance(int* arr,
									 const size_t size) {
	return sqrt(GetSumOfSquares(arr, size));
}

/**
 * @brief Сортировка массива точек, заданного с помощью матрицы в порядке
 * 				неубывания расстояния от начала координат
 * @param m матрица
 */
void SortByDistance(Matrix m) {
	InsertionSortRowsMatrixByRowCriteriaF(m, GetDistance);
}

static void test_SortByDistance_Sorted() {
	printf("[--------] Sorted\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 0, 0,
											 2, 3, 1, 1,
											 5, 5, 5, 5,
											 0, 100, 0, 0,
											 99, 99, 99, 99};
	int expected_arr[] = {1, 0, 0, 0,
												2, 3, 1, 1,
												5, 5, 5, 5,
												0, 100, 0, 0,
												99, 99, 99, 99};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SortByDistance(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SortByDistance_Unsorted() {
	printf("[--------] Unsorted\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {20, 21, 22, 23,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 1, 2, 3, 4,
											 15, 16, 17, 19};
	int expected_arr[] = {1, 2, 3, 4,
												6, 7, 8, 9,
												10, 11, 12, 13,
												15, 16, 17, 19,
												20, 21, 22, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SortByDistance(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SortByDistance_OneEl() {
	printf("[--------] OneEl\n");
	const size_t kInitialNRows = 1;
	const size_t kInitialNCols = 1;
	int initial_arr[] = {34, 723, 132};
	int expected_arr[] = {34, 723, 132};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);

	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SortByDistance(m);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SortByDistance() {
	printf("[========] %s()\n", __FUNCTION__);
	test_SortByDistance_Unsorted();
	test_SortByDistance_Sorted();
	test_SortByDistance_OneEl();
}

int main() {
	test_SortByDistance();

	return 0;
}

#endif // TASK_9

//  Определить количество классов эквивалентных строк данной прямоугольной
//	матрицы. Строки считать эквивалентными, если равны суммы их элементов.
#ifdef TASK_10

#include <stdlib.h>

#define cmp(a, b)                                                            \
((a) > (b) ? -1 : ((a) < (b) ? 1 : 0))

/**
 * @brief Вычисление суммы элементов массива
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов в массиве
 * @return	сумму элементов массива
 */
int GetSum(int* arr,
					 const size_t size) {
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

/**
 * @brief компаратор целочисленный переменных типа long long
 * @param pa	указатель на первую переменную
 * @param pb	указатель на вторую переменную
 * @return	-1, если числа упорядочены по убыванию,
 * 					1, если по возрастанию,
 * 					0, если числа равны
 */
int cmp_long_long(const void* pa,
									const void* pb) {
	return cmp(*(long long*) pa, *(long long*) pb);
}

/**
 * @brief Сортировка массива и подсчет кол-ва групп различных элементов
 * 				массива
 * @param arr 	указатель на нулевой элемент массива
 * @param size 	кол-во элементов массива
 * @return	кол-во групп неуникальных элементов
 */
size_t CountNUnique(long long* arr,
										const size_t size) {
	if (size == 0) {
		return 0;
	}

	qsort(arr, size, sizeof(*arr), cmp_long_long);
	size_t n_unique_count = 1;
	for (size_t i = 0; i < size - 1; i++) {
		n_unique_count += arr[i] != arr[i + 1];
	}

	return n_unique_count;
}

/**
 * @brief Подсчет кол-ва классов эквивалентных по сумме строк
 * @param m матрица
 * @return кол-во классов эквивалентных по сумме строк
 */
size_t CountEqClassesByRowsSum(const Matrix m) {
	long long* rows_sums = (long long*) malloc(m.n_cols * sizeof(*rows_sums));
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		rows_sums[row_i] = GetSum(m.data[row_i], m.n_cols);
	}

	const size_t n_unique_count = CountNUnique(rows_sums, m.n_rows);
	free(rows_sums);

	return n_unique_count;
}

static void test_CountEqClassesByRowsSum_OneClass() {
	printf("[--------] OneClass\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 2;
	int initial_arr[] = {1, 9,
											 10, 0,
											 2, 8,
											 4, 6,
											 3, 7};
	const size_t kEqClassesCount = 1;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(CountEqClassesByRowsSum(m) == kEqClassesCount);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_CountEqClassesByRowsSum_ManyClasses() {
	printf("[--------] ManyClasses\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 2;
	int initial_arr[] = {7, 1,
											 2, 7,
											 5, 4,
											 4, 3,
											 1, 6,
											 8, 0};
	const size_t kEqClassesCount = 3;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(CountEqClassesByRowsSum(m) == kEqClassesCount);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_CountEqClassesByRowsSum() {
	printf("[========] %s()\n", __FUNCTION__);
	test_CountEqClassesByRowsSum_OneClass();
	test_CountEqClassesByRowsSum_ManyClasses();
}

int main() {
	test_CountEqClassesByRowsSum();

	return 0;
}

#endif // TASK_10

// Дана матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая
//	элемент "особым", если он больше суммы остальных элементов своего столбца
#ifdef TASK_11

/**
 * @brief Подсчет кол-ва элементов матрицы, больших суммы остальных элементов
 * 				своего столбца
 * @param m матрица
 * @return 	кол-во элементов матрицы, больших суммы остальных элементов
 * 					своего столбца
 */
size_t GetNSpecialEl(const Matrix m) {
	size_t special_el_count = 0;
	for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
		long long cur_sum = 0;
		int cur_max = m.data[0][col_i];
		for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
			cur_sum += m.data[row_i][col_i];
			if (m.data[row_i][col_i] > cur_max) {
				cur_max = m.data[row_i][col_i];
			}
		}
		special_el_count += cur_max > cur_sum - cur_max;
	}

	return special_el_count;
}

static void test_GetNSpecialEl_SomeEl() {
	printf("[--------] SomeEl\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {3, 5, 5, 4,
											 2, 3, 6, 7,
											 12, 2, 1, 2};
	const size_t kSpecialCount = 2;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(GetNSpecialEl(m) == kSpecialCount);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_GetNSpecialEl_None() {
	printf("[--------] None\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {3, 5, 5, 4,
											 2, 3, 6, 6,
											 5, 2, 1, 2};
	const size_t kSpecialCount = 0;
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(GetNSpecialEl(m) == kSpecialCount);

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_CountEqClassesByRowsSum() {
	printf("[========] %s()\n", __FUNCTION__);
	test_GetNSpecialEl_SomeEl();
	test_GetNSpecialEl_None();
}

int main() {
	test_CountEqClassesByRowsSum();

	return 0;
}

#endif // TASK_11

#ifdef TASK_12

/**
 * @brief Поиск позиции самого левого минимального элемента матрицы
 * @param m матрица
 * @return позицию самого левого минимального элемента матрицы
 */
Position GetLeftMin(const Matrix m) {
	int min = m.data[0][0];
	size_t min_row_i = 0;
	size_t min_col_i = 0;
	for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
		for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
			if (m.data[row_i][col_i] < min) {
				min = m.data[row_i][col_i];
				min_row_i = row_i;
				min_col_i = col_i;
			}
		}
	}

	return (Position) {min_row_i, min_col_i};
}

/**
 * @brief Замена заданной строки квадратной матрицы на столбец, содержащий
 * 				самый левый минимальный элемент
 * @param m						матрица
 * @param swap_row_i	индекс строки
 */
void SwapPenultimateRow(Matrix m,
												const size_t swap_row_i) {
	const Position l_min_col_p = GetLeftMin(m);
	const int t = m.data[swap_row_i][l_min_col_p.col_i];
	for (size_t col_i = 0, row_i = 0; col_i < m.n_cols; col_i++, row_i++) {
		if (row_i == swap_row_i) {
			m.data[swap_row_i][col_i] = t;
		} else {
			m.data[swap_row_i][col_i] = m.data[row_i][l_min_col_p.col_i];
		}
	}
}

static void test_SwapPenultimateRow_First() {
	printf("[--------] First\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	const size_t kInitialSwapRowI = 1;
	int initial_arr[] = {1, 2, 3,
											 4, 5, 6,
											 7, 8, 1};
	int expected_arr[] = {1, 2, 3,
												1, 4, 7,
												7, 8, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SwapPenultimateRow(m, kInitialSwapRowI);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SwapPenultimateRow_NotFirst() {
	printf("[--------] NotFirst\n");
	const size_t kInitialNRows = 3;
	const size_t kInitialNCols = 3;
	const size_t kInitialSwapColI = 1;
	int initial_arr[] = {1, 2, -3,
											 4, 5, 6,
											 7, 8, 9};
	int expected_arr[] = {1, 2, -3,
												-3, 6, 9,
												7, 8, 9};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
																	 kInitialNCols);
	Matrix expected_m = CreateMatrixFromArray(expected_arr, kInitialNRows,
																						kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	SwapPenultimateRow(m, kInitialSwapColI);
	assert(AreTwoMatricesEqual(m, expected_m));

	FreeMemMatrix(&m);
	FreeMemMatrix(&expected_m);
	printf("[      OK]\n");
}

static void test_SwapPenultimateRow() {
	printf("[========] %s()\n", __FUNCTION__);
	test_SwapPenultimateRow_First();
	test_SwapPenultimateRow_NotFirst();
}

int main() {
	test_SwapPenultimateRow();

	return 0;
}

#endif // TASK_12
