#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class Stack{
private:
	Node* top;

public:
	
  Stack(){
  	top = NULL;
  }

  void push(int d){
  	Node* p = new Node;
    p->data = d;
    p->next = NULL;

    if (top==NULL){
       top = p;
    }
  	
  	else {
  		p->next= top;
  		top = p;
  	}
  }

  void displayStack(){
  	if (top==NULL){
  		cout << "Nothing";
  	}
  	else {
  		Node* p = top;
  		while(p != NULL){
  			cout << p->data << endl;
  			p = p->next;
  		}
  	}
  	cout << endl;
  }

  void pop(){
  	Node* p = top;
  	top = p->next;
    delete p;
  }
};

int main(){
	Stack s1;
	for (int j=0;j<5;j++){
		s1.push(j);
	} 
	
	s1.displayStack();
	s1.pop();
	s1.displayStack();

return 0;
}