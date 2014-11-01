#include <malloc.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	void* p_block = malloc(100);
	printf("block address : %p\n", p_block);
	printf("sizeof int: %lu\n", sizeof(int));
	printf("sizeof block : %d\n", *((int *)(p_block - 8)));
}
