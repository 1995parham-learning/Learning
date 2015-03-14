/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 06-03-2015
 *
 * [] Last Modified : Sat 14 Mar 2015 09:05:27 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>

#include "fstr.h"

int main(int argc, char *argv[])
{
	struct fstr *string = fstr_new("Hello world of Assembly");

	fstr_show(string);

	struct fstr *sub_string = fstr_cpy(string, 0, 10);

	fstr_show(sub_string);

	fstr_free(string);

	fstr_show(sub_string);

	fstr_free(sub_string);
}
