/*
 * In The Name Of God
 * ========================================
 * [] File Name : Sleep-Fork.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun Feb  8 08:49:16 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int p = fork();

  if (p == 0) {
    printf("Ok\n");
    sleep(10);
  } else {
    printf("hey!\n");
    sleep(1);
  }
  printf("done!\n");
  _exit(0);
  return 0;
}
