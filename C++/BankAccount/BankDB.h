#ifndef BANKDB_H
#define BANKDB_H

#include <map>
#include <stdexcept>
#include <string>
#include "BankAccount.h"

class BankDB{
	public:
		BankDB() {}
		bool addAccount(const BankAccount& acct);
		void deleteAccount(int acctNum);
		BankAccount& findAccount(int acctNum) throw(std::out_of_range);
		BankAccount& findAccount(const std::string& name) throw(std::out_of_range);
		void mergeDatabase(BankDB& db);
	protected:
		std::map<int,BankAccount> mAccounts;
};
#endif		
