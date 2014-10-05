#include <string.h>
#include <stdio.h>

int hello_writer(const char*, int);

int main(int argc, char* argv[]){
	char* TEST = "This is a test\nBut i love it !!!\nWTF ?? it's assembly ?!?!\n";
	int ret;
	ret = hello_writer(TEST, strlen(TEST));
	printf("Return: %d\n", ret);
}
