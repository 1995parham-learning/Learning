#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(int argc,char* argv[]){
	multimap<int,string> myFirstMultiMap;
	myFirstMultiMap.insert(make_pair(1,"Parham Alvani"));
	myFirstMultiMap.insert(make_pair(1,"Kamran Amini"));
}
