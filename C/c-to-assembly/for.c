/*
 * In The Name Of God
 * ========================================
 * [] File Name : for.c
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed 21 Jan 2015 01:04:12 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j;
	for (i = 0; i < 1000; i++) {
		j = i * 5;
		printf("The answer is %d\n", j);
	}
	return 0;
}

/*
 * for:
 *	<condition to evaluate for loop counter value>
 *	jxx forcode
 *	jmp end
 * forcode:
 *	<for loop code to execute>
 *	<increment for loop counter>
 *	jmp for
 * end:
*/
