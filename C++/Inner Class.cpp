#include <iostream>

using namespace std;

class outNumber{
	public:
		int number;
		class inNumber{
			public:
				int number;
				outNumber* pointer;
		};
};
int main(){
	outNumber num1;
	outNumber::inNumber num2;
	num1.number=1;
	num2.pointer=&num1;
	num2.number=2;
	(num2.pointer)->number=10;
	cout<<num1.number<<" "<<num2.number<<endl;
}
