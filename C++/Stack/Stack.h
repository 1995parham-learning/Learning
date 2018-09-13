#ifndef STACK_H
#define STACK_H

#include <iostream>

using std::ostream;

class stack{
	private:
		static const int MAX=1000;
		int top;
		int A[MAX];
	public:
		stack();
		bool isempty();
		bool isfull();
		int size();
		void push(int x);
		int pop();
		int& operator [](int op1);
		friend ostream& operator <<(ostream &output, stack op);	
};
#endif
