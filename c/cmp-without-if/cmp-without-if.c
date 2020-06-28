/*
 * In The Name Of God
 * ========================================
 * [] File Name : cmp-without-if.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun 08 Feb 2015 12:48:14 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <math.h>
#include <stdio.h>

double max(double a, double b) { return 1 / 2. * (a + b + fabs(a - b)); }

int main(int argc, char *argv[]) {
  double b = 0.01242;
  double a = 0.04231;

  printf("%g\n", max(a, b));

  int c = ceil(max(a, b) / b);
  c = (c + 1) % c;
  /* c should be 1 if a > b or else it should be 0 */
  printf("%d\n", c);
}
