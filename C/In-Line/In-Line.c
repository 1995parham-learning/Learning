/*
 * In The Name Of God
 * ========================================
 * [] File Name : In-Line.c
 *
 * [] Creation Date : 29-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  int num;
  printf("Absolute Value\n");
  printf("Please enter a number: ");
  scanf("%d", &num);

  if (num > 0) {
    int absVal = num;
  } else {
    int absVal = -num;
  }

  {
    int absVal;
    printf("The absolute value of %d is %d.\n\n", num, absVal);
  }
}
