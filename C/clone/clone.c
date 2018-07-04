/*
 * In The Name of God
 * =======================================
 * [] File Name : clone.c
 *
 * [] Creation Date : 04-07-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int fn(void *arg) {
  printf("Hello I am here\n");
}

int main(int argc, char *argv[]) {
  printf("Hello, I am back\n");

  void *s = malloc(1024);

  clone(fn, s + 1024, CLONE_FILES, NULL);
}
