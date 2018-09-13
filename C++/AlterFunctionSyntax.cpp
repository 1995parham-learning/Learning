#include <iostream>

using namespace std;

auto square(int n) -> int{
	return n*n;
}

int main(int argc, char* argv[]){
	cout << square(10) << endl;
}
