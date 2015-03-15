/*
 * In The Name Of God
 * ========================================
 * [] File Name : subsets.c
 *
 * [] Creation Date : 15-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 12:00:40 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

/*
 * set: S
 * set size: n
 * subset size: k
 * subset: t
 * S = {..., s, ...}
 *
 * http://stackoverflow.com/questions/4555565/
 *	generate-all-subsets-of-size-k-from-a-set
*/
void subset_r(const int *S, int n, int k, int *t, int index, int s)
{
	int i = 0;

	if (index == k) {
		for (i = 0; i < k; i++)
			printf("%d ", t[i]);
		printf("\n");
	} else {
		for (i = s; i < n; i++) {
			t[index] = S[i];
			subset_r(S, n, k, t, index + 1, i + 1);
		}
	}
}

void subset(const int *S, int n, int k)
{
	int *t;
	
	t = malloc(k * sizeof(int));
	subset_r(S, 5, 2, t, 0, 0);
	free(t);

}

int main(int argc, char *argv[])
{
	int s[] = {1, 2, 3, 4, 5};

	subset(s, 5, 2);
}
