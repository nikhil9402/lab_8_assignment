#include <iostream>
using namespace std;

class node{
 public:
 int data;
 node* next;
 
};

class linkedList{
 private:
  node* head;
  node* tail;
  int k;
 
 public:
  
  linkedList(){
   head = NULL;
   tail = NULL;
   k=0;
  }
  
  void addNode(int d){
   node* temp = new node;         //imp
   temp->data = d;
   temp->next = NULL;
   
   if (head==NULL){
    head = temp;
    tail = temp;
    k++;
   }
   
   else {
    tail->next = temp;
    tail = temp;
    k++;                        //k means the no. of nodes in the linked list
    }
  }

  void displayList(){
   if (head==NULL){             //imp
    cout << "Nothing" << endl;
   }
   else{
    node* temp=head;
    while (temp != NULL){         //imp
      cout << temp->data << endl;
      temp = temp->next;
    }
   }
   cout << endl;
  }

  void insertNode(int d, int i){       //i means the insert position
    node* n = new node;
    n->data=d;
    
    if (i==0){
     n->next = head;
     head = n;
     ++k;
    }
   
    else if (i==k){
     n->next = NULL;
     tail->next = n;
     tail = n;
     ++k;
    }
   
    else {
     node* p = head;
     for (int j=0; j<=i-2; j++){            //...
       p=p->next;
      }
     n->next = p->next;
     p->next = n;
     ++k;
    }
  }


  void deleteNode(int i){
    
    if (i==0){
       node* p = head;
       head = head->next;
       delete p;
       --k;
    }
    
    else if (i==k-1){
       node* p = head;
       for (int j = 0;j<=k-2; j++){
         p = p->next;
        }
       tail = p;
       delete tail->next;
       --k;
    } 

    else{
       node* p = head;
       node* q = head;
       for (int j = 0;j<=i-2; j++){
         p = p->next;
        }
       for (int j = 0;j<=i-1; j++){
         q = q->next;
        }
       p->next = q->next;
       delete q;
       --k;
     }
   }
 };
        
int main(){
  linkedList l1;
  for (int i=0;i<10;i++){
  l1.addNode(i);
  }
  cout << "Linked list l1:" << endl;
  l1.displayList();
  
  l1.insertNode(56,2);
  cout << "Inserted a node at position i=2" << endl; 
  l1.displayList();

  l1.insertNode(56,0);
  cout << "Inserted a node at position i=0" << endl; 
  l1.displayList();
 
  l1.insertNode(56,9);
  cout << "Inserted a node at position i=9" << endl; 
  l1.displayList();

  l1.deleteNode(0);
  cout << "Deleted a node at position i=0" << endl; 
  l1.displayList();

  l1.deleteNode(2);
  cout << "Deleted a node at position i=2" << endl; 
  l1.displayList();

  l1.deleteNode(10);
  cout << "Deleted a node at position i=10" << endl; 
  l1.displayList();
  
return 0;
}
