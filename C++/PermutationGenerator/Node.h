#ifndef NODE_H
#define NODE_H

class Node{
	private:
		int mValue;
		bool mDirection; //Letf = true -- Right = false
	public:
	private:
	public:
		Node(int vlaue); 
		void switchDirection();
		int getValue() const { return mValue; }
		bool getDirection() const { return mDirection; }
};
#endif
