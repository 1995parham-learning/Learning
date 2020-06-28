/*
 * In The Name Of God
 * ========================================
 * [] File Name : fstr.h
 *
 * [] Creation Date : 06-03-2015
 *
 * [] Last Modified : Fri 06 Mar 2015 06:50:18 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef FSTR_H
#define FSTR_H

#include <stdio.h>
#include <stdlib.h>

struct fstr {
	char *data;
	size_t start, end;
	int *refs;
};

struct fstr *fstr_new(const char *str);
struct fstr *fstr_cpy(const struct fstr *in, size_t start, size_t len);
void fstr_show(const struct fstr *in);
void fstr_free(struct fstr *in);

#endif
