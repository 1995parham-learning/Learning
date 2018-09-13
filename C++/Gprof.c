#include <stdio.h>

void function1();
void function2();

int main(){
	int i=0;
	for(i=0;i<100;i++){
		function1();
	}
	for(i=0;i<100;i++){
		function2();
	}
}
void function1(){
	int i=0;
	for(i=0;i<100;i++){
		printf("%d ",i);
	}
}
void function2(){
	int i=0;
	for(i=0;i<100;i++){
		printf("%d ",i*i);
	}
}
