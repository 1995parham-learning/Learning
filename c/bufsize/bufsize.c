/*
 * In The Name Of God
 * ========================================
 * [] File Name : bufsize.c
 *
 * [] Creation Date : 04-02-2015
 *
 * [] Last Modified : Wed 04 Feb 2015 03:41:26 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>
#include <stdio_ext.h>

int main(int argc, char *argv[]) {
  FILE *f;
  int bufsize;

  f = fopen("test.txt", "wb");
  if (f == NULL) {
    perror("fopen failed\n");
    return -1;
  }

  bufsize = __fbufsize(f);

  printf("The buffer size is %d\n", bufsize);

  return 0;
}
