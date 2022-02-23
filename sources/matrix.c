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
	for (size_t row_i = 0; row_i < n_rows; row_i++) {
		data[row_i] = (int*) malloc(n_cols * sizeof(**data));
		if (data[row_i] == NULL) {  // ! Allocation error
			THROW_EX(2, "Allocation error\n");
		}
	}

	return (Matrix) {data, n_rows, n_cols};
}

void FreeMemMatrix(Matrix* m) {
	for (size_t row_i = 0; row_i < m->n_rows; row_i++) {
		free(m->data[row_i]);
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
	for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
		ms[matrix_i] = GetMemMatrix(n_rows, n_cols);
	}

	return ms;
}

void FreeMemMatrices(Matrix* ms,
										 const size_t n_matrices) {
	for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
		FreeMemMatrix(ms + matrix_i);
	}
	free(ms);
}

void InputMatrix(Matrix m) {
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
			scanf("%d", m.data[row_i] + col_i);
		}
	}
}

void InputMatrices(Matrix* ms,
									 const size_t n_matrices) {
	for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
		InputMatrix(ms[matrix_i]);
	}
}

void OutputMatrix(const Matrix m) {
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
			printf("%d ", m.data[row_i][col_i]);
		}
		printf("\n");
	}
}

void OutputMatrices(Matrix* ms,
										const size_t n_matrices) {
	for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
		OutputMatrix(ms[matrix_i]);
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
							const size_t i_1,
							const size_t i_2) {
	if (i_1 != i_2) {
		Swap(m.data + i_1, m.data + i_2, sizeof(*m.data));
	}
}

void SwapCols(Matrix m,
							const size_t i_1,
							const size_t i_2) {
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		Swap(m.data[row_i] + i_1, m.data[row_i] + i_2, sizeof(**m.data));
	}
}

void InsertionSortRowsMatrixByRowCriteria(Matrix m,
																					int (* criteria)(int*,
																													 const size_t)) {
	int* weights = (int*) malloc(m.n_rows * sizeof(*weights));
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		weights[row_i] = criteria(m.data[row_i], m.n_cols);
	}

	for (size_t row_i = 1; row_i < m.n_rows; row_i++) {
		for (size_t cur_i = row_i;
				 cur_i > 0 && weights[cur_i] < weights[cur_i - 1];
				 cur_i--) {
			Swap(weights + cur_i, weights + cur_i - 1, sizeof(*weights));
			SwapRows(m, cur_i, cur_i - 1);
		}
	}
	free(weights);
}

void InsertionSortRowsMatrixByRowCriteriaF(Matrix m,
																					 double (* criteria)(int*,
																															 const size_t)) {
	double* weights = (double*) malloc(m.n_rows * sizeof(*weights));
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		weights[row_i] = criteria(m.data[row_i], m.n_cols);
	}

	for (size_t row_i = 1; row_i < m.n_rows; row_i++) {
		for (size_t cur_i = row_i;
				 cur_i > 0 && weights[cur_i] < weights[cur_i - 1];
				 cur_i--) {
			Swap(weights + cur_i, weights + cur_i - 1, sizeof(*weights));
			SwapRows(m, cur_i, cur_i - 1);
		}
	}
	free(weights);
}

void InsertionSortColsMatrixByColCriteria(Matrix m,
																					int (* criteria)(int*,
																													 const size_t)) {
	int* weights = (int*) malloc(m.n_cols * sizeof(*weights));
	int* cur_col = (int*) malloc(m.n_rows * sizeof(**m.data));
	for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
		for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
			cur_col[row_i] = m.data[row_i][col_i];
		}
		weights[col_i] = criteria(cur_col, m.n_rows);
	}
	free(cur_col);

	for (size_t col_i = 1; col_i < m.n_cols; col_i++) {
		for (size_t cur_i = col_i;
				 cur_i > 0 && weights[cur_i] < weights[cur_i - 1];
				 cur_i--) {
			Swap(weights + cur_i, weights + cur_i - 1, sizeof(*weights));
			SwapCols(m, cur_i, cur_i - 1);
		}
	}
	free(weights);
}

void InsertionSortColsMatrixByColCriteriaF(Matrix m,
																					 double (* criteria)(int*,
																															 const size_t)) {
	double* weights = (double*) malloc(m.n_cols * sizeof(*weights));
	int* cur_col = (int*) malloc(m.n_rows * sizeof(**m.data));
	for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
		for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
			cur_col[row_i] = m.data[row_i][col_i];
		}
		weights[col_i] = criteria(cur_col, m.n_rows);
	}
	free(cur_col);

	for (size_t col_i = 1; col_i < m.n_cols; col_i++) {
		for (size_t cur_i = col_i;
				 cur_i > 0 && weights[cur_i] < weights[cur_i - 1];
				 cur_i--) {
			Swap(weights + cur_i, weights + cur_i - 1, sizeof(*weights));
			SwapCols(m, cur_i, cur_i - 1);
		}
	}
	free(weights);
}

bool IsSquareMatrix(const Matrix m) {
	return m.n_rows == m.n_cols;
}

bool AreTwoMatricesEqual(const Matrix m_1,
												 const Matrix m_2) {
	if (m_1.n_rows != m_2.n_rows ||
			m_1.n_cols != m_2.n_cols) {
		return false;
	}

	const size_t n_rows = m_1.n_rows;
	const size_t n_cols = m_1.n_cols;
	for (size_t row_i = 0; row_i < n_rows; row_i++) {
		for (size_t col_i = 0; col_i < n_cols; col_i++) {
			if (m_1.data[row_i][col_i] != m_2.data[row_i][col_i]) {
				return false;
			}
		}
	}

	return true;
}

bool IsEMatrix(const Matrix m) {
	if (!IsSquareMatrix(m)) {
		return false;
	}

	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
			if (row_i == col_i && m.data[row_i][col_i] != 1 ||
					row_i != col_i && m.data[row_i][col_i] != 0) {
				return false;
			}
		}
	}

	return true;
}

bool IsSymmetricMatrix(const Matrix m) {
	if (!IsSquareMatrix(m)) {
		return false;
	}

	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_cols; col_i++) {
			if (m.data[row_i][col_i] != m.data[col_i][row_i]) {
				return false;
			}
		}
	}

	return true;
}

Position GetMinValuePos(const Matrix m) {
	size_t min_row_i = 0;
	size_t min_col_i = 0;
	int min_val = m.data[0][0];
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_rows; col_i++) {
			if (m.data[row_i][col_i] < min_val) {
				min_val = m.data[row_i][col_i];
				min_row_i = row_i;
				min_col_i = col_i;
			}
		}
	}

	return (Position) {min_row_i, min_col_i};
}

void TransposeMatrix(Matrix* m) {
	Matrix t_m = GetMemMatrix(m->n_cols, m->n_rows);
	for (size_t t_row_i = 0; t_row_i < t_m.n_rows; t_row_i++) {
		for (size_t t_col_i = 0; t_col_i < t_m.n_cols; t_col_i++) {
			t_m.data[t_row_i][t_col_i] = m->data[t_col_i][t_row_i];
		}
	}
	FreeMemMatrix(m);
	*m = t_m;
}

Position GetMaxValuePos(const Matrix m) {
	size_t max_row_i = 0;
	size_t max_col_i = 0;
	int max_val = m.data[0][0];
	for (size_t row_i = 0; row_i < m.n_rows; row_i++) {
		for (size_t col_i = 0; col_i < m.n_rows; col_i++) {
			if (m.data[row_i][col_i] > max_val) {
				max_val = m.data[row_i][col_i];
				max_row_i = row_i;
				max_col_i = col_i;
			}
		}
	}

	return (Position) {max_row_i, max_col_i};
}

Matrix CreateMatrixFromArray(int* arr,
														 const size_t n_rows,
														 const size_t n_cols) {
	Matrix m = GetMemMatrix(n_rows, n_cols);
	for (size_t row_i = 0; row_i < n_rows; row_i++) {
		memcpy(m.data[row_i], arr + row_i * n_cols, n_cols * sizeof(**m.data));
	}

	return m;
}

Matrix* CreateArrayOfMatrixFromArray(int* arr,
																		 const size_t n_matrices,
																		 const size_t n_rows,
																		 const size_t n_cols) {
	Matrix* ms = (Matrix*) malloc(n_matrices * sizeof(*ms));
	for (size_t matrix_i = 0; matrix_i < n_matrices; matrix_i++) {
		ms[matrix_i] = CreateMatrixFromArray(arr + matrix_i * n_rows * n_cols,
																				 n_rows,
																				 n_cols);
	}

	return ms;
}

Matrix MulMatrices(const Matrix m_1,
									 const Matrix m_2) {
	if (m_1.n_cols != m_2.n_rows) {
		THROW_EX(3, "Matrix size error\n");
	}

	const size_t n_rows = m_1.n_rows;
	const size_t n_cols = m_2.n_cols;
	const size_t els_in_row = m_1.n_cols;
	Matrix m = GetMemMatrix(n_rows, n_cols);
	for (size_t row_i = 0; row_i < n_rows; row_i++) {
		for (size_t col_i = 0; col_i < n_cols; col_i++) {
			m.data[row_i][col_i] = 0;
			for (size_t el_i = 0; el_i < els_in_row; el_i++) {
				m.data[row_i][col_i] += m_1.data[row_i][el_i] * m_2.data[el_i][col_i];
			}
		}
	}

	return m;
}