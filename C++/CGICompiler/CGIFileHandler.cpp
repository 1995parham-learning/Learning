#include "CGIFileHandler.h"
#include <cgicc/Cgicc.h>
#include <string>
#include <iostream>

using namespace std;
using namespace cgicc;

bool CGIFileHandler::getFile(const string& fileValue){
	auto fileIt = mCgicc.getFile(fileValue);
	if(fileIt != mCgicc.getFiles().end()){
		mFileIt = fileIt;
		return true;
	}
	return false;
}
void CGIFileHandler::writeToStream(ostream& output) const{
	mFileIt->writeToStream(output);
}
