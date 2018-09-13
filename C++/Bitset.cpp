#include <bitset>
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	bitset<10> myFirstBitset("000001");
	cout << myFirstBitset << endl;
	cout << endl << "\"set(9)\" method used:" << endl;
	myFirstBitset.set(9);
	cout << myFirstBitset << endl;
	cout << endl << "\"flip(9)\" method used:" << endl;
	myFirstBitset.flip(9);
	cout << myFirstBitset << endl;
	cout << endl << "\"flip(8)\" method used:" << endl;
	myFirstBitset.flip(8);
	cout << myFirstBitset << endl;
}
