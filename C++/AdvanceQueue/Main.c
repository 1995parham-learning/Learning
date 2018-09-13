#include <stdio.h>
#include "AdvanceQueue.h"

int main(int argc,char* argv[]){
	queue_t* ptr = create_queue();
	enqueue(10,  ptr);
	printf("Hip Hip ..... %d\n", dequeue(ptr));
}
