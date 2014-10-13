#include <stdio.h>
#include <string.h>

int parham_print(char* string, int len);

int main(int argc, char* argv[]){
	char* string = "Hello world, Are you assembly ????\n";
	printf("%d\n", parham_print(string, strlen(string)));
}
