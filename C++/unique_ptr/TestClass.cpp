/*
 * In The Name Of God
 * ========================================
 * [] File Name : TestClass.cpp
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 22 Dec 2014 01:51:37 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <iostream>

#include "TestClass.h"

TestClass::TestClass(int number)
{
	std::cout << "Building object with " << number << std::endl;
	setNumber(number);
}

void TestClass::setNumber(int number)
{
	mNumber = number;
}

const int& TestClass::getNumber() const
{
	return mNumber;
}

TestClass::~TestClass(){
	std::cout << "I am going ...." << std::endl;
}
