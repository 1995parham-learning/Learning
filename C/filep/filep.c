/*
 * In The Name Of God
 * ========================================
 * [] File Name : filep.c
 *
 * [] Creation Date : 07-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>

FILE *my_open(const char *name)
{
	return fopen(name, "r");
}

int main(int argc, char *argv[])
{
	my_open("filep.c");
}
