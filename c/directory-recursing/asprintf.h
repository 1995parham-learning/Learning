/*
 * In The Name Of God
 * ========================================
 * [] File Name : asprintf.h
 *
 * [] Creation Date : 15-02-2015
 *
 * [] Last Modified : Sun 15 Feb 2015 01:51:37 AM IRST
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
