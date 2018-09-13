#include <iostream>
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/CgiEnvironment.h>
#include <cgicc/HTMLClasses.h>
#include "CGIFileHandler.h"

using namespace std;
using namespace cgicc;

int main(int argc,char* argv[]){
	Cgicc cgicc;
	CGIFileHandler fileHandler(cgicc);
	cout << HTTPHTMLHeader() << endl;
	string cppPath = "/var/www/Home/upload/" + cgicc.getEnvironment().getRemoteAddr() + ".cpp";
	string exePath = "/var/www/Home/upload/" + cgicc.getEnvironment().getRemoteAddr() + ".out";
	cout << html() << head() << title("Compiler") << head() << body();
	if(fileHandler.getFile("userFile")){
		ofstream fileOutput(cppPath);
		fileHandler.writeToStream(fileOutput);
		fileOutput.flush();
		fileOutput.close();
		cout << "<div><pre>" << endl;
		system(("g++ -Wall -v " + cppPath + " -o " + exePath + " 2>&1").c_str());
		cout << "</pre></div>" << endl;
		cout << "<div><samp>" << endl;
		system(exePath.c_str());
		cout << "</samp></div>" << endl;
	}else{
		cout << "Every thing went wrong ..." << endl;
	}
	cout << body() << html();
}
