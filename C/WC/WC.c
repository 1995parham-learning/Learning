/*
 * In The Name Of God
 * ========================================
 * [] File Name : WC.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun Feb  8 07:46:49 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int out = 1;
  int in = 1;
  char **arr2D;
  int i = 0;

  arr2D = malloc(out * sizeof(char *));
  for (i = 0; i < out; i++)
    arr2D[i] = malloc(in * sizeof(char));

  while (!feof(stdin)) {

    scanf("%c", &arr2D[out - 1][in - 1]);

    in++;
    if (arr2D[out - 1][in - 2] == '\n') {
      arr2D[out - 1][in - 2] = '\0';
      out++;
      arr2D = realloc(arr2D, out * sizeof(char *));
      arr2D[out - 1] = NULL;
      in = 1;
    }

    arr2D[out - 1] = realloc(arr2D[out - 1], in * sizeof(char));
  }
  int out2 = 0;

  do {
    printf("%s\n", arr2D[out2++]);
  } while (out2 < out);
  printf("\n");
  return 0;
}
