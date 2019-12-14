/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 24-03-2015
 *
 * [] Last Modified : Tue 24 Mar 2015 03:50:30 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <glib.h>

int main(int argc, char *argv[]) {
  if (!GLIB_CHECK_VERSION(2, 44, 0))
    g_print("Glib version is too old\n");
}
