/*
 * In The Name Of God
 * ========================================
 * [] File Name : IO.c
 *
 * [] Creation Date : 16-01-2015
 *
 * [] Last Modified : Fri Jan 16 19:00:37 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/*
	 * change it to char *c and test .... HAVE FUN ;-)))
	 * when change to char *c it's size in unspecified then
	 * every things goes wrong.
	*/
	char c[10];

	scanf("%[1]", c);
	printf("%s\n", c);
}
