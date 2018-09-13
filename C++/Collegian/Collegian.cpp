#include <iostream>
#include <string>
#include "Collegian.h"

using namespace std;

collegian::collegian(int student_no,string student_first_name,string student_last_name,double avrage){
	this->student_no=student_no;
	this->student_first_name=student_first_name;
	this->student_last_name=student_last_name;
	this->avrage=avrage;
}
collegian::collegian(){
	this->student_no=0;
	this->student_first_name='\0';
	this->student_last_name='\0';
	this->avrage=0;
}
int collegian::getNo(){
	return this->student_no;
}
string collegian::getFN(){
	return this->student_first_name;
}
string collegian::getLN(){
	return this->student_last_name;
}
ostream &operator <<(ostream &output,collegian op){
	output<<op.student_no<<endl;
	output<<op.student_first_name<<endl;
	output<<op.student_last_name<<endl;
	output<<op.avrage<<endl;
	return output;
}
istream &operator >>(istream &input,collegian &op){
	input>>op.student_no>>op.student_first_name>>op.student_last_name>>op.avrage;
	return input;
}
bool operator <(collegian op1,collegian op2){
	if(op1.student_no>=op2.student_no)
		return false;
	return true;
}
bool operator >(collegian op1,collegian op2){
	if(op1.student_no<=op2.student_no)
		return false;
	return true;
}
