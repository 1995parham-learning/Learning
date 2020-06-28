/*
 * In The Name Of God
 * ========================================
 * [] File Name : pthread-scheduling.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 05:39:49 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <pthread.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  pthread_attr_t attr;
  int scope;
  int policy;

  pthread_attr_init(&attr);
  if (pthread_attr_getscope(&attr, &scope) != 0)
    perror("pthread_attr_getscope()");

  switch (scope) {
  case PTHREAD_SCOPE_PROCESS:
    printf("PTHREAD_SCOPE_PROCESS\n");
    break;
  case PTHREAD_SCOPE_SYSTEM:
    printf("PTHREAD_SCOPE_SYSTEM\n");
  }

  if (pthread_attr_getschedpolicy(&attr, &policy) != 0)
    perror("pthread_attr_getschedpolicy()");

  switch (policy) {
  case SCHED_FIFO:
    printf("SCHED_FIFO\n");
    break;
  case SCHED_RR:
    printf("SCHED_RR\n");
    break;
  case SCHED_OTHER:
    printf("SCHED_OTHER\n");
    break;
  }
}
