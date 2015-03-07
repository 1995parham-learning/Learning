/*
 * In The Name Of God
 * ========================================
 * [] File Name : DataToFile.c
 *
 * [] Creation Date : 07-03-2015
 *
 * [] Last Modified : Sat 07 Mar 2015 05:33:01 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 120

int main(int argc, char *argv[])
{
	char *cArray[MAX_STR_LEN] = {"example", "dinosaurs" };
	char cInput[MAX_STR_LEN] = {0};
	int y = 0;
	FILE *pWrite;

	printf("Type your message:\n");
	fgets(cInput, MAX_STR_LEN, stdin);
	cInput[strlen(cInput) - 1] = 0;     /* strip newline from input */
	printf("\nInitialised string array:\n");

	while (cArray[y]) {
		char *ptr = cInput;

		while ((ptr = strstr(ptr, cArray[y])) != NULL) {
			char *ep = strchr(ptr, ' ');

			if (ep)
				*ep = 0;	/* null-terminate at space */
			printf("%s\n", ptr);
			pWrite = fopen("test.txt", "a");
			if (pWrite != NULL) {
				fprintf(pWrite, "%s\n", ptr++);
				fclose(pWrite);
			} else {
				/* there is a file i/o error */
				goto ErrorHandler;
			}
			if (ep)
				*ep = ' ';	/* put the space back      */
		}
		y++;
	}
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Timestamp: %s", asctime(timeinfo));

	exit(EXIT_SUCCESS); /* exit program normally */

ErrorHandler:
	perror("The following error occurred");
	exit(EXIT_FAILURE); /* exit program with error */
}
