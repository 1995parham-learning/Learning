#ifndef CGIFILEHANDLER_H
#define CGIFILEHANDLER_H

#include <cgicc/Cgicc.h>
#include <string>

class CGIFileHandler{
	public:
		CGIFileHandler(const cgicc::Cgicc& cgicc):mCgicc(cgicc) {}
		bool getFile(const std::string& fileValue);
		void writeToStream(std::ostream& output) const;
	protected:
		cgicc::Cgicc mCgicc;
		cgicc::const_file_iterator mFileIt;
};
#endif
