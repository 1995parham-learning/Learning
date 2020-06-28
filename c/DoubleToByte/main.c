/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 06-08-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  double d = 10;
  void *d_pointer = &d;

  for (int i = 0; i < sizeof(d); i++) {
    printf("0x%x\n", *((char *)d_pointer + i));
  }
}

// https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/
// Single precision	1(31st bit)	8(30-23)	23(22-0)	127
// Double precision	1(63rd bit)	11(62-52)	52(51-0)	1023

// 10.0
// 10 = 1010
// 0 = 0
// 1010.0 => 1.0100 * 2^3
// 0 10000000010 010...
// 0100 = 4
// 0000 = 0
// 0010 = 2
// 0100 = 4
// ...
