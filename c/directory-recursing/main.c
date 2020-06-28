/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 15-02-2015
 *
 * [] Last Modified : Sun 15 Feb 2015 01:54:05 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <stdio.h>

#include "process_dir.h"

void print_dir(struct filestr in) {
  for (int i = 0; i < in.depth - 1; i++)
    printf("    ");
  printf("|- %s\n", in.name);
  for (int i = 0; i < in.depth - 1; i++)
    printf("    ");
  printf("|---|\n");
}

void print_file(struct filestr in) {
  for (int i = 0; i < in.depth; i++)
    printf("    ");
  printf("| %s\n", in.name);
}

int main(int argc, char *argv[]) {
  char *start = (argc > 1) ? argv[1] : ".";
  printf("Tree for %s\n", (argc > 1) ? start : "The current directory");
  process_dir(.name = start, .file_action = print_file,
              .directory_action = print_dir);
}
