/*
 * In The Name Of God
 * ========================================
 * [] File Name : asprintf.c
 *
 * [] Creation Date : 01-02-2015
 *
 * [] Last Modified : Sun 01 Feb 2015 07:59:50 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef HAVE_ASPRINTF
#define HAVE_ASPRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int asprintf(char **str, const char *fmt, ...)
	__attribute__((format(printf, 2, 3)));

int asprintf(char **str, const char *fmt, ...)
{
	va_list argp;
	int len = 0;
	/* temp array just for finding size */
	char one_char[1];

	/* finding size */
	va_start(argp, fmt);
	len = vsnprintf(one_char, 1, fmt, argp);
	if (len < 1) {
		fprintf(stderr, "An encoding error occured.");
		fprintf(stderr, "Setting the input pointer to NULL.\n");
		*str = NULL;
		return len;
	}
	va_end(argp);

	/* allocating space for string */
	*str = malloc(len + 1);

	/* printing string to allocated space */
	if (!str) {
		fprintf(stderr, "Couldn't allocate %i bytes.\n", len + 1);
		return -1;
	}
	va_start(argp, fmt);
	vsnprintf(*str, len + 1, fmt, argp);
	va_end(argp);
	return len;
}

#endif

#ifndef Test_asprintf

int main(int argc, char *argv[])
{
	char *s;
	asprintf(&s, "Hello, %s.", "-Reader-");
	printf("%s\n", s);

	free(s);

	asprintf(&s, "%c", '\0');
	printf("blank string: [%s]\n", s);

	free(s);

	int i = 0;
	asprintf(&s, "%i", i++);
	printf("Zero: %s\n", s);
	
	free(s);
}

#endif
