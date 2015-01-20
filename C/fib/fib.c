/*
 * In The Name Of God
 * ========================================
 * [] File Name : fib.c
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 10:31:48 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

int r_fib(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return r_fib(n - 1) + r_fib(n - 2);
}

long long s_fib(void)
{
	static long long first = 0;
	static long long second = 1;

	long long out = first + second;
	
	first = second;
	second = out;
	return out;
}

int main(int argc, char *argv[])
{
	int n = 0;
	int i = 0;

	scanf("%d", &n);
	
	printf("%d\n", r_fib(n));

	for (i = 0; i < n - 1; i++)
		s_fib();
	printf("%lld\n", s_fib());
}
