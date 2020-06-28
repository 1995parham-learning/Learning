/*
 * In The Name Of God
 * ========================================
 * [] File Name : Generic.c
 *
 * [] Creation Date : 06-03-2015
 *
 * [] Last Modified : Fri 06 Mar 2015 04:04:41 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Get the name of a type */
#define typename(x)                                                            \
  _Generic((x),			\
	_Bool: "_Bool",					\
	unsigned char: "unsigned char",			\
        char: "char",					\
	signed char: "signed char",			\
	short int: "short int",				\
    	unsigned short int: "unsigned short int",	\
        int: "int",					\
	unsigned int: "unsigned int",			\
     	long int: "long int",				\
	unsigned long int: "unsigned long int",		\
	long long int: "long long int",			\
        float: "float",					\
	double: "double",				\
  	long double: "long double",			\
	char *: "pointer to char",			\
       	void *: "pointer to void",			\
	int *: "pointer to int",			\
      	default: "other")

void test_typename(void) {
  size_t s = 0;
  intmax_t i = 0;
  int ai[3] = {0};

  printf("size_t is '%s'\n", typename(s));
  printf("intmax_t is '%s'\n", typename(i));
  printf("character constant is '%s'\n", typename('0'));
  printf("0x7FFFFFFF is '%s'\n", typename(0x7FFFFFFF));
  printf("0xFFFFFFFF is '%s'\n", typename(0xFFFFFFFF));
  printf("0x7FFFFFFFU is '%s'\n", typename(0x7FFFFFFFU));
  printf("array of int is '%s'\n", typename(ai));
}

int main(int argc, char *arg[]) { test_typename(); }
