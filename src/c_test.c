#include <check.h>

#include "c_matrix.h"

void c_matrix_add(matrix_t *A) {
  A->matrix[0][0] = 5;
  A->matrix[0][1] = 2;
  A->matrix[0][2] = 7;
  A->matrix[0][3] = 5;
  A->matrix[0][4] = 2;
  A->matrix[1][0] = 8;
  A->matrix[1][1] = 1;
  A->matrix[1][2] = 0;
  A->matrix[1][3] = 9;
  A->matrix[1][4] = 68;
  A->matrix[2][0] = 8;
  A->matrix[2][1] = 3;
  A->matrix[2][2] = 12;
  A->matrix[2][3] = 52;
  A->matrix[2][4] = 17;
  A->matrix[3][0] = 9;
  A->matrix[3][1] = 32;
  A->matrix[3][2] = 125;
  A->matrix[3][3] = 5;
  A->matrix[3][4] = 9;
  A->matrix[4][0] = 7;
  A->matrix[4][1] = 2;
  A->matrix[4][2] = 25;
  A->matrix[4][3] = 95;
  A->matrix[4][4] = 96;
}

START_TEST(create_matrix_1) {
  matrix_t result;
  ck_assert_int_eq(c_create_matrix(5, 5, &result), 0);
  c_matrix_add(&result);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t result;
  ck_assert_int_eq(c_create_matrix(0, 50, &result), 1);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t result;
  ck_assert_int_eq(c_create_matrix(0, 0, &result), 1);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t result;
  ck_assert_int_eq(c_create_matrix(5, 0, &result), 1);
}
END_TEST

START_TEST(eq_matrix_1) {
  int rows = 10;
  int columns = 10;
  matrix_t A, B;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.45434 + i + j;
      B.matrix[i][j] = 0.45434 + i + j;
    }
  }
  ck_assert_double_eq(c_eq_matrix(&A, &B), 1);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  int rows = 10;
  int columns = 10;
  matrix_t A, B;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(5, columns, &B);
  ck_assert_double_eq(c_eq_matrix(&A, &B), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  int rows = 10;
  int columns = 10;
  matrix_t A, B;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.454344 + i + j;
      B.matrix[i][j] = 0.45434 + i + j;
    }
  }
  ck_assert_double_eq(c_eq_matrix(&A, &B), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  int rows = 10;
  int columns = 10;
  matrix_t A, B;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.1000011 + i + j;
      B.matrix[i][j] = 0.1000011111 + i + j;
    }
  }
  ck_assert_double_eq(c_eq_matrix(&A, &B), 1);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  int rows = 1000;
  int columns = 1000;
  matrix_t A, B;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 0.1000011 + i + j;
      B.matrix[i][j] = 0.1000011111 + i + j;
    }
  }
  ck_assert_double_eq(c_eq_matrix(&A, &B), 1);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sum_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
  int rows = 20;
  int columns = 25;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sum_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_3) {
  int rows = 20;
  int columns = 25;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sum_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A, B, result;
  A.rows = 0;
  A.columns = 3;
  c_create_matrix(5, 6, &B);
  ck_assert_int_eq(c_sum_matrix(&A, &B, &result), 1);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 6.584 + i + j;
      B.matrix[i][j] = 9.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sub_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_2) {
  int rows = 20;
  int columns = 25;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sub_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_3) {
  int rows = 21;
  int columns = 25;
  matrix_t A, B, result;
  c_create_matrix(rows, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sub_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_4) {
  int rows = 21;
  int columns = 25;
  matrix_t A, B, result;
  c_create_matrix(0, columns, &A);
  c_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      B.matrix[i][j] = 6.840474758585 + i + j;
    }
  }
  ck_assert_int_eq(c_sub_matrix(&A, &B, &result), 2);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(mult_number_1) {
  int rows = 5;
  int columns = 5;
  int number = 0;
  matrix_t A, result;
  c_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
    }
  }
  ck_assert_int_eq(c_mult_number(&A, number, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  int rows = 5;
  int columns = 5;
  double number = 1.58;
  matrix_t A, result;
  c_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 8.584 + i + j;
    }
  }
  ck_assert_int_eq(c_mult_number(&A, number, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  double number = 1.58;
  matrix_t A, result;
  c_create_matrix(5, 5, &A);
  ck_assert_int_eq(c_mult_number(&A, number, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_4) {
  double number = 1.56;
  matrix_t A, result;
  A.rows = 0;
  A.columns = 5;
  ck_assert_int_eq(c_mult_number(&A, number, &result), 1);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t A, B, result;
  c_create_matrix(2, 2, &A);
  c_create_matrix(2, 2, &B);
  int k = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = ++k;
    }
  }
  k = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = ++k;
    }
  }
  ck_assert_int_eq(c_mult_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A, B, result;
  c_create_matrix(2, 3, &A);
  c_create_matrix(3, 2, &B);
  int k = 0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = ++k;
    }
  }
  k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      B.matrix[i][j] = ++k;
    }
  }
  ck_assert_int_eq(c_mult_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A, B, result;
  c_create_matrix(5, 1, &A);
  c_create_matrix(1, 5, &B);
  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 1; j++) {
      A.matrix[i][j] = ++k;
    }
  }
  k = 0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 5; j++) {
      B.matrix[i][j] = ++k;
    }
  }
  ck_assert_int_eq(c_mult_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A, B, result;
  c_create_matrix(5, 2, &A);
  c_create_matrix(1, 5, &B);
  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = ++k;
    }
  }
  k = 0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 5; j++) {
      B.matrix[i][j] = ++k;
    }
  }
  ck_assert_int_eq(c_mult_matrix(&A, &B, &result), 2);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A, B, result;
  c_create_matrix(100, 100, &A);
  c_create_matrix(100, 5, &B);
  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = ++k;
    }
  }
  k = 0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 5; j++) {
      B.matrix[i][j] = ++k;
    }
  }
  ck_assert_int_eq(c_mult_matrix(&A, &B, &result), 0);
  c_remove_matrix(&A);
  c_remove_matrix(&B);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A, result, otvet;
  c_create_matrix(5, 5, &A);
  c_matrix_add(&A);
  ck_assert_int_eq(c_transpose(&A, &result), 0);
  c_create_matrix(5, 5, &otvet);
  otvet.matrix[0][0] = 5;
  otvet.matrix[0][1] = 8;
  otvet.matrix[0][2] = 8;
  otvet.matrix[0][3] = 9;
  otvet.matrix[0][4] = 7;
  otvet.matrix[1][0] = 2;
  otvet.matrix[1][1] = 1;
  otvet.matrix[1][2] = 3;
  otvet.matrix[1][3] = 32;
  otvet.matrix[1][4] = 2;
  otvet.matrix[2][0] = 7;
  otvet.matrix[2][1] = 0;
  otvet.matrix[2][2] = 12;
  otvet.matrix[2][3] = 125;
  otvet.matrix[2][4] = 25;
  otvet.matrix[3][0] = 5;
  otvet.matrix[3][1] = 9;
  otvet.matrix[3][2] = 52;
  otvet.matrix[3][3] = 5;
  otvet.matrix[3][4] = 95;
  otvet.matrix[4][0] = 2;
  otvet.matrix[4][1] = 68;
  otvet.matrix[4][2] = 17;
  otvet.matrix[4][3] = 9;
  otvet.matrix[4][4] = 96;
  ck_assert_int_eq(c_eq_matrix(&result, &otvet), SUCCESS);
  c_remove_matrix(&A);
  c_remove_matrix(&otvet);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A, result, otvet;
  c_create_matrix(5, 2, &A);
  int k = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = k++;
    }
  }
  ck_assert_int_eq(c_transpose(&A, &result), 0);
  c_create_matrix(2, 5, &otvet);
  otvet.matrix[0][0] = 0.000000;
  otvet.matrix[0][1] = 2.000000;
  otvet.matrix[0][2] = 4.000000;
  otvet.matrix[0][3] = 6.000000;
  otvet.matrix[0][4] = 8.000000;
  otvet.matrix[1][0] = 1.000000;
  otvet.matrix[1][1] = 3.000000;
  otvet.matrix[1][2] = 5.000000;
  otvet.matrix[1][3] = 7.000000;
  otvet.matrix[1][4] = 9.000000;
  ck_assert_int_eq(c_eq_matrix(&result, &otvet), SUCCESS);
  c_remove_matrix(&A);
  c_remove_matrix(&otvet);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t A, result, otvet;
  c_create_matrix(5, 5, &A);
  c_matrix_add(&A);
  ck_assert_int_eq(c_calc_complements(&A, &result), 0);
  c_create_matrix(5, 5, &otvet);
  otvet.matrix[0][0] = -2214127;
  otvet.matrix[0][1] = 6099038;
  otvet.matrix[0][2] = -1422553;
  otvet.matrix[0][3] = 273026;
  otvet.matrix[0][4] = 134658;
  otvet.matrix[1][0] = 89984;
  otvet.matrix[1][1] = -1603296;
  otvet.matrix[1][2] = 410192;
  otvet.matrix[1][3] = 14992;
  otvet.matrix[1][4] = -94816;
  otvet.matrix[2][0] = 351272;
  otvet.matrix[2][1] = -3219968;
  otvet.matrix[2][2] = 804776;
  otvet.matrix[2][3] = -203136;
  otvet.matrix[2][4] = 32912;
  otvet.matrix[3][0] = 108262;
  otvet.matrix[3][1] = -354844;
  otvet.matrix[3][2] = 26010;
  otvet.matrix[3][3] = 284;
  otvet.matrix[3][4] = -7556;
  otvet.matrix[4][0] = -89965;
  otvet.matrix[4][1] = 1612074;
  otvet.matrix[4][2] = -405867;
  otvet.matrix[4][3] = 19638;
  otvet.matrix[4][4] = -15722;
  ck_assert_int_eq(c_eq_matrix(&result, &otvet), SUCCESS);
  c_remove_matrix(&otvet);
  c_remove_matrix(&A);
  c_remove_matrix(&result);
}
END_TEST

START_TEST(determinant) {
  matrix_t A;
  double result, otvet = -7195984.000000;
  c_create_matrix(5, 5, &A);
  c_matrix_add(&A);
  ck_assert_int_eq(c_determinant(&A, &result), 0);
  ck_assert_double_eq(result, otvet);
  c_remove_matrix(&A);
}
END_TEST

START_TEST(inverse) {
  matrix_t A, result, otvet;
  c_create_matrix(5, 5, &A);
  c_matrix_add(&A);
  c_create_matrix(5, 5, &otvet);
  otvet.matrix[0][0] = 0.3076893;
  otvet.matrix[0][1] = -0.0125048;
  otvet.matrix[0][2] = -0.0488150;
  otvet.matrix[0][3] = -0.0150448;
  otvet.matrix[0][4] = 0.0125021;
  otvet.matrix[1][0] = -0.8475614;
  otvet.matrix[1][1] = 0.2228043;
  otvet.matrix[1][2] = 0.4474674;
  otvet.matrix[1][3] = 0.0493114;
  otvet.matrix[1][4] = -0.2240241;
  otvet.matrix[2][0] = 0.1976871;
  otvet.matrix[2][1] = -0.0570029;
  otvet.matrix[2][2] = -0.1118368;
  otvet.matrix[2][3] = -0.0036145;
  otvet.matrix[2][4] = 0.0564019;
  otvet.matrix[3][0] = -0.0379414;
  otvet.matrix[3][1] = -0.0020834;
  otvet.matrix[3][2] = 0.0282291;
  otvet.matrix[3][3] = -0.0000395;
  otvet.matrix[3][4] = -0.0027290;
  otvet.matrix[4][0] = -0.0187129;
  otvet.matrix[4][1] = 0.0131762;
  otvet.matrix[4][2] = -0.0045737;
  otvet.matrix[4][3] = 0.0010500;
  otvet.matrix[4][4] = 0.0021848;
  ck_assert_int_eq(c_inverse_matrix(&A, &result), 0);
  ck_assert_int_eq(c_eq_matrix(&result, &otvet), SUCCESS);
  c_remove_matrix(&A);
  c_remove_matrix(&otvet);
  c_remove_matrix(&result);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_matrix_1);
  tcase_add_test(tc1_1, create_matrix_2);
  tcase_add_test(tc1_1, create_matrix_3);
  tcase_add_test(tc1_1, create_matrix_4);
  tcase_add_test(tc1_1, eq_matrix_1);
  tcase_add_test(tc1_1, eq_matrix_2);
  tcase_add_test(tc1_1, eq_matrix_3);
  tcase_add_test(tc1_1, eq_matrix_4);
  tcase_add_test(tc1_1, eq_matrix_5);
  tcase_add_test(tc1_1, sum_matrix_1);
  tcase_add_test(tc1_1, sum_matrix_2);
  tcase_add_test(tc1_1, sum_matrix_3);
  tcase_add_test(tc1_1, sum_matrix_5);
  tcase_add_test(tc1_1, sub_matrix_1);
  tcase_add_test(tc1_1, sub_matrix_2);
  tcase_add_test(tc1_1, sub_matrix_3);
  tcase_add_test(tc1_1, sub_matrix_4);
  tcase_add_test(tc1_1, mult_number_1);
  tcase_add_test(tc1_1, mult_number_2);
  tcase_add_test(tc1_1, mult_number_3);
  tcase_add_test(tc1_1, mult_number_4);
  tcase_add_test(tc1_1, mult_matrix_1);
  tcase_add_test(tc1_1, mult_matrix_2);
  tcase_add_test(tc1_1, mult_matrix_3);
  tcase_add_test(tc1_1, mult_matrix_4);
  tcase_add_test(tc1_1, mult_matrix_5);
  tcase_add_test(tc1_1, transpose_1);
  tcase_add_test(tc1_1, transpose_2);
  tcase_add_test(tc1_1, calc_complements);
  tcase_add_test(tc1_1, determinant);
  tcase_add_test(tc1_1, inverse);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
