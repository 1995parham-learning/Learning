#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	string name1 = "ABC";
	string name2 = "AB";
	if(lexicographical_compare(name1.begin(), name1.end(), name2.begin(), name2.end())){
		cout << name1 << endl;
	}else{
		cout << name2 << endl;
	}
}
