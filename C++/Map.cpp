#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(int argc,char* agrv[]){
	map<int,string> myFirstMap = {{1,"parham"},{2,"navid"},{3,"kamran"}};
	pair<map<int,string>::iterator,bool> returnPair = myFirstMap.insert(pair<int,string>(4,"mohammad"));
	cout << returnPair.second << endl;
	cout << "Simple For :" << endl;
	for(int i = 1; i <= 4; i++){
		cout << i << " : " << myFirstMap[i] << " | ";
	}
	cout << endl;
	cout << "C++11 Range Base For :" << endl;
	for(auto &p : myFirstMap){
		cout << p.first << " : " << p.second << " | ";
	}
	cout << endl;
	cout << "Iterator :" << endl;
	for(map<int,string>::const_iterator itr = myFirstMap.cbegin(); itr != myFirstMap.cend(); itr++){
		cout << itr->first << " : " << itr->second << " | ";
	}
	cout << endl;
	myFirstMap.erase(1);
	for(auto &p : myFirstMap){
		cout << p.first << " : " << p.second << " | ";
	}
	cout << endl;
	cout << "Using operator[] for accessing elements" << endl;
	cout << myFirstMap[2] << endl;
}
