#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATOINGENERATOR_H
#include <vector>
#include <string>
#include "Node.h"

class PermutationGenerator{
	private:
		int mNumber;
		bool mHasNext;
		std::vector<Node> mNodes;
	public:
	private:
		bool isMobile(int index);
	public:
		PermutationGenerator(int number);
		std::string next();
		bool hasNext();
};
#endif
