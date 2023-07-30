#include "c_matrix.h"

int c_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns &&
        (A->rows && B->rows && A->columns && B->columns) > 0) {
      char *ma = calloc(2, sizeof(double));
      char *mb = calloc(2, sizeof(double));
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          snprintf(ma, sizeof(double) * 2, "%.7f", A->matrix[i][j]);
          snprintf(mb, sizeof(double) * 2, "%.7f", B->matrix[i][j]);
          if (strcmp(ma, mb) == 0) {
            res = SUCCESS;
          } else {
            res = FAILURE;
          }
        }
      }
      free(ma);
      free(mb);
    } else {
      res = FAILURE;
    }
  } else {
    res = FAILURE;
  }
  return res;
}
