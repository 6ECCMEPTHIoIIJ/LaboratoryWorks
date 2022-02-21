#include "../include/matrix.h"

#include <malloc.h>
#include <windows.h>

#define THROW_EX(EXIT_CODE, ...) \
  fprintf(stderr, __VA_ARGS__);  \
  exit(EXIT_CODE)

Matrix GetMemMatrix(const size_t n_rows,
										const size_t n_cols) {
	if (n_rows * n_cols == 0) {
		return (Matrix) {NULL, 0, 0};
	}

	int** data = (int**) malloc(n_rows * n_cols * sizeof(*data));
	if (data == NULL) {   // ! Allocation error
		THROW_EX(2, "Allocation error\n");
	}
	for (size_t i = 0; i < n_rows; i++) {
		data[i] = (int*) malloc(n_cols * sizeof(**data));
		if (data[i] == NULL) {  // ! Allocation error
			THROW_EX(2, "Allocation error\n");
		}
	}

	return (Matrix) {data, n_rows, n_cols};
}

void FreeMemMatrix(Matrix* m) {
	for (size_t i = 0; i < m->n_rows; i++) {
		free(m->data[i]);
	}
	free(m->data);
	m->data = NULL;
	m->n_rows = 0;
	m->n_cols = 0;
}

Matrix* GetMemArrayOfMatrices(const size_t n_matrices,
															const size_t n_rows,
															const size_t n_cols) {
	if (n_matrices == 0) {
		return NULL;
	}

	Matrix* ms = (Matrix*) malloc(n_matrices * sizeof(*ms));
	if (ms == NULL) {   // ! Allocation error
		THROW_EX(2, "Allocation error\n");
	}
	for (size_t i = 0; i < n_matrices; i++) {
		ms[i] = GetMemMatrix(n_rows, n_cols);
	}

	return ms;
}

void FreeMemMatrices(Matrix* ms,
										 const size_t n_matrices) {
	for (size_t i = 0; i < n_matrices; i++) {
		FreeMemMatrix(ms + i);
	}
	free(ms);
}

void InputMatrix(Matrix m) {
	for (size_t j = 0; j < m.n_rows; j++) {
		for (size_t i = 0; i < m.n_cols; i++) {
			scanf("%d", m.data[j] + i);
		}
	}
}

void InputMatrices(Matrix* ms,
									 const size_t n_matrices) {
	for (size_t i = 0; i < n_matrices; i++) {
		InputMatrix(ms[i]);
	}
}

void OutputMatrix(const Matrix m) {
	for (size_t j = 0; j < m.n_rows; j++) {
		for (size_t i = 0; i < m.n_cols; i++) {
			printf("%d ", m.data[j][i]);
		}
		printf("\n");
	}
}

void OutputMatrices(Matrix* ms,
										const size_t n_matrices) {
	for (size_t i = 0; i < n_matrices; i++) {
		OutputMatrix(ms[i]);
	}
}

static void SwapBytes(char* a,
											char* b) {
	const char t = *a;
	*a = *b;
	*b = t;
}

static void Swap(void* a,
								 void* b,
								 const size_t size) {
	for (size_t i = 0; i < size; i++) {
		SwapBytes(a + i, b + i);
	}
}

void SwapRows(Matrix m,
							const size_t i1,
							const size_t i2) {
	if (i1 != i2) {
		Swap(m.data + i1, m.data + i2, sizeof(*m.data));
	}
}

void SwapCols(Matrix m,
							const size_t i1,
							const size_t i2) {
	for (size_t i = 0; i < m.n_rows; i++) {
		Swap(m.data[i] + i1, m.data[i] + i2, sizeof(**m.data));
	}
}

void InsertionSortRowsMatrixByRowCriteria(Matrix m,
																					int (* criteria)(int*,
																													 const size_t)) {
	int* weights = (int*) malloc(m.n_rows * sizeof(**m.data));
	for (size_t i = 0; i < m.n_rows; i++) {
		weights[i] = criteria(m.data[i], m.n_cols);
	}

	for (size_t i = 1; i < m.n_rows; i++) {
		for (size_t j = i; (j > 0) && (weights[j] < weights[j - 1]); j--) {
			Swap(weights + j, weights + j - 1, sizeof(*weights));
			SwapRows(m, j, j - 1);
		}
	}
	free(weights);
}

void InsertionSortColsMatrixByColCriteria(Matrix m,
																					int (* criteria)(int*,
																													 const size_t)) {
	int* weights = (int*) malloc(m.n_cols * sizeof(*weights));
	int* cur_col = (int*) malloc(m.n_rows * sizeof(**m.data));
	for (size_t i = 0; i < m.n_cols; i++) {
		for (size_t j = 0; j < m.n_rows; j++) {
			cur_col[j] = m.data[j][i];
		}
		weights[i] = criteria(cur_col, m.n_rows);
	}
	free(cur_col);

	for (size_t i = 1; i < m.n_cols; i++) {
		for (size_t j = i; (j > 0) && (weights[j] < weights[j - 1]); j--) {
			Swap(weights + j, weights + j - 1, sizeof(*weights));
			SwapCols(m, j, j - 1);
		}
	}
	free(weights);
}

Matrix CreateMatrixFromArray(int* arr,
														 const size_t n_rows,
														 const size_t n_cols) {
	Matrix m = GetMemMatrix(n_rows, n_cols);
	for (size_t i = 0; i < n_rows; i++) {
		memcpy(m.data[i], arr + i * n_cols, n_cols * sizeof(**m.data));
	}

	return m;
}