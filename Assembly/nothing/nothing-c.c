/* 
 * In The Name Of God
 * ========================================
 * [] File Name : nothing-c.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 12 Jan 2015 09:45:34 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

int hello_writer(const char *, int);

int main(int argc, char *argv[])
{
	char *TEST = "This is a test\nBut i love it !!!\nWTF ?? it's assembly ?!?!\n";
	int ret;
	ret = hello_writer(TEST, strlen(TEST));
	printf("Return: %d\n", ret);
}
