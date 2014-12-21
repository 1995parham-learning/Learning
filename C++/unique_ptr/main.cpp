/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.cpp
 *
 * [] Creation Date : 22-12-2014
 *
 * [] Last Modified : Mon 22 Dec 2014 01:52:24 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <iostream>
#include <memory>

#include "TestClass.h"

using namespace std;

int main()
{
	unique_ptr<TestClass> myPtr(new TestClass(12));
	myPtr = nullptr;
	cout << "Hey ..." << endl;
}
