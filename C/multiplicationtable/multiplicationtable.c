/*
 * In The Name Of God
 * ========================================
 * [] File Name : multiplicationtable.c
 *
 * [] Creation Date : 17-03-2015
 *
 * [] Last Modified : Tue 17 Mar 2015 08:25:25 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <apop.h>

int main(int argc, char *argv[]) {
  int i;
  gsl_matrix *m;

  m = gsl_matrix_alloc(20, 15);
  gsl_matrix_set_all(m, 1);

  for (i = 0; i < m->size1; i++) {
    /* the Apop_matrix_row macro to pull single row */
    Apop_matrix_row(m, i, row);
    gsl_vector_scale(row, i + 1);
  }

  for (i = 0; i < m->size2; i++) {
    Apop_matrix_col(m, i, col);
    gsl_vector_scale(col, i + 1);
  }

  apop_matrix_show(m);
  gsl_matrix_free(m);
}
