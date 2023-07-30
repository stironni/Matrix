#include "c_matrix.h"

void c_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = A->rows - 1; i >= 0; i--) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
}
