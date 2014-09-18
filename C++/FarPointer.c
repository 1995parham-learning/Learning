#include <stdio.h>

int main(int argc,char* argv[]){
	int a = 10;
	int far *pointer = (int far *) &a;
	printf("%d\n", pointer);
}
