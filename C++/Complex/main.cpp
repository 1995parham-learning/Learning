#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;

int main(){
    ofstream myFile("Complex.dat");
    Complex z1,z2,z3;
    int Re1,Im1,Re2,Im2;
    cin>>Re1>>Im1;
    cin>>Re2>>Im2;
    z1(Re1,Im1);
    z2(Re2,Im2);
    z1=z1+z2;
    z1=conjugation(z1);
    z1.conjugation();
    cout<<z1.getArg()<<endl;
    cout<<z1<<endl;
    ++z1;
    cout<<z1<<endl;
    z3=z2=z1;
    cout<<z1<<" - "<<z2<<" - "<<z3<<endl;
    myFile<<z1;
}
