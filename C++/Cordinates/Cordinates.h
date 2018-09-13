#ifndef CORDINATES_H
#define CORDINATES_H
#include <iostream>

using namespace std;

class cordinates{
	private:
		double x;
		double y;
	public:
		double norm();
		void negate();
		double getX();
		double getY();
		cordinates();
		cordinates(const cordinates &c);
		friend ostream &operator <<(ostream &output,cordinates c);
		friend istream &operator >>(istream &input,cordinates &c);
		friend bool operator ==(cordinates a,cordinates b);
};
#endif
