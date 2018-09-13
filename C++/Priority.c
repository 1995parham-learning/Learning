#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	int ret;
	ret = getpriority(PRIO_PROCESS,0);
	printf("nice value is %d\n", ret);
}
