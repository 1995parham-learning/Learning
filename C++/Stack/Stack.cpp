#include <iostream>
#include "Stack.h"

using namespace std;

stack::stack(){
	top=0;
}
bool stack::isempty(){
	if(top == 0)
		return true;
	return false;
}
bool stack::isfull(){
	if(this->size() == MAX)
		return true;
	return false;
}
int stack::size(){
	return top;
}
void stack::push(int x){
	A[top++] = x;
}
int stack::pop(){
	return A[--top];
}
int& stack::operator [](int x){
	return A[x];
}
ostream& operator <<(ostream& output, stack op){
	for(int i = 0; i < op.size(); i++){
		output << i << " => " << op[i] << " ";
	}
	return output;
}
