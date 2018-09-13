#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Node.h"
#include "PermutationGenerator.h"

using namespace std;

PermutationGenerator::PermutationGenerator(int number){
	mNumber = number;
	mNodes.reserve(mNumber);
	for(int i = 0; i < mNumber; i++){
		mNodes.push_back(Node(i + 1));
	}
}

string PermutationGenerator::next(){
	string answer;
	mHasNext = false;
	int mobileMax = 0;
	int mobileIndex = 0;
	for(int i = 0; i < mNodes.size(); i++){
		answer += to_string(mNodes[i].getValue());
		if(PermutationGenerator::isMobile(i)){
			mHasNext = true;
			if(mobileMax < mNodes[i].getValue()){
				mobileIndex = i;
				mobileMax = mNodes[i].getValue();
			}
		}
	}
	if(mNodes[mobileIndex].getDirection()){
		swap(mNodes[mobileIndex], mNodes[mobileIndex - 1]);
	}else{
		swap(mNodes[mobileIndex], mNodes[mobileIndex + 1]);
	}
	for(int i = 0; i < mNodes.size(); i++){
		if(mNodes[i].getValue() > mobileMax){
			mNodes[i].switchDirection();
		}
	}
	return answer;
}

bool PermutationGenerator::isMobile(int index){
	if(mNodes[index].getDirection()){
		if(index == 0){
			return false;
		}else if(mNodes[index - 1].getValue() < mNodes[index].getValue()){
			return true;
		}else{
			return false;
		}
	}else{
		if(index == mNumber - 1){
			return false;
		}else if(mNodes[index + 1].getValue() < mNodes[index].getValue()){
			return true;
		}else{
			return false;
		}
	}
}

bool PermutationGenerator::hasNext(){
	return mHasNext;
}
