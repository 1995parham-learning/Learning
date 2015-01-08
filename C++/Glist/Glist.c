/*
 * In The Name Of God
 * ========================================
 * [] File Name : Glist.c
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Thu 08 Jan 2015 09:21:47 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <stdio.h>

GList *list;

int main(int argc, char *argv[])
{
	list = g_list_append(list, "a");
	list = g_list_append(list, "b");
	list = g_list_append(list, "c");
	
	for(; list != NULL; list = list->next)
		printf("%s\n", (char *)list->data);
}
