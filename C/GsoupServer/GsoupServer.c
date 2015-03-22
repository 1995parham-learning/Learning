/*
 * In The Name Of God
 * ========================================
 * [] File Name : GsoupServer.c
 *
 * [] Creation Date : 22-03-2015
 *
 * [] Last Modified : Sun 22 Mar 2015 11:41:02 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <stdlib.h>
#include <libsoup/soup.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	SoupServer *server;
	GError *error = NULL;
	gboolean status;
	GMainLoop *loop;

	server = soup_server_new(SOUP_SERVER_SERVER_HEADER,
			"Parham Server", NULL);

	status = soup_server_listen_all(server, 1373,
			SOUP_SERVER_LISTEN_IPV4_ONLY, &error);

	if (status == FALSE)
		printf("no ok !\n");
	else
		printf("ok !\n");

	if (error) {
		g_printerr("Unable to create server: %s\n",
				error->message);
		exit(1);
	}

	loop = g_main_loop_new(NULL, TRUE);
	g_main_loop_run(loop);
}
