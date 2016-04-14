/*
Write a program to check if a linked list is a palindrome

The approach:-
Solution for this problem is recursion with a reference to head node of the list.

Whenever the recursive function returns compare the node values and move the 
reference to the next node.
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
	private:
	int value;
	public:
	Node* next;
	Node(){next=NULL;value=0;};
	Node(int v){value=v; next=NULL;};
	int getValue(){return value;}
};
class List{
	public:
	Node* head;
	List(){head=NULL;};
	void addNode(int value){
		Node* node=new Node(value);
		if(head==NULL)
			head=node;
		else{
			node->next=head;
			head=node;
		}
	}
	int getSize(){
		Node* ptr=head;
		int counter=0;
		while(ptr!=NULL){
			ptr=ptr->next;
			counter++;
		}
		return counter;
	}
};

bool ifPalindrom(Node* head, Node* runner, int size, int counter){
	if(runner==NULL)return true;
	bool result=ifPalindrom(head, runner->next, size, counter+1);
	if(result==false)return false;
	for(int i=0;i<size-counter;i++)
		head=head->next;
	if(size/2<counter){
		cout<<head->getValue()<<"=?"<<runner->getValue()<<endl;

		if(head->getValue()==runner->getValue()){
			cout<<"TRUE"<<endl;
			return true;
		}
		else{
			cout<<"FALSE"<<endl;
			return false;
		}
	}
	else return result;
}


int main(){
	List* l1=new List();
	l1->addNode(1);
	l1->addNode(2);
	l1->addNode(3);
	l1->addNode(3);
	l1->addNode(2);
	l1->addNode(1);
	int counter=1;
	if(ifPalindrom(l1->head, l1->head, l1->getSize(), counter)!=false)
		cout<<"is Palindrom"<<endl;
	else
		cout<<"is not Palindrom"<<endl;
	return 0;
}