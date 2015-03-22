/*
 * In The Name Of God
 * ========================================
 * [] File Name : Gsoup.c
 *
 * [] Creation Date : 22-02-2015
 *
 * [] Last Modified : Sun 22 Mar 2015 07:28:31 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <libsoup/soup.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	SoupSession *session;
	SoupMessage *msg;
	SoupBuffer *buffer;


	session = soup_session_new();
	/*
	 * SoupMessage *soup_message_new(const char *method,
	 * const char *uri_string);
	*/	
	msg = soup_message_new("GET", "http://www.google.com/");
	
	/*
	 * GInputStream *soup_session_send(SoupSession *session,
	 * SoupMessage *msg, GCancellable *cancellable, GError **error);
	 *
	 * Synchronously sends msg and waits for the beginning of a response.
	 * On success, a GInputStream will be returned which you can use to read
	 * the response body. ("Success" here means only that an HTTP response
	 * was received and understood; it does not necessarily mean that a 2xx class
	 * status code was received.)
	 * If non-NULL, cancellable can be used to cancel the request;
	 * soup_session_send() will return a G_IO_ERROR_CANCELLED error.
	 * Note that with requests that have side effects (eg, POST, PUT, DELETE)
	 * it is possible that you might cancel the request after the server acts on it,
	 * but before it returns a response, leaving the remote resource in an unknown state.
	 *
	 * If msg is requeued due to a redirect or authentication, the initial (3xx/401/407)
	 * response body will be suppressed, and soup_session_send() will only return once a
	 * final response has been received.
	 *
	 * Contrast this method with soup_session_send_message(), which also synchronously sends a
	 * SoupMessage, but doesn't return until the response has been completely read.
	 * (Note that this method cannot be called on the deprecated SoupSessionAsync subclass.)
	*/
	soup_session_send_message(session, msg);
	
	printf("%u\n", msg->status_code);
	
	buffer = soup_message_body_flatten(msg->response_body);
	
	printf("%s\n", buffer->data);
	printf("%d\n", SOUP_STATUS_CANT_CONNECT);

//	printf("%s\n", soup_message_headers_get_one(msg->request_headers, "Host"));
}
