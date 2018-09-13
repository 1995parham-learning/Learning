#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main(int argc,char* argv[]){
	array<int, 10> A10;
	int index = 1;
	generate(A10.begin(), A10.end(), [&index]() -> int { return (index *= 2); });
	for(int i : A10){
		cout << i << " ";
	}
	cout << endl;
}
