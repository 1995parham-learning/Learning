#include <iostream>
#include <string>

using namespace std;

class SingletonA{
	private:
		string mName;
		SingletonA(){
		}
	public:
		static SingletonA* getInstance(){
			static SingletonA* instance = NULL;
			if(instance == NULL){
				instance = new SingletonA();
			}
			return instance;
		}	
		string getName(){
			return mName;
		}
		void setName(const string& name){
			mName = name;
		}
};

class SingletonB{
	private:
		static SingletonB* instance;
		string mName;
		SingletonB(){
		}
	public:
		static SingletonB* getInstance(){
			if(SingletonB::instance == NULL){
				SingletonB::instance = new SingletonB();
			}
			return SingletonB::instance;
		}
		string getName(){
			return mName;
		}
		void setName(const string& name){
			mName = name;
		}
};

int main(int argc,char* argv[]){
	(SingletonA::getInstance())->setName("First C++ Singleton");
	cout << (SingletonA::getInstance())->getName() << endl;
	(SingletonB::getInstance())->setName("Second C++ Singleton");
	cout << (SingletonB::getInstance())->getName() << endl;
}
