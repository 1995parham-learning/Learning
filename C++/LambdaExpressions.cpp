#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

function<int(void)> multiplyBy2Lambda(int x){
	return [=]() -> int{ return 2*x; };
}

void testCallback(const vector<int>& vec, const function<bool(int)>& callback){
	for(auto i : vec){
		if(!callback(i)){
			break;
		}else{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main(int argc, char* argv[]){
	[]{ cout << "Hello from lambda expressions" << endl; }();
		
	cout << endl;
	int number = 10;
	cout << "number : " << number << endl;
	//
	//  if 'mutable' part remove following error show:
	//  LambdaExpressions.cpp:9:36: error: assignment of read-only variable ‘number’
	//  int result = [=]() -> int{ number += 100; return number; }();
	//
	int result = [=]() mutable -> int{ number += 100; return number; }();
	cout << "result : " << result << endl;
	cout << "number : " << number << endl;

	cout << endl;
	number = 10;
	cout << "number : " << number << endl;
	[&]() -> void{ number *= 100; }();
	cout << "number : " << number << endl;
	
	cout << endl;
	cout << multiplyBy2Lambda(10)() << endl;
	cout << "see the code please ... " << endl;

	cout << endl;
	vector<int> vec(10);
	int index = 0;
	generate(vec.begin(), vec.end(), [&index]{ return ++index; });
	for_each(vec.begin(), vec.end(), [](int i){ cout << i << " "; });
	cout << endl;
	testCallback(vec, [](int i){ return i < 6; });
}
