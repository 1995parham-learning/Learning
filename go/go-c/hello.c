/*
 * In The Name Of God
 * ========================================
 * [] File Name : hello.c
 *
 * [] Creation Date : 22-12-2017
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2017 Parham Alvani.
 */
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void say_hello(const char *name) {
	printf("Hello %s\n", name);
}

static void signal_handler(int signo) {
	say_hello("SIGALRM");
}

void setup_signal_handler() {
	struct sigaction sig;

	sig.sa_handler = signal_handler;
	sig.sa_flags   = SA_ONSTACK;
	sigemptyset(&sig.sa_mask);
	int retval = sigaction(SIGALRM, &sig, NULL);

	if(retval != 0)
	{
		fputs("set signal failed\n", stderr);
		return;
	}
	printf("SIGALRM is ready\n");
}

void setup_timer() {
	/* set time interval */
	struct itimerval timer;
	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 0;
	timer.it_interval = timer.it_value;

	int retval = setitimer(ITIMER_REAL, &timer, NULL);

	if(retval != 0) {
		fputs("set timer failed\n", stderr);
		return;
	}

	printf("timer is ready\n");
}
