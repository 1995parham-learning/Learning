#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[]){
	const string& nameRef = "Parham Alvani";
	string number("1234");
	string& numberRef = number;
	cout << nameRef << endl;
}
