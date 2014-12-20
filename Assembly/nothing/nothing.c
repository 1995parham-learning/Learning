/* 
 * In The Name Of God
 * ========================================
 * [] File Name : nothing.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Sun 21 Dec 2014 01:59:44 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>

int hello_writer(const char*, int) __attribute__((stdcall));

int main(int argc, char* argv[]){
	char* TEST = "This is a test\nBut i love it !!!\nWTF ?? it's assembly ?!?!\n";
	int ret;
	ret = hello_writer(TEST, strlen(TEST));
	printf("Return: %d\n", ret);
}
