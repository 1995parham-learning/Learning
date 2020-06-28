/* 
 * In The Name Of God
 * ========================================
 * [] File Name : nothing-c.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 12 Jan 2015 10:04:05 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

int hello_writer(const char *, int);

int main(int argc, char *argv[])
{
	int retval;
	char *str = "This is a test\nBut i love it !!!\nWhat ?? it's assembly ?!?!\n";
	
	retval = hello_writer(str, strlen(str));
	printf("Return: %d\n", retval);
}
