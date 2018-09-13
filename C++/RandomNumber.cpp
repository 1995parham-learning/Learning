#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int seed = 10;
	int m = 13;
	int a = 2;
	for(int i = 0; i < n; i++){
		cout << seed << " ";
		seed = (seed * a) % m;
	}
	cout << endl;
}
