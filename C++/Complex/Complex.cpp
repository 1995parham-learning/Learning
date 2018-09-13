#include "Complex.h"
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

Complex::Complex(float Re,float Im){
	this->Re=Re;
    	this->Im=Im;
    	setArg();
}
Complex::Complex(){
    	Re=0;
    	Im=0;
    	this->Arg=-1;
}
Complex operator +(Complex op1,Complex op2){
    	Complex temp;
    	temp.Re=op1.Re+op2.Re;
    	temp.Im=op1.Im+op2.Im;
    	return temp;
}
Complex operator *(Complex op1,Complex op2){
    	Complex temp;
    	temp.Re=(op1.Re*op2.Re)-(op1.Im*op2.Im);
    	temp.Im=(op1.Im*op2.Re)+(op2.Im*op1.Re);
    	return temp;
}
ostream &operator <<(ostream &output,Complex &op){
    	output<<op.Re<<" + "<<op.Im<<" * i";
    	return output;
}
float Complex::getRe(){
    	return Re;
}
void Complex::setRe(float Re){
    	this->Re=Re;
}
float Complex::getIm(){
    	return Im;
}
void Complex::setIm(float Im){
    	this->Im=Im;
}
void Complex::show(){
	cout<<Re<<" + "<<Im<<" * i";
}
Complex conjugation(Complex op){
    	Complex temp;
    	temp.Re=op.Re;
    	temp.Im=-op.Im;
    	return temp;
}
void Complex::conjugation(){
    	this->Im=-Im;
}	
float Complex::getArg(){
    	if(this->Arg==-1)
        	setArg();
    	return Arg;
}
void Complex::setArg(){
    	if(this->Im==0)
        	this->Arg=0;
    	else if(this->Re==0&&this->Im>0)
        	this->Arg=Pi/2;
    	else if(this->Re==0&&this->Im>0)
        	this->Arg=(3*Pi)/2;
    	else{
        	if(this->Im>0&&this->Re>0)
        	    this->Arg=atan(this->Im/this->Re);
        	if(this->Im>0&&this->Re<0)
        	    this->Arg=Pi-atan(-this->Im/this->Re);
        	if(this->Im<0&&this->Re>0)
        	    this->Arg=2*Pi-atan(this->Im/-this->Re);
        	if(this->Im<0&&this->Re<0)
        	    this->Arg=Pi+atan(-this->Im/-this->Re);
	}
}
Complex Complex::operator ++(){
    	this->Re++;
    	this->Im++;
    	return *this;
}
Complex Complex::operator =(Complex op){
    	this->Re=op.Re;
    	this->Im=op.Im;
    	return *this;
}
Complex Complex::operator ()(float Re,float Im){
    	this->Re=Re;
    	this->Im=Im;
    	this->Arg=getArg();
    	return *this;
}
