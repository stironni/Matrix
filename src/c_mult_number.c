#include "c_matrix.h"

int c_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (A != NULL && A->rows > 0 && A->columns > 0) {
    if (c_create_matrix(A->rows, A->columns, result) == 0) {
      if (A->rows == result->rows && A->columns == result->columns) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] * number;
          }
        }

      } else {
        res = 2;
      }
    } else {
      res = 1;
    }
  } else {
    res = 1;
  }
  return res;
}
