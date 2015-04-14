/*
 * In The Name Of God
 * ========================================
 * [] File Name : hello.c
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 09:46:41 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include "hello.h"

int hello(const char *name)
{
	return printf("Hello Mr.%s\n", name);
}
