#include "Cordinates.h"
#include <iostream>

using namespace std;

double slope(cordinates a,cordinates b){
	return (a.getY()-b.getY())/(a.getX()-b.getX());
}
bool check_parallel(cordinates a,cordinates b,cordinates c,cordinates d){
	if(slope(a,b)==slope(c,d))
		return true;
	return false;
}
bool check_coincident(cordinates a,cordinates b,cordinates c,cordinates d){
	if(a==c&&b==d)
		return true;
	return false;
}

int main(){
	cordinates a,b,c,d;
	cin>>a>>b>>c>>d;
	if(check_parallel(a,b,c,d)){
		if(check_coincident(a,b,c,d)){
			cout<<"coincident"<<endl;
		}
		else{
			cout<<"parallel"<<endl;
		}
	}
	else{
		cout<<"intersecting"<<endl;
	}
}
