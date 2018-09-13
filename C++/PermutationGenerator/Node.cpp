#include "Node.h"

Node::Node(int value){
	mValue = value;
	mDirection = true;
}

void Node::switchDirection(){
	mDirection = (mDirection) ? false : true;
}
