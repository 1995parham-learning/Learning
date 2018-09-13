#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount{
	public:
		BankAccount(int acctNum,const std::string& name):mAcctNum(acctNum), mClientName(name) {}
		void setAcctNum(int acctNum) { mAcctNum = acctNum; }
		int getAcctNum() const { return mAcctNum; }
		void setClientName(std::string name) { mClientName = name; }
		std::string getClientName() const { return mClientName; }
	protected:
		std::string mClientName;
		int mAcctNum;
};
#endif
