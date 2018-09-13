#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* funcThread(void* pointer);

int main(int argc, char* argv[]) {
	static int arr[] = { 10, 20, 30 };
	
	pthread_t tid;
	pthread_create(&tid, NULL, funcThread, arr);
	

	/*
	 * using pthread_join.
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("%s : %d\n", __func__, arr[i]);
	}
	printf("END\n");
	
	void* returnFrom;
	pthread_join(thread, &returnFrom);
	printf("%p : %d\n", returnFrom, *(int*) returnFrom);
	*/

	/*
	 * using pthread_detatch
	 * remember this function just delete thread informantion after his end.
	 */
	pthread_detach(tid);

	return 0;
}

void* funcThread(void* pointer) {
	int* newPointer = (int*) pointer;
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("%s : %d\n", __func__, *(newPointer + i));
	}
	static int x = 10;
	return &x;
}
