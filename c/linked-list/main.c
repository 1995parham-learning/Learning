/*
 * In The Name of God
 * =======================================
 * [] File Name : main.c
 *
 * [] Creation Date : 07-11-2019
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2019 Parham Alvani.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct node {
  char name[200];
  int age;

  struct node *next;
};

int main() {
  struct node *list = malloc(sizeof(struct node));
  list->next = NULL;

  struct node *e1 = malloc(sizeof(struct node));
  strcpy(e1->name, "Parham Alvnai");
  e1->age = 26;
  linked_list_append(list, e1, struct node, next);

  struct node *e2 = malloc(sizeof(struct node));
  strcpy(e2->name, "Saman Fekri");
  e2->age = 26;
  linked_list_append(list, e2, struct node, next);

  linked_list_foreach(list, e, struct node, next) {
    printf("%s %d\n", e->name, e->age);
  }
}
