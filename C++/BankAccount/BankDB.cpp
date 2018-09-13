#include <string>
#include <map>
#include <stdexcept>
#include <utility>
#include "BankDB.h"
#include "BankAccount.h"

bool BankDB::addAccount(const BankAccount& acct){
	auto res = mAccounts.insert(std::make_pair(acct.getAcctNum(),acct));
	return res.second;
}
void BankDB::deleteAccount(int acctNum){
	mAccounts.erase(acctNum);
}
BankAccount& BankDB::findAccount(int acctNum) throw(std::out_of_range){
	auto it = mAccounts.find(acctNum);
	if(it == mAccounts.end()){
		throw std::out_of_range("No account with that number.");
	}
	return it->second;
}
BankAccount& BankDB::findAccount(const std::string& name) throw(std::out_of_range){
	for(auto &p : mAccounts){
		if(p.second.getClientName() == name){
			return p.second;
		}
	}
	throw std::out_of_range("No account with that name");
}
void BankDB::mergeDatabase(BankDB &db){
	mAccounts.insert(db.mAccounts.begin(), db.mAccounts.end());
	db.mAccounts.clear();
}
