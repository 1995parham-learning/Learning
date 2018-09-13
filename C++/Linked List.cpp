#include <iostream>

using namespace std;

struct node{
	int key;
	struct node* next;
	struct node* back;
};
template <class T> class LinkList{
	private:
		struct node* last;
		struct node* first;
		T num;
	public:
		LinkList(){
			num=0;
			first=new struct node;
			first -> next=NULL;
			first -> back=NULL;
			last=first;
		}
		int &operator [](int op){
			struct node* temp=first;
			for(int i=0;i<op;i++){
				temp=temp -> next;
			}
			return temp -> key;
		}
		struct node* at(int n){
			if(n>=num)
				return NULL;
			struct node* temp=first;
			for(int i=0;i<n;i++){
				temp=temp -> next;
			}
			return temp;
		}
		int find(T k){
			struct node* temp=first;
			int index=0;
			while(temp -> key!=k){
				temp=temp -> next;
				index++;
				if(index==num)
					return -1;
			}
			return index;
		}
		void pushBack(T n){
			struct node* temp=new struct node;
			if(num==0){
				first=temp;
			}
			temp -> key=n;
			temp -> next=NULL;
			temp -> back=last;
			last -> next=temp;
			last=temp;
			num++;
		}
		void pushTop(T n){
			if(num==0){
				this -> pushBack(n);
				return;
			}
			struct node* temp=new struct node;
			temp -> key=n;
			temp -> next=first;
			temp -> back=NULL;
			first -> back=temp;
			first=temp;
			num++;
		}
		int size(){
			return num;
		}
		void remove(int n){
			if(n!=0&&n!=num-1){
				struct node* temp=this -> at(n-1);
				((temp -> next) -> next) -> back=temp;
				temp -> next=(temp -> next) -> next;
			}
			else if(n==0){
				first=first -> next;
				first -> back=NULL;
			}
			else{
				(last -> back) -> next=NULL;
				last=last -> back;
			}
			num--;
		}
		void insert(T k,int n){
			if(num==0){
				this -> pushBack(k);
				return;
			}
			if(n==num-1){
				this -> pushBack(k);
				return;
			}
			if(n==-1){
				this -> pushTop(k);
				return;
			}
			struct node* temp1=this -> at(n);
			struct node* temp2=new struct node;
			temp2 -> next=temp1->next;
			temp2 -> key=k;
			temp1 -> next=temp2;
			num++;
		}
};

int main(int argc,char* argv[]){
	LinkList <int> A;
	int n;
	if(argv[1]==NULL){
		cout<<"please enter switch -h -e -r -f"<<endl;
		return -1;
	}
	if(*argv[1]=='-'&&*(argv[1]+1)=='h'){
		cout<<"this is test program for my linked list"<<endl;
		cout<<"-e enter n and then enter n key"<<endl;
		cout<<"-f enter key and get index"<<endl;
		cout<<"-r enter index and key then in linked list reaplace key in index with new key"<<endl;
		return 0;
	}
	if(*argv[1]=='-'&&*(argv[1]+1)=='e'){	
		cin>>n;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			A.pushBack(x);
		}
	}
	/*int m;
	cin>>m;
	A.remove(m-1);
	int k;
	cin>>k;
	A.insert(k,m-2);
	*/for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}/*
	int f;
	cin>>f;
	cout<<A.find(f)+1<<endl;
	cout<<endl;*/
}

