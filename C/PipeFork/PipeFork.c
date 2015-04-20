/*
 * In The Name Of God
 * ========================================
 * [] File Name : PipeFork.c
 *
 * [] Creation Date : 20-04-2015
 *
 * [] Last Modified : Mon 20 Apr 2015 11:52:32 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int c2p[2];
	int i;
	int stat;

	for (i = 1; i < argc; i++) {
		pipe(c2p);
		if (fork() == 0) {
			/* child code */
			if (fork() == 0) {
				/* grandchild code */
				if (execlp(argv[i], argv[i], NULL) == -1)
					exit(errno);
			}
			wait(&stat);
			write(c2p[1], &stat, sizeof(stat));
			exit(0);
		}
		read(c2p[0], &stat, sizeof(int));
		if (stat != 0)
			printf("Not succsesful: %s %d\n", argv[i], stat);
		else
			printf("Succes! %s\n", argv[i]);
	}
}
