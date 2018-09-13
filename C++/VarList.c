#include <stdio.h>
#include <stdarg.h>

void printInt(int count,...);

int main(int argc,char** argv){
	printInt(3,1,2,3);
	return 0;
}

void printInt(int count,...){
	va_list list;
	va_start(list,count);
	int i=0;
	for(i=0;i<count;i++){
		int temp;
		temp = va_arg(list,int);
		printf("%d\n",temp);
	}
	va_end(list);
}
