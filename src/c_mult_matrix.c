#include "c_matrix.h"

int c_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (A != NULL && B != NULL &&
      (A->rows && B->rows && A->columns && B->columns) > 0) {
    if (A->columns == B->rows) {
      if (c_create_matrix(A->rows, B->columns, result) == 0) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else {
        res = 1;
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}
