#include "c_matrix.h"

int c_determinant(matrix_t *A, double *result) {
  int res = 0;
  *result = 0.0;
  double result2 = 0.0;
  if (A->rows == A->columns && A->matrix != NULL &&
      (A->rows && A->columns) > 0) {
    if (A->rows == 1) *result = A->matrix[0][0];
    if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    if (A->rows > 2) {
      matrix_t cube;
      c_create_matrix(A->rows - 1, A->rows - 1, &cube);
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->columns; j++) {
          int cube_row = 0;
          for (int k = 0; k < A->columns; k++) {
            if (k == i) continue;
            int cube_col = 0;
            for (int l = 0; l < A->columns; l++) {
              if (l == j) continue;
              cube.matrix[cube_row][cube_col] = A->matrix[k][l];
              cube_col++;
            }
            cube_row++;
          }
          c_determinant(&cube, &result2);
          *result += A->matrix[i][0] * pow(-1, i + j + 2) * result2;
        }
      }
      c_remove_matrix(&cube);
    }
  } else {
    res = 1;
  }
  return res;
}
