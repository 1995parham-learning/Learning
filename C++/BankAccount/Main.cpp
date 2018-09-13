#include <iostream>
#include <stdexcept>
#include <string>
#include "BankDB.h"
#include "BankAccount.h"

using namespace std;

int main(int argc, char* argv[]){
	BankDB db;
	db.addAccount(BankAccount(100, "Parham Alvani"));
	db.addAccount(BankAccount(200, "Kamran Amini"));
	try{
		auto acct = db.findAccount(100);
		cout << "Found account 100 : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct.setClientName("Parham Alvani ...");
		acct = db.findAccount("Kamran Amini");
		cout << "Found account of Kamran Amini : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct = db.findAccount(100);
		cout << "Found account 100 : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct = db.findAccount("Parham Alvani");
	}catch(const out_of_range& except){
		cout << except.what() << endl;
	}
	cout << endl << "And when you use auto& you get : " << endl << endl;
	db.addAccount(BankAccount(100, "Parham Alvani"));
	db.addAccount(BankAccount(200, "Kamran Amini"));
	try{
		auto& acct = db.findAccount(100);
		cout << "Found account 100 : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct.setClientName("Parham Alvani ...");
		acct = db.findAccount("Kamran Amini");
		cout << "Found account of Kamran Amini : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct = db.findAccount(100);
		cout << "Found account 100 : " << acct.getClientName() << " --- " << acct.getAcctNum() << endl;
		acct = db.findAccount("Parham Alvani");
	}catch(const out_of_range& except){
		cout << except.what() << endl;
	}
	cout << endl << "<<<<<< THINKING >>>>>>" << endl;
}
