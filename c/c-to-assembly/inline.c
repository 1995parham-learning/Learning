/*
 * In The Name Of God
 * ========================================
 * [] File Name : inline.c
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed Jan 21 09:18:08 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = 100;

  printf("%d\n", a);
  __asm__("xorl	%1, %1\n" : "=r"(a) : "r"(a));
  printf("%d\n", a);
}
