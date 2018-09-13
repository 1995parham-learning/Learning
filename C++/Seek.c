#include <stdio.h>

int main(){
	int n=fileno(stdin);
	int N=ftell(stdout);
	(void)printf("Hey I am returning with fileno %d offset = %d\n",n,N);
}
