/*
 * In The Name Of God
 * ========================================
 * [] File Name : fstr.c
 *
 * [] Creation Date : 06-03-2015
 *
 * [] Last Modified : Fri 06 Mar 2015 06:59:48 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fstr.h"

struct fstr *fstr_new(const char *str) {
  struct fstr *new;

  new = malloc(sizeof(struct fstr));
  *new = (struct fstr){.start = 0, .refs = malloc(sizeof(int))};
  new->data = malloc(strlen(str) + 1);
  strcpy(new->data, str);
  new->data[strlen(str)] = 0;
  new->end = strlen(str);
  *new->refs = 1;
  return new;
}

struct fstr *fstr_cpy(const struct fstr *in, size_t start, size_t len) {
  struct fstr *new;

  new = malloc(sizeof(struct fstr));
  *new = *in;
  new->start += start;
  if (in->end > new->start + len)
    new->end = new->start + len;
  (*new->refs)++;
  return new;
}

void fstr_free(struct fstr *in) {
  (*in->refs)--;
  if (!*in->refs) {
    free(in->data);
    free(in->refs);
  }
  free(in);
}

void fstr_show(const struct fstr *in) {
  printf("%.*s\n", (int)(in->end - in->start), &(in->data[in->start]));
}
