/*
 * In The Name Of God
 * ========================================
 * [] File Name : ifthen.c
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed 21 Jan 2015 12:20:05 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 100;
	int b = 25;
	
	if (a > b)
		printf("The higher value is %d\n", a);
	else
		printf("The higher value is %d\n", b);
	return 0;
}
