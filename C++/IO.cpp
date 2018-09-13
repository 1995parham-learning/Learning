#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	/*iostream &parham;
	parham<<"salam"<<endl;*/
	int n;
	int scanCheck;
	while(scanCheck=scanf("%1d",&n)){
		/*if(ch=="\n")
			printf("I read \\n first in my life\n");
		else
			printf("I am stupid and read this shit %s\n",ch);*/
		printf("%#x ! ",scanCheck);
		printf("%d - ",scanCheck);
		printf("%d\n",n);
	}
}
