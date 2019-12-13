/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 01-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;
  double sum1 = 0.0;
  double sum2 = 0.0;

  for (i = 1; i < 1024; i++) {
    sum1 += 1.0 / i;
  }
  printf("%g\n", sum1);
  for (i = 1024; i > 0; i--) {
    sum2 += 1.0 / i;
  }
  printf("%g\n", sum2);
}
