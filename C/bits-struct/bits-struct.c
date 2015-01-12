/*
 * In The Name Of God
 * ========================================
 * [] File Name : bits-struct.c
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Thu 08 Jan 2015 08:45:59 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

struct attrs {
	unsigned char p1	: 1;
	unsigned char p2	: 1;
	unsigned char p3	: 1;
	unsigned char p4	: 5;
};

int main(int argc, char *argv[])
{
	printf("%ld\n", sizeof(struct attrs));
	
	struct attrs attrs;
	attrs.p1 = 1;
	attrs.p2 = 1;
	attrs.p3 = 1;
	attrs.p4 = 31;
	printf("%X\n", attrs);
}
