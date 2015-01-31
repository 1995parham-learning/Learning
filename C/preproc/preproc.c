/*
 * In The Name Of God
 * ========================================
 * [] File Name : preproc.c
 *
 * [] Creation Date : 31-01-2015
 *
 * [] Last Modified : Sat 31 Jan 2015 06:57:32 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

#define Peval(cmd)				\
	do {					\
		printf(#cmd ": %g\n", cmd);	\
	} while(0)				\

#define ListGen(name, ...)			\
	double *name ## _list = (double [])	\
			{__VA_ARGS__};		\

int main(int argc, char *argv[])
{
	double *plist = (double []){1, 2, 3};
	double list[] = {1, 2, 3};
	
	Peval(sizeof(plist) / (sizeof(double) + 0.0));
	Peval(sizeof(list) / (sizeof(double) + 0.0));

	ListGen(hello, 1.1, 2.2, 3.3, 4.4);

	Peval(hello_list[0]);
}
