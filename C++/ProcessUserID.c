#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char* argv[]){
	
	uid_t realUid = getuid();
	gid_t realGid = getgid();
	uid_t effUid = geteuid();
	gid_t effGid = getegid();
	printf("Real UID: %d GID: %d\n", realUid, realGid);
	printf("Effective UID: %d GID: %d\n", effUid, effGid);
	printf("\n");

	if (seteuid(1000) == -1){
		perror("seteuid()");
	}
	realUid = getuid();
	realGid = getgid();
	effUid = geteuid();
	effGid = getegid();
	printf("Real UID: %d GID: %d\n", realUid, realGid);
	printf("Effective UID: %d GID: %d\n", effUid, effGid);
	printf("\n");

	if (seteuid(100) == -1) {
		perror("seteuid()");
	}
	realUid = getuid();
	realGid = getgid();
	effUid = geteuid();
	effGid = getegid();
	printf("Real UID: %d GID: %d\n", realUid, realGid);
	printf("Effective UID: %d GID: %d\n", effUid, effGid);
	printf("\n");

	if (seteuid(0) == -1) {
		perror("seteuid()");
	}
	realUid = getuid();
	realGid = getgid();
	effUid = geteuid();
	effGid = getegid();
	printf("Real UID: %d GID: %d\n", realUid, realGid);
	printf("Effective UID: %d GID: %d\n", effUid, effGid);
	printf("\n");

	pid_t sessionId = getsid(0);
	printf("Session ID: %d\n", sessionId);
	return 0;
}
