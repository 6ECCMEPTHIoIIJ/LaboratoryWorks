#include "../include/matrix_tests.h"

#include "../include/matrix.h"

#include <assert.h>

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

void test_matrix() {
	printf("[########] %s\n", __FILE__);
	test_GetMemMatrix_FreeMemMatrix();
	test_GetMemArrayOfMatrices();
	printf("[ PASSED ]\n");
}