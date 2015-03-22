/*
 * In The Name Of God
 * ========================================
 * [] File Name : GsoupServer.c
 *
 * [] Creation Date : 22-03-2015
 *
 * [] Last Modified : Mon 23 Mar 2015 01:02:05 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <stdlib.h>
#include <libsoup/soup.h>
#include <stdio.h>

static void http_callback(SoupServer *server, SoupMessage *msg,
		const char *path, GHashTable *query,
		SoupClientContext *client, gpointer user_data)
{
	SoupSession *session;
	guint status;

	g_print("Sendding request...\n");
	session = soup_session_new();
	status = soup_session_send_message(session, msg);
	g_print("Rquest sent : %d\n", status);
	
	soup_message_set_status(msg, status);
	soup_message_body_complete(msg->response_body);
}

int main(int argc, char *argv[])
{
	SoupServer *server;
	GError *error = NULL;
	GMainLoop *loop;

	server = soup_server_new(SOUP_SERVER_SERVER_HEADER,
			"Parham-Server-1.0", NULL);
	soup_server_listen_all(server, 1373,
			SOUP_SERVER_LISTEN_IPV4_ONLY, &error);
	if (error) {
		g_printerr("Unable to create server: %s\n",
				error->message);
		exit(1);
	}
	soup_server_add_handler(server, NULL, http_callback, NULL, NULL);

	loop = g_main_loop_new(NULL, TRUE);
	g_main_loop_run(loop);
}
