#include <string.h>

void hello_writer(const char*, int);

int main(int argc, char* argv[]){
	char* TEST = "This is a test\nBut i love it !!!\nWTF ?? it's assembly ?!?!\n";
	hello_writer(TEST, strlen(TEST));
}
