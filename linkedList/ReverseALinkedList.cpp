/*
We write an iterative approach to reverse a linked list. 
The approach is to start from the head node and prep-end 
the subsequent nodes so that the list gets reversed. 
3 pointers are used to do the list manipulation.
*/

#include <iostream>
#include <stdio.h>

using namespace std;


class Node{
	private:
	int value;
	public:
	Node *next;
	Node(){next=NULL; value=0;};
	Node(int v){value=v;next=NULL;};
	void setValue(int v){value=v;};
	int getValue(){return value;};
};

Node* reverseLinkedList(Node* head){
	Node *ptr1=head;
	Node *ptr2=head->next;
	head->next=NULL;
	Node *ptr3=ptr2->next;

	while(ptr2!=NULL){
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
		if(ptr3!=NULL){
			ptr3=ptr3->next;
		}
	}
	return ptr1;
}


int main(){
	Node* head=new Node(1);
	Node* node2=new Node(2);
	Node* node3=new Node(3);
	Node* node4=new Node(4);
	head->next=node2;
	node2->next=node3;
	node3->next=node4;
	
	/*print*/
	Node* print=head;
	while(print!=NULL){
		cout<<print->getValue()<<" ";
		print=print->next;
	}
	cout<<endl;
	Node *newHead=reverseLinkedList(head);
	
	/*print*/
	print=newHead;
	while(print!=NULL){
		cout<<print->getValue()<<" ";
		print=print->next;
	}
	cout<<endl;
	while(newHead!=NULL){
		Node* ptr;
		ptr=newHead;
		newHead=newHead->next;
		delete ptr;
	}
	return 0;
}