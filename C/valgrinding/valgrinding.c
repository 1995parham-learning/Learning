/*
 * In The Name Of God
 * ========================================
 * [] File Name : valgrinding.c
 *
 * [] Creation Date : 05-02-2015
 *
 * [] Last Modified : Thu 05 Feb 2015 05:42:33 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSize(int *array)
{
	int i = 0;

	while (1) {
		if (array[i] == -1)
			return i;
		else
			i++;
	}
}

int main(int argc, char *argv[])
{
	int *array;

	array = malloc(sizeof(int) * 5);
	memset(array, 0, 5 * sizeof(int));
	array[4] = -1;
	printf("\nsize = %d\n", getSize(array));
	free(array);
	return 0;
}
