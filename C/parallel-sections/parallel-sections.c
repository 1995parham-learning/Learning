/*
 * In The Name Of God
 * ========================================
 * [] File Name : parallel-sections.c
 *
 * [] Creation Date : 08-03-2015
 *
 * [] Last Modified : Sun 08 Mar 2015 12:23:28 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
#pragma omp parallel sections
  {
#pragma omp section
    {
      /*
       * Everything in this block happens
       * only in one thread
       */

      unsigned int i = -1;

      printf("Hello world of omp #%u\n", i++);
    }

#pragma omp section
    {
      /*
       * Everything in this block happens
       * only in one other thread
       */
      unsigned int i;

      printf("Hello world of omp #%u\n", i++);
    }
  }
}
