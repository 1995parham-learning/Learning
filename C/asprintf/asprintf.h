/*
 * In The Name Of God
 * ========================================
 * [] File Name : asprintf.h
 *
 * [] Creation Date : 06-03-2015
 *
 * [] Last Modified : Fri 06 Mar 2015 12:31:42 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef ASPRINTF_H
#define ASPRINTF_H

/*
 * __printf(string-index, first-to-check)
 * is preferred over
 * __attribute__((format(printf, string-index, first-to-check)))
*/

int asprintf(char **str, const char *fmt, ...)
	__attribute__((format(printf, 2, 3)));


#endif
