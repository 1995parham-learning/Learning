/* 
 * In The Name Of God
 * ========================================
 * [] File Name : c.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Sun 21 Dec 2014 01:46:17 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <string.h>

int parham_print(char* string, int len);

int main(int argc, char* argv[]){
	char* string = "Hello world, Are you assembly ????\n";
	printf("%d\n", parham_print(string, strlen(string)));
}
