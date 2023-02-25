#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int res = 0;
    double det = 0.0;
    if (A == NULL || A->rows < 1 || A->columns < 1) {
        res = 1;
    } else {
        if (!res) {
            res = s21_determinant(A, &det);
            if ((fabs(det - 0) >= pow(10, -7)) && !res) {
                matrix_t calc = {0};
                res = s21_calc_complements(A, &calc);
                if (!res) {
                    matrix_t transpose = {0};
                    res = s21_transpose(&calc, &transpose);
                    if (!res) {
                        s21_mult_number(&transpose, (1.0 / det), result);
                    }
                    s21_remove_matrix(&transpose);
                }
                s21_remove_matrix(&calc);
            }
        }
    }
    return res;
}
