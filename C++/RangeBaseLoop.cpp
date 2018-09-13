#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	int A[10] = {1,2,3,4,5,6,7,8,9,10}; 
	for(int a : A){
		cout << ++a << " ";
	}
	cout << endl;
	cout << "A array values after running \'for(int a : A){ cout << ++a << \" \"}\' :" << endl;
	for(int a : A){
		cout << a << " ";
	}
	cout << endl;
	for(int &a : A){
		cout << ++a << " ";
	}
	cout << endl;
	cout << "A array values after running \'for(int a : A){ cout << ++a << \" \"}\' :" << endl;
	for(int a : A){
		cout << a << " ";
	}
	cout << endl;
}
