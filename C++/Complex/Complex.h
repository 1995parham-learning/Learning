#pragma once
#include <iostream>

using namespace std;

class Complex{
    	private:
		float Re;
       		float Im;
        	float Arg;
        	static const float Pi=3.1415926535897;
    	public:
        	Complex(float,float);
        	Complex();
        	friend Complex operator +(Complex op1,Complex op2);
        	friend Complex operator *(Complex op1,Complex op2);
        	friend ostream &operator <<(ostream &output,Complex &op);
        	Complex operator ++();
        	Complex operator =(Complex op);
        	Complex operator ()(float Re,float Im);
        	float getRe();
        	void setRe(float Re);
        	float getIm();
        	void setIm(float Im);
        	void show();
        	friend Complex conjugation(Complex op);
        	void conjugation();
        	float getArg();
        	void setArg();
};

