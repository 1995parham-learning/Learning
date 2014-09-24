#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	int n = 0;
	int m = 0;
	int number = 1;
	if(argc == 3){
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}else if(argc > 3){
		n = atoi(argv[1]);
		m = atoi(argv[2]);
		number = atoi(argv[3]);
	}
	else{
		exit(1);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", number);
		}
		printf("\n");
	}
}
