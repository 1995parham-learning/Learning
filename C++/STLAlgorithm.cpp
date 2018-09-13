#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc,char* argv[]){
	//  Random Shuffle
	cout << endl << "random_shuffle()" << endl;
	vector<int> randomVector = {1,2,3,4,5,6,7,8,9,10};
	random_shuffle(randomVector.begin(),randomVector.end());
	for(int x : randomVector){
		cout << x << endl;
	}
	//Find
	cout << endl << "find()" << endl;
	vector<int> findVector = {1,2,3,4,5,6,11,12};
	auto it = find(findVector.begin(), findVector.end(), 11);
	if(it == findVector.end()){
		cout << "10 is not found" << endl;
	}
	else{
		cout << *it << endl;
		cout << "Index : " << it - findVector.begin() << endl;
	}
	//  Accumulate
	cout << endl << "accumulate()" << endl;
	vector<int> accumulateVector = {1,2,3,4,5,6,7,8,9,10};
	cout << accumulate(accumulateVector.begin(), accumulateVector.end(), 0) << endl;
	cout << accumulate(accumulateVector.begin(), accumulateVector.end(), 1, [](int num1, int num2){ return num1 * num2; }) << endl;
}
