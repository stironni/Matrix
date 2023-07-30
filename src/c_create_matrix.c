#include "c_matrix.h"

int c_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < result->rows; ++i) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    }
  } else {
    res = 1;
  }
  return res;
}
