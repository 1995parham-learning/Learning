/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 11-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = 0;
  printf("%ld\n", sizeof(a++));
  printf("%d\n", a);
}
