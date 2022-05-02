/*
 * In The Name Of God
 * ========================================
 * [] File Name : sockline.c
 *
 * [] Creation Date : 19-04-2015
 *
 * [] Last Modified : Sun 19 Apr 2015 10:59:49 PM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int server_socket_fd;
  int client_socket_fd;
  FILE *fp;
  char output_buffer[2048];
  char input_buffer[1024];
  struct sockaddr_in server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(1373);

  server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket_fd == -1)
    perror("socket()");

  if (bind(server_socket_fd, (struct sockaddr *)&server_addr,
           sizeof(server_addr)) == -1)
    perror("bind()");

  if (listen(server_socket_fd, 10) == -1)
    perror("listen()");

  client_socket_fd = accept(server_socket_fd, NULL, NULL);
  fp = fdopen(client_socket_fd, "r");
  while (fgets(input_buffer, sizeof(input_buffer) / sizeof(char), fp)) {
    sprintf(output_buffer, "<tr><td>%s", input_buffer);
    send(client_socket_fd, output_buffer, strlen(output_buffer), 0);
  }
}
