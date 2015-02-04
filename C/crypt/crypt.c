/*
 * In The Name Of God
 * ========================================
 * [] File Name : crypt.c
 *
 * [] Creation Date : 04-02-2015
 *
 * [] Last Modified : Wed 04 Feb 2015 04:48:42 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#define _BSD_SOURCE
#define _XOPEN_SOURCE

#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "common.h"

int main(int argc, char *argv[])
{
	char *username, *password, *encrypted, *p;
	struct passwd *pwd;
	struct spwd *spwd;
	bool authOk;
	size_t len;
	long lnmax;

	lnmax = sysconf(_SC_LOGIN_NAME_MAX);
	if (lnmax == -1)
		lnmax = 256;

	username = malloc(lnmax);
	if (username == NULL)
		sdie("malloc");

	printf("Username :");
	fflush(stdout);
	if (fgets(username, lnmax, stdin) == NULL)
		udie("Please enter the username...");

	len = strlen(username);
	if (username[len - 1] == '\n')
		username[len - 1] = '\0';

	pwd = getpwnam(username);
	if (pwd == NULL)
		udie("couldn't get password record");
	spwd = getspnam(username);
	if (spwd == NULL && errno == EACCES)
		udie("no permission to read shadow password file");

	if (spwd != NULL)
		pwd->pw_passwd = spwd->sp_pwdp;

	password = getpass("Password: ");

	encrypted = crypt(password, pwd->pw_passwd);
	for (p = password; *p != '\0';)
		*p++ = '\0';

	if (encrypted == NULL)
		sdie("crypt");

	authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
	if (!authOk)
		udie("Incorrect password\n");
	
	printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);

	/* Now do authenticated work .. */

	return 0;
}
