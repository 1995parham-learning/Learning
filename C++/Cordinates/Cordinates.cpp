#include "Cordinates.h"
#include <math.h>
#include <iostream>

using namespace std;

cordinates::cordinates(){
	this->x=0;
	this->y=0;
}
cordinates::cordinates(const cordinates &c){
	this->x=c.x;
	this->y=c.y;
}
void cordinates::negate(){
	this->x=-x;
	this->y=-y;
}
double cordinates::norm(){
	return sqrt(this->x*this->x+this->y*this->y);
}
double cordinates::getX(){
	return this->x;
}
double cordinates::getY(){
	return this->y;
}
ostream &operator <<(ostream &output,cordinates c){
	output<<c.x<<" "<<c.y<<endl;
	return output;
}
istream &operator >>(istream &input,cordinates &c){
	input>>c.x>>c.y;
	return input;
}
bool operator ==(cordinates a,cordinates b){
	if(a.x==b.x&&a.y==b.y)
		return true;
	return false;
}
