/*
 * In The Name Of God
 * ========================================
 * [] File Name : non-blocking.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Sun 15 Mar 2015 01:32:37 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void die(const char *msg) {
  perror(msg);
  exit(1);
}

/*
 * Tests :
 * 1) ./non-blocking =>
 * fgets() [Like I say..]: Resource temporarily unavailable
 * 2) echo Hello | ./non-blocking =>
 * Hello : No way !!!
 */

int main(int argc, char *argv[]) {
  int flags = fcntl(0, F_GETFL);

  if (flags == -1)
    die("fcntl(): F_GETFL");

  flags |= O_NONBLOCK;

  if (fcntl(0, F_SETFL, flags) == -1)
    die("fcntl(): F_SETFL");

  char buffer[1024];

  if (!fgets(buffer, 1024, stdin))
    die("fgets() [Like I say..]");
  buffer[strlen(buffer) - 1] = 0;
  printf("%s : No way !!!\n", buffer);
}
