/*
 * In The Name Of God
 * ========================================
 * [] File Name : grid.c
 *
 * [] Creation Date : 16-02-2015
 *
 * [] Last Modified : Mon 16 Feb 2015 02:09:03 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned char ch;
	/* Our 2D array */
	int **C;
	int N, i, j;
	char filenamein[] = "input.txt";

	fp = fopen(filenamein, "r");

	N = (ch = fgetc(fp)) - '0';

	/* Initialize Grid, set all cells to 0 */
	C = malloc(N * sizeof(int *));
	for (i = 0; i < N; i++)
		C[i] = malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			C[i][j] = 0;

	i = 0;
	j = 0;
	do {
		ch = fgetc(fp);
		if (ch != ' ' && ch != '\n') {
			C[i][j] = ch - '0';
			j++;
			i += j / N;
			j %= N;
		}
	} while (i < N && j < N);

	/* Print 2D Array: */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
	fclose(fp);
}
