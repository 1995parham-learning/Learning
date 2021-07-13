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

// gnu libc finally supports iso threads in 2.28.
// in order to use them, your application must linked against pthread.

#ifdef __STDC_NO_THREADS__
#error "No threading support"
#else
#include <threads.h>
#endif
#include <stdio.h>

int run(void *arg) {
  printf("hello world of c11 threads.\n");
  return 0;
}

int main(int argc, const char *argv[]) {
  thrd_t thread;

  thrd_create(&thread, run, NULL);

  thrd_join(thread, NULL);
}
