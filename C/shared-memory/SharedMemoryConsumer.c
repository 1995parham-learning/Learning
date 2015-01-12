/* 
 * In The Name Of God
 * ========================================
 * [] File Name : SharedMemoryConsumer.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 12 Jan 2015 05:18:06 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

const int SIZE = 4096;

int main(int argc,char *argv[])
{
	int fd = shm_open("firstSharedMemory", O_RDONLY, 0644);
	void *ptr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	printf("%s", (char*) ptr);
	shm_unlink("firstSharedMemory");
	printf("Hosh.... it's over now !!!\n");
}
