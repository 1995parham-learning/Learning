/*
 * In The Name Of God
 * ========================================
 * [] File Name : exiting.c
 *
 * [] Creation Date : 28-01-2015
 *
 * [] Last Modified : Wed 28 Jan 2015 04:49:00 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void wail(void)
{
	fprintf(stderr, "0000ooooooo.\n");
}

void on_death(void)
{
	for (int i = 0; i < 4; i++)
		fprintf(stderr, "I am dead.\n");
}

_Noreturn void the_count(void)
{
	for (int i = 5; i --> 0;) {
		printf("%i\n", i);
		sleep(1);
	}
	quick_exit(1);
	_Exit(1);
	exit(1);
}

int main(int argc, char *argv[])
{
	at_quick_exit(wail);
	atexit(on_death);
	the_count();
}
