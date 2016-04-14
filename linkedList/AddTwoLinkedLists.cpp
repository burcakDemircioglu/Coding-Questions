/*
Write a program to add two linked lists like integer addition without additional data structures

For example, if list 1 contains values 1, 7, 5, 6 as its content nodes and list 2 
contains 9, 9, 9 as its content nodes then resultant result is expected to have nodes 2, 7, 5, 5.

The approach:-
The first problem. The lists could be of variable lengths.

The second problem. Integer addition happens from right to left. 
We cannot use any additional data structures like stacks.

The third problem. We need to support carry.

Easiest solution is to make the linked lists of equal size by pre-pending zeros to the shorter list.

Implement a recursive function which keeps pushing a pair of elements till 
end of linked list is reached.

On return of the recursive function sum the data elements and previous c
arry value if any. Also, return the new carry value for the next function call.

Add the new sum element to the final list.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
	private:
	int value;
	public:
	Node* next;
	Node(){next=NULL;value=0;};
	Node(int v){next=NULL; value=v;};
	int getValue(){return value;};
	void setVAlue(int v){value=v;};
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
	};
	int size(){
		Node* ptr=head;
		int count=0;
		while(ptr!=NULL){
			ptr=ptr->next;
			count++;
		}
		return count;
	}
};

void print(List* list){
	Node* print=list->head;
	while(print!=NULL){
		cout<<print->getValue()<<" ";
		print=print->next;
	}
	cout<<endl;
}

int addList(Node* l1, Node* l2, List* result, int size){
	if(size==0)return 0;
	int carry=addList(l1->next, l2->next, result, size-1);
	int sum=l1->getValue()+l2->getValue()+carry;
	int newCarry=sum/10;
	result->addNode(sum%10);
	if(size==4 && newCarry!=0)
		result->addNode(newCarry);
	return newCarry;
}
int main(){
	List* int1=new List();
	List* int2=new List();
	List* result=new List();
	int1->addNode(6);
	int1->addNode(5);
	int1->addNode(7);
	int1->addNode(1);
	int2->addNode(9);
	int2->addNode(9);
	int2->addNode(9);

	print(int1);
	print(int2);

	int difference=int1->size()-int2->size();
	if(difference>0){
		while(difference!=0){
			int2->addNode(0),
			difference--;
		}
	}
	else if(difference<0){
		while(difference!=0){
			int1->addNode(0),
			difference++;
		}
	}
	addList(int1->head,int2->head, result, int1->size());
	print(result);
	return 0;
}