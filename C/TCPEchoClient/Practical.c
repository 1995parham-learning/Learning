/*
 * In The Name Of God
 * ========================================
 * [] File Name : Practical.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 12 Jan 2015 04:15:13 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include "Practical.h"
#include <stdio.h>
#include <stdlib.h>

void DieWithUserMessage(const char *message, const char *detail) {
  fprintf(stderr, "%s:%s\n", message, detail);
  exit(1);
}
void DieWithSystemMessage(const char *message) {
  perror(message);
  exit(1);
}
