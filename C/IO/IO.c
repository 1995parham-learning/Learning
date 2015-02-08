/*
 * In The Name Of God
 * ========================================
 * [] File Name : IO.c
 *
 * [] Creation Date : 16-01-2015
 *
 * [] Last Modified : Sun 08 Feb 2015 11:15:16 AM IRST
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
	c[0] = '\0';
	
	char str[1024];

	scanf("%[1]", c);
	printf("%s\n", c);

	scanf("%[^:]", str);
	printf("%s\n", str);
}
