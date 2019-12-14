/*
 * In The Name Of God
 * ========================================
 * [] File Name : erf.c
 *
 * [] Creation Date : 04-01-2015
 *
 * [] Last Modified : Sun 04 Jan 2015 10:29:13 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("The integral of Normal(0, 1) distribution"
         "bettween -1.96 and 1.96 is %g\n",
         erf(1.96 * sqrt(1 / 2.)));
}
