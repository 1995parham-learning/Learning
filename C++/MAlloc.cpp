#include <new>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace  std;

const int MAX=1000*1000*1000+10;

int main(){
	double* mem[20];
	int i=0;
	do{
		try{
			mem[i]=new double[MAX];
		}
		catch(bad_alloc &p){
			cout<<"fuck u men !!!! "<<p.what()<<endl;
		}
		i++;
	}while(i<20);
	cout<<i<<" Times allocation is happening"<<endl;
}

