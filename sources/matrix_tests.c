#include "../include/matrix_tests.h"

#include <assert.h>
#include <memory.h>

#include "../include/matrix.h"

static void test_GetMemMatrix_FreeMemMatrix_BothZeroDimensions() {
	printf("[--------] BothZeroDimensions\n");
	const size_t kInitialNRows = 0;
	const size_t kInitialNCols = 0;
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);

	FreeMemMatrix(&m);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);
	printf("[      OK]\n");
}

static void test_GetMemMatrix_FreeMemMatrix_FirstZeroDimesion() {
	printf("[--------] FirstZeroDimesion\n");
	const size_t kInitialNRows = 0;
	const size_t kInitialNCols = 100;
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);

	FreeMemMatrix(&m);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);
	printf("[      OK]\n");
}

static void test_GetMemMatrix_FreeMemMatrix_SecondZeroDimesion() {
	printf("[--------] SecondZeroDimesion\n");
	const size_t kInitialNRows = 100;
	const size_t kInitialNCols = 0;
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);

	FreeMemMatrix(&m);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);
	printf("[      OK]\n");
}

static void test_GetMemMatrix_FreeMemMatrix_BothNonZeroDimensions() {
	printf("[--------] BothNonZeroDimensions\n");
	const size_t kInitialNRows = 100;
	const size_t kInitialNCols = 1000;
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	assert(m.data != NULL);
	assert(m.n_rows == kInitialNRows);
	assert(m.n_cols == kInitialNCols);

	FreeMemMatrix(&m);
	assert(m.data == NULL);
	assert(m.n_rows == 0);
	assert(m.n_cols == 0);
	printf("[      OK]\n");
}

static void test_GetMemMatrix_FreeMemMatrix() {
	printf("[========] %s()\n", __FUNCTION__);
	test_GetMemMatrix_FreeMemMatrix_BothZeroDimensions();
	test_GetMemMatrix_FreeMemMatrix_FirstZeroDimesion();
	test_GetMemMatrix_FreeMemMatrix_SecondZeroDimesion();
	test_GetMemMatrix_FreeMemMatrix_BothNonZeroDimensions();
}

static void test_GetMemArrayOfMatrices_ZeroAmount() {
	printf("[--------] ZeroAmount\n");
	const size_t kInitialNMatrices = 0;
	const size_t kInitialNRows = 1000;
	const size_t kInitialNCols = 100;
	printf("[--------] n_matrices = %zu n_rows = %zu, n_cols = %zu\n",
				 kInitialNMatrices,
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix* ms =
			GetMemArrayOfMatrices(kInitialNMatrices, kInitialNRows, kInitialNCols);
	assert(ms == NULL);
	FreeMemMatrices(ms, kInitialNMatrices);
	printf("[      OK]\n");
}

static void test_GetMemArrayOfMatrices_NonZeroAmount() {
	printf("[--------] NonZeroAmount\n");
	const size_t kInitialNMatrices = 10;
	const size_t kInitialNRows = 1000;
	const size_t kInitialNCols = 100;
	printf("[--------] n_matrices = %zu n_rows = %zu, n_cols = %zu\n",
				 kInitialNMatrices,
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix* ms =
			GetMemArrayOfMatrices(kInitialNMatrices, kInitialNRows, kInitialNCols);
	assert(ms != NULL);
	for (size_t i = 0; i < kInitialNMatrices; i++) {
		assert(ms[i].data != NULL);
		assert(ms[i].n_rows == kInitialNRows);
		assert(ms[i].n_cols == kInitialNCols);
	}
	FreeMemMatrices(ms, kInitialNMatrices);
	printf("[      OK]\n");
}

static void test_GetMemArrayOfMatrices_ZeroDimension() {
	printf("[--------] ZeroDimension\n");
	const size_t kInitialNMatrices = 10000;
	const size_t kInitialNRows = 0;
	const size_t kInitialNCols = 100;
	printf("[--------] n_matrices = %zu n_rows = %zu, n_cols = %zu\n",
				 kInitialNMatrices,
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");

	Matrix* ms =
			GetMemArrayOfMatrices(kInitialNMatrices, kInitialNRows, kInitialNCols);
	assert(ms != NULL);
	for (size_t i = 0; i < kInitialNMatrices; i++) {
		assert(ms[i].data == NULL);
		assert(ms[i].n_rows == 0);
		assert(ms[i].n_cols == 0);
	}
	FreeMemMatrices(ms, kInitialNMatrices);
	printf("[      OK]\n");
}

static void test_GetMemArrayOfMatrices() {
	printf("[========] %s()\n", __FUNCTION__);
	test_GetMemArrayOfMatrices_ZeroAmount();
	test_GetMemArrayOfMatrices_NonZeroAmount();
	test_GetMemArrayOfMatrices_ZeroDimension();
}

static void test_SwapRows_Near() {
	printf("[--------] Near\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 2;
	const size_t kI2 = 3;
	int expected_arr[] = {1, 2, 3, 4,
												6, 7, 8, 9,
												15, 16, 17, 19,
												10, 11, 12, 13,
												20, 21, 22, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapRows(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapRows_OnBounds() {
	printf("[--------] OnBounds\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 0;
	const size_t kI2 = 4;
	int expected_arr[] = {20, 21, 22, 23,
												6, 7, 8, 9,
												10, 11, 12, 13,
												15, 16, 17, 19,
												1, 2, 3, 4};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapRows(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapRows_One() {
	printf("[--------] One\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 3;
	const size_t kI2 = 3;
	int expected_arr[] = {1, 2, 3, 4,
												6, 7, 8, 9,
												10, 11, 12, 13,
												15, 16, 17, 19,
												20, 21, 22, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapRows(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapRows() {
	printf("[========] %s()\n", __FUNCTION__);
	test_SwapRows_OnBounds();
	test_SwapRows_Near();
	test_SwapRows_One();
}

static void test_SwapCols_OnBounds() {
	printf("[--------] OnBounds\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 0;
	const size_t kI2 = 3;
	int expected_arr[] = {4, 2, 3, 1,
												9, 7, 8, 6,
												13, 11, 12, 10,
												19, 16, 17, 15,
												23, 21, 22, 20};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapCols(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapCols_Near() {
	printf("[--------] Near\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 1;
	const size_t kI2 = 2;
	int expected_arr[] = {1, 3, 2, 4,
												6, 8, 7, 9,
												10, 12, 11, 13,
												15, 17, 16, 19,
												20, 22, 21, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapCols(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapCols_One() {
	printf("[--------] One\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	const size_t kI1 = 3;
	const size_t kI2 = 3;
	int expected_arr[] = {1, 2, 3, 4,
												6, 7, 8, 9,
												10, 11, 12, 13,
												15, 16, 17, 19,
												20, 21, 22, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu, i1 = %zu, i2 = %zu\n",
				 kInitialNRows,
				 kInitialNCols,
				 kI1,
				 kI2);
	printf("[RUN     ]\n");
	SwapCols(m, kI1, kI2);
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_SwapCols() {
	printf("[========] %s()\n", __FUNCTION__);
	test_SwapCols_OnBounds();
	test_SwapCols_Near();
	test_SwapCols_One();
}

static int GetSum(int* arr,
									const size_t size) {
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

static void test_InsertionSortRowsMatrixByRowCriteria_Sorted() {
	printf("[--------] Sorted\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 6, 7, 8, 9,
											 10, 11, 12, 13,
											 15, 16, 17, 19,
											 20, 21, 22, 23};
	int expected_arr[] = {1, 2, 3, 4,
												6, 7, 8, 9,
												10, 11, 12, 13,
												15, 16, 17, 19,
												20, 21, 22, 23};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	InsertionSortRowsMatrixByRowCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortRowsMatrixByRowCriteria_Unsorted() {
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
	InsertionSortRowsMatrixByRowCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortRowsMatrixByRowCriteria_OneEl() {
	printf("[--------] OneEl\n");
	const size_t kInitialNRows = 1;
	const size_t kInitialNCols = 1;
	int initial_arr[] = {34};
	int expected_arr[] = {34};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	InsertionSortRowsMatrixByRowCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortRowsMatrixByRowCriteria() {
	printf("[========] %s()\n", __FUNCTION__);
	test_InsertionSortRowsMatrixByRowCriteria_Unsorted();
	test_InsertionSortRowsMatrixByRowCriteria_Sorted();
	test_InsertionSortRowsMatrixByRowCriteria_OneEl();
}

static void test_InsertionSortColsMatrixByColCriteria_OneEl() {
	printf("[--------] OneEl\n");
	const size_t kInitialNRows = 1;
	const size_t kInitialNCols = 1;
	int initial_arr[] = {34};
	int expected_arr[] = {34};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	InsertionSortColsMatrixByColCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortColsMatrixByColCriteria_Unsorted() {
	printf("[--------] Unsorted\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {11, 2, 1, 7,
											 12, 3, 2, 8,
											 12, 4, 3, 9,
											 13, 5, 4, 10,
											 14, 6, 5, 11};
	int expected_arr[] = {1, 2, 7, 11,
												2, 3, 8, 12,
												3, 4, 9, 12,
												4, 5, 10, 13,
												5, 6, 11, 14};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	InsertionSortColsMatrixByColCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortColsMatrixByColCriteria_Sorted() {
	printf("[--------] Sorted\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 7, 11,
											 2, 3, 8, 12,
											 3, 4, 9, 12,
											 4, 5, 10, 13,
											 5, 6, 11, 14};
	int expected_arr[] = {1, 2, 7, 11,
												2, 3, 8, 12,
												3, 4, 9, 12,
												4, 5, 10, 13,
												5, 6, 11, 14};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	InsertionSortColsMatrixByColCriteria(m, GetSum);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	for (size_t i = 0; i < kInitialNRows; i++) {
		assert(memcmp(m.data[i],
									expected_arr + i * kInitialNCols,
									kInitialNCols * sizeof(**m.data)) == 0);
	}

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_InsertionSortColsMatrixByColCriteria() {
	printf("[========] %s()\n", __FUNCTION__);
	test_InsertionSortColsMatrixByColCriteria_Sorted();
	test_InsertionSortColsMatrixByColCriteria_Unsorted();
	test_InsertionSortColsMatrixByColCriteria_OneEl();
}

static void test_IsSquareMatrix_True() {
	printf("[--------] True\n");
	const size_t kInitialNRows = 100;
	const size_t kInitialNCols = 100;
	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(IsSquareMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSquareMatrix_Toll() {
	printf("[--------] Toll\n");
	const size_t kInitialNRows = 101;
	const size_t kInitialNCols = 100;
	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsSquareMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSquareMatrix_Wide() {
	printf("[--------] Wide\n");
	const size_t kInitialNRows = 100;
	const size_t kInitialNCols = 101;
	Matrix m = GetMemMatrix(kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsSquareMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSquareMatrix() {
	printf("[========] %s()\n", __FUNCTION__);
	test_IsSquareMatrix_True();
	test_IsSquareMatrix_Toll();
	test_IsSquareMatrix_Wide();
}

static void test_AreTwoMatricesEqual_Equal() {
	printf("[--------] Equal\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 7, 11,
											 2, 3, 8, 12,
											 3, 4, 9, 12,
											 4, 5, 10, 13,
											 5, 6, 11, 14};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(AreTwoMatricesEqual(m, m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_AreTwoMatricesEqual_NotEqual() {
	printf("[--------] NotEqual\n");
	const size_t kInitialNRows = 5;
	const size_t kInitialNCols = 4;
	int initial_arr_1[] = {1, 2, 7, 11,
												 2, 3, 8, 12,
												 3, 4, 9, 12,
												 4, 5, 10, 13,
												 5, 6, 11, 14};
	int initial_arr_2[] = {1, 2, 7, 11,
												 2, 3, 8, 12,
												 3, 50, 9, 12,
												 4, 5, 10, 13,
												 5, 6, 11, 14};
	Matrix m_1 = CreateMatrixFromArray(initial_arr_1, kInitialNRows,
																		 kInitialNCols);
	Matrix m_2 = CreateMatrixFromArray(initial_arr_2, kInitialNRows,
																		 kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!AreTwoMatricesEqual(m_1, m_2));

	FreeMemMatrix(&m_1);
	FreeMemMatrix(&m_2);
	printf("[      OK]\n");
}

static void test_AreTwoMatricesEqual_DiffSizes() {
	printf("[--------] DiffSizes\n");
	const size_t kInitialNRows1 = 5;
	const size_t kInitialNCols1 = 4;
	const size_t kInitialNRows2 = 7;
	const size_t kInitialNCols2 = 8;
	Matrix m_1 = GetMemMatrix(kInitialNRows1, kInitialNCols1);
	Matrix m_2 = GetMemMatrix(kInitialNRows2, kInitialNCols2);
	printf("[--------] n_rows_1 = %zu, n_cols_1 = %zu, "
				 "n_rows_2 = %zu, n_cols_2 = %zu\n",
				 kInitialNRows1,
				 kInitialNCols1,
				 kInitialNRows2,
				 kInitialNCols2);
	printf("[RUN     ]\n");
	assert(!AreTwoMatricesEqual(m_1, m_2));

	FreeMemMatrix(&m_1);
	FreeMemMatrix(&m_2);
	printf("[      OK]\n");
}

static void test_AreTwoMatricesEqual() {
	printf("[========] %s()\n", __FUNCTION__);
	test_AreTwoMatricesEqual_Equal();
	test_AreTwoMatricesEqual_NotEqual();
	test_AreTwoMatricesEqual_DiffSizes();
}

static void test_IsEMatrix_True() {
	printf("[--------] True\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 0, 0,
											 0, 1, 0, 0,
											 0, 0, 1, 0,
											 0, 0, 0, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(IsEMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsEMatrix_NotE() {
	printf("[--------] NotE\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 7, 0,
											 0, 1, 0, 0,
											 0, 0, 1, 0,
											 0, 0, 0, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsEMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsEMatrix_NotSquare() {
	printf("[--------] NotSquare\n");
	const size_t kInitialNRows = 6;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 0, 0,
											 0, 1, 0, 0,
											 0, 0, 1, 0,
											 0, 0, 0, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsEMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsEMatrix() {
	printf("[========] %s()\n", __FUNCTION__);
	test_IsEMatrix_True();
	test_IsEMatrix_NotSquare();
	test_IsEMatrix_NotE();
}

static void test_IsSymmetricMatrix_NotSquare() {
	printf("[--------] NotSquare\n");
	const size_t kInitialNRows = 6;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 0, 0,
											 0, 1, 0, 0,
											 0, 0, 1, 0,
											 0, 0, 0, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsSymmetricMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSymmetricMatrix_NotSymmetric() {
	printf("[--------] NotSymmetric\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 0, 7, 0,
											 0, 1, 0, 0,
											 0, 0, 1, 0,
											 0, 0, 0, 1};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(!IsSymmetricMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSymmetricMatrix_True() {
	printf("[--------] True\n");
	const size_t kInitialNRows = 4;
	const size_t kInitialNCols = 4;
	int initial_arr[] = {1, 2, 3, 4,
											 2, 9, 5, 6,
											 3, 5, 9, 7,
											 4, 6, 7, 0};
	Matrix m = CreateMatrixFromArray(initial_arr, kInitialNRows, kInitialNCols);
	printf("[--------] n_rows = %zu, n_cols = %zu\n",
				 kInitialNRows,
				 kInitialNCols);
	printf("[RUN     ]\n");
	assert(IsSymmetricMatrix(m));

	FreeMemMatrix(&m);
	printf("[      OK]\n");
}

static void test_IsSymmetricMatrix() {
	printf("[========] %s()\n", __FUNCTION__);
	test_IsSymmetricMatrix_True();
	test_IsSymmetricMatrix_NotSquare();
	test_IsSymmetricMatrix_NotSymmetric();
}

void test_matrix() {
	printf("[########] %s\n", __FILE__);
	test_GetMemMatrix_FreeMemMatrix();
	test_GetMemArrayOfMatrices();
	test_SwapRows();
	test_SwapCols();
	test_InsertionSortRowsMatrixByRowCriteria();
	test_InsertionSortColsMatrixByColCriteria();
	test_IsSquareMatrix();
	test_AreTwoMatricesEqual();
	test_IsEMatrix();
	test_IsSymmetricMatrix();
	printf("[ PASSED ]\n");
}