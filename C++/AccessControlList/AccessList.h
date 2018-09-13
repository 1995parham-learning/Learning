#ifndef ACCESSLIST_H
#define ACCESSLIST_H

#include <string>
#include <set>
#include <initializer_list>
#include <list>

using std::set;
using std::string;
using std::list;
using std::initializer_list;

class AccessList{
	public:
		AccessList() {}
		AccessList(const initializer_list<string>& initlst);
		void addUser(const string& user);
		void removeUser(const string& user);
		bool isAllowed(const string& user) const;
		list<string> getAllUsers() const;
	protected:
		set<string> mAllowed;
};
#endif
