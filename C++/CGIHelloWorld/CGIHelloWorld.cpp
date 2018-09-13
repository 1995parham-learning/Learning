#include <iostream>
#include <exception>
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>

using namespace std;
using namespace cgicc;

int main(int argc,char* argv[]){
	try{
		Cgicc cgi;
		cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
		auto name = cgi.getElement("username");
		cout << html() << endl;
		cout << head() << endl;
		cout << title("Hello CGI Program") << endl;
		cout << head() << endl;
		cout << body() << endl;
		if(name != cgi.getElements().end()){	
			cout << h1("Hello " + name->getValue()) << endl;
		} else{
			cout << h1("Hello") << endl;
		}
		cout << body() << endl;
		cout << html() << endl;
	}catch(exception &e){
		cout << e.what() << endl;	
	}
}
