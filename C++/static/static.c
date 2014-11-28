// In The Name Of God
// ========================================
// * File Name : static.c
// 
// * Creation Date : 28-11-2014
//
// * Last Modified : Fri 28 Nov 2014 08:26:35 PM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdio.h>

void func(){
	static int x = 1;
	printf("%d\n", x);
	x *= 2;
}

int main(int argc, char* argv[]){
	func();
	func();
	func();
}
