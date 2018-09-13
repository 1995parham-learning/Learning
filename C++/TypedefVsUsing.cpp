#include <iostream>

using namespace std;

void function1(int number);
int function2(int number);

int main(int argc, char* argv[]){
	cout << endl << "Typedef using \"typedef\" " << endl;
	typedef int Integer;
	Integer integer = 10;
	cout << integer << endl;
	
	cout << endl << "Typedef using \"using\" " << endl;
	using Float = float;
	Float floatingPoint = 10.5;
	cout << floatingPoint << endl;
	
	cout << endl << "Function typedef using \"typedef\" " << endl;
	typedef void(*voidIntFunction)(int);
	voidIntFunction function1Pointer = function1 ;
	(*function1Pointer)(10);
	
	cout << endl << "Function typedef using \"using\" " << endl;
	using intIntFunction = int(*)(int);
	intIntFunction function2Pointer = function2;
	cout << (*function2Pointer)(20) << endl;
}
void function1(int number){
	cout << number << endl;
}
int function2(int number){
	cout << number << endl;
	return number * number;
}
