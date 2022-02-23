#include "../include/matrix.h"
#include <assert.h>
#include <malloc.h>
#include <minmax.h>

//#define TEST_MATRIX
//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define TASK_5
//#define TASK_6
//#define TASK_7
//#define TASK_8
//#define TASK_9
//#define TASK_10
//#define TASK_11
//#define TASK_12
//#define TASK_13
//#define TASK_14
//#define TASK_15
//#define TASK_16
//#define TASK_17
#define TASK_18

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

static void test_FindSumOfMaxesOfPseudoDiagonal() {
  printf("[========] %s()\n", __FUNCTION__);
  test_FindSumOfMaxesOfPseudoDiagonal_Square();
  test_FindSumOfMaxesOfPseudoDiagonal_Wide();
  test_FindSumOfMaxesOfPseudoDiagonal_Toll();
}

int main() {
  test_FindSumOfMaxesOfPseudoDiagonal();

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

// 	Дана матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая
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

static void test_GetNSpecialEl() {
  printf("[========] %s()\n", __FUNCTION__);
  test_GetNSpecialEl_SomeEl();
  test_GetNSpecialEl_None();
}

int main() {
  test_GetNSpecialEl();

  return 0;
}

#endif // TASK_11

// 	Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым
//	из столбцов, в котором находится минимальный элемент матрицы.
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

// 	Дан массив матриц одного размера. Определить число матриц, строки которых
// 	упорядочены по неубыванию элементов
#ifdef TASK_13

/**
 * @brief Проверка, является ли массив неубывающей последовательностью
 *
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов в массиве
 * @return	'true', если массив упорядочен по неубыванию,
 * 					'false' в противном случае
 */
bool IsNonDecreasingSorted(int* arr,
                           const size_t size) {
  for (size_t i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }

  return true;
}

/**
 * @brief Проверка, что все строки матрицы упорядочены по неубыванию
 *
 * @param m	матрица
 * @return	'true', се строки матрицы упорядочены по неубыванию,
 * 					'false' в противном случае
 */
bool HasAllNonDecreasingRows(const Matrix m) {
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    if (!IsNonDecreasingSorted(m.data[row_i], m.n_cols)) {
      return false;
    }
  }

  return true;
}

/**
 * @brief Подсчет матриц, содержащих все строки, упорядоченные по неубыванию
 *
 * @param ms
 * @param n_matrices
 * @return
 */
size_t CountNonDescendingRowsMatrices(Matrix* ms,
                                      const size_t n_matrices) {
  size_t non_descending_row_ms_count = 0;
  for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
    non_descending_row_ms_count += HasAllNonDecreasingRows(ms[matrix_i]);
  }

  return non_descending_row_ms_count;
}

static void test_CountNonDescendingRowsMatrices() {
  printf("[========] %s()\n", __FUNCTION__);
  const size_t kInitialNMatrices = 4;
  const size_t kInitialNRows = 2;
  const size_t kInitialNCols = 2;
  int initial_arr[] = {7, 1,
                       1, 1,

                       1, 6,
                       2, 2,

                       5, 4,
                       2, 3,

                       1, 3,
                       7, 9};
  const size_t kExpected = 2;
  Matrix* ms = CreateArrayOfMatrixFromArray(initial_arr,
                                            kInitialNMatrices,
                                            kInitialNRows,
                                            kInitialNCols);

  printf("[--------] n_matrices = %zu,  n_rows = %zu, n_cols = %zu\n",
         kInitialNMatrices,
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(CountNonDescendingRowsMatrices(ms, kInitialNMatrices) == kExpected);

  FreeMemMatrices(ms, kInitialNMatrices);
  printf("[      OK]\n");
}

int main() {
  test_CountNonDescendingRowsMatrices();

  return 0;
}

#endif // TASK_13

//	Дан массив целочисленных матриц. Вывести матрицы, имеющие наибольшее
//	число нулевых строк
#ifdef TASK_14

/**
 * @brief Подсчет кол-ва вхождений искомого значения в массив
 * @param arr 	указатель на нулевой элемент массива
 * @param size 	кол-во элементов массива
 * @param val 	искомое значение
 * @return кол-во вхождений искомого значения в массив
 */
size_t CountValues(int* arr,
                   const size_t size,
                   const size_t val) {
  size_t val_count = 0;
  for (size_t i = 0; i < size; i++) {
    val_count += arr[i] == val;
  }

  return val_count;
}

/**
 * @brief Подсчет нулевых строк матрицы
 * @param m матрица
 * @return кол-во нулевых строк матрицы
 */
size_t CountZeroRows(const Matrix m) {
  size_t zero_rows_count = 0;
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    zero_rows_count += CountValues(m.data[row_i], m.n_cols, 0) == m.n_cols;
  }

  return zero_rows_count;
}

static void test_CountZeroRows_Zero() {
  printf("[--------] Zero\n");
  const size_t kInitialNRows = 5;
  const size_t kInitialNCols = 2;
  int initial_arr[] = {1, 0,
                       4, 6,
                       0, 7,
                       9, 8,
                       11, 0};
  const size_t kExpected = 0;
  Matrix m = CreateMatrixFromArray(initial_arr,
                                   kInitialNRows,
                                   kInitialNCols);

  printf("[--------] n_rows = %zu, n_cols = %zu\n",

         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(CountZeroRows(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_CountZeroRows_NotZero() {
  printf("[--------] Zero\n");
  const size_t kInitialNRows = 5;
  const size_t kInitialNCols = 2;
  int initial_arr[] = {0, 0,
                       4, 0,
                       0, 7,
                       9, 8,
                       0, 0};
  const size_t kExpected = 2;
  Matrix m = CreateMatrixFromArray(initial_arr,
                                   kInitialNRows,
                                   kInitialNCols);

  printf("[--------] n_rows = %zu, n_cols = %zu\n",

         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(CountZeroRows(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_CountZeroRows() {
  printf("[========] %s()\n", __FUNCTION__);
  test_CountZeroRows_NotZero();
  test_CountZeroRows_Zero();
}

/**
 * @brief Поиск максимального значения элементов массива
 *
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return	максимальное значение элементов массива
 */
size_t GetMax(size_t* arr,
              const size_t size) {
  size_t max = arr[0];
  for (size_t i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

void PrintMatrixWithMaxZeroRows(Matrix* ms,
                                const size_t n_matrices) {
  size_t* ms_zero_rows_counts = (size_t*) malloc(n_matrices *
                                                 sizeof(*ms_zero_rows_counts));
  for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
    ms_zero_rows_counts[matrix_i] = CountZeroRows(ms[matrix_i]);
  }
  size_t max_m_zero_rows = GetMax(ms_zero_rows_counts, n_matrices);
  for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
    if (ms_zero_rows_counts[matrix_i] == max_m_zero_rows) {
      OutputMatrix(ms[matrix_i]);
    }
  }
}

int main() {
  test_CountZeroRows();

  size_t n_matrices, n_rows, n_cols;
  scanf("%zu %zu %zu", &n_matrices, &n_rows, &n_cols);
  Matrix* ms = GetMemArrayOfMatrices(n_matrices, n_rows, n_cols);
  InputMatrices(ms, n_matrices);
  PrintMatrixWithMaxZeroRows(ms, n_matrices);

  return 0;
}

#endif // TASK_14

//  Дан массив вещественных квадратных матриц. Вывести матрицы с наименьшей
//	нормой. В качестве нормы матрицы взять максимум абсолютных величин ее
//	элементов
#ifdef TASK_15

/**
 * @brief Поиск максимального абсолютного значения элементов массива
 *
 * @param arr		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return	максимальное абсолютное значение элементов массива
 */
int GetMatrixAbsMax(const Matrix m) {
  int max = abs(m.data[0][0]);
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
      if (abs(m.data[row_i][col_i]) > max) {
        max = abs(m.data[row_i][col_i]);
      }
    }
  }

  return max;
}

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

void PrintMatrixWithMinNorms(Matrix* ms,
                             const size_t n_matrices) {
  int* ms_norms = (int*) malloc(n_matrices *
                                sizeof(*ms_norms));
  for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
    ms_norms[matrix_i] = GetMatrixAbsMax(ms[matrix_i]);
  }
  size_t min_m_norm = GetMin(ms_norms, n_matrices);
  for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
    if (ms_norms[matrix_i] == min_m_norm) {
      OutputMatrix(ms[matrix_i]);
    }
  }
}

int main() {
  size_t n_matrices, n_rows, n_cols;
  scanf("%zu %zu %zu", &n_matrices, &n_rows, &n_cols);
  Matrix* ms = GetMemArrayOfMatrices(n_matrices, n_rows, n_cols);
  InputMatrices(ms, n_matrices);
  PrintMatrixWithMinNorms(ms, n_matrices);

  return 0;
}

#endif // TASK_15

//	*Дана матрица. Определить 𝑘 – количество "особых" элементов данной матрицы,
//	считая элемент "особым" если в строке слева от него находятся меньшие
//	элементы, а справа – большие
#ifdef TASK_16

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

size_t GetNSpecialEl2(const Matrix m) {
  size_t specials_count = 0;
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
      bool l_cond = col_i == 0 ||
                    GetMax(m.data[row_i], col_i) < m.data[row_i][col_i];
      bool r_cond = col_i == m.n_cols - 1 ||
                    GetMin(m.data[row_i] + col_i + 1, m.n_cols - col_i - 1) >
                    m.data[row_i][col_i];
      specials_count += l_cond && r_cond;
    }
  }

  return specials_count;
}

static void test_GetNSpecialEl2_SomeEl() {
  printf("[--------] SomeEl\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 5;
  int initial_arr[] = {2, 3, 5, 5, 4,
                       6, 2, 3, 8, 12,
                       12, 12, 2, 1, 2};
  const size_t kExpected = 4;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetNSpecialEl2(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetNSpecialEl2_None() {
  printf("[--------] SomeEl\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 5;
  int initial_arr[] = {2, 1, 5, 5, 4,
                       6, 2, 3, 8, 6,
                       12, 12, 2, 1, 2};
  const size_t kExpected = 0;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);

  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetNSpecialEl2(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetNSpecialEl2() {
  printf("[========] %s()\n", __FUNCTION__);
  test_GetNSpecialEl2_SomeEl();
  test_GetNSpecialEl2_None();
}

int main() {
  test_GetNSpecialEl2();

  return 0;
}

#endif // TASK_16

//  *Каждая строка данной матрицы представляет собой координаты вектора в
//  пространстве. Определить, какой из этих векторов образует максимальный угол
//  с данным вектором 𝑣.
#ifdef TASK_17

#define THROW_EX(EXIT_CODE, ...) \
  fprintf(stderr, __VA_ARGS__);  \
  exit(EXIT_CODE)

#include <math.h>

long long GetScalarProduct(int* v_1,
                           int* v_2,
                           const size_t n) {
  long long scalar_prod = 0;
  for (size_t i = 0; i < n; i++) {
    scalar_prod += v_1[i] * v_2[i];
  }

  return scalar_prod;
}

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
 * @brief Вычисление длины вектора, заданного в n-мерном пространстве
 *
 * @param v		указатель на нулевой элемент массива
 * @param size	кол-во элементов массива
 * @return 	длину вектора, заданного в n-мерном пространстве
 */
double GetVectorLength(int* v,
                       const size_t size) {
  return sqrt(GetSumOfSquares(v, size));
}

double GetCosine(int* v_1,
                 int* v_2,
                 const size_t n) {
  const double v_len_1 = GetVectorLength(v_1, n);
  const double v_len_2 = GetVectorLength(v_2, n);
  if (v_len_1 == 0 || v_len_2 == 0) {
    THROW_EX(69, "Dividing by zero\n");
  }
  return GetScalarProduct(v_1, v_2, n) / v_len_1 / v_len_2;
}

size_t GetVectorIndexWithMaxAngle(const Matrix m,
                                  int* v) {
  size_t min_angle_i = 0;
  double min_cos = GetCosine(m.data[0], v, m.n_cols);
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    const double cur_cos = GetCosine(m.data[row_i], v, m.n_cols);
    if (cur_cos < min_cos) {
      min_cos = cur_cos;
      min_angle_i = row_i;
    }
  }

  return min_angle_i;
}

static void test_GetVectorIndexWithMaxAngle_Unique() {
  printf("[--------] Unique\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 3;
  int initial_arr[] = {0, 1, 0,
                       -1, -1, -1,
                       5, 5, 5};

  int v[] = {1, 1, 1};
  const size_t kExpected = 1;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
                                   kInitialNCols);
  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetVectorIndexWithMaxAngle(m, v) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetVectorIndexWithMaxAngle_NotUnique() {
  printf("[--------] NotUnique\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 3;
  int initial_arr[] = {-7, -7, 0,
                       -1, -1, 0,
                       5, 5, 5};

  int v[] = {1, 1, 1};
  const size_t kExpected = 0;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
                                   kInitialNCols);
  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetVectorIndexWithMaxAngle(m, v) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetVectorIndexWithMaxAngle() {
  printf("[========] %s()\n", __FUNCTION__);
  test_GetVectorIndexWithMaxAngle_Unique();
  test_GetVectorIndexWithMaxAngle_NotUnique();
}

int main() {
  test_GetVectorIndexWithMaxAngle();

  return 0;
}

#endif // TASK_17

//  *Дана целочисленная квадратная матрица, все элементы которой различны.
//  Найти скалярное произведение строки, в которой находится наибольший элемент
//  матрицы, на столбец
#ifdef TASK_18

long long GetScalarProduct(int* v_1,
                           int* v_2,
                           const size_t n) {
  long long scalar_prod = 0;
  for (size_t i = 0; i < n; i++) {
    scalar_prod += v_1[i] * v_2[i];
  }

  return scalar_prod;
}

long long GetScalarProductRowAndCol(const Matrix m,
                                    const size_t init_row_i,
                                    const size_t init_col_i) {
  int* cur_col = (int*) malloc(m.n_rows * sizeof(*cur_col));
  for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
    cur_col[row_i] = m.data[row_i][init_col_i];
  }

  return GetScalarProduct(m.data[init_row_i], cur_col, m.n_cols);
}

long long GetSpecialScalarProduct(const Matrix m) {
  return GetScalarProductRowAndCol(m,
                                   GetMaxValuePos(m).row_i,
                                   GetMinValuePos(m).col_i);
}

static void test_GetSpecialScalarProduct_Simple() {
  printf("[--------] Simple\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 3;
  int initial_arr[] = {1, 2, 3,
                       4, 5, 6,
                       7, 8, 9};

  const size_t kExpected = 1 * 7 + 4 * 8 + 7 * 9;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
                                   kInitialNCols);
  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetSpecialScalarProduct(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetSpecialScalarProduct_NotSimple() {
  printf("[--------] NotSimple\n");
  const size_t kInitialNRows = 3;
  const size_t kInitialNCols = 3;
  int initial_arr[] = {1, -5, 3,
                       4, 11, 6,
                       7, 0, 9};

  const size_t kExpected = -5 * 4 + 11 * 11;
  Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows,
                                   kInitialNCols);
  printf("[--------] n_rows = %zu, n_cols = %zu\n",
         kInitialNRows,
         kInitialNCols);
  printf("[RUN     ]\n");
  assert(GetSpecialScalarProduct(m) == kExpected);

  FreeMemMatrix(&m);
  printf("[      OK]\n");
}

static void test_GetSpecialScalarProduct() {
  printf("[========] %s()\n", __FUNCTION__);
  test_GetSpecialScalarProduct_Simple();
  test_GetSpecialScalarProduct_NotSimple();
}

int main() {
  test_GetSpecialScalarProduct();

  return 0;
}

#endif // TASK_18