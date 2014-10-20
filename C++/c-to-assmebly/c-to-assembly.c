int b = 10;	// expect go to data section

int c;		// expect go to bss section

int main(int argc, char* argv[]){
	int a = 2 * 10;
}
