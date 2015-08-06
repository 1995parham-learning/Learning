/*
 * In The Name Of God
 * ========================================
 * [] File Name : DoubleToByte.c
 *
 * [] Creation Date : 06-08-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	double A = 10;
	void *A_pointer = &A;
	for (int i = 0; i < sizeof(A); i++) {
		printf("%x\n", *((char *)A_pointer + i));
	}
}
