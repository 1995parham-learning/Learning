/*
 * In The Name Of God
 * ========================================
 * [] File Name : Glist.c
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Sat 14 Feb 2015 12:47:56 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <glib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  GList *list = NULL;

  char str[] = "My name is parham";

  list = g_list_append(list, "a");
  list = g_list_append(list, "b");
  list = g_list_append(list, "c");
  list = g_list_append(list, str);

  GList *it = list;
  for (; it != NULL; it = it->next)
    printf("%s\n", (char *)it->data);

  str[0] = 'm';

  it = list;
  for (; it != NULL; it = it->next)
    printf("%s\n", (char *)it->data);
  /*
   * GList only stores pointer so if you change variable,
   * its value changes in GList
   */

  /*
   * frees all of the memory used by a GList.
   * the freed elements are returned to the slice allocator.
   */
  g_list_free(list);
}
