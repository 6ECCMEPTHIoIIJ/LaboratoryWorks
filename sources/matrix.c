#include "../include/matrix.h"

#include <malloc.h>
#include <windows.h>

#define THROW_EX(EXIT_CODE, ...) \
	fprintf(stderr, __VA_ARGS__);  \
	exit(EXIT_CODE)

Matrix GetMemMatrix(const size_t n_rows, const size_t n_cols) {
	if (n_rows * n_cols == 0) {
		return (Matrix) {NULL, 0, 0};
	}

	int** data = (int**) malloc(n_rows * n_cols * sizeof(*data));
	if (data == NULL) {	 // ! Allocation error
		THROW_EX(2, "Allocation error\n");
	}
	for (size_t i = 0; i < n_rows; i++) {
		data[i] = (int*) malloc(n_cols * sizeof(**data));
		if (data == NULL) {	 // ! Allocation error
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
	if (ms == NULL) {	 // ! Allocation error
		THROW_EX(2, "Allocation error\n");
	}
	for (size_t i = 0; i < n_matrices; i++) {
		ms[i] = GetMemMatrix(n_rows, n_cols);
	}

	return ms;
}

void FreeMemMatrices(Matrix* ms, const size_t n_matrices) {
	for (size_t i = 0; i < n_matrices; i++) {
		FreeMemMatrix(ms + i);
	}
	free(ms);
}