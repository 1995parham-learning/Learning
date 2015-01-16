/*
 * In The Name Of God
 * ========================================
 * [] File Name : Fork.c
 *
 * [] Creation Date : 16-01-2015
 *
 * [] Last Modified : Fri 16 Jan 2015 11:14:56 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();

	if (pid == 0) {
		printf("i am CHILD ....\n");
		return -1;
	} else {
		int returnValue;

		if (wait(&returnValue) < 0)
			perror("wait() failed\n");
		printf("child proccess id is : %d\n", pid);
		printf("child proccess is die(%d) ", WIFEXITED(returnValue));
		printf("with return value %d ", (signed char)
				WEXITSTATUS(returnValue));
		printf("we are sorry ....\n");
	}
}
