/*
 * In The Name Of God
 * ========================================
 * [] File Name : flonum.c
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Fri 23 Jan 2015 09:31:43 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

float A = 10.;

int main(int argc, char *argv[])
{
	A *= 10;
	printf("%g\n", A);

	A += 10.5;
	printf("%g\n", A);
}
