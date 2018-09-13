#include <queue>
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	queue<int> myFristQueue;
	priority_queue<int> myFirstPriorityQueue;
	int numbers[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i = 0; i < 10; ++i){
		myFirstPriorityQueue.push(numbers[i]);
	}
	for(int i = 0; i < 10; ++i){
		int number = myFirstPriorityQueue.top();
		cout << number << endl;
		myFirstPriorityQueue.pop();
	}
	throw(exception error("Error is Error"));
}
