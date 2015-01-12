/*
 * In The Name Of God
 * ========================================
 * [] File Name : non-blocking.c
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 04:06:01 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int flags = fcntl(0, F_GETFL);

	if (flags == -1)
		die("fcntl(): F_GETFL");

	flags |= O_NONBLOCK;

	if (fcntl(0, F_SETFL, flags) == -1)
		die("fcntl(): F_SETFL");

	char buffer[1024];

	if (fgets(buffer, 1024, stdin) == NULL)
		die("scanf(): Like i said !!!");
	buffer[strlen(buffer) - 1] = 0;
	printf("%s : No way !!!\n", buffer);
}
