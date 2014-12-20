/* 
 * In The Name Of God
 * ========================================
 * [] File Name : Practical.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Sun 21 Dec 2014 12:53:54 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "Practical.h"

void DieWithUserMessage(const char* message, const char* detail){
	fprintf(stderr, "%s:%s\n", message, detail);
	exit(1);
}
void DieWithSystemMessage(const char* message){
	perror(message);
	exit(1);
}

