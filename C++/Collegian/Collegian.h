#ifndef COLLEGIAN_H
#define COLLEGIAN_H
#include <string>
#include <iostream>

using namespace std;

class collegian{
	private:
		int student_no;
		string student_first_name;
		string student_last_name;
		double avrage;
	public:
		collegian(int student_no,string student_frist_name,string student_last_name,double avrage);
		collegian();
		int getNo();
		string getFN();
		string getLN();
		friend ostream& operator <<(ostream &output,collegian op);
		friend istream& operator >>(istream &input,collegian &op);
		friend bool operator <(collegian op1,collegian op2);
		friend bool operator >(collegian op1,collegian op2);
};
#endif
