/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 04:08:14 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

static int n1;
static int n2;

int main(int argc, char *argv[]) {
  // work with static variable's addresses
  printf("n1 = %d\n", n1);
  printf("n2 = %d\n", n2);

  int *p1 = &n1;
  *p1 = 20;
  *(p1 + 1) = 10;

  int *p2 = &n2;

  printf("n1 = %d\n", n1);
  printf("n2 = %d\n", n2);

  printf("offset = %ld\n", p1 - p2);
  printf("n1 ea = %p\n", p1);
  printf("n2 ea = %p\n", p2);

  printf("\n--------\n\n");

  // work with fixed-sized arrays
  int a[10] = {1, 2, 3, 4, 5};
  // print array elements to see their values
  for (int i = 0; i < 10; i++) {
    printf("a[%d]: %d\n", i, a[i]);
  }
  // https://stackoverflow.com/questions/2528318/how-come-an-arrays-address-is-equal-to-its-value-in-c
  // The name of an array usually evaluates to the address of the first element
  // of the array, so array and &array have the same value (but different types,
  // so array+1 and &array+1 will not be equal if the array is more than 1
  // element long).
  printf("*a: %d\n", *a);
  printf("a: %p\n", a);
  printf("&a: %p\n", &a);
  printf("*(&a): %p\n", *(&a));
}
