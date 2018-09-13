#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

template<class T>
void printMap(const T& m){
	for(auto& p : m){
		cout << p.first << " (Phone: " << p.second << ")" << endl;
	}
	cout << "---------------" << endl;
}

int main(int argc,char* argv[]){
	unordered_map<string,string> um;
	um.insert({{"Parham Alvani", "09124493153"}, {"Mahtab Ebrahimi", "09123396377"}});
	printMap(um);
	um.insert(make_pair("Kamran Amini", "09121234567"));
	printMap(um);
	int bucketNumber = um.bucket("Parham Alvani");
	cout << "Parham Alvani is in bucket " << bucketNumber << " which contains the following " << um.bucket_size(bucketNumber) << " elements :" << endl;
	auto liter = um.cbegin(bucketNumber);
	auto literEnd = um.cend(bucketNumber);
	while(liter != literEnd){
		cout << "\t" << liter->first << " (Phone: " << liter->second << ")" << endl;
		++liter;
	}
	cout << "----------------" << endl;
}
