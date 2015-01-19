/*
 * In The Name Of God
 * ========================================
 * [] File Name : c-to-assembly.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 19 Jan 2015 11:44:30 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

struct test_struct {
	int a;
	int b;
};

int f(int a, int b, int c);

int A = 10;

static int S = 15;

int main(long argc)
{
	struct test_struct s;
	s.a = 10;
	s.b = 20;

	A += 20;

	printf("%p\n", &A);
	printf("%p\n", &S);

	int i = 0;
	for(i = 0; i < 10; i++)
		;

	f(1, 2, 3);
}

int f(int a, int b, int c)
{
	A += 30;
	return a * b * c;
}
