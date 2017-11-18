#include <iostream>
using namespace std;

class Stack
{
private:
	int s[20];
    int n;
   
public:
	Stack(){
		n=0;
	}	
	
	void push(int d){
		s[n]=d;
		n++;
	}
	void pop(){
	    s[n]='\0';
		n--;
	}
	void display(){
		cout << "Elements in the stack are" << endl;
		for(int i=n-1;i>=0;i--){
			cout << s[i] << endl;
		}
	}
};


int main(){
	Stack s1;
	s1.push(3);
	s1.push(4);
	s1.push(2);
	s1.display();
	s1.pop();
	s1.display();
return 0;
}