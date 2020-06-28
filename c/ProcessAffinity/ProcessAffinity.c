/*
 * In The Name Of God
 * ========================================
 * [] File Name : ProcessAffinity.c
 *
 * [] Creation Date : 07-03-2015
 *
 * [] Last Modified : Sat 07 Mar 2015 05:22:05 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#define _GNU_SOURCE

#include <sched.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  cpu_set_t set;
  int ret, i;

  CPU_ZERO(&set);
  ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
  if (ret == -1)
    perror("sched_getaffinity()");

  /*
   * You can use CPU_SETSIZE in here but
   * I want to use 10 instead.
   */
  for (i = 0; i < 10; i++) {
    int cpu = CPU_ISSET(i, &set);

    printf("cpu=%i is %s\n", i, cpu ? "set" : "unset");
  }
}
