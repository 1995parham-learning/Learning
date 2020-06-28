/*
 * In The Name Of God
 * ========================================
 * [] File Name : threads.c
 *
 * [] Creation Date : 13-01-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2017 Parham Alvani.
 */
#ifdef __STDC_NO_THREADS__
#error "No threading support"
#else
#include <threads.h>
#endif
#include <stdio.h>

int run(void *arg) { printf("Hello world of C11 threads."); }

int main(int argc, const char *argv[]) {
  thrd_t thread;

  thrd_create(&thread, run, NULL);
}
