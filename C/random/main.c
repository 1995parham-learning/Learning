/*
 * In The Name of God
 * =======================================
 * [] File Name : main.c
 *
 * [] Creation Date : 13-12-2019
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2019 Parham Alvani.
*/

#include <stdio.h>
#include <stdlib.h>

int random_walk(void);

int main(int argc, const char *argv[]) {
  for (int i = 0; i < 50; i++) {
    printf("%d\n", random_walk());
  }
}

int random_walk(void) {
  static char statebuf[255];
  static int s = 0;
  if (s == 0) {
    initstate(0, statebuf, 255);
    s++;
  }

  return random() % 4;
}
