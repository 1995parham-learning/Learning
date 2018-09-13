#include <iostream>
#include <vector>

using namespace std;

int main(int argc,char* argv[]){	
	vector<int> myFirstVector;
	cout << "myFirstVector capacity (time = 0) : " << myFirstVector.capacity() << endl;
	myFirstVector.push_back(10);
	cout << "myFirstVector capacity (time = 1) : " << myFirstVector.capacity() << endl;
	myFirstVector.push_back(20);
	myFirstVector.push_back(30);
	cout << "myFisrtVector capacity (time = 3) : " << myFirstVector.capacity() << endl;
	vector<int> mySecondVector(10,100);
	for(int i = 0; i < mySecondVector.size(); i++){
		cout << mySecondVector[i] << endl;
	}
	for(vector<int>::iterator it = myFirstVector.begin(); it != myFirstVector.end(); ++it){
		cout << *it << endl;
	}
	return 0;
}
