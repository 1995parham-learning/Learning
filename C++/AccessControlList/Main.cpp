#include <iostream>
#include "AccessList.h"

using namespace std;

int main(int argc, char* argv[]){
	AccessList fileX = {"parham", "kamran", "navid", "mohammad"};
	fileX.removeUser("parham");
	if(fileX.isAllowed("kamran")){
		cout << "Kamran has permissions" << endl;
	}
	auto users = fileX.getAllUsers();
	for(auto& user : users){
		cout << user << " | ";
	}
	cout << endl;
}
