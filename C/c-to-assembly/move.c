/*
 * In The Name Of God
 * ========================================
 * [] File Name : test.c
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Fri 23 Jan 2015 10:46:04 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

char getch()
{
	return -1;
}

int main(int argc, char *argv[])
{
	char a = getch();
	printf("%u\n", a);
	printf("%d\n", a);

	unsigned char b = getch();
	printf("%u\n", b);
	printf("%d\n", b);
}
