#include <iostream>
#include <vector>

using namespace std;

class ParhamWraper{
	private:
		int number;
	public:
		typedef int parhamInt;
	private:
	
	public:
		ParhamWraper(int number):number(number) {
		}
		parhamInt getInt(){
			return number;
		}
		operator int(){
			return number;
		}
};

ParhamWraper operator "" _p(long double number){
	ParhamWraper parham(number);
	return parham;
}

int main(int argc,char* argv[]){
	ParhamWraper::parhamInt a;
	a = 10;
	cout << a << endl;

	ParhamWraper b(10);
	ParhamWraper* c = new ParhamWraper(100);
	b = 10.0_p;
	cout << (int)b << " ------- " << b.getInt() << endl;
	cout << (int)(*c) << "-------" << c->getInt() << endl;

	return 0;
}
