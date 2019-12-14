/*
 * In The Name Of God
 * ========================================
 * [] File Name : TwinPrimes.c
 *
 * [] Creation Date : 08-02-2015
 *
 * [] Last Modified : Sun Feb  8 08:02:31 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int low, high, n, count, i;

  scanf("%d %d", &low, &high);

  count = 0;
  n = 0;

  if (low <= 3)
    count++;

  while (n < low)
    n += 6;

  while (n < high) {
    i = 1;
    int flag = 0;

    while (i * i < n + 1) {
      i++;
      if ((n - 1) % i == 0 || (n + 1) % i == 0)
        flag = 1;
    }
    if (!flag)
      count++;
    n += 6;
  }
  printf("the number of twin primes between %d and %d are %d", low, high,
         count);
}
