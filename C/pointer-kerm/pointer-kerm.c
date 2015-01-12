/*
 * In The Name Of God
 * ========================================
 * [] File Name : pointer-kerm.c
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

int main(int argc, char *argv[])
{
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
}
