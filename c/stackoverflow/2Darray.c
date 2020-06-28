/*
 * In The Name Of God
 * ========================================
 * [] File Name : 2Darray.c
 *
 * [] Creation Date : 13-02-2015
 *
 * [] Last Modified : Fri 13 Feb 2015 02:57:37 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */

/*
 * program to allocate a 2d array and fill
 * it with 0's and then print it.
 */

#include <stdio.h>
#include <stdlib.h>

struct stuff {
  int **arr;
};

int main(int argc, char *argv[]) {
  struct stuff x;

  /* loop counters */
  int i, j;

  /* allocate 2d array */
  x.arr = malloc(sizeof(int *) * 4);
  for (i = 0; i < 4; i++)
    x.arr[i] = malloc(sizeof(int) * 4);

  /* intialize 2d array to 0 */
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      x.arr[i][j] = 0;

  /* print 2d array */
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      printf("arr[%d][%d] = %d\n", i, j, x.arr[i][j]);
    free(x.arr[i]);
  }
  free(x.arr);
  return 0;
}
