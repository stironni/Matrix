#ifndef SRC_c_MATRIX_H_
#define SRC_c_MATRIX_H_
#define SUCCESS 1
#define FAILURE 0
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int c_create_matrix(int rows, int columns, matrix_t *result);
void c_remove_matrix(matrix_t *A);
int c_eq_matrix(matrix_t *A, matrix_t *B);
int c_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int c_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int c_mult_number(matrix_t *A, double number, matrix_t *result);
int c_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int c_transpose(matrix_t *A, matrix_t *result);
int c_calc_complements(matrix_t *A, matrix_t *result);
int c_determinant(matrix_t *A, double *result);
int c_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_c_MATRIX_H_
