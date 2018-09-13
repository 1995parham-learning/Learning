#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Collegian.h"

using namespace std;

void add_collegian(){
	ofstream list("collegian_list.txt",ifstream::app);
	collegian New;
	cin>>New;
	list<<New;
	list.close();
}
void print_collegian(){
	ifstream list("collegian_list.txt");
	collegian Old;
	vector <collegian> C;
	while(list>>Old){
		C.push_back(Old);
	}
	sort(C.begin(),C.end());
	for(int i=0;i<C.size();i++)
		cout<<C[i];
	list.close();
}

int main(){
	ofstream list("collegian_list.txt",ifstream::trunc);
	list.close();
	while(true){
		char c=cin.get();
		//cerr<<c<<endl;
		cin.get();
		switch(c){
			case 'e':
				return 0;
			case 'f':
				add_collegian();
				cin.get();
				break;
			case 'p':
				print_collegian();
				break;
		}
	}
}
