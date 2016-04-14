/*
Write a program to find in a linked list nth last element
The approach:-
Maintain 2 pointers to head of the list.

Move 1st pointer n - 1 elements.

Now move both the pointers until one of them hits the end of list.

Return the other pointer which would point in the linked list nth element from last.
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
	Node(int v){value=v;next=NULL;};
	int getValue(){return value;};
};
class List{
	public:
	Node* head;
	List(){head=NULL;};
	void addNode(int value){
		Node* newNode=new Node(value);
		if(head==NULL){
			head=newNode;
		}else{
			newNode->next=head;
			head=newNode;
		}
	};
};

int findNthLastElement(List* list, int n){
	Node* ptr1;
	Node* ptr2;
	ptr1=list->head;
	ptr2=list->head;
	for(int i=0;i<n;i++){
		ptr2=ptr2->next;
	}

	while(ptr2!=NULL){
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return ptr1->getValue();
}
void print(List* list){
	Node* ptr=list->head;

	while(ptr!=NULL){
		cout<<ptr->getValue()<<" ";
		ptr=ptr->next;
	}
	cout<<endl;

}
int main(){
	List* list=new List;
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);
	list->addNode(5);
	list->addNode(6);
	list->addNode(7);
	print(list);
	int n=3;
	cout<<findNthLastElement(list,n)<<endl;


	return 0;
}