/*
 * In The Name Of God
 * ========================================
 * [] File Name : fib.c
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Thu 08 Jan 2015 08:33:25 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

int fib(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[])
{
	printf("%d\n", fib(5));
}
