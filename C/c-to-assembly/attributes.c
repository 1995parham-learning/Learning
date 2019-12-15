/*
 * In The Name Of God
 * ========================================
 * [] File Name : attributes.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun 08 Feb 2015 11:55:22 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

/* Variables Attribute */
#ifdef __MACH__
int parham __attribute__((section("PARHAM, .parham"))) = 137303;
#else
int parham __attribute__((section(".parham"))) = 137303;
#endif

int main(int argc, char *argv[]) {
  printf("Hello world of attributes... %d\n", parham);
}
