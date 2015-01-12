/*
 * In The Name Of God
 * ========================================
 * [] File Name : malloc.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 04:07:02 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <malloc.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	void *p_block = malloc(100);

	printf("block address : %p\n", p_block);
	printf("sizeof int: %lu\n", sizeof(int));
	printf("sizeof block : %d\n", *((int *)(p_block - 8)));
}
