/*
 * In The Name Of God
 * ========================================
 * [] File Name : derivative.c
 *
 * [] Creation Date : 04-02-2015
 *
 * [] Last Modified : Wed Feb  4 13:28:14 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

double f(double x) { return x * x * x; }

double derivative(double (*f)(double), double x0, int order) {
  const double delta = 1.0e-6;
  if (order == 1) {
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);

    return (y2 - y1) / (x2 - x1);
  } else if (order == 2) {
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = derivative(f, x1, 1);
    double y2 = derivative(f, x2, 1);

    return (y2 - y1) / (x2 - x1);
  } else {
    printf("order too high error \n");
    return 0;
  }
}

int main(int argc, char *argv[]) {
  printf("f'(2) = %g\n", derivative(f, 2, 1));
  printf("f''(2) = %g\n", derivative(f, 2, 2));
}
