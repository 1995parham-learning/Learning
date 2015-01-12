#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10;
	
	printf("a = %d\n", a);
	int *pointer = &a;
	
	printf("&a = %p\n", pointer);
}
