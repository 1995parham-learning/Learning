/*
 * In The Name Of God
 * ========================================
 * [] File Name : parallel-for.c
 *
 * [] Creation Date : 07-03-2015
 *
 * [] Last Modified : Sat 07 Mar 2015 11:26:29 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

#define pfor(...) _Pragma("omp parallel for") for (__VA_ARGS__)

int main(int argc, char *argv[]) {
  int i = 0;

  pfor(i = 0; i < 100; i++) {
    int j = 0;

    printf("%i\n", i);
    printf("%i\n", j);
    j++;
    printf("%i\n", j);
  }
}
