/*
 * In The Name Of God
 * ========================================
 * [] File Name : who.c
 *
 * [] Creation Date : 16-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2016 Parham Alvani.
 */

#include <glib.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <utmpx.h>

void displ(gpointer value, gpointer userdata) {
  printf("%-25s ", (char *)value);
}

void dell(gpointer value) { g_free(value); }

void del_list(gpointer value) {
  g_slist_free_full((GSList *)value, (GDestroyNotify)dell);
}

int disp_del(gpointer key, gpointer value, gpointer userdata) {
  printf("%-10s", (char *)key);
  g_slist_foreach((GSList *)value, (GFunc)displ, NULL);
  printf("\n");
  return TRUE;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("Too many input arguments.\n");
    exit(1);
  }

  GHashTable *hash = NULL;
  hash = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify)g_free,
                               (GDestroyNotify)del_list);
  GSList *list = NULL;

  struct utmpx *ret = NULL;
  struct passwd *uentry = NULL;
  char *id = NULL;
  char *name = NULL;
  char *hostid = NULL;

  while ((ret = getutxent()) != NULL) {
    if (USER_PROCESS == ret->ut_type) {
      /* fetch userid for this user */
      uentry = getpwnam(ret->ut_user);
      if (NULL == uentry) {
        printf("No user found. \n");
        return 0;
      } else {
        /* Create new list for each user */
        list = NULL;
        id = strdup(ret->ut_user);
        name = strdup(uentry->pw_gecos);
        hostid = strdup(ret->ut_host);
        list = g_slist_append(list, name);
        list = g_slist_append(list, hostid);
        g_hash_table_insert(hash, id, list);
      }
    }
  }
  /* printing the details of respective users */
  g_hash_table_foreach_remove(hash, (GHRFunc)disp_del, NULL);
  /*freeing memory created for Hash Table */
  g_hash_table_remove_all(hash);
  g_hash_table_destroy(hash);
  return 0;
}
