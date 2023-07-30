#include "c_matrix.h"

int c_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  double det = 0.0;
  if (A == NULL || A->rows < 1 || A->columns < 1) {
    res = 1;
  } else {
    if (!res) {
      res = c_determinant(A, &det);
      if ((fabs(det - 0) >= pow(10, -7)) && !res) {
        matrix_t calc = {0};
        res = c_calc_complements(A, &calc);
        if (!res) {
          matrix_t transpose = {0};
          res = c_transpose(&calc, &transpose);
          if (!res) {
            c_mult_number(&transpose, (1.0 / det), result);
          }
          c_remove_matrix(&transpose);
        }
        c_remove_matrix(&calc);
      }
    }
  }
  return res;
}
