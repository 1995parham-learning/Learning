#include <iostream>
#include <string>
#include "PermutationGenerator.h"

using namespace std;

int main(int argc,char* argv[]){
	PermutationGenerator gen(4);
	while(gen.hasNext()){
		cout << gen.next() << endl;
	}
}
