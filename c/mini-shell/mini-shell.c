/*
 * In The Name Of God
 * ========================================
 * [] File Name : mini-shell.c
 *
 * [] Creation Date : 12-03-2015
 *
 * [] Last Modified : Fri 13 Mar 2015 11:13:42 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_LINE 80

int main(int argc, char *args[]) {
  char *args_new[MAX_LINE / 2 + 1];
  char buffer[MAX_LINE];
  char *token = NULL;
  char *whiteSpace = " \t\n\f\r\v";
  int status;

  while (1) {
    printf("psh> ");
    fflush(stdout);
    /* IMPORTANT */
    scanf(" %[^\n]", buffer);

    int count = 0;

    token = strtok(buffer, whiteSpace);
    do {
      args_new[count] = strdup(token);
      count++;
      token = strtok(NULL, whiteSpace);
    } while (token != NULL);
    args_new[count] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
      if ((execvp(args_new[0], args_new)) == -1) {
        perror("psh");
        exit(1);
      }
    } else if (pid > 0) {
      if (!strcmp(args_new[count - 1], "&"))
        wait(&status);
      else
        waitpid(pid, 0, 0);
      fflush(stdout);
    } else {
      perror("psh");
      exit(1);
    }
  }
  return 0;
}
