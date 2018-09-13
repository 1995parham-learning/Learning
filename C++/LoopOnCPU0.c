#define _GNU_SOURCE

#include <sched.h>

int main(int argc,char* argv[]){
	cpu_set_t set;
	int ret;

	CPU_ZERO(&set);
	CPU_SET(0, &set);
	CPU_CLR(1, &set);	//The CPU_CLR operation is redundant as we just zeroed out the whole set, but it is provided for completeness.
	ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
	if(ret == -1){
		perror("sched_setaffinity()");
	}
	int index = 0;
	while(1){
		index++;
	}
}
