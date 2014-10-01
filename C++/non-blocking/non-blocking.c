#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(const char* msg);

int main(int argc,char* argv[]){
	int flags = fcntl(0, F_GETFL);
	if(flags == -1){
		die("fcntl(): F_GETFL");
	}

	flags |= O_NONBLOCK;

	if(fcntl(0, F_SETFL, flags) == -1){
		die("fcntl(): F_SETFL");
	}

	char buffer[1024];
	if(fgets(buffer, 1024, stdin) == NULL){
		die("scanf(): Like i said !!!");
	}
	buffer[strlen(buffer) - 1] = 0;
	printf("%s : No way !!!\n", buffer);
}

void die(const char* msg){
	perror(msg);
	exit(1);
}
