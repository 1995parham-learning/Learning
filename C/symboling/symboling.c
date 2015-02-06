/*
 * In The Name Of God
 * ========================================
 * [] File Name : symboling.c
 *
 * [] Creation Date : 06-02-2015
 *
 * [] Last Modified : Fri 06 Feb 2015 12:07:35 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

extern char p;

int main(int argc, char *argv[])
{
	printf("%p\n", &p);
	

	FILE *fout = stdout;
	fprintf(fout, "Hello world of symboling\n");
}
