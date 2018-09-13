#include <iostream>
#include <functional>
#include <string>

using namespace std;

int func(int number, string name){
	cout << "Your name is " << name << " and your number is " << number << endl;
}

int main(int argc,char* argv[]){
	func(18, "Parham");

	auto bindedFunction = bind(func, 20, placeholders::_1);

	bindedFunction("Amir");
}
