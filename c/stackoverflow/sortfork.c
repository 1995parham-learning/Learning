/*
 * In The Name Of God
 * ========================================
 * [] File Name : sortfork.c
 *
 * [] Creation Date : 12-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2017 Parham Alvani.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int pipefd[2];
  pid_t cpid;

  /* create a pipe before you fork a child process */
  pipe(pipefd);

  cpid = fork();

  if (cpid < 0) {
    perror("Fork");
  } else if (cpid == 0) {
    printf("This is child process\n");

    close(pipefd[1]);
    close(0);

    dup2(pipefd[0], 0);

    execlp("sort", "sort", NULL);

    exit(0);
  } else {
    printf("This is parent process\n");

    close(pipefd[0]);

    static const char *const sort_array[] = {"hello", "amigos", "gracias",
                                             "hola"};
    int i;

    for (i = 0; i < 4; i++) {
      write(pipefd[1], sort_array[i], strlen(sort_array[i]));
      write(pipefd[1], "\n", 1);
    }

    close(pipefd[1]);

    int cstatus;

    wait(&cstatus);
  }
}
