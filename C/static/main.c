/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 04:21:34 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

void func() {
  static int x = 1;
  printf("%d\n", x);
  x *= 2;
}

int main(int argc, char *argv[]) {
  func();
  func();
  func();
}
