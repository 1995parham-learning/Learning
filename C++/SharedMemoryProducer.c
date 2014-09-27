#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

const size_t SIZE = 4096;

int main(int argc,char* argv[]){
	int fd = shm_open("firstSharedMemory", O_CREAT | O_RDWR, 0644);
	void* ptr = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
	sprintf((char*) ptr, "Hello world of linux IPC\n");
	printf("I write !!!!\n");
}
