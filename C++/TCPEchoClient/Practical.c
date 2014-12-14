// In The Name Of God
// ========================================
// * File Name : Practical.c
// 
// * Creation Date : 14-12-2014
//
// * Last Modified : Mon 15 Dec 2014 12:56:02 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
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

